#include "Manager.h"

void Manager::Init_Window()
{
	this->ventana = nullptr;

	this->video_mode.height = 854;
	this->video_mode.width = 480;

	this->ventana = new sf::RenderWindow(this->video_mode, "KloosterBallMenu", sf::Style::Default);

	if (!font.loadFromFile("Fonts/SourceCodePro-VariableFont_wght.ttf"))
	{
		std::cout << "Error cargando la fuente" << std::endl;
	}

	//Opcion Jugar
	this->main_menu[0].setFont(font);
	this->main_menu[0].setFillColor(sf::Color::Cyan);
	this->main_menu[0].setString("Jugar");
	this->main_menu[0].setCharacterSize(40);
	this->main_menu[0].setPosition(50, 200);
	//Otras Opciones
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

	main_menu_selected = 0;
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
				this->Up();
				break;
			}
			//Con la fechita para abajo, bajamos
			else if (this->evento.key.code == sf::Keyboard::Down)
			{
				this->Down();
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
		this->Dibujar_Menu(ventana);
		this->ventana->display();
	}
}

void Manager::Dibujar_Menu(sf::RenderWindow* &window)
{

	for (int i = 0; i < max_main_menu; i++)
	{
		window->draw(main_menu[i]);
	}
}

void Manager::Up()
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

void Manager::Down()
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

int Manager::MainMenuPressed()
{
	return main_menu_selected;
}

void Manager::Iniciar_Juego()
{
	std::cout << "entro a Iniciar_Juego()" << std::endl;

	bool loop_juego = true;

	Juego instancia_juego;

	while (loop_juego)
	{
		std::cout << "entro a while(loop_juego)" << std::endl;

		this->ventana->setVisible(false);

		loop_juego = instancia_juego.primer_nivel();

		std::cout << "Termino el juego" << std::endl;

		this->ventana->setVisible(true);
	}
	std::cout << "Paso el While y vuelve al menu" << std::endl;
}
