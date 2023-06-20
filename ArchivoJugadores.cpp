#include "ArchivoJugadores.h"
#include <iostream>


ArchivoJugadores::ArchivoJugadores()
{
    _ruta = "Jugadores.dat";
}

int ArchivoJugadores::getCantidadRegistros()
{
    FILE* p = fopen(_ruta.c_str(), "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Jugadores);
}

bool ArchivoJugadores::guardar(Jugadores reg)
{
    FILE* p = fopen(_ruta.c_str(), "ab");

    if (p == NULL)
    {
        return false;
    }

    bool pudoEscribir = fwrite(&reg, sizeof(Jugadores), 1, p);

    fclose(p);

    std::cout << "Guardado con exito " << std::endl;

    return pudoEscribir;
}

Jugadores ArchivoJugadores::leer(int nroRegistro)
{
    std::cout << "Entro a Leer " << std::endl;
    Jugadores aux;

    std::cout << "Paso Jugadores aux " << std::endl;

    FILE* p = fopen(_ruta.c_str(), "rb");

    std::cout << "Paso fopen " << std::endl;

    if (p == NULL)
    {
        return aux;
    }

    std::cout << "Paso if(NULL) " << std::endl;

    fseek(p, nroRegistro * sizeof(Jugadores), SEEK_SET);

    std::cout << "Paso fseek " << std::endl;

    fread(&aux, sizeof(Jugadores), 1, p);

    std::cout << "Paso fread " << std::endl;

    fclose(p);

    std::cout << "Llego al final de leer " << std::endl;

    return aux;
}

void ArchivoJugadores::ListarTodo() 
{
    Jugadores aux;

    FILE* p = fopen(_ruta.c_str(), "rb");

    if (p == NULL)
    {
        return;
    }

    for (int x = 0; x < getCantidadRegistros(); x++) 
    {
        aux = leer(x);

        std::cout << "Nombre del Jugador: " << std::endl;
        std::cout << aux.get_nombre() << std::endl;
        std::cout << "Puntaje: " << std::endl;
        std::cout << aux.get_puntaje() << std::endl << std::endl;
    }
}
