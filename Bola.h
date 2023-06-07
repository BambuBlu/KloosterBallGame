#pragma once
#include <SFML/Graphics.hpp>

#include "FisicasCirculo.h"
#include "ParametrosCuerpos.h"


class Bola : public sf::Drawable
{
private:
	FisicasCirculo circulo;
	sf::Color color;
public:
	Cuerpo cuerpo;
	Bola();
	Bola(const sf::Vector2f, const sf::Vector2f, const sf::Vector2f, const float);
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

	sf::Color getColor() const;
	void setColor(const sf::Color& );
	
	Bola(const FisicasCirculo& circulo, const sf::Color& color, const Cuerpo& cuerpo);
};




