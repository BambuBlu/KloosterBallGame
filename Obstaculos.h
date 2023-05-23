#pragma once
#include "Mapas.h"
#include "Bolas.h"
#include "Enemigos.h"
#include "Bolas.h"
#include "Flippers.h"
#include "Pistones.h"
#include "Juego.h"

class Obstaculos
{
	private:
		float posicion;
		float tamaño;
		bool esta_vivo;
		void Init_Obstaculo();
	public:
		void Actualizar();
		void Dibujar();
};

