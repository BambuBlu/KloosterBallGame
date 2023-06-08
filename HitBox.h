#ifndef HITBOX_H
#define HITBOX_H

#include <SFML/Graphics.hpp>
#include "ParametrosCuerpos.h"
#include "HitBoxFisicas.h"

/*
    Clase proveniente de  OBB
*/

class HitBox : public sf::Drawable
{
    protected:
        HitBoxFisicas forma;
        sf::Color color;
    public:
        Cuerpo cuerpo;

        HitBox();
        
        HitBox(const sf::Vector2f, const sf::Vector2f, const float, const sf::Color);
   
       virtual void Dibujar(sf::RenderTarget& target, sf::RenderStates states) const;
   
       sf::Color get_color() const;
  
       void set_color(const sf::Color& _color);
};
#endif

