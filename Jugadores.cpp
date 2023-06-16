#include "Jugadores.h"

Jugadores::Jugadores()
{
	strcpy(nombre, "Sin Nombre");
	puntaje = 0;
}

void Jugadores::set_nombre(sf::String& _nombre)
{
	strcpy(nombre, _nombre.toAnsiString().c_str());
}

const char *Jugadores::get_nombre()
{
	return nombre;
}

void Jugadores::set_puntaje(int _puntaje)
{
	puntaje = _puntaje;
}

int Jugadores::get_puntaje()
{
	return puntaje;
}