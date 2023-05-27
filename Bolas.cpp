#include "Bolas.h"

//Inicializar BOLA
void Bolas::Init_Bola()
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
}

//Cons - Dest
Bolas::Bolas()
{
	this->Init_Bola();

}

Bolas::~Bolas()
{

}

//Funciones Publicas de  BOLA
void Bolas::Colision_Con_Obstaculo(Obstaculos obstaculo)
{

}

void Bolas::Colision_Con_Mob(Enemigos mob)
{

}

void Bolas::Quitar_Vida(Enemigos mob)
{

}
