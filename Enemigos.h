#pragma once

class Enemigos
{
	private:
		float posicion;
		float tama�o;
		int vida;
		bool esta_vivo;
		void Init_Enemigo();

	public:
		Enemigos();
		virtual ~Enemigos();

		void Golpear_Bola();
		void Bajar_Vida();
};

