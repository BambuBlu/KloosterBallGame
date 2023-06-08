#include "EnemigoRedondo.h"

EnemigoRedondo::EnemigoRedondo()
{
    cuerpo = Cuerpo();

    cuerpo.setPosicion(sf::Vector2f(0,0));

    cuerpo.setRestitucion(0.9);

    cuerpo.setMasa(0);

    circulo = FisicasCirculo(0);

    cuerpo.fisicaTipo = (FisicasPorTipo*)&circulo;

    setColor(sf::Color::Black);

    set_tipo(redondo);

    set_puntos(0);
}

EnemigoRedondo::EnemigoRedondo(const sf::Vector2f _posicion, const float _radio, const int _puntos, const sf::Color _color)
{
    cuerpo = Cuerpo();

    cuerpo.setPosicion(_posicion);

    cuerpo.setRestitucion(0.9);

    cuerpo.setMasa(0);

    circulo = FisicasCirculo(_radio);

    cuerpo.fisicaTipo = (FisicasPorTipo*)&circulo;

    setColor(_color);

    set_tipo(redondo);

    set_puntos(_puntos);
}