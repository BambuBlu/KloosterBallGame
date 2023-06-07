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
#include "Jugadores.h"


class Juego
{
	private:
		//VENTANA DEL JUEGO
		sf::RenderWindow ventana;
		sf::VideoMode video_mode;
		sf::Event evento;
		Jugadores jugador;
		void Init_Variables();

	public:
		Juego();
		virtual ~Juego();
	
		bool Update(float deltaTime, std::list<Bola> bolas, std::list<Bola>::iterator bolasIterador, Flippers flipper_1, Flippers flipper_2);

		void Dibujar(sf::RenderWindow*, std::list<Bola>, std::list<Bola>::iterator, Flippers, Flippers);

		//bool Sumar_Puntaje(Jugadores);
		//bool Guardar_Puntaje(Jugadores);
};
