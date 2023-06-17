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
		std::string str_nombre;
		char char_nombre[30];
		int puntaje;
		int nivel; 

	public:

		Jugadores();
		void set_nombre(sf::String& _nombre);
		void set_puntaje(int _puntaje);
		void set_nivel(int _nroNivel);

		const char* get_nombre();
		std::string get_str_nombre();
		int get_puntaje();
		int get_nivel();
};
#endif