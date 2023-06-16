#pragma once

#include <SFML/Audio.hpp>
#include <iostream>
using namespace sf;
class Sonidos
{
 private: 
	 Music musicafondo;
	 SoundBuffer buffer;
	 Sound sound;

 public:

	 Sonidos();
	 

	void ReproducirMusicaFondo();
	void DetenerMusicaFondo();
	
	void ReproducirGentes();

	Sound& getsonido();
};

