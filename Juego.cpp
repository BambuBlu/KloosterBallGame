#include "Juego.h"

//Inicializar variables en JUEGO
void Juego::Init_Variables()
{
	this->puntaje = 0;
}

//VENTANA DEL JUEGO
void Juego::Init_Window()
{
	this->ventana = nullptr;

	this->video_mode.height = 720;
	this->video_mode.width = 1280;

	this->ventana = new sf::RenderWindow(this->video_mode, "KloosterBallGAME", sf::Style::Default);
}

const bool Juego::Ventana_Esta_Abierta() const
{
	return this->ventana->isOpen();
}


//Constructor & Destructor
Juego::Juego()
{
	this->Init_Variables();
}

Juego::~Juego()
{
	delete this->ventana;
}


//Funciones de Game Logic
void Juego::Iniciar() 
{

	while (this->Ventana_Esta_Abierta())
	{

		while (this->ventana->pollEvent(this->evento))
		{

			this->ventana->clear();

			//Aca se dibuja lo que queramos

			this->ventana->display();

		}

	}

}

void Juego::Terminar()
{
	this->~Juego();
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
