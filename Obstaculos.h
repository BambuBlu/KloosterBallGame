#pragma once
#include "Juego.h"

class Obstaculos
{
	private:
		float posicion;
		float tama�o;
		bool esta_vivo;
		void Init_Obstaculo();
	public:
		void Actualizar();
		void Dibujar();
};

