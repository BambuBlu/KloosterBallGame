#ifndef JUGADORES_H
#define JUGADORES_H

#include <SFML/Graphics.hpp>
#include <cstring>
/*
	Clase para controlar los jugadores y sus puntajes	
*/

class Jugadores
{
	private:
		char nombre[30];
		int puntaje;

	public:

		Jugadores();

		void set_nombre(sf::String& _nombre);

		void set_puntaje(int _puntaje);

		const char* get_nombre();

		int get_puntaje();
};
#endif