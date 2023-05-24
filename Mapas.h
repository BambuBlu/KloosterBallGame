#pragma once

#include "Obstaculos.h"
#include "Enemigos.h"

class Mapas
{
	private:
		Obstaculos obstaculo;
		Enemigos enemigo;
		//Item objeto;

	public:
		Mapas();
		virtual ~Mapas();

		void Agregar_Obstaculo(Obstaculos);
		void Quitar_Obstaculo(Obstaculos);
		void Agregar_Mob(Enemigos);
		void Quitar_Mob(Enemigos);
		//void Agregar_Item();
		//void Quitar_Item();
};

