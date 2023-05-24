#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "Mapas.h"
#include "Bolas.h"
#include "Obstaculos.h"
#include "Flippers.h"
#include "Pistones.h"

class Juego
{
	private:
		int puntaje;
		sf::RenderWindow* ventana;
		sf::VideoMode video_mode;
		sf::Event evento;

		Mapas mapa_de_juego;
		Bolas bola;
		Obstaculos obstaculo;
		Flippers flippers;
		Pistones piston;
		//Item inventario;
		
		void Init_Variables();
		void Init_Window();
	public:
		//
		Juego();
		virtual ~Juego();
		//
		const bool get_Ventana_Esta_Abierta() const;
		//
		void Iniciar_Juego();
		void Terminar_Juego();
		void Lanzar_Bola();
		void Mover_Flippers(/*direccion*/);
		void Actualizar_Puntaje(int);
		void Reiniciar_Puntaje();

		/*
		void Agregar_Al_Inventario(Item);
		void Quitar_Del_Inventario(Item);
		*/
		void Actualizar_Eventos();
		void Actualizar();
		void Renderizar();
};
