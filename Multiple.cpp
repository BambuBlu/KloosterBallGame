#include "Multiple.h"
#include <cmath>
#include "rotationMat.h"

Multiple::Multiple()//!< Default constructor
{

}

Multiple::Multiple(Cuerpo* first/*!< First rigid body*/, Cuerpo* second/*!< Second rigid body*/)//!< Constructor that takes in two bodies to generate the collision manifold
{
    cuerpo_a = first;
    cuerpo_b = second;
}

bool Multiple::CircleVsCircle()
{
    /*!< Setting up pointers to two circles*/
    CirclePhys* circleA = (CirclePhys*)cuerpo_a->physicsShape;
    CirclePhys* circleB = (CirclePhys*)cuerpo_b->physicsShape;

    /*!< Calculating vector between the two bodies */
    sf::Vector2f difference = cuerpo_b->getPosicion() - cuerpo_a->getPosicion();

    /*!< Sum of both radiuses */
    float fRadiusSum = circleA->getRadius() + circleB->getRadius();

    float fMag = difference.dotProduct(difference);

    if ((fRadiusSum * fRadiusSum) < fMag)
        return false;


    fMag = std::sqrtf(fMag);

    // If distance between circles is not 0
    if (fMag != 0)
    {
        penetracion = fMag - fRadiusSum; // Penetration distance
        normal = difference / fMag; 
        punto_de_contacto = cuerpo_b->getPosicion() - (normal * circleB->getRadius());
    }
    else
    {
        penetracion = circleA->getRadius();
        normal = sf::Vector2f(1, 0);
        punto_de_contacto = cuerpo_a->getPosicion();
    }
    return true;
}

bool Multiple::CircleVsRect()
{
    /*!< Setting up pointers to a rectangle and a circle */
    RectPhys* rect = (RectPhys*)cuerpo_a->physicsShape;
    CirclePhys* circle = (CirclePhys*)cuerpo_b->physicsShape;

    // Vector between A and B
    sf::Vector2f difference = cuerpo_b->getPosicion() - cuerpo_a->getPosicion();

    /*!< Clamping closest point to nearest edge */
    sf::Vector2f closest = Clamp(rect->getHalfExtent(), difference);

    bool bInside = false;

    // Clamp circle to the closest edge
    if (difference == closest) 
    {
        bInside = true;

        // Find closest axis
        if (std::abs(difference.x()) > std::abs(difference.y()))
        {

            // Clamp to closest extent
            if (closest.x() > 0) 
            {
                closest.setX(rect->getHalfExtent().x());
            }
            else 
            {
                closest.setX(-rect->getHalfExtent().x());
            }
        }
        else
        {
            if (closest.y() > 0) 
            {
                closest.setY(rect->getHalfExtent().y());
            }
            else
            {
                closest.setY(-rect->getHalfExtent().y());
            }
        }
    }

    sf::Vector2f n = difference - closest;
    float fDistance = n.dotProduct(n);
    float fRadius = circle->getRadius();

    // if circle isn't inside AABB
    if (fDistance > fRadius * fRadius && !bInside) {
        return false;
    }

    fDistance = std::sqrtf(fDistance);
    n = n / fDistance;

    // if circle is inside AABB
    if (bInside) {
        normal = -n;
        punto_de_contacto = cuerpo_b->getPosicion() - (normal * circle->getRadius());
        penetracion = fDistance - fRadius;
    }
    else {
        normal = n;
        punto_de_contacto = cuerpo_b->getPosicion() - (normal * circle->getRadius());
        penetracion = fDistance - fRadius;
    }
    return true;
}

