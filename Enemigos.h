#pragma once

#include "Juego.h"

class Enemigos
{
	private:
		float posicion;
		float tama�o;
		int vida;
		bool esta_vivo;
		void Init_Mob();

	public:
		void Golpear_Bola();
		void Bajar_Vida();
		void actualizar();
		void dibujar();
};

