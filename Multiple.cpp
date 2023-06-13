#include "Multiple.h"

/// Funciones matematicas utilizadas

//Calcula el cuadrado de las variables del vector v1 con el v2
float productoEscalar(sf::Vector2f& v1, sf::Vector2f& v2)
{
    float producto = 0;
    producto = v1.x * v2.x + v1.y * v2.y;
    return producto;
}

//Calcula el cuadrado de las variables del vector v1
float productoEscalar(sf::Vector2f& v1)
{
    float producto = 0;
    producto = (v1.x * v1.x) + (v1.y * v1.y);
    return producto;
}

float productoCruzado(sf::Vector2f& v1, sf::Vector2f& v2) 
{

    float resultado = (v1.x * v2.y) - (v1.y * v2.x);

    return resultado;
}

sf::Vector2f escalar_cruzado(sf::Vector2f& vector, float scalar) {

    sf::Vector2f resultado;

    resultado.x = vector.y * scalar;
    resultado.y = vector.x * -scalar;

    return resultado;
}

///METODOS DE LA CLASE
Multiple::Multiple()//!< Default constructor
{

}

//Constructor que toma dos cuerpos para generar la variedad de colisi�n
Multiple::Multiple(Cuerpo* first, Cuerpo* second)
{
    cuerpo_a = first;
    cuerpo_b = second;
}

bool Multiple::CirculoVsCirculo()
{
    /*!< Configuraci�n de punteros a dos c�rculos*/
    FisicasCirculo* circulo1 = (FisicasCirculo*)cuerpo_a->fisicaTipo;
    FisicasCirculo* circulo2 = (FisicasCirculo*)cuerpo_b->fisicaTipo;

    /*!< C�lculo del vector entre los dos cuerpos.*/
    sf::Vector2f diferencia = cuerpo_b->getPosicion() - cuerpo_a->getPosicion();

    /*!< Suma de ambos radios */
    float suma_radios = circulo1->getRadio() + circulo2->getRadio();


    //Eleva al cuadrado las variables del vector2f diferencia 
    float diferenciaAlCuadrado = productoEscalar(diferencia);

    //Comprueba si un circulo est� dentro de otro
    if ((suma_radios * suma_radios) < diferenciaAlCuadrado)
    {
        return false;
    }

    //Calcula la raiz cuadrada
    diferenciaAlCuadrado = std::sqrtf(diferenciaAlCuadrado);

    //Si la distancia entre 2 circulos != 0
    if (diferenciaAlCuadrado != 0)
    {
        penetracion = diferenciaAlCuadrado - suma_radios; // distancia de penetracion
        normal = diferencia / diferenciaAlCuadrado;
        punto_de_contacto = cuerpo_b->getPosicion() - (normal * circulo2->getRadio());
    }
    else
    {
        penetracion = circulo1->getRadio();
        normal = sf::Vector2f(1, 0);
        punto_de_contacto = cuerpo_a->getPosicion();
    }

    return true;
}

bool Multiple::CirculoVsRectangulo()
{
    /*!< Configuraci�n de punteros a un rect�ngulo y un c�rculo */
    RectanguloFisicas* rectangulo = (RectanguloFisicas*)cuerpo_a->fisicaTipo;

    FisicasCirculo* circulo = (FisicasCirculo*)cuerpo_b->fisicaTipo;

    // Vector de la diferencia entre el cuerpo (B - A)
    sf::Vector2f diferencia = cuerpo_b->getPosicion() - cuerpo_a->getPosicion();

    /*!< Clamping closest point to nearest edge */
    sf::Vector2f closest = Clamp(rectangulo->get_extensionMedia(), diferencia);

    bool adentro = false;

    // Clamp circle to the closest edge
    if (diferencia == closest)
    {
        adentro = true;

        // Encuentra el eje m�s cercano
        if (std::abs(diferencia.x) > std::abs(diferencia.y))
        {

            // Clamp to closest extent
            if (closest.x > 0) 
            {
                closest.x = (rectangulo->get_extensionMedia().x);
            }
            else 
            {
                closest.x = (-rectangulo->get_extensionMedia().x);
            }
        }
        else
        {
            if (closest.y > 0) 
            {
                closest.y = (rectangulo->get_extensionMedia().y);
            }
            else
            {
                closest.y = (-rectangulo->get_extensionMedia().y);
            }
        }
    }

    sf::Vector2f aux = diferencia - closest;

    float distancia = productoEscalar(aux);

    float radio = circulo->getRadio();

    //Si el circulo no esta adentro AABB
    if (distancia > radio * radio && !adentro) 
    {
        return false;
    }

    distancia = std::sqrtf(distancia);

    aux = aux / distancia;

    //si el circulo esta adentro AABB
    if (adentro) {
        normal = -aux;
        punto_de_contacto = cuerpo_b->getPosicion() - (normal * circulo->getRadio());
        penetracion = distancia - radio;
    }
    else {
        normal = aux;
        punto_de_contacto = cuerpo_b->getPosicion() - (normal * circulo->getRadio());
        penetracion = distancia - radio;
    }
    return true;
}

