#pragma once
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

