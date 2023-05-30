#include <iostream>
#include "Juego.h"
#include "Manager.h"
using namespace std;

int main()
{
	Manager menu;

	while (menu.Ventana_Esta_Abierta())
	{
		menu.Actualizar();
	}

	return 0;
}