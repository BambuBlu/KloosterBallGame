#pragma once
#include <SFML/Graphics.hpp>
#include "Obstaculos.h"
#include "Enemigos.h"
#include "ElementoDeJuego.h"
#include "Juego.h"

class Bola : public ElementoDeJuego
{
	private:
		float posicion;
		float velocidad;
		float tama�o;
		int vidas;
		int da�o;
		bool esta_vivo;
		Juego instancia_juego;

		sf::Texture* text_bola;
		sf::Sprite* sprite_bola;

	public:
		Bola(Juego _instancia_juego);
		virtual ~Bola();

		void Colision_Con_Obstaculo(Obstaculos);
		void Colision_Con_Mob(Enemigos);
		void Quitar_Vida(Enemigos);
};

