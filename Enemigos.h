#pragma once
#include "Mapas.h"
#include "Bolas.h"
#include "Obstaculos.h"
#include "Bolas.h"
#include "Flippers.h"
#include "Pistones.h"
#include "Juego.h"

class Enemigos
{
	private:
		float posicion;
		float tamaño;
		int vida;
		bool esta_vivo;
		void Init_Mob();

	public:
		void Golpear_Bola();
		void Bajar_Vida();
		void actualizar();
		void dibujar();
};

