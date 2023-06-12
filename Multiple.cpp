#include "Multiple.h"

/// Funciones matematicas utilizadas
float productoEscalar(sf::Vector2f& v1, sf::Vector2f& v2)
{
    float producto = 0;
    producto = v1.x * v2.x + v1.y * v2.y;
    return producto;
}

float productoEscalar(sf::Vector2f& v1)
{
    float producto = 0;
    producto = v1.x * v1.x + v1.y * v1.y;
    return producto;
}

float productoCruzado(sf::Vector2f& v1, sf::Vector2f& v2) 
{

    float resultado = v1.x * v2.y - v1.y * v2.x; // "Producto cruzado" extendido

    return resultado;
}

sf::Vector2f escalar_cruzado(sf::Vector2f& vector, float scalar) {

    sf::Vector2f resultado;

    resultado.x = vector.y * scalar;
    resultado.y = vector.x * -scalar;

    return resultado;
}

///METODOS DE LA CLASE
Multiple::Multiple()//!< Default constructor
{

}

Multiple::Multiple(Cuerpo* first, Cuerpo* second)//!< Constructor that takes in two bodies to generate the collision manifold
{
    cuerpo_a = first;
    cuerpo_b = second;
}

bool Multiple::CircleVsCircle()
{
    /*!< Setting up pointers to two circles*/
    FisicasCirculo* circleA = (FisicasCirculo*)cuerpo_a->fisicaTipo;
    FisicasCirculo* circleB = (FisicasCirculo*)cuerpo_b->fisicaTipo;

    /*!< Calculating vector between the two bodies */
    sf::Vector2f difference = cuerpo_b->getPosicion() - cuerpo_a->getPosicion();

    /*!< Sum of both radiuses */
    float fRadiusSum = circleA->getRadio() + circleB->getRadio();

    float fMag = productoEscalar(difference);

    if ((fRadiusSum * fRadiusSum) < fMag)
        return false;


    fMag = std::sqrtf(fMag);

    // If distance between circles is not 0
    if (fMag != 0)
    {
        penetracion = fMag - fRadiusSum; // Penetration distance
        normal = difference / fMag; 
        punto_de_contacto = cuerpo_b->getPosicion() - (normal * circleB->getRadio());
    }
    else
    {
        penetracion = circleA->getRadio();
        normal = sf::Vector2f(1, 0);
        punto_de_contacto = cuerpo_a->getPosicion();
    }
    return true;
}

bool Multiple::CircleVsRect()
{
    /*!< Setting up pointers to a rectangle and a circle */
    RectanguloFisicas* rect = (RectanguloFisicas*)cuerpo_a->fisicaTipo;
    FisicasCirculo* circle = (FisicasCirculo*)cuerpo_b->fisicaTipo;

    // Vector between A and B
    sf::Vector2f difference = cuerpo_b->getPosicion() - cuerpo_a->getPosicion();

    /*!< Clamping closest point to nearest edge */
    sf::Vector2f closest = Clamp(rect->get_extensionMedia(), difference);

    bool bInside = false;

    // Clamp circle to the closest edge
    if (difference == closest) 
    {
        bInside = true;

        // Find closest axis
        if (std::abs(difference.x) > std::abs(difference.y))
        {

            // Clamp to closest extent
            if (closest.x > 0) 
            {
                closest.x = (rect->get_extensionMedia().x);
            }
            else 
            {
                closest.x = (-rect->get_extensionMedia().x);
            }
        }
        else
        {
            if (closest.y > 0) 
            {
                closest.y = (rect->get_extensionMedia().y);
            }
            else
            {
                closest.y = (-rect->get_extensionMedia().y);
            }
        }
    }

    sf::Vector2f n = difference - closest;

    float fDistance = productoEscalar(n);

    float fRadius = circle->getRadio();

    // if circle isn't inside AABB
    if (fDistance > fRadius * fRadius && !bInside) {
        return false;
    }

    fDistance = std::sqrtf(fDistance);
    n = n / fDistance;

    // if circle is inside AABB
    if (bInside) {
        normal = -n;
        punto_de_contacto = cuerpo_b->getPosicion() - (normal * circle->getRadio());
        penetracion = fDistance - fRadius;
    }
    else {
        normal = n;
        punto_de_contacto = cuerpo_b->getPosicion() - (normal * circle->getRadio());
        penetracion = fDistance - fRadius;
    }
    return true;
}

