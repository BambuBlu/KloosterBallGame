#pragma once
#include "Bolas.h"
#include "Enemigos.h"
#include "Obstaculos.h"
#include "Bolas.h"
#include "Flippers.h"
#include "Pistones.h"
#include "Juego.h"

class Mapas
{
	private:
		Obstaculos obstaculo;
		Enemigos mob;
		//Item objeto;
	public:
		void Agregar_Obstaculo(Obstaculos obstaculo);
		void Quitar_Obstaculo(Obstaculos obstaculo);
		void Agregar_Mob(Enemigos mob);
		void Quitar_Mob(Enemigos mob);

		//void Agregar_Item();
		//void Quitar_Item();
};

