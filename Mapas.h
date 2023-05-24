#pragma once
#include "Juego.h"
#include "Obstaculos.h"
#include "Enemigos.h"

class Mapas
{
	private:
		Obstaculos obstaculo;
		Enemigos mob;
		//Item objeto;
	public:
		void Agregar_Obstaculo(Obstaculos);
		void Quitar_Obstaculo(Obstaculos);
		void Agregar_Mob(Enemigos mob);
		void Quitar_Mob(Enemigos mob);

		//void Agregar_Item();
		//void Quitar_Item();
};

