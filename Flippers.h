#pragma once
#include <SFML/Graphics.hpp>
#include "SetsGlobales.h"
#include "ParametrosCuerpos.h"

class Flippers 
{

    private:
           
        sf::Sprite _sprite;
        sf::Texture _texture;
        bool en_lado_izquierdo; 

    public:
        Cuerpo cuerpo;

        Flippers(const sf::Vector2f& _position, const sf::Vector2f& _aceleracion, const sf::Vector2f& _velocidad, float _angulo, bool _lado);

        void Mover(std::string);

        void clampPaddle();

        void Dibujar(sf::RenderWindow*&);
};