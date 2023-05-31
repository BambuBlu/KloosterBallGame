#include "Juego.h"
#include "TextureManager.h"


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
	 this->ventana.close();
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

/*
	Funcion principal para la actualizacion de la logica del juego

	La variable "float deltaTime" indica cuantos segundos pasan desde el ultimo llamado
	Y es utilizado para el calculo de fisicas
*/
bool Juego::Update(float deltaTime)
{

	return true;
}

void Juego::Notificar_Evento(Tipo_De_Evento evento)
{

}
