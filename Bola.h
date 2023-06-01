#pragma once
#include <SFML/Graphics.hpp>
#include "Obstaculos.h"
#include "Enemigos.h"
#include "ElementoDeJuego.h"
#include "Juego.h"
/*
class Bola : public ElementoDeJuego
{
	private:
		float posicion_X, posicion_Y;
		float velocidad_X, velocidad_y;
		float tamaño;
		int vidas;
		int daño;
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
*/

class Bola {
    private:
		sf::CircleShape bola;
		sf::Vector2f velocidad;
		void InitBola();

    public:
		Bola();
		void mover(float deltaTime);
		void dibujar(sf::RenderWindow*& ventana);
		void comprobarColision(const sf::FloatRect& objeto);
};