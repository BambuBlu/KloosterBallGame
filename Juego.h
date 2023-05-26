#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "Manager.h"

#include "Mapas.h"
#include "Bolas.h"
#include "Obstaculos.h"
#include "Flippers.h"
#include "Pistones.h"

class Juego : private Manager
{
	private:
		int puntaje;

		Mapas mapa_de_juego;
		Bolas bola;
		Obstaculos obstaculo;
		Flippers flippers;
		Pistones piston;
		//Item inventario;
		
		void Init_Variables();

	public:
		//
		Juego();
		virtual ~Juego();
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
};
