#include "Juego.h"
#include "TextureManager.h"
#include "Bola.h"
#include "Flippers.h"
//Inicializar variables en JUEGO
void Juego::Init_Variables()
{
	this->puntaje = 0;
}



//Constructor & Destructor
Juego::Juego()
{
	this->Init_Variables();
}

Juego::~Juego()
{
	 this->ventana.close();
}

bool Juego::Update(float deltaTime, std::list<Bola> bolas, std::list<Bola>::iterator bolasIterador)
{
	for (bolasIterador = bolas.begin(); bolasIterador != bolas.end(); bolasIterador++)
	{
		bolasIterador->cuerpo.update(deltaTime);
	}

	return true;
}

void Juego::Dibujar(RenderWindow* ventana, std::list<Bola> bolas, std::list<Bola>::iterator bolasIterador, Flippers fliper_1, Flippers fliper_2)
{
	for (bolasIterador = bolas.begin(); bolasIterador != bolas.end(); bolasIterador++)
	{
		ventana->draw(*bolasIterador);
	}

	fliper_1.Dibujar(ventana);

	fliper_2.Dibujar2(ventana);
}
