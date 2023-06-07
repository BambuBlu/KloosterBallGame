#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "TextureManager.h"
#include "ElementoDeJuego.h"
#include <list>

#include "Jugadores.h"
#include "Bola.h"
#include "Flippers.h"

std::list<Bola> bolas;  
std::list<Bola>::iterator bolasIterador;

class Juego
{
	private:
		//VENTANA DEL JUEGO
		sf::RenderWindow ventana;
		sf::VideoMode video_mode;
		sf::Event evento;

        ///Game Logic

        bool bool_En_Juego = false;
        bool bool_Fin_Juego = false;
        int puntaje_total = 0;
        int bolas_restantes = 3;
        int puntaje_mas_alto = 0;

	public:
        Juego();
        void restar_vida();
};







