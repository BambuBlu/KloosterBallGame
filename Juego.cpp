#include "Juego.h"

//Inicializar variables en JUEGO
void Juego::Init_Variables()
{
	this->puntaje = 0;
}

//VENTANA DEL JUEGO
void Juego::Init_Window()
{
	this->video_mode.height = 720;
	this->video_mode.width = 1280;

	this->ventana.create(this->video_mode, "KloosterBallGAME", sf::Style::Default);
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

//Dibujar()
void Juego::Dibujar(Mapas)
{

}

void Juego::Dibujar(Bolas)
{

}

void Juego::Dibujar(Obstaculos)
{

}

void Juego::Dibujar(Flippers)
{

}

void Juego::Dibujar(Pistones)
{

}
