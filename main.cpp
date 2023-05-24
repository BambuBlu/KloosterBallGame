#include <iostream>
#include "Juego.h"
using namespace std;

int main()
{
	Juego juego;

	while (juego.get_Ventana_Esta_Abierta())
	{
		juego.Actualizar();

		juego.Renderizar();
	}

	return 0;
}