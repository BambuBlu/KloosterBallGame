#pragma once
#include "Mapas.h"
#include "Bolas.h"
#include "Enemigos.h"
#include "Obstaculos.h"
#include "Bolas.h"
#include "Flippers.h"
#include "Juego.h"

class Pistones
{
	private:
		float posicion;
		float fuerza;

	public:
		void Fuerza_De_Empuje(float);
		void Soltar();
};