bool Multiple::CircleVsOBB()
{
    HitBoxFisicas* hitbox = (HitBoxFisicas*)cuerpo_a->fisicaTipo;

    FisicasCirculo* circle = (FisicasCirculo*)cuerpo_b->fisicaTipo;

    // Vector between A and B
    sf::Vector2f difference = cuerpo_b->getPosicion() - cuerpo_a->getPosicion();

    Rotacion matrix = Rotacion(cuerpo_a->getGradosAngulo());

    sf::Vector2f transform = matrix.rotar_vector_inversamente(difference);

    // Closest point on A to B
    sf::Vector2f closest = Clamp(hitbox->get_extension_media(), transform);

    bool bInside = false;

    // Clamp circle to the closest edge
    if (transform == closest)
    {
        bInside = true;
        if (std::abs(transform.x) >= std::abs(transform.y))
        {
            if (closest.x > 0)
            {
                closest.x = (hitbox->get_extension_media().x);
            }
            else
            {
                closest.x = (-hitbox->get_extension_media().x);
            }
        }
        else
        {
            if (closest.y > 0)
            {
                closest.y = (hitbox->get_extension_media().y);
            }
            else
            {
                closest.y = (-hitbox->get_extension_media().y);
            }
        }
    }

    sf::Vector2f n = transform - closest;

    float fDistance = productoEscalar(n);

    float fRadius = circle->getRadio();

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

        punto_de_contacto = cuerpo_b->getPosicion() - matrix.rotar_vector(normal * circle->getRadio());

        penetracion = fDistance - fRadius;
    }
    else
    {
        normal = n;

        punto_de_contacto = cuerpo_b->getPosicion() - matrix.rotar_vector(normal * circle->getRadio());

        penetracion = fDistance - fRadius;
    }
    return true;
}

void Multiple::correctPosition() //!< Applies position correction 
{
    const float kfPercent = 0.2f;

    const float kfSlop = 0.01f;

    const float kfInvMassSum = cuerpo_a->getMasaInversa() + cuerpo_b->getMasaInversa();

    const float kFScalarNum = std::max(std::abs(penetracion) - kfSlop, 0.0f) / kfInvMassSum;

    sf::Vector2f correction = normal * kFScalarNum * kfPercent;

    cuerpo_a->posicion -= correction * cuerpo_a->getMasaInversa();

    cuerpo_b->posicion += correction * cuerpo_b->getMasaInversa();
}

void Multiple::applyRotationalImpulse()
{
    /*!< Calculating contact points*/
    sf::Vector2f kBodyAContact(punto_de_contacto - cuerpo_a->getPosicion());
    sf::Vector2f kBodyBContact(punto_de_contacto - cuerpo_b->getPosicion());

    /*!< Calculate the relative velocity */
    sf::Vector2f velocidadRelativa = (cuerpo_b->getVelocidad() + escalar_cruzado(kBodyBContact , -cuerpo_b->getVelocidadAngular())) -
                         (cuerpo_a->getVelocidad() + escalar_cruzado(kBodyAContact, -cuerpo_a->getVelocidadAngular()));

    /*!< Calculate relative velocity along the normal*/
    float fVelAlongNormal = productoEscalar(normal, velocidadRelativa);

    /*!< Do not apply impulse if velocities are separating*/
    if (fVelAlongNormal > 0) 
    {
        return;
    }

    /*!< Calculate restitution */
    float fRestitution = std::min(cuerpo_a->getRestitucion(), cuerpo_b->getRestitucion());

    const float kfContactACrossNormal = productoCruzado(normal, kBodyAContact);

    const float kfContactBCrossNormal = productoCruzado(normal, kBodyBContact);

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