#include "Sonidos.h"



Sonidos::Sonidos() {
	

}

void Sonidos::ReproducirMusicaFondo() {
	if (!musica.openFromFile("Sonidos/Musica.wav")) {
		std::cout << "No se cargo la musica" << std::endl;
	}

	musica.setVolume(10);
	musica.setLoop(true);
	musica.play();
}

void Sonidos::DetenerMusicaFondo() {

	musica.stop();

}
void Sonidos::ReproducirMusicaJuego()
{
	if (!musica.openFromFile("Sonidos/MusicaJuego.wav")) {
		std::cout << "No se cargo la musica" << std::endl;
	}

	musica.setVolume(10);
	musica.setLoop(true);
	musica.play();

}
void Sonidos::DetenerMusicaJuego()
{
	musica.stop();
}
Sound Sonidos::ReproducirFlipper()
{
	if (!buffer.loadFromFile("Sonidos/SonidoFlipper.wav")) {
		std::cout << "No se cargo los sonidos" << std::endl;
	}

	sound.setBuffer(buffer);
	sound.setVolume(25);
	return sound;
}
Sound Sonidos::ReproducirGentes() {
	if (!buffer.loadFromFile("Sonidos/gentes.wav")) {
		std::cout << "No se cargo los sonidos" << std::endl;
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

Sound Sonidos::ReproducirSeleccion()
{
	if (!buffer.loadFromFile("Sonidos/seleccion.wav")) {
		std::cout << "No se cargo los sonidos" << std::endl;
	}
	sound.setBuffer(buffer);
	sound.setVolume(20);

	return sound;
	
}

