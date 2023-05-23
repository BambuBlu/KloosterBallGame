#pragma once
#include "Mapas.h"
#include "Enemigos.h"
#include "Obstaculos.h"
#include "Bolas.h"
#include "Flippers.h"
#include "Pistones.h"
#include "Juego.h"

class Bolas
{
	private:
		float posicion;
		float velocidad;
		float tamaño;
		int vidas;
		int daño;
		bool esta_vivo;

		void Init_Bola();
	public:
		void Colision_Con_Obstaculo(Obstaculos);
		void Colision_Con_Mob(Enemigos);
		void Quitar_Vida(Enemigos);
		void Actualizar();
		void Dibujar();
};

