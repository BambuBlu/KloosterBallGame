#include "Manager.h"
#include "Juego.h"
//
void Manager::Init_Window()
{
	this->ventana = nullptr;

	this->video_mode.height = 720;
	this->video_mode.width = 1280;

	this->ventana = new sf::RenderWindow(this->video_mode, "KloosterBallMENU", sf::Style::Default);

	if (!font.loadFromFile("Fonts/SourceCodePro-VariableFont_wght.ttf"))
	{
		cout << "Error cargando la fuente" << endl;
	}

	//Opcion Jugar
	this->main_menu[0].setFont(font);
	this->main_menu[0].setFillColor(Color::Cyan);
	this->main_menu[0].setString("Jugar");
	this->main_menu[0].setCharacterSize(40);
	this->main_menu[0].setPosition(580, 200);
	//Otras Opciones
	this->main_menu[1].setFont(font);
	this->main_menu[1].setFillColor(Color::White);
	this->main_menu[1].setString("Maximos Puntajes");
	this->main_menu[1].setCharacterSize(40);
	this->main_menu[1].setPosition(580, 300);

	this->main_menu[2].setFont(font);
	this->main_menu[2].setFillColor(Color::White);
	this->main_menu[2].setString("Logros");
	this->main_menu[2].setCharacterSize(40);
	this->main_menu[2].setPosition(580, 400);

	this->main_menu[3].setFont(font);
	this->main_menu[3].setFillColor(Color::White);
	this->main_menu[3].setString("Salir");
	this->main_menu[3].setCharacterSize(40);
	this->main_menu[3].setPosition(580, 600);

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
		std::cout << "entro al while Actualizar()" << endl;
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
			else if (this->evento.key.code == sf::Keyboard::Return)
			{
				int x = this->MainMenuPressed();

				//JUGAR
				if (x == 0)
				{	
					std::cout << "Entro a if(x == 0)" << endl;
					this->Iniciar_Juego();
					system("pause");
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

	std::cout << "Se va del while Actualizar() :C" << endl;
}

void Manager::Dibujar_Menu(RenderWindow* &window)
{

	for (int i = 0; i < max_main_menu; i++)
	{
		window->draw(main_menu[i]);
	}
}

void Manager::MoveUp()
{
	if (main_menu_selected >= 0)
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

void Manager::Iniciar_Juego()
{
	std::cout << "entro a Iniciar_Juego()" << endl;

	while (this->Ventana_Esta_Abierta())
	{
		std::cout << "entro al while de la funcion Iniciar_Juego()" << endl;
		while (this->ventana->pollEvent(this->evento))
		{
			std::cout << "entro a While (this->ventana->pollevent(this->evento))" << endl;
			
			switch (this->evento.type)
			{
				case sf::Event::Closed:
					{
						this->ventana->close();
					}
				case sf::Event::KeyPressed:
					{
						if(sf::Keyboard::Escape)
						{
							this->ventana->close();
						}
					}
			}
		}
		this->ventana->clear();
		this->ventana->display();
		std::cout << "Llego al final del recorrido del while Iniciar_Juego()" << endl;
	}
	std::cout << "Paso el While y se va de la funcion" << endl;
}
