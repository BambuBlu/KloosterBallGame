#include "Bola.h"


//Cons - Dest
Bola::Bola(Juego _instancia_juego)
{
	this->posicion = 0;
	this->velocidad = 0;
	this->tamaño = 0;
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
