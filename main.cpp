#include <iostream>
#include "Juego.h"
#include "Manager.h"
using namespace std;

int main()
{
	Manager menu;

	while (menu.Ventana_Esta_Abierta())
	{
		std::cout << "Inicio del programa" << endl;
		menu.Actualizar();
		std::cout << "Fin del programa" << endl;
	}

	return 0;
}