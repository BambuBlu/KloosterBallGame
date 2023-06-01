#include "Bola.h"

//PRIMER BOLA QUE PLANTEAMOS
/* 
//Cons - Dest
Bola::Bola(Juego _instancia_juego)
{
	this->velocidad = 0;
	this->vidas = 0;
	this->daño = 0;
	this->esta_vivo = 0;
	this->text_bola = new sf::Texture;
	this->sprite_bola = new sf::Sprite;
	this->text_bola->loadFromFile("bola.png");
	this->sprite_bola->setTexture(*text_bola);
	this->sprite_bola->setPosition(480, 460);

	//Error de puntero, hay que arreglarlo.
	//this->instancia_juego = _instancia_juego;
}

Bola::~Bola()
{

}

//Funciones Publicas de  BOLA
void Bola::Colision_Con_Obstaculo(Obstaculos obstaculo)
{

}

void Bola::Colision_Con_Mob(Enemigos mob)
{

}

void Bola::Quitar_Vida(Enemigos mob)
{

}
*/


//SEGUNDA BOLA (Usando SFML como ayuda)
void Bola::InitBola()
{
	this->bola.setRadius(10);
	this->bola.setPosition(100, 150);
	this->velocidad.x = 5;
	this->velocidad.y = 5;
}

Bola::Bola() 
{
	InitBola();
}

void Bola::mover(float deltaTime) 
{
	this->bola.move(velocidad * deltaTime);
}

void Bola::dibujar(sf::RenderWindow*& ventana) 
{
	ventana->draw(bola);
}

void Bola::comprobarColision(const sf::FloatRect& objeto)
{
	if (this->bola.getGlobalBounds().intersects(objeto)) 
	{
		//Aca se intersecta con el objeto y podemos 
		//agregar la logica que queramos cuando esto ocurre,
		//en este caso solo revierto la posición, por lo que la bola 
		//solo choca en direccion contraria (va palla --> *Colisiona* ahora va palla<-- )
		this->velocidad.x = -velocidad.x;
		this->velocidad.y = -velocidad.y;
    }
}