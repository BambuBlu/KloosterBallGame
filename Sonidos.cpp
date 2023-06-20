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

void Sonidos::ReproducirMusicaJuego()
{
	if (!musica.openFromFile("Sonidos/MusicaJuego.wav")) {
		std::cout << "No se cargo la musica" << std::endl;
	}

	musica.setVolume(10);
	musica.setLoop(true);
	musica.play();

}
void Sonidos::PausarMusica()
{
	musica.pause();
}
void Sonidos::Reanudar()
{
	musica.play();
}
void Sonidos::DetenerMusica()
{
	musica.stop();
}
void Sonidos::ReproducirFlipper()
{
	if (!buffer.loadFromFile("Sonidos/SonidoFlipper.wav")) {
		std::cout << "No se cargo los sonidos" << std::endl;
	}

	sound.setBuffer(buffer);
	sound.setVolume(25);
	sound.play();
}
void Sonidos::ReproducirGentes() {
	if (!buffer.loadFromFile("Sonidos/gentes.wav")) {
		std::cout << "No se cargo los sonidos" << std::endl;
	}

	sound.setBuffer(buffer);
	sound.setVolume(25);
	sound.play();

}
void Sonidos::ReproducirArranque() {

	if (!buffer.loadFromFile("Sonidos/Arranque.wav")) {
		std::cout << "No se cargo los sonidos" << std::endl;
	}
	sound.setBuffer(buffer);

	sound.play();
}

void Sonidos::ReproducirSeleccion()
{
	if (!buffer.loadFromFile("Sonidos/seleccion.wav")) {
		std::cout << "No se cargo los sonidos" << std::endl;
	}
	sound.setBuffer(buffer);
	sound.setVolume(20);

	sound.play();
	
}

void Sonidos::ReproducirGameOver()
{
	if (!buffer.loadFromFile("Sonidos/Fin.wav")) {
		std::cout << "No se cargo los sonidos" << std::endl;
	}
	sound.setBuffer(buffer);
	sound.setVolume(100);

	sound.play();
}

void Sonidos::ReproducirRestarBola()
{
	if (!buffer.loadFromFile("Sonidos/RestarBola.wav")) {
		std::cout << "No se cargo los sonidos" << std::endl;
	}
	sound.setBuffer(buffer);
	sound.setVolume(100);

	sound.play();
}

void Sonidos::ReproducirChoque()
{
	if (!buffer.loadFromFile("Sonidos/Choque.wav")) {
		std::cout << "No se cargo los sonidos" << std::endl;
	}
	sound.setBuffer(buffer);
	sound.setVolume(50);

	sound.play();
}

