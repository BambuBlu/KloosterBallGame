#include "Sonidos.h"



Sonidos::Sonidos() {
	

}

void Sonidos::ReproducirMusicaFondo() {
	
	sound.play();
}

void Sonidos::DetenerMusicaFondo() {

	sound.stop();

}
void Sonidos::ReproducirGentes() {
	SoundBuffer buffer;
	if (buffer.loadFromFile("Sonidos/gentes.wav")) {
		std::cout << "se cargo" << std::endl;
	}

	sound.setBuffer(buffer);

}

Sound& Sonidos::getsonido() {
	return sound;
}