#include "Rectangulo.h"


Rectangulo::Rectangulo()
{
    cuerpo = Cuerpo();

    forma = RectanguloFisicas();

    cuerpo.fisicaTipo = (FisicasPorTipo*)&forma;

    cuerpo.setMasa(0);

    cuerpo.setRestitucion(0);

    color = sf::Color::Black;
}

Rectangulo::Rectangulo(const sf::Vector2f _origen, const sf::Vector2f _extensionMedia, const sf::Color _color)
{
    cuerpo = Cuerpo();

    cuerpo.setPosicion(_origen);

    cuerpo.setAceleracion(sf::Vector2f(0,0));

    cuerpo.setVelocidad(sf::Vector2f(0, 0));

    cuerpo.setMasa(0);

    cuerpo.setRestitucion(0.5);

    forma = RectanguloFisicas(_origen, _extensionMedia);

    cuerpo.fisicaTipo = (FisicasPorTipo*)&forma;

    color = _color;
}

void Rectangulo::Dibujar(sf::RenderTarget& _ventana) const
{
    const sf::Vector2f size = forma.getHalfExtent() * 40;

    sf::RectangleShape rectangle;

    rectangle.setSize(sf::Vector2f(size.x, size.y));

    rectangle.setOrigin(size.x / 2, size.y / 2);

    rectangle.setPosition(cuerpo.getPosicion().x * PIXELTOMETER, cuerpo.getPosicion().y * PIXELTOMETER);

    rectangle.setFillColor(color);

    _ventana.draw(rectangle);
}

sf::Color Rectangulo::get_color() const
{
    return color;
}

void Rectangulo::set_color(const sf::Color& _color)
{
    color = _color;
}