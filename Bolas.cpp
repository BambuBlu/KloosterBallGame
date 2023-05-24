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
}

//Cons - Dest
Bolas::Bolas()
{
	this->Init_Bola();
}
Bolas::~Bolas()
{

}

//Funciones Publicas de BOLA
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
