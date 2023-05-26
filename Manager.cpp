#include "Manager.h"
//
void Manager::Init_Window()
{
	this->ventana = nullptr;

	this->video_mode.height = 960;
	this->video_mode.width = 920;

	this->ventana = new sf::RenderWindow(this->video_mode, "KloosterBall", sf::Style::Default);

	if (!font.loadFromFile("Fonts/SourceCodePro-VariableFont_wght.ttf"))
	{
		cout << "Error cargando la fuente" << endl;
	}

	//Opcion Jugar
	this->main_menu[0].setFont(font);
	this->main_menu[0].setFillColor(Color::White);
	this->main_menu[0].setString("Jugar");
	this->main_menu[0].setCharacterSize(40);
	this->main_menu[0].setPosition(310, 200);
	//Otras Opciones
	this->main_menu[1].setFont(font);
	this->main_menu[1].setFillColor(Color::White);
	this->main_menu[1].setString("Maximos Puntajes");
	this->main_menu[1].setCharacterSize(40);
	this->main_menu[1].setPosition(310, 300);

	this->main_menu[2].setFont(font);
	this->main_menu[2].setFillColor(Color::White);
	this->main_menu[2].setString("Logros");
	this->main_menu[2].setCharacterSize(40);
	this->main_menu[2].setPosition(310, 400);

	this->main_menu[3].setFont(font);
	this->main_menu[3].setFillColor(Color::White);
	this->main_menu[3].setString("Salir");
	this->main_menu[3].setCharacterSize(40);
	this->main_menu[3].setPosition(310, 600);

	main_menu_selected = 0;
}

//
Manager::Manager()
{
	this->Init_Window();
}

Manager::~Manager()
{
	delete this->ventana;
}

//
const bool Manager::get_Ventana_Esta_Abierta() const
{
	return this->ventana->isOpen();
}

//
void Manager::Actualizar_Eventos()
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
				this->MoveUp();
				break;
			}
			//Con la fechita para abajo, bajamos
			else if (this->evento.key.code == sf::Keyboard::Down)
			{
				this->MoveDown();
				break;
			}
			/*
	
			*/ 
			
			else if (this->evento.key.code == sf::Keyboard::Return)
			{
				int x = this->MainMenuPressed();
				RenderWindow* Iniciar_Juego(this->video_mode, "Jugar", sf::Style::Default);
				RenderWindow* Maximos_Puntajes(this->video_mode, "Puntajes", sf::Style::Default);
				RenderWindow* Logros(this->video_mode, "Logros", sf::Style::Default);
				Event aevento;
				//JUGAR
				if (x == 0)
				{	
					while (Iniciar_Juego->isOpen()) {
						Iniciar_Juego->draw(Juego::bola);
						while (Iniciar_Juego->pollEvent(aevento)) {
							if (aevento.type == Event::Closed) {
								Iniciar_Juego->close;
							}
							if (aevento.type == Event::KeyPressed) {
								if (aevento.key.code == Keyboard::Escape)
								Iniciar_Juego->close;
							}
						}
					}
					Maximos_Puntajes->close;
					Logros->close;
					Iniciar_Juego->clear();
					Iniciar_Juego->display();
					
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
		ventana->clear();
		Draw(ventana);
		ventana->display();
	}
}


void Manager::Renderizar()
{
	this->Actualizar_Eventos();
}


void Manager::Draw(RenderWindow* &window)
{

	for (int i = 0; i < max_main_menu; i++)
	{
		window->draw(main_menu[i]);
	}
}

void Manager::MoveUp()
{
	if (main_menu_selected - 1 >= 0)
	{
		main_menu[main_menu_selected].setFillColor(Color::White);
		main_menu_selected--;
		if (main_menu_selected == -1)
		{
			main_menu_selected = 3;
		}
		main_menu[main_menu_selected].setFillColor(Color::Cyan);
	}
}

void Manager::MoveDown()
{
	if (main_menu_selected + 1 <= max_main_menu)
	{
		main_menu[main_menu_selected].setFillColor(Color::White);
		main_menu_selected++;
		if (main_menu_selected == 4)
		{
			main_menu_selected = 0;
		}
		main_menu[main_menu_selected].setFillColor(Color::Cyan);
	}
}

int Manager::MainMenuPressed()
{
	return main_menu_selected;
}