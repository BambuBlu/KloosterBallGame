#pragma once

#include <iostream> 

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "ElementoDeJuego.h"
#include "Bola.h"
#include "Flippers.h"


class Juego
{
	private:
		//VENTANA DEL JUEGO
		sf::RenderWindow ventana;
		sf::VideoMode video_mode;
		sf::Event evento;

		//VARIABLES Y OBJETOS DEL JUEGO
		int puntaje;

		//Item inventario;
		void Init_Variables();

	public:
		//
		Juego();
		virtual ~Juego();
		//

		void Actualizar_Puntaje(int);

		void Reiniciar_Puntaje();

		bool Update(float);

};
