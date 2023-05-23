#pragma once
#include "Mapas.h"
#include "Bolas.h"
#include "Enemigos.h"
#include "Obstaculos.h"
#include "Bolas.h"
#include "Pistones.h"
#include "Juego.h"

class Flippers
{
	private:
		float posicion;
		float orientacion;

	public:
		void Mover();
		void Actualizar();
		void Dibujar();
};

