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
#include "EnemigoRedondo.h"
#include "EnemigoRectangular.h"
#include "Flippers.h"
#include <list>

/*
    Clase proveniente de Main 
    Pienso que la usemos para crear dos o tres mapas y manejemos todo de acá

*/


class Juego
{
	private:
		//Ventana
		sf::RenderWindow ventana;
		sf::VideoMode video_mode;
		sf::Event evento;
        sf::Font fuente_de_texto;

        ///Game Logic
        bool bool_En_Juego;
        bool bool_Fin_Juego;
        int puntaje_total;
        int bolas_restantes;
        int puntaje_mas_alto;

        void InitJuego();

	public:
        Juego();

        bool primer_nivel();

        bool EventosTeclas(Flippers fliper_1, Flippers fliper_2);

        void restar_vida();
};

#endif





