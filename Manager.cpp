#include "Manager.h"


void Manager::Init_Menu()
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
	if (!musica.openFromFile("Sonidos/Musica.wav")) 
	{
		std::cout << "No se cargo la musica" << std::endl;
	}
	musica.setVolume(25);
	musica.play();
}

Manager::Manager()
{
	this->Init_Menu();
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
					this->IniciarJuego();
					break;
				}
				//MAYORES PUNTAJES
				if (x == 1)
				{
					//RankingDePuntajes();
					break;
				}
				//LOGROS
				if (x == 2)
				{
					break;
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
		this->DibujarMenu(ventana, 1);
		this->ventana->display();
	}
}

int Manager::MainMenuPressed()
{
	return main_menu_selected;
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

void Manager::DibujarMenu(sf::RenderWindow*& ventana, int tipo_de_menu)
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

void Manager::IniciarJuego()
{
	main_menu_selected = 0;

	Jugadores Jugador;

	if (!IngresarNombre(Jugador))
	{
		return;
	}
	
	std::cout << "nombre en Iniciar_juego() " << std::endl;

	std::cout << Jugador.get_nombre() << std::endl;

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
							this->ventana->setVisible(false);
							Juego instancia_juego;
							musica.stop();
							instancia_juego.primer_nivel(Jugador);
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
			this->DibujarMenu(ventana, 2);
			this->ventana->display();
		}
	}
}

bool Manager::IngresarNombre(Jugadores& _jugador)
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
						std::cout << "nombre en ingresar_nombre() " << std::endl;
						std::cout << _jugador.get_nombre() << std::endl;
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
	return false;
}

void Manager::RankingDePuntajes()
{
	sf::Text titulo;
	titulo.setFont(font);
	titulo.setFillColor(sf::Color::Green);
	titulo.setString("Ranking");
	titulo.setCharacterSize(35);
	titulo.setPosition(66, 20);

	sf::Text titulo2;
	titulo2.setFont(font);
	titulo2.setFillColor(sf::Color::Green);
	titulo2.setString("Maximos Puntajes");
	titulo2.setCharacterSize(35);
	titulo2.setPosition(40, 50);

	//CREA UN VECTOR DINAMICO CON TODOS LOS REGISTROS DE JUGADORES
	ArchivoJugadores archivo;
	int cantidad_de_registros = archivo.getCantidadRegistros();

	Jugadores *vJugadores;

	vJugadores = new Jugadores[cantidad_de_registros];

	for (int i = 0; i <= cantidad_de_registros; i++)
	{
		vJugadores[i] = archivo.leer(i);
	}

	//ORDENA EL VECTOR DE MAYOR A MENOR PUNTAJE
	OrdenarJugadoresxPuntos(vJugadores, cantidad_de_registros);

	//Creo los textos y les paso los nombres de los TRES primeros jugadores y sus respectivos puntajes
	sf::Text PodioNombres[3];
	sf::Text PodioPuntajes[3];

	//MENSAJES DE NOMBRES

	PodioNombres[0].setFont(font);
	PodioNombres[0].setFillColor(sf::Color::Cyan);
	PodioNombres[0].setString(vJugadores[0].get_str_nombre());
	PodioNombres[0].setCharacterSize(35);
	PodioNombres[0].setPosition(20, 100);

	PodioNombres[1].setFont(font);
	PodioNombres[1].setFillColor(sf::Color::Green);
	PodioNombres[1].setString(vJugadores[1].get_str_nombre());
	PodioNombres[1].setCharacterSize(35);
	PodioNombres[1].setPosition(20, 130);

	PodioNombres[2].setFont(font);
	PodioNombres[2].setFillColor(sf::Color::Cyan);
	PodioNombres[2].setString(vJugadores[2].get_str_nombre());
	PodioNombres[2].setCharacterSize(35);
	PodioNombres[2].setPosition(20, 160);

	//MENSAJES DE PUNTOS

	PodioPuntajes[0].setFont(font);
	PodioPuntajes[0].setFillColor(sf::Color::Cyan);
	PodioPuntajes[0].setString(std::to_string(vJugadores[0].get_puntaje()));
	PodioPuntajes[0].setCharacterSize(35);
	PodioPuntajes[0].setPosition(60, 100);

	PodioPuntajes[1].setFont(font);
	PodioPuntajes[1].setFillColor(sf::Color::Green);
	PodioPuntajes[1].setString(std::to_string(vJugadores[1].get_puntaje()));
	PodioPuntajes[1].setCharacterSize(35);
	PodioPuntajes[1].setPosition(60, 130);

	PodioPuntajes[2].setFont(font);
	PodioPuntajes[2].setFillColor(sf::Color::Cyan);
	PodioPuntajes[2].setString(std::to_string(vJugadores[2].get_puntaje()));
	PodioPuntajes[2].setCharacterSize(35);
	PodioPuntajes[2].setPosition(60, 160);

	delete[] vJugadores;

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
						return;
					}
					if (this->evento.key.code == sf::Keyboard::Enter)
					{
						return;
					}
			}
		}
		this->ventana->draw(titulo);
		this->ventana->draw(titulo2);

		for (int i = 0; i < 3; i++)
		{
			this->ventana->draw(PodioNombres[i]);
			this->ventana->draw(PodioPuntajes[i]);
		}

		this->ventana->display();

	}
}

void Manager::OrdenarJugadoresxPuntos(Jugadores*& _vector, int _tamanio)
{
	int actual, mayor;

	Jugadores aux;
	 
	for (actual = 0; actual < _tamanio - 1; actual++)
	{
		mayor = actual;

		for (int j = actual + 1; j < _tamanio; j++)
		{
			if (_vector[j].get_puntaje() > _vector[mayor].get_puntaje())
			{
				mayor = j;
			}
		}

		aux = _vector[actual];

		_vector[actual] = _vector[mayor];

		_vector[mayor] = aux;
	}
}