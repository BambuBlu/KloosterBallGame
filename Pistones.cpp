#include "Pistones.h"

void Pistones::Init_Piston()
{
	this->posicion = 0;
	this->fuerza = 0;
}
//Const - Dest
Pistones::Pistones()
{
	this->Init_Piston();
}
Pistones::~Pistones()
{

}

//Funciones Publicas de PISTON
void Pistones::Fuerza_De_Empuje(float fuerzaEmpuje)
{
	this->fuerza = fuerzaEmpuje;
}

void Pistones::Soltar()
{

}