bool Multiple::CircleVsOBB()
{
    ObbPhys* obb = (ObbPhys*)cuerpo_a->physicsShape;

    CirclePhys* circle = (CirclePhys*)cuerpo_b->physicsShape;

    // Vector between A and B
    sf::Vector2f difference = cuerpo_b->getPosicion() - cuerpo_a->getPosicion();

    RotationMat matrix = RotationMat(cuerpo_a->getAngleRad());

    sf::Vector2f transform = matrix.inverseRotateVector(difference);

    // Closest point on A to B
    sf::Vector2f closest = Clamp(obb->getHalfExtent(), transform);

    bool bInside = false;

    // Clamp circle to the closest edge
    if (transform == closest) 
    {
        bInside = true;
        if (std::abs(transform.x()) >= std::abs(transform.y()))
        {
            if (closest.x() > 0) 
            {
                closest.setX(obb->getHalfExtent().x());
            }
            else 
            {
                closest.setX(-obb->getHalfExtent().x());
            }
        }
        else 
        {
            if (closest.y() > 0) 
            {
                closest.setY(obb->getHalfExtent().y());
            }
            else 
            {
                closest.setY(-obb->getHalfExtent().y());
            }
        }
    }

    sf::Vector2f n = transform - closest;
    float fDistance = n.dotProduct(n);
    float fRadius = circle->getRadius();

    if (fDistance > fRadius * fRadius && !bInside)
    {
        return false;
    }

    fDistance = std::sqrtf(fDistance);
    n = n / fDistance;

    // if circle is inside AABB
    if (bInside) 
    {
        normal = -n;
        punto_de_contacto = cuerpo_b->getPosicion() - matrix.rotateVector(normal * circle->getRadius());
        penetracion = fDistance - fRadius;
    }
    else 
    {
        normal = n;
        punto_de_contacto = cuerpo_b->getPosicion() - matrix.rotateVector(normal * circle->getRadius());
        penetracion = fDistance - fRadius;
    }
    return true;
}

void Multiple::correctPosition() //!< Applies position correction 
{
    const float kfPercent = 0.2;

    const float kfSlop = 0.01;

    const float kfInvMassSum = cuerpo_a->getMasaInversa() + cuerpo_b->getMasaInversa();

    const float kFScalarNum = std::max(std::abs(penetracion) - kfSlop, 0.0f) / kfInvMassSum;

    sf::Vector2f correction = normal * kFScalarNum * kfPercent;

    cuerpo_a->posicion -= correction * cuerpo_a->getMasaInversa();

    cuerpo_b->posicion += correction * cuerpo_b->getMasaInversa();
}

void Multiple::applyRotationalImpulse()
{
    /*!< Calculating contact points*/
    const sf::Vector2f kBodyAContact(punto_de_contacto - cuerpo_a->getPosicion());
    const sf::Vector2f kBodyBContact(punto_de_contacto - cuerpo_b->getPosicion());

    /*!< Calculate the relative velocity */
    sf::Vector2f rv = (cuerpo_b->getVelocidad() + kBodyBContact.vectorCrossScalar(-cuerpo_b->getVelocidadAngular())) - (cuerpo_a->getVelocidad() + kBodyAContact.vectorCrossScalar(-cuerpo_a->getVelocidadAngular()));

    /*!< Calculate relative velocity along the normal*/
    float fVelAlongNormal = rv.dotProduct(normal);

    /*!< Do not apply impulse if velocities are separating*/
    if (fVelAlongNormal > 0) 
    {
        return;
    }

    /*!< Calculate restitution */
    float fRestitution = std::min(cuerpo_a->getRestitucion(), cuerpo_b->getRestitucion());

    const float kfContactACrossNormal = kBodyAContact.crossProduct(normal);
    const float kfContactBCrossNormal = kBodyBContact.crossProduct(normal);

    /*!< Calculate impulse scalar */
    float fImpulseScalar = -(1 + fRestitution) * fVelAlongNormal;
    fImpulseScalar /= cuerpo_a->getMasaInversa() + cuerpo_b->getMasaInversa() + (kfContactACrossNormal * kfContactACrossNormal) * cuerpo_a->getInerciaInversa() + (kfContactBCrossNormal * kfContactBCrossNormal) * cuerpo_b->getInerciaInversa();

    /*!< Apply rotational impulse */
    sf::Vector2f impulse = normal * fImpulseScalar;

    cuerpo_a->AplicarImpulso(-impulse, kBodyAContact);

    cuerpo_b->AplicarImpulso(impulse, kBodyBContact);
}

sf::Vector2f Multiple::Clamp(const sf::Vector2f& rectExtents, const sf::Vector2f& circlePos) { //!< Determining closest point to closest edge of AABB

    sf::Vector2f gancho = sf::Vector2f();

    if (circlePos.x >= 0) 
    {
        gancho.x = std::min(circlePos.x, rectExtents.x);
    }
    else 
    {
        gancho.x = std::max(circlePos.x, - rectExtents.x);
    }

    if (circlePos.y >= 0) 
    {
        gancho.y = std::min(circlePos.y, rectExtents.y);
    }
    else 
    {
        gancho.y = std::max(circlePos.y, -rectExtents.y);
    }
    return gancho;
}