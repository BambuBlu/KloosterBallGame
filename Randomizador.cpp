#include "Randomizador.h"

Randomizador::Randomizador()
{
    srand(static_cast<unsigned int>(time(NULL)));
}

int Randomizador::get_random_entre(int _menor, int _mayor)
{
    double delta = _mayor - _menor;

    double randomScalar = (double)rand() / (double)RAND_MAX;

    double randomDelta = delta * randomScalar;

    return _menor + (int)randomDelta;
}

float Randomizador::get_random_entre(float _menor, float _mayor)
{
    double delta = _mayor - _menor;

    double randomScalar = (double)rand() / (double)RAND_MAX;

    double randomDelta = delta * randomScalar;

    return _menor + (float)randomDelta;
}

double Randomizador::get_random_entre(double _menor, double _mayor)
{
    double delta = _mayor - _menor;

    double randomScalar = (double)rand() / (double)RAND_MAX;

    double randomDelta = delta * randomScalar;

    return _menor + randomDelta;
}