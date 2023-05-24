#include "Juego.h"

//Inicializar variables en JUEGO
void Juego::Init_Variables()
{
	this->puntaje = 0;
	this->ventana = nullptr;
}

void Juego::Init_Window()
{
	this->video_mode.height = 600;
	this->video_mode.width = 800;

	this->ventana = new sf::RenderWindow(this->video_mode, "KloosterBall", sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);
}

//Constructor & Destructor
Juego::Juego()
{
	this->Init_Variables();
	this->Init_Window();
}

Juego::~Juego()
{
	delete this->ventana;
}

//Accesors
const bool Juego::get_Ventana_Esta_Abierta() const
{
	return this->ventana->isOpen();
}

//Funciones Publicas de JUEGO (Game Logic)
void Juego::Actualizar_Eventos()
{
	while (this->ventana->pollEvent(this->evento))
	{
		switch (this->evento.type)
		{
		case sf::Event::Closed:
			this->ventana->close();
			break;
		case sf::Event::KeyPressed:
			if (this->evento.key.code == sf::Keyboard::Escape)
			{
				this->ventana->close();
			}
			break;
		}
	}
}

void Juego::Actualizar()
{
	this->Actualizar_Eventos();
}

void Juego::Renderizar()
{
	/*
		-Limpia el frame viejo
		-Renderiza los Objetos
		-Muestra el frame en la ventana
	*/

	this->ventana->clear(sf::Color(128, 128, 128));
	
	//Aca se dibuja lo que queramos.

	this->ventana->display();
}

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
