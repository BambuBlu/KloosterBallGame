#include "Jugadores.h"

Jugadores::Jugadores()
{
	strcpy(char_nombre, "Sin Nombre");
	nivel = 0;
	puntaje = 0;
}


void Jugadores::set_nombre(sf::String& _nombre)
{
	std::string str_nombre;
	str_nombre = _nombre.toAnsiString();

	strcpy(char_nombre, str_nombre.c_str());

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
	const char* nombre = char_nombre;
	sf::String sf_str_nombre(nombre);

	return sf_str_nombre;
}

int Jugadores::get_puntaje()
{
	return puntaje;
}

int Jugadores::get_nivel()
{
	return nivel;
}