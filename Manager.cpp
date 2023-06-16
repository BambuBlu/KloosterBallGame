#include "Manager.h"


void Manager::Init_Window()
{
	//Especificaciones de la ventana
	this->ventana = nullptr;

	this->video_mode.height = 854;
	this->video_mode.width = 480;

	this->ventana = new sf::RenderWindow(this->video_mode, "KloosterBallMenu", sf::Style::Default);

	//Carga la fuente utilizada en la ventana
	this->font.loadFromFile("Fonts\\BrunoAceSC-Regular.ttf");

	//Vector con las opciones del MENU PRINCIPAL
	this->main_menu[0].setFont(font);
	this->main_menu[0].setFillColor(sf::Color::Cyan);
	this->main_menu[0].setString("Jugar");
	this->main_menu[0].setCharacterSize(40);
	this->main_menu[0].setPosition(50, 200);

	this->main_menu[1].setFont(font);
	this->main_menu[1].setFillColor(sf::Color::White);
	this->main_menu[1].setString("Maximos Puntajes");
	this->main_menu[1].setCharacterSize(30);
	this->main_menu[1].setPosition(50, 300);

	this->main_menu[2].setFont(font);
	this->main_menu[2].setFillColor(sf::Color::White);
	this->main_menu[2].setString("Logros");
	this->main_menu[2].setCharacterSize(30);
	this->main_menu[2].setPosition(50, 400);

	this->main_menu[3].setFont(font);
	this->main_menu[3].setFillColor(sf::Color::White);
	this->main_menu[3].setString("Salir");
	this->main_menu[3].setCharacterSize(20);
	this->main_menu[3].setPosition(50, 600);


	//Vector con los distintos niveles
	this->menu_niveles[0].setFont(font);
	this->menu_niveles[0].setFillColor(sf::Color::Cyan);
	this->menu_niveles[0].setString("Primer nivel");
	this->menu_niveles[0].setCharacterSize(40);
	this->menu_niveles[0].setPosition(50, 200);

	this->menu_niveles[1].setFont(font);
	this->menu_niveles[1].setFillColor(sf::Color::White);
	this->menu_niveles[1].setString("Segundo nivel");
	this->menu_niveles[1].setCharacterSize(30);
	this->menu_niveles[1].setPosition(50, 300);

	this->menu_niveles[2].setFont(font);
	this->menu_niveles[2].setFillColor(sf::Color::White);
	this->menu_niveles[2].setString("Tercer nivel");
	this->menu_niveles[2].setCharacterSize(30);
	this->menu_niveles[2].setPosition(50, 400);

	this->menu_niveles[3].setFont(font);
	this->menu_niveles[3].setFillColor(sf::Color::White);
	this->menu_niveles[3].setString("Regresar");
	this->menu_niveles[3].setCharacterSize(30);
	this->menu_niveles[3].setPosition(50, 600);

	//Variable que recorre el menu para elegir la opción
	this->main_menu_selected = 0;
	///MUSICA MENU
	if (!musica.openFromFile("Sonidos/Musica.wav")) {
		std::cout << "No se cargo la musica" << std::endl;
	}
	musica.setVolume(25);
	musica.play();
}

Manager::Manager()
{
	this->Init_Window();
}

Manager::~Manager()
{
	delete this->ventana;
}

const bool Manager::Ventana_Esta_Abierta() const
{
	return this->ventana->isOpen();
}

void Manager::Actualizar()
{

	//Siempre que haya un evento se mantiene el While
	while (this->ventana->pollEvent(this->evento))
	{
		
		//Checkea el tipo de evento
		switch (this->evento.type)
		{
			//La "X" de la ventana es para cerrar
		case sf::Event::Closed:
			this->ventana->close();
			break;

		case sf::Event::KeyPressed:
			//"Escape" es para cerrar
			if (this->evento.key.code == sf::Keyboard::Escape)
			{
				this->ventana->close();
				break;
			}
			//Con la fechita para arriba subimos
			else if (this->evento.key.code == sf::Keyboard::Up)
			{
				this->Up(1);
				break;
			}
			//Con la fechita para abajo, bajamos
			else if (this->evento.key.code == sf::Keyboard::Down)
			{
				this->Down(1);
				break;
			}
			else if (this->evento.key.code == sf::Keyboard::Return)
			{
				int x = this->MainMenuPressed();

				//JUGAR
				if (x == 0)
				{	
					std::cout << "Entro a if(x == 0)" << std::endl;
					this->Iniciar_Juego();
				}
				//MAYORES PUNTAJES
				if (x == 1)
				{

				}
				//LOGROS
				if (x == 2)
				{

				}
				//SALIR
				if (x == 3) 
				{
					this->ventana->close();
					break;
				}
			}
		}
		this->ventana->clear();
		this->Dibujar_Menu(ventana, 1);
		this->ventana->display();
	}
}

