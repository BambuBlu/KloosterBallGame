#include "Jugadores.h"

Jugadores::Jugadores()
{
	strcpy(char_nombre, "Sin Nombre");
	str_nombre = "Sin Nombre";
	nivel = 0;
	puntaje = 0;
}


void Jugadores::set_nombre(sf::String& _nombre)
{
	str_nombre = _nombre.toAnsiString();

	strcpy(char_nombre, _nombre.toAnsiString().c_str());

}

void Jugadores::set_puntaje(int _puntaje)
{
	puntaje = _puntaje;
}

void Jugadores::set_nivel(int _nroNivel)
{
	nivel = _nroNivel;
}

const char *Jugadores::get_nombre()
{
	return char_nombre;
}

std::string Jugadores::get_str_nombre()
{
	return str_nombre;
}

int Jugadores::get_puntaje()
{
	return puntaje;
}

int Jugadores::get_nivel()
{
	return nivel;
}