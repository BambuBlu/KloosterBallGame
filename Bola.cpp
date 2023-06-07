#include "Bola.h"
#include "Flippers.h"
#include "SetsGlobales.h"


Bola::Bola()
{
    sf::Vector2f aux;
    aux.x = 0.f;
    aux.y = 0.f;

    cuerpo = Cuerpo();
    cuerpo.setPosicion(aux);
    cuerpo.setAceleracion(aux);
    cuerpo.setVelocidad(aux);
    cuerpo.setRestitucion(1);
    cuerpo.setInercia(0);
    cuerpo.setMasa(1);
    circulo = FisicasCirculo(0);
    cuerpo.fisicaTipo = (FisicasPorTipo*)&circulo;
    color = sf::Color::White;
}

Bola::Bola(const sf::Vector2f _posicion, const sf::Vector2f _velocidad, const sf::Vector2f _aceleracion, const float _radio)
{
    cuerpo = Cuerpo();
    cuerpo.setPosicion(_posicion);
    cuerpo.setAceleracion(_aceleracion);
    cuerpo.setVelocidad(_velocidad);
    cuerpo.setRestitucion(1);
    cuerpo.setInercia(0);
    cuerpo.setMasa(1);
    circulo = FisicasCirculo(_radio);
    cuerpo.fisicaTipo = (FisicasPorTipo*)&circulo;
    color = sf::Color::White;
}

void Bola::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::CircleShape Bola = sf::CircleShape(circulo.getRadio() * PIXELTOMETER, 15);

    Bola.setFillColor(getColor());

    Bola.setOrigin(circulo.getRadio() * PIXELTOMETER, circulo.getRadio() * PIXELTOMETER);

    Bola.setPosition(cuerpo.getPosicion().x * PIXELTOMETER, cuerpo.getPosicion().y * PIXELTOMETER);

    target.draw(Bola);
}

sf::Color Bola::getColor() const
{
    return color;
}

void Bola::setColor(const sf::Color& _color)
{
    color = _color;
}

Bola::Bola(const FisicasCirculo& circulo, const sf::Color& color, const Cuerpo& cuerpo)
{

}

/*
void Bola::Mover(float deltaTime)
{
	this->bola.move(velocidad * deltaTime);

    if (velocidad.y < velocidad_max_y) velocidad += gravity;

    std::cout << "Velocidad Y -->   " << velocidad.y << endl;
    std::cout << "Velocidad X -->   " << velocidad.x << endl;
}

void Bola::Dibujar(sf::RenderWindow*& ventana) 
{
	ventana->draw(bola);
}

void Bola::Comprobar_Colision_Bolas(Bola& objeto_a_colisionar, int tipo_de_colision = 1)
{

        float distancia_entre_circulos =
            (objeto_a_colisionar.bola.getPosition().x - this->bola.getPosition().x) * (objeto_a_colisionar.bola.getPosition().x - this->bola.getPosition().x) +
            (objeto_a_colisionar.bola.getPosition().y - this->bola.getPosition().y) * (objeto_a_colisionar.bola.getPosition().y - this->bola.getPosition().y);

        if (distancia_entre_circulos > ((this->bola.getRadius() + objeto_a_colisionar.bola.getRadius()) * (this->bola.getRadius() + objeto_a_colisionar.bola.getRadius())))
        {
            double angulo = 
                atan2(objeto_a_colisionar.bola.getPosition().y - this->bola.getPosition().y,
                objeto_a_colisionar.bola.getPosition().x - this->bola.getPosition().x);

            float suma_de_radios = this->bola.getRadius() + objeto_a_colisionar.bola.getRadius();


            float distancia_a_mover = suma_de_radios - distancia_entre_circulos;

            

            float posicion_x = this->bola.getPosition().x;
            float posicion_y = this->bola.getPosition().y;

            float nueva_posicion_x = posicion_x += (float)(cos(angulo) * distancia_a_mover);
            float nueva_posicion_y = posicion_y += (float)(sin(angulo) * distancia_a_mover);

            this->bola.setPosition(nueva_posicion_x, nueva_posicion_y);


            sf::Vector2f vector_tangente;
            vector_tangente.x = objeto_a_colisionar.bola.getPosition().y - this->bola.getPosition().y;
            vector_tangente.y = -(objeto_a_colisionar.bola.getPosition().x - this->bola.getPosition().x);

            sf::Vector2f Normalize(vector_tangente);


            sf::Vector2f velocidad_relativa(
                objeto_a_colisionar.velocidad.x - this->velocidad.x,
                objeto_a_colisionar.velocidad.y - this->velocidad.y
            ); 


            float longitud = (velocidad_relativa.x * vector_tangente.x) + (velocidad_relativa.y * vector_tangente.y);


            sf::Vector2f componente_velocidad_en_tangente;
            componente_velocidad_en_tangente.x = vector_tangente.x * longitud;
            componente_velocidad_en_tangente.y = vector_tangente.y * longitud;


            sf::Vector2f componente_velocidad_perpendicular_a_tangente = velocidad_relativa - componente_velocidad_en_tangente;


            switch (tipo_de_colision)
            {
                case 1:
                {
                    this->velocidad.x -= 2 * componente_velocidad_perpendicular_a_tangente.x;
                    this->velocidad.y -= 2 * componente_velocidad_perpendicular_a_tangente.y;

                    break;
                }
                case 2:
                {
                    this->velocidad.x -= componente_velocidad_perpendicular_a_tangente.x;
                    this->velocidad.y -= componente_velocidad_perpendicular_a_tangente.y;

                    objeto_a_colisionar.velocidad.x += componente_velocidad_perpendicular_a_tangente.x;
                    objeto_a_colisionar.velocidad.y += componente_velocidad_perpendicular_a_tangente.y;

                    break;
                }
            }

        }
}


void Bola::comprobarLimites()
{
     float factorRebote = 0.8f;

        if (this->bola.getGlobalBounds().left < 0 || this->bola.getGlobalBounds().left + this->bola.getGlobalBounds().width > 480) 
        {
            this->velocidad.x = -(this->velocidad.x);  // Invertir la dirección horizontal

            this->velocidad.x *= factorRebote;  // Disminuir la velocidad por el factor de rebote
        }

        if (this->bola.getGlobalBounds().top < 0 || this->bola.getGlobalBounds().top + this->bola.getGlobalBounds().height > 854) 
        {
            this->velocidad.y = -(this->velocidad.y);  // Invertir la dirección vertical

            this->velocidad.y *= factorRebote;  // Disminuir la velocidad por el factor de rebote
        }
}

void Bola::impulso_prueba()
{
    float impulso = 2.f;
    this->velocidad.y = -(this->velocidad.y);

    this->velocidad.y *= impulso;

}

void Bola::Comprobar_Colision(const Flippers objeto)
{
*/