bool Multiple::CirculoVsHitbox()
{
    HitBoxFisicas* hitbox = (HitBoxFisicas*)cuerpo_a->fisicaTipo;

    FisicasCirculo* circulo = (FisicasCirculo*)cuerpo_b->fisicaTipo;

    // Vector entre A y B
    sf::Vector2f diferencia = cuerpo_b->getPosicion() - cuerpo_a->getPosicion();

    Rotacion rotar = Rotacion(cuerpo_a->getRadioAngulo());

    sf::Vector2f transform = rotar.rotar_vector_inversamente(diferencia);

    // Punto m�s cercano de A a B
    sf::Vector2f closest = Clamp(hitbox->get_extension_media(), transform);

    bool adentro = false;

    // Clamp circle to the closest edge
    if (transform == closest)
    {
        adentro = true;
        if (std::abs(transform.x) >= std::abs(transform.y))
        {
            if (closest.x > 0)
            {
                closest.x = (hitbox->get_extension_media().x);
            }
            else
            {
                closest.x = (-hitbox->get_extension_media().x);
            }
        }
        else
        {
            if (closest.y > 0)
            {
                closest.y = (hitbox->get_extension_media().y);
            }
            else
            {
                closest.y = (-hitbox->get_extension_media().y);
            }
        }
    }

    sf::Vector2f aux = transform - closest;

    float distancia = productoEscalar(aux);

    float radio = circulo->getRadio();

    if (distancia > radio * radio && !adentro)
    {
        return false;
    }

    distancia = std::sqrtf(distancia);

    aux = aux / distancia;

    //si el c�rculo est� dentro AABB
    if (adentro)
    {
        normal = -aux;

        punto_de_contacto = cuerpo_b->getPosicion() - rotar.rotar_vector(normal * circulo->getRadio());

        penetracion = distancia - radio;
    }
    else
    {
        normal = aux;

        punto_de_contacto = cuerpo_b->getPosicion() - rotar.rotar_vector(normal * circulo->getRadio());

        penetracion = distancia - radio;
    }
    return true;
}

void Multiple::correctPosition() //!< Aplica la correcci�n de posici�n
{
    const float porcentaje = 0.2f;
    
    const float kfSlop = 0.01f;

    const float sumatoriaMasaInversa = cuerpo_a->getMasaInversa() + cuerpo_b->getMasaInversa();

    const float kFScalarNum = std::max(std::abs(penetracion) - kfSlop, 0.0f) / sumatoriaMasaInversa;

    sf::Vector2f correncion = normal * kFScalarNum * porcentaje;

    cuerpo_a->posicion -= correncion * cuerpo_a->getMasaInversa();

    cuerpo_b->posicion += correncion * cuerpo_b->getMasaInversa();
}

void Multiple::aplicarImpulsoRotacional()
{
    /*!< Calcula los puntos de contacto*/
    sf::Vector2f contactoCuerpoA(punto_de_contacto - cuerpo_a->getPosicion());
    sf::Vector2f contactoCuerpoB(punto_de_contacto - cuerpo_b->getPosicion());

    /*!< Calcula la velocidad relativa */
    sf::Vector2f velocidadRelativa = (cuerpo_b->getVelocidad() + escalar_cruzado(contactoCuerpoB, -cuerpo_b->getVelocidadAngular())) -
                         (cuerpo_a->getVelocidad() + escalar_cruzado(contactoCuerpoA, -cuerpo_a->getVelocidadAngular()));

    /*!< Calcula la velocidad relativa a travez de la normal */
    float fVelAlongNormal = productoEscalar(normal, velocidadRelativa);

    /*!< si es mayor a 0 NO aplica impulso si las velocidades se est�n separando*/
    if (fVelAlongNormal > 0) 
    {
        return;
    }

    /*!< Calcula  restitucion */
    float restitucion = std::min(cuerpo_a->getRestitucion(), cuerpo_b->getRestitucion());

    const float kfContactACrossNormal = productoCruzado(normal, contactoCuerpoA);

    const float kfContactBCrossNormal = productoCruzado(normal, contactoCuerpoB);

    /*!< Calculate impulse scalar */
    float fImpulseScalar = -(1 + restitucion) * fVelAlongNormal;
    fImpulseScalar /= cuerpo_a->getMasaInversa() + cuerpo_b->getMasaInversa() + (kfContactACrossNormal * kfContactACrossNormal) * cuerpo_a->getInerciaInversa() + (kfContactBCrossNormal * kfContactBCrossNormal) * cuerpo_b->getInerciaInversa();

    /*!<Aplica impulso de rotacion */
    sf::Vector2f impulso = normal * fImpulseScalar;

    cuerpo_a->AplicarImpulso(-impulso, contactoCuerpoA);

    cuerpo_b->AplicarImpulso(impulso, contactoCuerpoB);
}

sf::Vector2f Multiple::Clamp(const sf::Vector2f& rectExtents, const sf::Vector2f& circlePos) 
{ //Determina el punto mas cercano al borde mas cercano de AABB

    sf::Vector2f gancho = sf::Vector2f();

    if (circlePos.x >= 0) 
    {
        gancho.x = std::min(circlePos.x, rectExtents.x);
    }
    else 
    {
        gancho.x = std::max(circlePos.x, - rectExtents.x);
    }

    if (circlePos.y >= 0) 
    {
        gancho.y = std::min(circlePos.y, rectExtents.y);
    }
    else 
    {
        gancho.y = std::max(circlePos.y, -rectExtents.y);
    }
    return gancho;
}