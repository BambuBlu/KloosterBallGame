#include "Bola.h"
#include "Flippers.h"

void Bola::InitBola()
{
    this->bola.setRadius(10);
    this->bola.setPosition(50, 15);
    this->bola.setFillColor(sf::Color::White);

    this->velocidad.x = 200;
	this->velocidad.y = 300;

    this->gravedad = 10.f;
}

Bola::Bola() 
{
	InitBola();
}

void Bola::Mover(float deltaTime) 
{
	this->bola.move(velocidad * deltaTime);
}

void Bola::Dibujar(sf::RenderWindow*& ventana) 
{
	ventana->draw(bola);
}

void Bola::Comprobar_Colision_Bolas(Bola& objeto_a_colisionar, int tipo_de_colision = 1)
{
    /*
    Esta funcion comprueba colisiones entre dos bolas,
    por lo que "objeto_a_colisionar" debe ser de tipo BOLA
    Incluye funciones para:
        Detectar distancia entre los circulos
        Colisionar y reposicionar objetos para que no se superpongan
        Provocar el rebote de la bola (En caso de que el objeto_a_colisionar no se deba mover) [1]
        Provocar el rebote de ambas bolas [2]
        "tipo_de_colision" podrá tomar el valor ["1"] o ["2"]
    */

        ///Detectar colision

        float distancia_entre_circulos =
            (objeto_a_colisionar.bola.getPosition().x - this->bola.getPosition().x) * (objeto_a_colisionar.bola.getPosition().x - this->bola.getPosition().x) +
            (objeto_a_colisionar.bola.getPosition().y - this->bola.getPosition().y) * (objeto_a_colisionar.bola.getPosition().y - this->bola.getPosition().y);

        if (distancia_entre_circulos > ((this->bola.getRadius() + objeto_a_colisionar.bola.getRadius()) * (this->bola.getRadius() + objeto_a_colisionar.bola.getRadius())))
        {
            ///LOS OBJETOS COLISIONARON, ahora toca reposicionar uno de ellos para que no se superponga.
                //Calcular el angulo 
            double angulo = 
                atan2(objeto_a_colisionar.bola.getPosition().y - this->bola.getPosition().y,  //y
                objeto_a_colisionar.bola.getPosition().x - this->bola.getPosition().x); //x

                //Suma de radios para obtener distancia entre los centros de ambos cuadrados
            float suma_de_radios = this->bola.getRadius() + objeto_a_colisionar.bola.getRadius();

             //La distancia a mover para acomodar los objetos una vez colisionan.
            float distancia_a_mover = suma_de_radios - distancia_entre_circulos;

            
              //Ya teniendo angulos y distancias definidas, podemos reposicionar una bola
                //Asi se reposicionaria SOLO el circulo 1
            float posicion_x = this->bola.getPosition().x;
            float posicion_y = this->bola.getPosition().y;

            float nueva_posicion_x = posicion_x += (float)(cos(angulo) * distancia_a_mover);
            float nueva_posicion_y = posicion_y += (float)(sin(angulo) * distancia_a_mover);

            this->bola.setPosition(nueva_posicion_x, nueva_posicion_y);

            /*
                Podemos tambien reposicionar SOLO el circulo 2 (lo cual es util si queremos hacer que nuestra pelota 
                empuje a un objeto, ya que es mas logico que se reposicione el objeto que choca, 
                antes que se reposicione nuestra bola)  
            */
            
            ///UNA VEZ QUE LOS OBJETOS COLISIONAN Y SE REPOSICIONAN, DEBEN REBOTAR

                //Creamos la tangente del punto de impacto en base a los circulos que tenemos
                //Y le damos un valor perpendicular al que ya tiene
            sf::Vector2f vector_tangente;
                //El vector perpendicular a (x, y) == (-y, x)
            vector_tangente.x = objeto_a_colisionar.bola.getPosition().y - this->bola.getPosition().y;
            vector_tangente.y = -(objeto_a_colisionar.bola.getPosition().x - this->bola.getPosition().x);

                //Se normaliza el vector tangente (Dandole una longitud de 1)
            sf::Vector2f Normalize(vector_tangente);

                //Ahora necesitamos la LONGITUD del componente de velocidad paralelo a la tangente
                //Para eso, sacamos la velocidad relativa
            sf::Vector2f velocidad_relativa(
                objeto_a_colisionar.velocidad.x - this->velocidad.x, //Velocidad en x
                objeto_a_colisionar.velocidad.y - this->velocidad.y // Velocidad en y
            ); 

                //La LONGITUD del componente de velocidad paralelo a la tangente se obtiene 
                //haciendo la multiplicacion escalar de la velocidad relativa y la tangente
            float longitud = (velocidad_relativa.x * vector_tangente.x) + (velocidad_relativa.y * vector_tangente.y);

                //Ahora multiplicamos la tangente ya normalizada por la longitud, 
                //para así obtener el componente de velocidad de la tangente
            sf::Vector2f componente_velocidad_en_tangente;
            componente_velocidad_en_tangente.x = vector_tangente.x * longitud;
            componente_velocidad_en_tangente.y = vector_tangente.y * longitud;

                //Finalmente sacamos esto que es re importante, mira que importante que es.
            sf::Vector2f componente_velocidad_perpendicular_a_tangente = velocidad_relativa - componente_velocidad_en_tangente;

            /*
                La colision está lista, ahora decidimos si queremos que nuestra bola (La que llamó a la funcion)
                debe rebotar y  mover al objeto con el que chocó (ej: choca contra otra bola), 
                o solo va a rebotar contra el (ej: pared, bumper, flipper)
            */
            switch (tipo_de_colision)
            {
                case 1:
                {
                    //Hace que rebote solo nuestra bola
                    this->velocidad.x -= 2 * componente_velocidad_perpendicular_a_tangente.x;
                    this->velocidad.y -= 2 * componente_velocidad_perpendicular_a_tangente.y;

                    break;
                }
                case 2:
                {
                    //Hace que reboten ambos objetos entre si
                    this->velocidad.x -= componente_velocidad_perpendicular_a_tangente.x;
                    this->velocidad.y -= componente_velocidad_perpendicular_a_tangente.y;

                    objeto_a_colisionar.velocidad.x += componente_velocidad_perpendicular_a_tangente.x;
                    objeto_a_colisionar.velocidad.y += componente_velocidad_perpendicular_a_tangente.y;

                    break;
                }
            }

        }
}

void Bola::Aplicar_Gravedad(float deltaTime) 
{
    this->velocidad.y += this->gravedad * deltaTime;
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

void Bola::Comprobar_Colision(const Flippers objeto)
{

}
