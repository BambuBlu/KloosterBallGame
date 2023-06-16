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
    Jugadores aux;

    FILE* p = fopen(_ruta.c_str(), "rb");

    if (p == NULL)
    {
        return aux;
    }

    fseek(p, nroRegistro * sizeof(Jugadores), SEEK_SET);

    fread(&aux, sizeof(Jugadores), 1, p);

    fclose(p);

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

        std::cout << "Nombre del Jugador: " << aux.get_nombre() << std::endl;

        std::cout << "Puntaje: " << aux.get_puntaje() << std::endl << std::endl;
    }
}
