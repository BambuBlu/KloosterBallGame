#ifndef RECTANGULO_H
#define RECTANGULO_H

#include <SFML/Graphics.hpp>
#include "SetsGlobales.h"
#include "ParametrosCuerpos.h"
#include "RectanguloFisicas.h"

/*
    Clase proveniente de rect
*/

class Rectangulo : public sf::Drawable
{
    protected:
        RectanguloFisicas forma;
        sf::Color color;
    public:
        Cuerpo cuerpo;

        Rectangulo();

        Rectangulo(const sf::Vector2f _origen, const sf::Vector2f _extensionMedia, const sf::Color _color);
       
        void Dibujar(sf::RenderTarget& _ventana) const;

        void set_color(const sf::Color&);

        sf::Color get_color() const;
};

#endif

