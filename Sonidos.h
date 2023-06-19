#pragma once

#include <SFML/Audio.hpp>
#include <iostream>
using namespace sf;
class Sonidos
{
 private: 
	 Music musica;
	 SoundBuffer buffer;
	 Sound sound;

 public:

	 Sonidos();
	 

	void ReproducirMusicaFondo();
	void DetenerMusicaFondo();

	void ReproducirMusicaJuego();
	void DetenerMusicaJuego();
	

	Sound ReproducirFlipper();
	Sound ReproducirGentes();
	Sound ReproducirArranque();
	Sound ReproducirSeleccion();
	
};

