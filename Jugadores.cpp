#include "Jugadores.h"

Jugadores::Jugadores()
{
	strcpy_s(jugador, "Facu");
	puntaje = 0;
}

void Jugadores::set_jugador(char* _Jugador)
{
	strcpy_s(jugador, _Jugador);
}
void Jugadores::set_puntaje(int _puntaje)
{
	puntaje = _puntaje;
}
const char* Jugadores::get_jugador()
{
	return jugador;
}
int Jugadores::get_puntaje()
{
	return puntaje;
}