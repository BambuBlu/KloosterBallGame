 #include "Flippers.h"

Flippers::Flippers(const sf::Vector2f& _position, const sf::Vector2f& _aceleracion, const sf::Vector2f& _velocidad, float _angulo ,bool _lado)
{
	cuerpo = Cuerpo();
	cuerpo.setPosicion(_position);
	cuerpo.setAceleracion(_aceleracion);
	cuerpo.setVelocidad(_velocidad);
	cuerpo.setMasa(0);
	cuerpo.setInercia(0);
	cuerpo.setRestitucion(0.2);

	en_lado_izquierdo = _lado;

	if (en_lado_izquierdo == true) 
	{
		cuerpo.setRadioAngulo(_angulo);
	}
	else 
	{
		cuerpo.setRadioAngulo(-_angulo);
	}

	_texture.loadFromFile("flipper.png");
	_sprite.setTexture(_texture);
	_sprite.setPosition(_position);

}

void Flippers::Mover(std::string evento)
{
	if (evento == "arriba") 
	{
		if (en_lado_izquierdo == true)
		{
			cuerpo.AplicarAnguloDeImpulso(PADDLE_SPEED);
		}
		else 
		{
			cuerpo.AplicarAnguloDeImpulso(-PADDLE_SPEED);
		}
	}
	else if (evento == "abajo")
	{
		if (en_lado_izquierdo == true)
		{
			cuerpo.AplicarAnguloDeImpulso(-PADDLE_SPEED);
		}
		else
		{
			cuerpo.AplicarAnguloDeImpulso(PADDLE_SPEED);
		}
	}
}

void Flippers::clampPaddle()
{

	if (en_lado_izquierdo == true) 
	{

		if (cuerpo.getRadioAngulo() > PADDLE_MAX_ANGLE) 
		{
			cuerpo.setRestitucion(PADDLE_MAX_ANGLE);
			cuerpo.setVelocidadAngular(0);
		}

		if (cuerpo.getRadioAngulo() < PADDLE_MIN_ANGLE) 
		{
			cuerpo.setRadioAngulo(PADDLE_MIN_ANGLE);
			cuerpo.setVelocidadAngular(0);
		}
	}
	else 
	{
		if (cuerpo.getRadioAngulo() < -PADDLE_MAX_ANGLE)
		{
			cuerpo.setRadioAngulo(-PADDLE_MAX_ANGLE);
			cuerpo.setVelocidadAngular(0);
		}

		if (cuerpo.getRadioAngulo() > -PADDLE_MIN_ANGLE)
		{
			cuerpo.setRadioAngulo(-PADDLE_MIN_ANGLE);
			cuerpo.setVelocidadAngular(0);
		}
	}

}

void Flippers::Dibujar(sf::RenderWindow*& ventana)
{
    ventana->draw(_sprite);
}
