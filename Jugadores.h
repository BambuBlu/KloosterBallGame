#pragma once

#include <string.h>

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

