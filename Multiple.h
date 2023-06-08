#ifndef MULTIPLE_H
#define MULTIPLE_H

#include "bola.h"
#include "rect.h"
#include "obb.h"

/*
    Clase proveniente de Manifold
     Genera un sistema de colisiones.
*/

class Multiple
{
    protected:
        Cuerpo* cuerpo_a;
        Cuerpo* cuerpo_b; 

    private:
        float penetracion;
        sf::Vector2f normal;
        sf::Vector2f punto_de_contacto;

    public:
        Multiple();

        Multiple(Cuerpo* first , Cuerpo* second); 

        bool CircleVsCircle();  //Determina colision entre circulo - circulo

        bool CircleVsRect(); //Determina colision entre circulo - rectangulo

        bool CircleVsOBB(); //Determina colision entre circulo - obb

        sf::Vector2f getNormal() const { return normal;}

        float getPenetration() const { return penetracion;}

        void applyRotationalImpulse();

        void correctPosition();

        sf::Vector2f Clamp(const sf::Vector2f& rectExtents, const sf::Vector2f& circlePos); //Determina el punto mas cecano al borde de AABB
};
#endif
