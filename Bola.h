#pragma once
#include <SFML/Graphics.hpp>
#include "Obstaculos.h"
#include "Enemigos.h"
#include "ElementoDeJuego.h"
#include "Juego.h"
#include "Flippers.h"

/*
	Conceptos proximamente aplicables a la bola
		-int vidas;
		-int daño;
		-bool esta_vivo;
		-void Quitar_Vida(Enemigos);
*/

class Bola
{
private:
	sf::CircleShape bola;

	sf::Vector2f velocidad;

	float gravedad;

	void InitBola();

public:
	Bola();

	void Mover(float deltaTime);

	void Dibujar(sf::RenderWindow*& ventana);

	void Aplicar_Gravedad(float deltaTime);

	void Comprobar_Colision_Bolas(Bola&, int);

	void Comprobar_Colision(const Flippers objeto);

	void comprobarLimites();

};