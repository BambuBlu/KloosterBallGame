#include <iostream>
#include "Juego.h"
#include "MainMenu.h"
using namespace std;

int main()
{
	Manager menu;

	while (menu.get_Ventana_Esta_Abierta())
	{
		menu.Actualizar_Eventos();

		menu.Renderizar();
	}

	return 0;
}