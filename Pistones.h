#pragma once

class Pistones
{
	private:
		float posicion;
		float fuerza;

		void Init_Piston();
	public:
		Pistones();
		virtual ~Pistones();

		void Fuerza_De_Empuje(float);
		void Soltar();
};

