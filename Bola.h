#pragma once
#include <SFML/Graphics.hpp>
#include "Obstaculos.h"
#include "Enemigos.h"
#include "ElementoDeJuego.h"
#include "Juego.h"

/*
* Conceptos proximamente aplicables a la bola
		int vidas;
		int daño;
		bool esta_vivo;
		void Quitar_Vida(Enemigos);
*/

class Bola 
{
    private:
		sf::CircleShape bola;

		sf::Vector2f velocidad;


		void InitBola();

    public:
		Bola();
		void Mover(float deltaTime);
		void Dibujar(sf::RenderWindow*& ventana);
		void ComprobarColision(Bola&, int);
};