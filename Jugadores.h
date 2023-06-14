#ifndef JUGADORES_H
#define JUGADORES_H

#include <string.h>

/*
	Clase para controlar los jugadores y sus puntajes	
*/

class Jugadores
{
	private:

		char jugador[30];
		int puntaje;

	public:
		Jugadores();

		void set_jugador(char* _Jugador);
		void set_puntaje(int _puntaje);
		const char *get_jugador();
		int get_puntaje();

};

#endif