#pragma once
#include <string>
#include <cstdio>
#include "Jugadores.h"

using namespace std;


class ArchivoJugadores
{
private:
	string _ruta;
public:
	ArchivoJugadores();

	int getCantidadRegistros();
	bool guardar(Jugadores reg);
	Jugadores leer(int nroRegistro);
	
	void ListarTodo();
	void CrearCopiadeSeguridad();
	  

};


