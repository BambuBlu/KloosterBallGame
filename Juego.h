#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Randomizador.h"
#include "SetsGlobales.h"
#include "Bola.h"
#include "Rectangulo.h"
#include "HitBox.h"
#include "Multiple.h"
#include "TextureManager.h"
#include <list>

/*
    Clase proveniente de Main 
    Pienso que la usemos para crear dos o tres mapas y manejemos todo de acá
*/

std::list<Bola> bolas;  
std::list<Bola>::iterator bolasIterador;

class Juego
{
	private:
		//Ventana
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

#endif





