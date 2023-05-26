#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Juego.h"
using namespace std;
using namespace sf;

#define max_main_menu 4

class Manager 
{
	private:
		int main_menu_selected;
		Font font;
		Text main_menu[max_main_menu];

		Juego juego;
		RenderWindow* ventana;
		VideoMode video_mode;
		Event evento;

		void Init_Window();

	public:
		Manager();

		virtual ~Manager();

		const bool get_Ventana_Esta_Abierta() const;

		void Actualizar_Eventos();

		void Renderizar();

		void MoveUp();

		void MoveDown();

		int MainMenuPressed();

		void Draw(RenderWindow*& window);
};

