#pragma once

#include <iostream> 

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "ElementoDeJuego.h"

enum Tipo_De_Evento 
{
	bola_destruida,
};


class Juego
{
	private:
		//VENTANA DEL JUEGO
		sf::RenderWindow ventana;
		sf::VideoMode video_mode;
		sf::Event evento;

		//VARIABLES Y OBJETOS DEL JUEGO
		int puntaje;
		//Mapas mapa_de_juego;

		//Colocar array dinamico con ElementoDeJuego
		//Ejemplo:
		//ElementoDeJuego[] elementos_de_juego;

		//Item inventario;
		void Init_Variables();

	public:
		//
		Juego();
		virtual ~Juego();
		//
		void Lanzar_Bola();

		void Mover_Flippers(/*direccion*/);

		void Actualizar_Puntaje(int);

		void Reiniciar_Puntaje();

		bool Update(float);

		void Notificar_Evento(Tipo_De_Evento);
};
