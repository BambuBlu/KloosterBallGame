#include "Juego.h"

void Juego::InitJuego()
{
    this->ventana;
    this->video_mode;
    this->evento;

    this->bool_En_Juego = false;
    this->bool_Fin_Juego = false;
    this->puntaje_total = 0;
    this->bolas_restantes = 3;
    this->puntaje_mas_alto = 0;


    ///FUENTE DE TEXTO
    this->fuente_de_texto.loadFromFile("Fonts\\SourceCodePro-Italic-VariableFont_wght.ttf");
}

Juego::Juego()
{
    InitJuego();
}

void Juego::primer_nivel(int, char const**)
{
    ///Cada vez que se inicie este nivel, las variables deberan volver a iniciarse
       InitJuego();

        ///FONDO DEL NIVEL
        TextureManager texturas;
        texturas.cargar_textura("background", "resources\\BackgroundGame.png");

        sf::Sprite fondo;
        fondo.setTexture(texturas.get_textura("background"));
        fondo.setPosition(0, 0);

        ///DECLARACION DE COLORES DEL NIVEL
        sf::Color azulcito = sf::Color(117, 137, 191);
        sf::Color cyan = sf::Color(179, 226, 221);
        sf::Color amarillo = sf::Color(255, 237, 81);
        sf::Color naranja = sf::Color(252, 169, 133);
        sf::Color verde = sf::Color(72, 181, 163);

        ///MENSAJES EN PANTALLA
        sf::Text str_maximo_puntaje = sf::Text("MAXIMO PUNTAJE: " + std::to_string(puntaje_mas_alto), arcadeFont, 60);
        str_maximo_puntaje.setFillColor(verde);
        str_maximo_puntaje.setPosition(40, 5);

        sf::Text str_puntaje = sf::Text("PUNTAJE: " + std::to_string(puntaje_total), arcadeFont, 60);
        str_puntaje.setFillColor(verde);
        str_puntaje.setPosition(40, 80);

        sf::Text str_bolas_restantes = sf::Text("BOLAS: " + std::to_string(bolas_restantes), arcadeFont, 60);
        str_bolas_restantes.setFillColor(verde);
        str_bolas_restantes.setPosition(500, 5);

        sf::Text str_fin_juego = sf::Text("FIN DEL JUEGO", arcadeFont, 150);
        str_fin_juego.setFillColor(sf::Color::Black);
        str_fin_juego.setPosition(100, 400);

        ///DECLARACION DE RANDOMIZADOR
        Randomizador rand;

        //LISTAS E ITERADORES DE OBJETOS
        std::list<Rectangulo> lRectangulos;
        std::list<Rectangulo>::iterator lRectangulosIt;

        std::list<HitBox> lHitbox;
        std::list<HitBox>::iterator lHitboxIt;


        std::list<EnemigoRedondo> lEnemigosRedondos;
        std::list<EnemigoRedondo>::iterator lEnemigosRedondosIt;

        std::list<EnemigoRectangular> lEnemigosRectangulares;
        std::list<EnemigoRectangular>::iterator lEnemigosRectangularesIt; 

        ///MUROS DEL JUEGO
        Rectangulo muro_superior = Rectangulo(sf::Vector2f(18, 8.8), sf::Vector2f(17, 0.7), azulcito);
        Rectangulo muro_izquierdo = Rectangulo(sf::Vector2f(0.5, 27.5), sf::Vector2f(0.7, 30), azulcito);
        Rectangulo muro_derecho = Rectangulo(sf::Vector2f(35.5, 27.5), sf::Vector2f(0.7, 30), azulcito);
        Rectangulo esquina_superior_derecha = Rectangulo(sf::Vector2f(34.8, 9.8), sf::Vector2f(0.5, 0.5), azulcito);
        Rectangulo esquina_inferior_izquierda = Rectangulo(sf::Vector2f(1.3, 37.5), sf::Vector2f(0.5, 0.5), azulcito);
        Rectangulo esquina_inferior_derecha = Rectangulo(sf::Vector2f(32.5, 37.5), sf::Vector2f(0.5, 0.5), azulcito);
        Rectangulo tunel = Rectangulo(sf::Vector2f(32.9, 34), sf::Vector2f(0.2, 21), azulcito);

        ///ENEMIGOS / BUMPERS DEL JUEGO
        EnemigoRedondo eRedondo1 = EnemigoRedondo(sf::Vector2f(10, 13), 1.7, 10, cyan);
        EnemigoRedondo eRedondo2 = EnemigoRedondo(sf::Vector2f(27, 16), 1.7, 10, amarillo);
        EnemigoRedondo eRedondoGrande1 = EnemigoRedondo(sf::Vector2f(17.5, 21), 2, 10, verde);
        EnemigoRedondo eRedondoGrande2 = EnemigoRedondo(sf::Vector2f(6, 25), 2, 10, amarillo);
        EnemigoRedondo eRedondoGrande3 = EnemigoRedondo(sf::Vector2f(28, 25), 2, 10, cyan);

        ///FLIPPERS
        Flippers FlipperIzquierdo(sf::Vector2f(50.f, 200.f), sf::Vector2f(4.5, 0.6), sf::Vector2f(1.f, 1.f), 0.5, sf::Vector2f(30.f, 30.f), cyan, false);
        Flippers FlipperDerecho(sf::Vector2f(350.f, 200.f), sf::Vector2f(4.5, 0.6), sf::Vector2f(1.f, 1.f), 0.5, sf::Vector2f(30.f, 30.f), cyan, true);



        HitBox rampaIzquierda = HitBox(sf::Vector2f(5.5, 41), sf::Vector2f(6, 0.5), 0.6, azulcito);
        HitBox rampaDerecha = HitBox(sf::Vector2f(27.7, 41), sf::Vector2f(6, 0.5), -0.6, azulcito);

        ///ENEMIGOS RECTANGULARES
        EnemigoRectangular eRectangular1 = EnemigoRectangular(sf::Vector2f(4.5, 33), sf::Vector2f(0.5, 2), 0.3, 20, azulcito);
        EnemigoRectangular eRectangular2 = EnemigoRectangular(sf::Vector2f(30, 33), sf::Vector2f(0.5, 2), -0.3, 20, azulcito);

        lEnemigosRectangulares.push_back(eRectangular1);
        lEnemigosRectangulares.push_back(eRectangular2);

        ///ENEMIGOS CIRCULARES
        lEnemigosRedondos.push_back(eRedondo1);
        lEnemigosRedondos.push_back(eRedondo2);
        lEnemigosRedondos.push_back(eRedondoGrande1);
        lEnemigosRedondos.push_back(eRedondoGrande2);
        lEnemigosRedondos.push_back(eRedondoGrande3);


        lRectangulos.push_back(muro_superior);
        lRectangulos.push_back(muro_izquierdo);
        lRectangulos.push_back(muro_derecho);
        lRectangulos.push_back(tunel);
        lRectangulos.push_back(esquina_superior_derecha);
        lRectangulos.push_back(esquina_inferior_derecha);
        lRectangulos.push_back(esquina_inferior_izquierda);

        lHitbox.push_back(rampaIzquierda);
        lHitbox.push_back(rampaDerecha);

        sf::Clock clock;

        while (this->ventana.isOpen())
        {

            while (this->ventana.pollEvent(this->evento))
            {

                if (this->evento.type == sf::Event::Closed)
                {
                    this->ventana.close();
                }
                else if (this->evento.type == sf::Event::KeyPressed && this->evento.key.code == sf::Keyboard::Escape)
                {
                    this->ventana.close();
                }
                else if (this->evento.type == sf::Event::KeyPressed && this->evento.key.code == sf::Keyboard::Space)
                {

                    if (!bool_En_Juego && !bool_Fin_Juego)
                    {

                        sf::Vector2f pos = sf::Vector2f(34.f, 55.f);
                        sf::Vector2f vel = sf::Vector2f(0.f, -60.f);
                        sf::Vector2f acc = sf::Vector2f(0.f, 20.f);

                        Bola bola = Bola(pos, vel, acc, 0.9);

                        bola.set_color(sf::Color::Black);

                        bolas.push_back(bola);

                        bool_En_Juego = true;
                    }
                }
                else if (this->evento.type == sf::Event::KeyPressed && this->evento.key.code == sf::Keyboard::Left)
                {
                    FlipperIzquierdo.Mover("up");
                }
                else if (this->evento.type == sf::Event::KeyPressed && this->evento.key.code == sf::Keyboard::Right)
                {
                    FlipperDerecho.Mover("up");
                }

                else if (this->evento.type == sf::Event::KeyReleased && this->evento.key.code == sf::Keyboard::Left)
                {
                    FlipperIzquierdo.Mover("down");
                }
                else if (this->evento.type == sf::Event::KeyReleased && this->evento.key.code == sf::Keyboard::Right)
                {
                    FlipperDerecho.Mover("down");
                }

            }

            this->ventana.clear(sf::Color::Black);

            sf::Time intervalo_tiempo = clock.getElapsedTime();

            const unsigned int tiempo_transcurrido = intervalo_tiempo.asMilliseconds();

            if (tiempo_transcurrido >= 10 && !bool_Fin_Juego)
            {
                const float fSegundos = intervalo_tiempo.asSeconds();

                for (bolasIterador = bolas.begin(); bolasIterador != bolas.end(); ++bolasIterador)
                {

                    for (auto p = bolas.begin(); p != bolas.end(); ++p)
                    {

                        if (bolasIterador != p)
                        {
                            Multiple m = Multiple(&bolasIterador->cuerpo, &p->cuerpo);

                            if (m.CircleVsCircle())
                            {
                                m.correctPosition();
                                m.applyRotationalImpulse();
                            }
                        }
                    }

                    for (lEnemigosRedondosIt = lEnemigosRedondos.begin(); lEnemigosRedondosIt != lEnemigosRedondos.end(); ++lEnemigosRedondosIt) {

                        Multiple m = Multiple(&lEnemigosRedondosIt->cuerpo, &bolasIterador->cuerpo);

                        if (m.CircleVsCircle())
                        {
                            puntaje_total += lEnemigosRedondosIt->getPoints();

                            m.correctPosition();

                            m.applyRotationalImpulse();
                        }
                    }

                    for (lEnemigosRectangularesIt = lEnemigosRectangulares.begin(); lEnemigosRectangularesIt != lEnemigosRectangulares.end(); ++lEnemigosRectangularesIt)
                    {

                        Multiple m = Multiple(&lEnemigosRectangularesIt->cuerpo, &bolasIterador->cuerpo);

                        if (m.CircleVsOBB())
                        {
                            puntaje_total += lEnemigosRectangularesIt->getPoints();

                            m.correctPosition();

                            m.applyRotationalImpulse();
                        }
                    }

                    for (lRectangulosIt = lRectangulos.begin(); lRectangulosIt != lRectangulos.end(); ++lRectangulosIt)
                    {

                        Multiple m = Multiple(&lRectangulosIt->cuerpo, &bolasIterador->cuerpo);

                        if (m.CircleVsRect())
                        {
                            m.correctPosition();

                            m.applyRotationalImpulse();
                        }
                    }

                    for (lHitboxIt = lHitbox.begin(); lHitboxIt != lHitbox.end(); ++lHitboxIt)
                    {
                        Multiple m = Multiple(&lHitboxIt->cuerpo, &bolasIterador->cuerpo);

                        if (m.CircleVsOBB())
                        {
                            m.correctPosition();

                            m.applyRotationalImpulse();
                        }
                    }

                    Multiple FlipperIzquierdo_Manifold = Multiple(&FlipperDerecho.cuerpo, &bolasIterador->cuerpo);

                    if (FlipperIzquierdo_Manifold.CircleVsOBB())
                    {
                        FlipperIzquierdo_Manifold.correctPosition();

                        FlipperIzquierdo_Manifold.applyRotationalImpulse();
                    }

                    Multiple FlipperDerecho_Manifold = Multiple(&FlipperIzquierdo.cuerpo, &bolasIterador->cuerpo);

                    if (FlipperDerecho_Manifold.CircleVsOBB())
                    {
                        FlipperDerecho_Manifold.correctPosition();

                        FlipperDerecho_Manifold.applyRotationalImpulse();
                    }

                    bolasIterador->cuerpo.update(fSegundos);
                }

                for (lEnemigosRedondosIt = lEnemigosRedondos.begin(); lEnemigosRedondosIt != lEnemigosRedondos.end(); ++lEnemigosRedondosIt)
                {
                    lEnemigosRedondosIt->cuerpo.update(fSegundos);
                }

                for (lEnemigosRectangularesIt = lEnemigosRectangulares.begin(); lEnemigosRectangularesIt != lEnemigosRectangulares.end(); ++lEnemigosRectangularesIt)
                {
                    lEnemigosRectangularesIt->cuerpo.update(fSegundos);
                }

                for (lRectangulosIt = lRectangulos.begin(); lRectangulosIt != lRectangulos.end(); ++lRectangulosIt)
                {
                    lRectangulosIt->cuerpo.update(fSegundos);
                }

                for (lHitboxIt = lHitbox.begin(); lHitboxIt != lHitbox.end(); ++lHitboxIt)
                {
                    lHitboxIt->cuerpo.update(fSegundos);
                }

                FlipperDerecho.cuerpo.update(fSegundos);
                FlipperDerecho.clampPaddle();

                FlipperIzquierdo.cuerpo.update(fSegundos);
                FlipperIzquierdo.clampPaddle();

                clock.restart();
            }

            this->ventana.draw(fondo);

            str_puntaje.setString("PUNTAJE: " + std::to_string(puntaje_total));

            str_bolas_restantes.setString("BOLAS: " + std::to_string(bolas_restantes));

            str_maximo_puntaje.setString("PUNTAJE MAS ALTO: " + std::to_string(puntaje_mas_alto));

            restar_vida();

            if (bolas_restantes <= 0)
            {
                bool_Fin_Juego = true;
            }

            if (puntaje_total > puntaje_mas_alto)
            {
                puntaje_mas_alto = puntaje_total;
            }

            for (lRectangulosIt = lRectangulos.begin(); lRectangulosIt != lRectangulos.end(); ++lRectangulosIt)
            {
                ventana.draw(*lRectangulosIt);
            }

            for (lHitboxIt = lHitbox.begin(); lHitboxIt != lHitbox.end(); ++lHitboxIt)
            {
                ventana.draw(*lHitboxIt);
            }

            for (bolasIterador = bolas.begin(); bolasIterador != bolas.end(); ++bolasIterador)
            {
                this->ventana.draw(*bolasIterador);
            }

            for (lEnemigosRedondosIt = lEnemigosRedondos.begin(); lEnemigosRedondosIt != lEnemigosRedondos.end(); ++lEnemigosRedondosIt)
            {
                ventana.draw(*lEnemigosRedondosIt);
            }

            for (lEnemigosRectangularesIt = lEnemigosRectangulares.begin(); lEnemigosRectangularesIt != lEnemigosRectangulares.end(); ++lEnemigosRectangularesIt)
            {
                ventana.draw(*lEnemigosRectangularesIt);
            }

            this->ventana.draw(FlipperDerecho);

            this->ventana.draw(FlipperIzquierdo);


            if (bool_Fin_Juego)
            {
                bool_En_Juego = false;

                this->ventana.draw(str_fin_juego);

                float  fDelay = sf::seconds(2.0).asSeconds();

                sf::Time now = clock.getElapsedTime();

                printf("%f \n", now.asSeconds());

                if (now.asSeconds() >= fDelay)
                {
                    puntaje_total = 0;
                    bolas_restantes = 3;
                    bool_Fin_Juego = false;
                    clock.restart();
                }
            }

            this->ventana.draw(str_maximo_puntaje);
            this->ventana.draw(str_puntaje);
            this->ventana.draw(str_bolas_restantes);

            this->ventana.display();
        }
        return;
}

void Juego::restar_vida()
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
