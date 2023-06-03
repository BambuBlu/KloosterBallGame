#include "Flippers.h"

void Flippers::Init_Flippers()
{
	this->flipper.setSize(sf::Vector2f(200, 30));

	this->flipper.setPosition(100, 600);

	this->flipper.setFillColor(sf::Color::Green);

	this->velocidad = 5.f;
}

Flippers::Flippers()
{
	this->Init_Flippers();
}

void Flippers::Mover_Izquierda() 
{
    flipper.move(-velocidad, 0.f);
}

void Flippers::Mover_Derecha() 
{
    flipper.move(velocidad, -5.f);
}



void Flippers::Dibujar(sf::RenderWindow*& ventana) 
{
    ventana->draw(flipper);
}

sf::FloatRect Flippers::Get_Bounds() const 
{
    return flipper.getGlobalBounds();
}