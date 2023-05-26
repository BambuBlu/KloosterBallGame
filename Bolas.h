#pragma once

#include "Obstaculos.h"
#include "Enemigos.h"
#include "Juego.h"

class Bolas
{
	private:
		float posicion;
		float velocidad;
		float tama�o;
		int vidas;
		int da�o;
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

