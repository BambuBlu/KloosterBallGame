#pragma once

#include "Obstaculos.h"
#include "Enemigos.h"
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
		Texture * text_bola;
		Sprite * sprite_bola;

		void Init_Bola();

	public:
		Bolas();
		virtual ~Bolas();

		void Colision_Con_Obstaculo(Obstaculos);
		void Colision_Con_Mob(Enemigos);
		void Quitar_Vida(Enemigos);
		void Actualizar();
		void Dibujar();
};

