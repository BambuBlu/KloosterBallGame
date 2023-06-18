#include "Juego.h"

std::list<Bola> bolas;
std::list<Bola>::iterator bolasIterador;

void Juego::InitJuego()
{
    //Determina si la bola está en juego
    this->bool_En_Juego = false;
    //Determina si el juego sigue o no
    this->bool_Fin_Juego = false;
    //Puntos
    this->puntaje_total = 0;
    this->puntaje_mas_alto = 0;
    //Bolas
    this->bolas_restantes = 3;
    //cantidad de juegos 
    this->intentos = 0;

    ///FUENTE DE TEXTO
    this->fuente_de_texto.loadFromFile("Fonts\\Roboto-Black.ttf");
   
    ///VENTANA
    this->video_mode.width = 720;
    this->video_mode.height = 980;
    this->ventana.create(this->video_mode, "Capitán Kloosman", sf::Style::Default);

    ///MUSICA
    if (!buffer.loadFromFile("Sonidos/gentes.wav")) {
        std::cout << "No se cargo los sonidos" << std::endl;
    }
    sound.setBuffer(buffer);

    if (!buffer2.loadFromFile("Sonidos/Arranque.wav")) {
        std::cout << "No se cargo los sonidos" << std::endl;
    }
    sound2.setBuffer(buffer2);
}

Juego::Juego()
{
    InitJuego();
}

