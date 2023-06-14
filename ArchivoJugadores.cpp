#include "ArchivoJugadores.h"

/*
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

*/