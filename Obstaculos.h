#pragma once

class Obstaculos
{
	private:
		float posicion;
		float tama�o;
		bool esta_vivo;

		void Init_Obstaculo();
	public:
		Obstaculos();
		virtual ~Obstaculos();
};

