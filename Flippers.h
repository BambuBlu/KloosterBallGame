#pragma once
#include <SFML/Graphics.hpp>

class Flippers 
{

    private:
           
        sf::Sprite _sprite;
        sf::Texture _texture;

        sf::Sprite _sprite2;
        sf::Texture _texture2;
        

        void Init_Flippers();

    public:
        Flippers();

        /*void Mover_Izquierda();

        void Mover_Derecha();*/

        void Mover(std::string);

        //void Mover_Flipper();

        void Dibujar(sf::RenderWindow*&);
        void Dibujar2(sf::RenderWindow*& ventana);
        

        
};