#include "Bolas.h"

//Inicializar BOLA
void Bolas::Init_Bola()
{
	this->posicion = 0;
	this->velocidad = 0;
	this->tama�o = 0;
	this->vidas = 0;
	this->da�o = 0;
	this->esta_vivo = 0;
}

//Cons - Dest
Bolas::Bolas()
{
	this->Init_Bola();
	text_bola = new Texture;
	sprite_bola = new Sprite;
	text_bola->loadFromFile("bola.png");
	sprite_bola->setTexture(*text_bola);
	sprite_bola->setPosition(480, 460);

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

void Bolas::Actualizar()
{

}

void Bolas::Dibujar()
{
	

}
