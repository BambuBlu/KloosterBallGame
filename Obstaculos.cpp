#include "Obstaculos.h"

//Inicializar OBSTACULOS.
void Obstaculos::Init_Obstaculo()
{
	this->tamaño = 0;
	this->posicion = 0;
	this->esta_vivo = true;
}

Obstaculos::Obstaculos()
{
	this->Init_Obstaculo();
}

Obstaculos::~Obstaculos()
{
}