void Juego::primer_nivel(Jugadores& _jugador)
{
        ///FONDO DEL NIVEL
        sf::Texture textura;
        sf::Texture textura1;
        sf::Texture textura2;
        if (!textura.loadFromFile("resources/background.png"))
        {
            std::cout << "No se cargo el fondo" << std::endl;
        }
        sf::Sprite background(textura);
        if (!textura1.loadFromFile("resources/game_over.png"))
        {
            std::cout << "No se cargo el fondo" << std::endl;
        }
        sf::Sprite gameOver(textura1);
        if (!textura2.loadFromFile("resources/texture_map.png"))
        {
            std::cout << "No se cargo el fondo" << std::endl;
        }
        sf::Sprite textureMap(textura2);

        sound2.play();
       
        sound = sonido.ReproducirArranque();
        sound.play();
       
        ///DECLARACION DE COLORES DEL NIVEL
        sf::Color Azul = sf::Color(8, 68, 112);
        sf::Color blanco = sf::Color(235, 235, 235);
        sf::Color rosa = sf::Color(200, 90, 129);
        sf::Color gris = sf::Color(39, 36, 36);

        ///MENSAJES EN PANTALLA
        sf::Text str_maximo_puntaje = sf::Text("~ Mejor puntaje: " + std::to_string(puntaje_mas_alto) + "...", fuente_de_texto, 18);
        str_maximo_puntaje.setFillColor(blanco);
        str_maximo_puntaje.setPosition(200, 30);

        sf::Text puntos = sf::Text("Puntos", fuente_de_texto, 35);
        puntos.setFillColor(blanco);
        puntos.setPosition(448, 28);

        sf::Text str_puntaje = sf::Text(std::to_string(puntaje_total), fuente_de_texto, 30);
        str_puntaje.setFillColor(blanco);
        str_puntaje.setPosition(445, 72);

        sf::Text bola = sf::Text("Bola", fuente_de_texto, 25);
        bola.setFillColor(rosa);
        bola.setPosition(616, 22);

        sf::Text str_bolas_restantes = sf::Text(std::to_string(bolas_restantes), fuente_de_texto, 30);
        str_bolas_restantes.setFillColor(blanco);
        str_bolas_restantes.setPosition(634,64);

        sf::Text str_intentos = sf::Text("~ Intentos: " + std::to_string(intentos) + "...", fuente_de_texto, 18);
        str_intentos.setFillColor(blanco);
        str_intentos.setPosition(230, 50);

        std::cout << "Nombre en PrimerNivel() " << std::endl;
        std::cout << _jugador.get_nombre() << std::endl;
        std::cout << "Puntaje PrimerNivel() " << std::endl;
        std::cout << _jugador.get_puntaje() << std::endl;

        ///LISTAS E ITERADORES DE OBJETOS (Almacenan los Objetos)
        std::list<Rectangulo> lRectangulos;
        std::list<Rectangulo>::iterator lRectangulosIt;
        std::list<HitBox> lHitbox;
        std::list<HitBox>::iterator lHitboxIt;
        std::list<EnemigoRedondo> lEnemigosRedondos;
        std::list<EnemigoRedondo>::iterator lEnemigosRedondosIt;
        std::list<EnemigoRectangular> lEnemigosRectangulares;
        std::list<EnemigoRectangular>::iterator lEnemigosRectangularesIt; 
        std::list<TextureManager>::iterator lTexturas;


        //MUROS DEL JUEGO
        Rectangulo muro_superior = Rectangulo(sf::Vector2f(18.f, 7.8f) /*ORIGEN*/, sf::Vector2f(17.f, 0.4f)/*EXTENSION*/, gris/*COLOR*/);

        Rectangulo muro_izquierdo = Rectangulo(sf::Vector2f(0.5f, 27.5f)/*ORIGEN*/, sf::Vector2f(0.7f, 30.f)/*EXTENSION*/, gris/*COLOR*/);

        Rectangulo muro_derecho = Rectangulo(sf::Vector2f(35.5f, 27.5f), sf::Vector2f(0.7f, 30.f), gris);

        Rectangulo esquina_superior_derecha = Rectangulo(sf::Vector2f(34.8f, 8.2f)/*POSICION*/, sf::Vector2f(0.5f, 0.5f)/*EXTENSION MEDIA*/, gris/*COLOR*/);

        Rectangulo tunel = Rectangulo(sf::Vector2f(32.9f, 40.f), sf::Vector2f(0.4f, 15.f), gris);

        //ENEMIGOS REDONDOS - BUMPERS DEL JUEGO

        EnemigoRedondo eRedondo1 = EnemigoRedondo(sf::Vector2f(17.f, 12.f)/*Posicion*/, 1.2f/*Radio*/, 50/*Puntos*/, gris/*Color*/);

        EnemigoRedondo eRedondo2 = EnemigoRedondo(sf::Vector2f(17.f, 24.f), 1.2f, 50, gris);

        EnemigoRedondo eRedondo3 = EnemigoRedondo(sf::Vector2f(10.2f, 18.f), 1.2f, 100, gris);

        EnemigoRedondo eRedondo4 = EnemigoRedondo(sf::Vector2f(23.8f, 18.f), 1.2f, 100, gris);

        EnemigoRedondo eRedondoGrande1 = EnemigoRedondo(sf::Vector2f(17.f, 18.f), 2.f, 10, gris);

        EnemigoRedondo eRedondoGrande2 = EnemigoRedondo(sf::Vector2f(6.f, 25.f), 2.f, 25, gris);

        EnemigoRedondo eRedondoGrande3 = EnemigoRedondo(sf::Vector2f(28.f, 25.f), 2.f, 25, gris);


        //FLIPPERS
        Flippers FlipperIzquierdo(sf::Vector2f(11.5f, 44.1f)/*Posicion*/, 0.6f/*Angulo*/, sf::Vector2f(4.75f, 0.5f)/*Extension media*/, Azul/*Color*/, true/*EnladoIzquierdo*/);

        Flippers FlipperDerecho(sf::Vector2f(21.9f, 44.1f)/*Posicion*/, 0.6f/*Angulo*/, sf::Vector2f(4.75f, 0.5f)/*Extension media*/, Azul/*Color*/, false/*EnladoIzquierdo*/);

        //RAMPAS AL COSTADO DE LOS FLIPPERS

        HitBox rampaIzquierda = HitBox(sf::Vector2f(5.5f, 40.f), sf::Vector2f(6.f, 0.5f), 0.6f, gris);

        HitBox rampaDerecha = HitBox(sf::Vector2f(27.9f, 40.f), sf::Vector2f(6.f, 0.5f), -0.6f, gris);

        //ENEMIGOS RECTANGULARES (Los dos finitos de la pantalla)
        EnemigoRectangular eRectangular1 = EnemigoRectangular(sf::Vector2f(10.4f, 36.3f), sf::Vector2f(0.5f, 2.9f), -0.7f, 10, gris);

        EnemigoRectangular eRectangular2 = EnemigoRectangular(sf::Vector2f(23.f, 36.3f), sf::Vector2f(0.5f, 2.9f), 0.7f, 10, gris);

        EnemigoRectangular eRectangular3 = EnemigoRectangular(sf::Vector2f(5.f, 11.5f), sf::Vector2f(0.5f, 2.f), 0.65f, 500, gris);

        //TEXTURAS
        


        ///AÑADE LOS OBJETOS CREADOS A LAS LISTAS
        lEnemigosRectangulares.push_back(eRectangular1);    
        lEnemigosRectangulares.push_back(eRectangular2);
        lEnemigosRectangulares.push_back(eRectangular3);


        lEnemigosRedondos.push_back(eRedondo1);
        lEnemigosRedondos.push_back(eRedondo2);
        lEnemigosRedondos.push_back(eRedondo3);
        lEnemigosRedondos.push_back(eRedondo4);
        lEnemigosRedondos.push_back(eRedondoGrande1);
        lEnemigosRedondos.push_back(eRedondoGrande2);
        lEnemigosRedondos.push_back(eRedondoGrande3);

        lRectangulos.push_back(muro_superior);
        lRectangulos.push_back(muro_izquierdo);
        lRectangulos.push_back(muro_derecho);
        lRectangulos.push_back(esquina_superior_derecha);

        lRectangulos.push_back(tunel);

        lHitbox.push_back(rampaIzquierda);
        lHitbox.push_back(rampaDerecha);

        ///RELOJ PARA USAR FUNCIONES DE TIEMPO
        sf::Clock clock;

        ///WHILE PARA CONTROLAR QUE LA VENTANA ESTÉ ABIERTA
        while (this->ventana.isOpen())
        {
            ///WHILE PARA CONTROLAR QUE HAYAN EVENTOS Y RECIBIR LA ACCION DEL JUGADOR
            while (this->ventana.pollEvent(this->evento))
            {
                if (this->evento.type == sf::Event::Closed) //Cierra la ventana
                {
                
                    this->ventana.close();
                }
                else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape) //Cierra la ventana
                {
                    this->ventana.close();
                }
                else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Space) //Crea y lanza la bola
                {
                    
                    if (!bool_En_Juego && !bool_Fin_Juego)
                    {
                        //Parametros de la bola
                        sf::Vector2f posicion = sf::Vector2f(34.f, 50.f);
                        sf::Vector2f velocidad = sf::Vector2f(0.f, -60.f);
                        sf::Vector2f aceleracion = sf::Vector2f(0.f, 30.f);

                        //Crea la bola
                        Bola bola = Bola(posicion, velocidad, aceleracion, 0.9f);

                        bola.set_color(sf::Color::White);

                        //Agrega la bola a la lista
                        bolas.push_back(bola);

                        //Indica que hay una bola en juego
                        bool_En_Juego = true;


                    }
                }
                else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Z)
                {
                    
                    FlipperIzquierdo.Mover("arriba");
                   
                    
                }
                else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::X)
                {
                    
                    FlipperDerecho.Mover("arriba");
                   
                }
                else if (this->evento.type == sf::Event::KeyReleased && evento.key.code == sf::Keyboard::Z)
                {
                    
                    FlipperIzquierdo.Mover("abajo");
                }
                else if (this->evento.type == sf::Event::KeyReleased && evento.key.code == sf::Keyboard::X)
                {
                    
                    FlipperDerecho.Mover("abajo");
                }
            }

            this->ventana.clear(sf::Color::Black);

            ///SE UTILIZAN FUNCIONES DE TIEMPO PARA EL FLUJO DEL JUEGO
            sf::Time intervalo_tiempo = clock.getElapsedTime();

            const unsigned int tiempo_transcurrido = intervalo_tiempo.asMilliseconds();

            if (tiempo_transcurrido >= 10 && !bool_Fin_Juego)
            {
                const float fSegundos = intervalo_tiempo.asSeconds();

                ///FOR PARA CONTROLAR LA COLISION DE LA BOLA CON CADA OBJETO
                for (bolasIterador = bolas.begin(); bolasIterador != bolas.end(); ++bolasIterador)
                {
                    for (auto p = bolas.begin(); p != bolas.end(); p++)
                    {
                        if (bolasIterador != p)
                        {
                            Multiple colision = Multiple(&bolasIterador->cuerpo, &p->cuerpo);

                            if (colision.CirculoVsCirculo())
                            {
                                colision.correctPosition();

                                colision.aplicarImpulsoRotacional();
                            }
                        }
                    }
                    ///FOR PARA CONTROLAR LA COLISION DE LA BOLA CON CADA ENEMIGO REDONDO
                    for (lEnemigosRedondosIt = lEnemigosRedondos.begin(); lEnemigosRedondosIt != lEnemigosRedondos.end(); ++lEnemigosRedondosIt) 
                    {
                        Multiple colision = Multiple(&lEnemigosRedondosIt->cuerpo, &bolasIterador->cuerpo);

                        if (colision.CirculoVsCirculo())
                        {
                            sound = sonido.ReproducirGentes();
                            sound.play();
                            
                            puntaje_total += lEnemigosRedondosIt->get_puntos();

                            colision.correctPosition();

                            colision.aplicarImpulsoRotacional();
                        }
                    }

                    ///FOR PARA CONTROLAR LA COLISION DE LA BOLA CON CADA ENEMIGO RECTANGULAR
                    for (lEnemigosRectangularesIt = lEnemigosRectangulares.begin(); lEnemigosRectangularesIt != lEnemigosRectangulares.end(); ++lEnemigosRectangularesIt)
                    {
                        Multiple colision = Multiple(&lEnemigosRectangularesIt->cuerpo, &bolasIterador->cuerpo);

                        if (colision.CirculoVsHitbox())
                        {
                            puntaje_total += lEnemigosRectangularesIt->get_puntos();

                            colision.correctPosition();

                            colision.aplicarImpulsoRotacional();
                        }
                    }

                    ///FOR PARA CONTROLAR LA COLISION DE LA BOLA CON CADA OBJETO RECTANGULAR
                    for (lRectangulosIt = lRectangulos.begin(); lRectangulosIt != lRectangulos.end(); ++lRectangulosIt)
                    {
                        Multiple colision = Multiple(&lRectangulosIt->cuerpo, &bolasIterador->cuerpo);

                        if (colision.CirculoVsRectangulo())
                        {
                            colision.correctPosition();

                            colision.aplicarImpulsoRotacional();
                        }
                    }

                    //FOR PARA CONTROLAR LA COLISION DE LA BOLA CON CADA RAMPA
                    for (lHitboxIt = lHitbox.begin(); lHitboxIt != lHitbox.end(); ++lHitboxIt)
                    {
                        Multiple colision = Multiple(&lHitboxIt->cuerpo, &bolasIterador->cuerpo);

                        if (colision.CirculoVsHitbox())
                        {
                            colision.correctPosition();

                            colision.aplicarImpulsoRotacional();
                        }
                    }

                    /*
                        TOMA A UN FLIPPER COMO CUERPO A Y A UNA BOLA COMO CUERPO B.
                        CHECKEA SI SE ESTÁN TOCANDO, CORRIGE LA POSICIÓN Y LE APLICA EL IMPULSO A LA BOLA.
                    */
                    Multiple FlipperIzquierdo_colision = Multiple(&FlipperDerecho.cuerpo, &bolasIterador->cuerpo);

                    if (FlipperIzquierdo_colision.CirculoVsHitbox())
                    {
                        FlipperIzquierdo_colision.correctPosition();

                        FlipperIzquierdo_colision.aplicarImpulsoRotacional();
                    }

                    Multiple FlipperDerecho_colision = Multiple(&FlipperIzquierdo.cuerpo, &bolasIterador->cuerpo);

                    if (FlipperDerecho_colision.CirculoVsHitbox())
                    {
                        FlipperDerecho_colision.correctPosition();

                        FlipperDerecho_colision.aplicarImpulsoRotacional();
                    }

                    //ACTUALIZA LAS PROPIEDADES DE LA BOLA (POSICION, VELOCIDAD Y ACELERACION)
                    bolasIterador->cuerpo.updateBola(fSegundos);
                }

                //actualiza el movimientos de los flipper
                FlipperDerecho.cuerpo.update(fSegundos);
                FlipperDerecho.rotarFlipper();

                FlipperIzquierdo.cuerpo.update(fSegundos);
                FlipperIzquierdo.rotarFlipper();

                clock.restart();
            }

            this->ventana.draw(background);

            //Actualiza los mensajes de la pantalla
            str_puntaje.setString(std::to_string(puntaje_total));

            str_bolas_restantes.setString(std::to_string(bolas_restantes));

            str_maximo_puntaje.setString("~ Mejor puntaje: " + std::to_string(puntaje_mas_alto) + "...");

            str_intentos.setString("~ Intentos: " + std::to_string(intentos) + "...");
            

            restar_bola();

            //Si no quedan bolas, termina el juego
            if (bolas_restantes <= 0)
            {
                bool_Fin_Juego = true;
            }
            //Si nuestro puntaje es mayor al puntaje más alto, se actualiza
            if (puntaje_total > puntaje_mas_alto)
            {
                puntaje_mas_alto = puntaje_total;
            }

            /*
                A PARTIR DE ACA SE DIBUJAN LOS OBJETOS HASTA
                    "if (bool_Fin_Juego)"
            */

            //DIBUJA FLIPPERS
            this->ventana.draw(FlipperDerecho);
            this->ventana.draw(FlipperIzquierdo);

            for (lRectangulosIt = lRectangulos.begin(); lRectangulosIt != lRectangulos.end(); ++lRectangulosIt)
            {
                this->ventana.draw(*lRectangulosIt);
            }

            for (lHitboxIt = lHitbox.begin(); lHitboxIt != lHitbox.end(); ++lHitboxIt)
            {
                this->ventana.draw(*lHitboxIt);
            }

            for (bolasIterador = bolas.begin(); bolasIterador != bolas.end(); ++bolasIterador)
            {
                this->ventana.draw(*bolasIterador);
            }

            for (lEnemigosRedondosIt = lEnemigosRedondos.begin(); lEnemigosRedondosIt != lEnemigosRedondos.end(); ++lEnemigosRedondosIt)
            {
                this->ventana.draw(*lEnemigosRedondosIt);
            }

            for (lEnemigosRectangularesIt = lEnemigosRectangulares.begin(); lEnemigosRectangularesIt != lEnemigosRectangulares.end(); ++lEnemigosRectangularesIt)
            {
                this->ventana.draw(*lEnemigosRectangularesIt);
            }



            //DIBUJA TEXTO EN LA PANTALLA
            this->ventana.draw(str_maximo_puntaje);
            this->ventana.draw(puntos);
            this->ventana.draw(str_puntaje);
            this->ventana.draw(bola);
            this->ventana.draw(str_bolas_restantes);
            this->ventana.draw(str_intentos);
            this->ventana.draw(textureMap);



            /*
                En caso de que termine el juego, se reinicia.
                Tenemos que decidir que hacer en caso de perder, si se debe reiniciar el juego y guardar el puntaje,
                si se debe enviar al menu para volver a elegir el mapa, etc...

                Al ser la funcion un booleano, puede retornar True en caso de haber superado el maximo puntaje
                y False en caso de no haberlo superado o algo xd
            */

            if (bool_Fin_Juego)
            {
                bool_En_Juego = false;

                this->ventana.draw(gameOver);

                float  fDelay = sf::seconds(6.0).asSeconds();

                sf::Time now = clock.getElapsedTime();

                printf("%f \n", now.asSeconds());
                

                if (now.asSeconds() >= fDelay)
                {
                    intentos++;
                    puntaje_total = 0;
                    bolas_restantes = 3;
                    bool_Fin_Juego = false;
                    clock.restart();
                }
            }
            //Muestra todo lo dibujado
            this->ventana.display();
        }

        _jugador.set_puntaje(puntaje_total);
        _jugador.set_nivel(1);

        ArchivoJugadores archivo;
        if (archivo.guardar(_jugador))
        {
            std::cout << "Jugador guardado correctamente!" << std::endl;
        }

}
/*
    CONTROLA QUE LA PELOTA NO SE HAYA IDO DE LA PANTALLA,
    EN CASO DE QUE SI, RESTA UNA VIDA.
*/
void Juego::restar_bola()
{
    for (bolasIterador = bolas.begin(); bolasIterador != bolas.end();) 
    {
        if (bolasIterador->cuerpo.getPosicion().y > 60) 
        {

            bolasIterador = bolas.erase(bolasIterador);
            bolas_restantes--;
            bool_En_Juego = false;
        }
        else 
        {
            ++bolasIterador;
        }
    }
}
