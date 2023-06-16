#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "SetsGlobales.h"
#include "Juego.h"
#include "Jugadores.h"

/*
	Clase para controlar el menú y la continuidad del juego
*/

class Manager
{
	private:
		int main_menu_selected;

		sf::Font font;

		sf::Text main_menu[max_main_menu];

		sf::Text menu_niveles[max_main_menu];

		sf::RenderWindow* ventana;
		sf::VideoMode video_mode;
		sf::Event evento;
		sf::Music musica;
		

		void Init_Window();


	public:
		Manager();

		~Manager();

		const bool Ventana_Esta_Abierta() const;

		void Actualizar();

		void Up(int tipo_de_menu);

		void Down(int tipo_de_menu);

		int MainMenuPressed();

		void Dibujar_Menu(sf::RenderWindow*& ventana, int tipo_de_menu);

		void Iniciar_Juego();

		bool ingresar_nombre(Jugadores& _jugador);
};
#endif