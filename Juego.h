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
		// Ejemplo:
		//	ElementoDeJuego[] elementos_de_juego;

		//Item inventario;
		
		void Init_Window();
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

		/*
		Todo lo que tenga que ver con Items y/o inventario lo dejamos para el final :P
		void Agregar_Al_Inventario(Item);
		void Quitar_Del_Inventario(Item);
		*/

		/*La funcion dibujar va a estar fragmentada, de esta forma, siempre que queramos dibujar un objeto por pantalla,
		podemos usar dibujar() y enviarle su respectivo objeto. Yo imagino que en el codigo quedaria algo como:
			bola.mover();
			Dibujar(bola);
		*/
};
