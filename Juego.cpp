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

bool Juego::Update(float deltaTime, std::list<Bola> bolas, std::list<Bola>::iterator bolasIterador, Flippers flipper_1, Flippers flipper_2)
{
	for (bolasIterador = bolas.begin(); bolasIterador != bolas.end(); bolasIterador++)
	{
		bolasIterador->cuerpo.update(deltaTime);
	}

	flipper_1.cuerpo.update(deltaTime);

	flipper_1.clampPaddle();

	/*
	if (!Sumar_Puntaje())
	{
		Guardar_Puntaje();

		return false;
	}
	*/

	return true;
}

void Juego::Dibujar(sf::RenderWindow* ventana, std::list<Bola> bolas, std::list<Bola>::iterator bolasIterador, Flippers fliper_1, Flippers fliper_2)
{
	for (bolasIterador = bolas.begin(); bolasIterador != bolas.end(); bolasIterador++)
	{
		ventana->draw(*bolasIterador);
	}

	fliper_1.Dibujar(ventana);

	fliper_2.Dibujar(ventana);
}

/*
bool Juego::Sumar_Puntaje(Jugadores jugador)
{
	int puntaje = jugador.get_puntaje();

	if (colision_A)
	{
		puntaje += 250;
	}
	else if (colision_B)
	{
		puntaje += 500;
	}
	else if (colision_C)
	{
		puntaje += 1000;
	}

	jugador.set_puntaje(puntaje);

	if (jugador.get_puntaje() == 100000)
	{
		return false;
	}


	return true;
}


bool Juego::Guardar_Puntaje(Jugadores jugador)
{
	FILE* p = fopen("Puntajes", "ab");
	if (p == NULL)
	{
		return false;
	}
	fwrite(&jugador, sizeof(Jugadores), 1, p);
	fclose(p);
}

*/