#pragma once

class Flippers
{
	private:
		float posicion;
		float orientacion;

		void Init_Flippers();

	public:
		Flippers();
		virtual ~Flippers();

		void Mover();
};

