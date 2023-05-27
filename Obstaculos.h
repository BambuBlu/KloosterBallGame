#pragma once

class Obstaculos
{
	private:
		float posicion;
		float tamaño;
		bool esta_vivo;

		void Init_Obstaculo();
	public:
		Obstaculos();
		virtual ~Obstaculos();
};

