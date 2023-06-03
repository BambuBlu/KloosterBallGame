#pragma once
#include <SFML/Graphics.hpp>

class Flippers 
{

    private:
        sf::RectangleShape flipper;
        float velocidad;

        void Init_Flippers();

    public:
        Flippers();

        void Mover_Izquierda();

        void Mover_Derecha();

        void Mover_Flipper();

        void Dibujar(sf::RenderWindow*&);

        sf::FloatRect Get_Bounds() const;
};