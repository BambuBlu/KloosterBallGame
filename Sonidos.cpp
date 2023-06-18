#include "Sonidos.h"



Sonidos::Sonidos() {
	

}

void Sonidos::ReproducirMusicaFondo() {
	
}

void Sonidos::DetenerMusicaFondo() {

	sound.stop();

}
Sound Sonidos::ReproducirGentes() {
	if (buffer.loadFromFile("Sonidos/gentes.wav")) {
		std::cout << "se cargo" << std::endl;
	}

	sound.setBuffer(buffer);
	return sound;

}
Sound Sonidos::ReproducirArranque() {

	if (!buffer.loadFromFile("Sonidos/Arranque.wav")) {
		std::cout << "No se cargo los sonidos" << std::endl;
	}
	sound.setBuffer(buffer);

	return sound;
}

