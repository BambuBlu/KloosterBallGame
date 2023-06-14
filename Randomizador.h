#ifndef RANDOMIZADOR_H
#define RANDOMIZADOR_H

#include <ctime>
#include <cstdlib>

/*
    Clase proveniente de Randomizer
    Esta clase usa ctime y csdtdlib para crear numeros aleatorios.
    La copié pero al parecer no la usa en ningun momento, si vemos que 
    es asi entonces deberiamos eliminarla.
*/

class Randomizador
{
    public:
        Randomizador();

        int get_random_entre(int, int); 

        float get_random_entre(float, float);

        double get_random_entre(double, double);
};

#endif