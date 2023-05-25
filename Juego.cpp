#include "Juego.h"

//Inicializar variables en JUEGO
void Juego::Init_Variables()
{
	this->puntaje = 0;
}


//Constructor & Destructor
Juego::Juego()
{
	this->Init_Variables();
}

Juego::~Juego()
{
}


//Funciones Publicas de JUEGO (Game Logic)

void Juego::Iniciar_Juego()
{

}

void Juego::Terminar_Juego()
{

}

void Juego::Lanzar_Bola()
{

}

void Juego::Mover_Flippers(/*direccion*/)
{

}

void Juego::Actualizar_Puntaje(int _puntos)
{
	this->puntaje += _puntos;
}

void Juego::Reiniciar_Puntaje()
{
	this->puntaje = 0;
}
