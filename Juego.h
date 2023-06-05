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
#include <list>


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

		bool Update(float, std::list<Bola>, std::list<Bola>::iterator);

		void Dibujar(RenderWindow*, std::list<Bola>, std::list<Bola>::iterator, Flippers, Flippers);

};
