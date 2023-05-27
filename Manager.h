#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#define max_main_menu 4

class Manager
{
	private:
		int main_menu_selected;
		Font font;
		Text main_menu[max_main_menu];

		RenderWindow* ventana;
		VideoMode video_mode;
		Event evento;

		void Init_Window();

	public:
		Manager();

		virtual ~Manager();

		const bool Ventana_Esta_Abierta() const;

		void Actualizar();

		void MoveUp();

		void MoveDown();

		int MainMenuPressed();

		void Dibujar_Menu(RenderWindow*& window);

		void Iniciar_Juego();
};

