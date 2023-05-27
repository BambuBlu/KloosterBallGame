#include "Enemigos.h"

//Inicializar ENEMIGO

void Enemigos::Init_Enemigo()
{
	this->vida = 5;
	this->tamaño = 0;
	this->posicion = 0;
	this->esta_vivo = true;
}

Enemigos::Enemigos()
{
	this->Init_Enemigo();
}

Enemigos::~Enemigos()
{

}

//Funciones Publicas de MOB 	

void  Enemigos::Golpear_Bola()
{

}

void Enemigos::Bajar_Vida()
{

}