void Manager::Dibujar_Menu(sf::RenderWindow*& ventana, int tipo_de_menu)
{
	if (tipo_de_menu == 1)
	{
		for (int i = 0; i < max_main_menu; i++)
		{
			ventana->draw(main_menu[i]);
		}
	}
	if (tipo_de_menu == 2)
	{
		for (int i = 0; i < max_main_menu; i++)
		{
			this->ventana->draw(menu_niveles[i]);
		}
	}
}

void Manager::Up(int tipo_de_menu)
{
	if (tipo_de_menu == 1)
	{
		if (main_menu_selected >= 0)
		{
			main_menu[main_menu_selected].setFillColor(sf::Color::White);

			main_menu_selected--;

			if (main_menu_selected == -1)
			{
				main_menu_selected = 3;
			}
			main_menu[main_menu_selected].setFillColor(sf::Color::Cyan);
		}
	}
	if (tipo_de_menu == 2)
	{
		if (main_menu_selected >= 0)
		{
			menu_niveles[main_menu_selected].setFillColor(sf::Color::White);

			main_menu_selected--;

			if (main_menu_selected == -1)
			{
				main_menu_selected = 3;
			}

			this->menu_niveles[main_menu_selected].setFillColor(sf::Color::Cyan);
		}
	}

}

void Manager::Down(int tipo_de_menu)
{
	if (tipo_de_menu == 1)
	{
		if (main_menu_selected + 1 <= max_main_menu)
		{
			main_menu[main_menu_selected].setFillColor(sf::Color::White);
			main_menu_selected++;
			if (main_menu_selected == 4)
			{
				main_menu_selected = 0;
			}
			main_menu[main_menu_selected].setFillColor(sf::Color::Cyan);
		}
	}
	if (tipo_de_menu == 2)
	{
		if (main_menu_selected + 1 <= max_main_menu)
		{
			menu_niveles[main_menu_selected].setFillColor(sf::Color::White);

			main_menu_selected++;

			if (main_menu_selected == 4)
			{
				main_menu_selected = 0;
			}

			menu_niveles[main_menu_selected].setFillColor(sf::Color::Cyan);
		}
	}
}

int Manager::MainMenuPressed()
{
	return main_menu_selected;
}

void Manager::Iniciar_Juego()
{
	main_menu_selected = 0;

	Jugadores jugador;

	if (!ingresar_nombre(jugador))
	{
		return;
	}
	
	while (Ventana_Esta_Abierta())
	{
		while (this->ventana->pollEvent(this->evento))
		{
			switch (this->evento.type)
			{
				case sf::Event::Closed:
					this->ventana->close();
					break;

				case sf::Event::KeyPressed:
					if (this->evento.key.code == sf::Keyboard::Escape)
					{
						this->ventana->close();
						break;
					}

					else if (this->evento.key.code == sf::Keyboard::Up)
					{
						this->Up(2);
						break;
					}
					else if (this->evento.key.code == sf::Keyboard::Down)
					{
						this->Down(2);
						break;
					}
					else if (this->evento.key.code == sf::Keyboard::Return)
					{
						if (main_menu_selected == 0)
						{
							Jugadores jugador;
							this->ventana->setVisible(false);
							Juego instancia_juego;
							musica.stop();
							instancia_juego.primer_nivel(jugador);
							this->ventana->setVisible(true);
						}
						if (main_menu_selected == 1)
						{

						}
						if (main_menu_selected == 2)
						{

						}
						if (main_menu_selected == 3){return;}
					}
			}
			this->ventana->clear();
			this->Dibujar_Menu(ventana, 2);
			this->ventana->display();
		}
	}
}

bool Manager::ingresar_nombre(Jugadores& _jugador)
{
	sf::Text texto;
	texto.setFont(font);
	texto.setFillColor(sf::Color::Cyan);
	texto.setString("Ingrese su nombre");
	texto.setCharacterSize(35);
	texto.setPosition(40, 300);

	sf::Text textBox;
	textBox.setFont(font);
	textBox.setCharacterSize(40);
	textBox.setPosition(40, 400);

	sf::String _nombreDeJugador;

	while (Ventana_Esta_Abierta())
	{
		this->ventana->clear();

		while (this->ventana->pollEvent(this->evento))
		{
			switch (this->evento.type)
			{
				case sf::Event::Closed:

					this->ventana->close();
					break;

				case sf::Event::KeyPressed:

					if (this->evento.key.code == sf::Keyboard::Escape)
					{
						return false;
					}
					if (this->evento.key.code == sf::Keyboard::Enter)
					{
						_jugador.set_nombre(_nombreDeJugador);
						return true;
					}

				case sf::Event::TextEntered:

					if (this->evento.type == sf::Event::TextEntered)
					{
						if (this->evento.text.unicode < 256)
						{
							if (this->evento.text.unicode == 8 && _nombreDeJugador.getSize() > 0)
							{
								_nombreDeJugador.erase(_nombreDeJugador.getSize() - 1, 1);
							}
							else
							{
								_nombreDeJugador += static_cast<char>(this->evento.text.unicode);
							}

							textBox.setString(_nombreDeJugador);
						}
					}
			}
		}

		this->ventana->draw(texto);

		this->ventana->draw(textBox);

		this->ventana->display();
	}
}