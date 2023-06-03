 #include "Flippers.h"

void Flippers::Init_Flippers()
{
	_texture.loadFromFile("flipper.png");
	_sprite.setTexture(_texture);
	_sprite.setPosition(50, 426);

	_texture2.loadFromFile("flipper2.png");
	_sprite2.setTexture(_texture2);
	_sprite2.setPosition(450, 426);
	
}

Flippers::Flippers()
{
	this->Init_Flippers();
}

void Flippers::Mover_Izquierda() 
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		_sprite.setOrigin(_sprite.getTexture()->getSize().x/20,_sprite.getTexture()->getSize().y/100);
		_sprite.setRotation(-45);
	}
	else {
		_sprite.setRotation(0);
	}
}

void Flippers::Mover_Derecha()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
		_sprite2.setOrigin(_sprite2.getTexture()->getSize().x, _sprite2.getTexture()->getSize().y/100);
		_sprite2.setRotation(45);
	}
	else {
		_sprite2.setRotation(0);
	}

}

void Flippers::Dibujar(sf::RenderWindow*& ventana) 
{
    ventana->draw(_sprite);
}

void Flippers::Dibujar2(sf::RenderWindow*& ventana)
{	
	ventana->draw(_sprite2);
}

