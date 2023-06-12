#ifndef MANAGER_H
#define MANAGER_H

#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "SetsGlobales.h"
#include "Juego.h"
#include <iostream>

/*
	Clase para controlar el menú y la continuidad del juego
*/

class Manager
{
	private:
		int main_menu_selected;
		sf::Font font;
		sf::Text main_menu[max_main_menu];

		sf::RenderWindow* ventana;
		sf::VideoMode video_mode;
		sf::Event evento;

		void Init_Window();


	public:
		Manager();

		virtual ~Manager();

		const bool Ventana_Esta_Abierta() const;

		void Actualizar();

		void Up();

		void Down();

		int MainMenuPressed();

		void Dibujar_Menu(sf::RenderWindow*& window);

		void Iniciar_Juego();
};
#endif