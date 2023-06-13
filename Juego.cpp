#include "Juego.h"

std::list<Bola> bolas;
std::list<Bola>::iterator bolasIterador;

void Juego::InitJuego()
{
    ///JUEGO
    //Determina si la bola est� en juego
    this->bool_En_Juego = false;
    //Determina si el juego sigue o no
    this->bool_Fin_Juego = false;

    this->puntaje_total = 0;

    this->bolas_restantes = 3;

    this->puntaje_mas_alto = 0;


    ///FUENTE DE TEXTO
    this->fuente_de_texto.loadFromFile("Fonts\\SourceCodePro-Italic-VariableFont_wght.ttf");

    ///VENTANA
    this->video_mode.width = 720;
    this->video_mode.height = 980;

    this->ventana.create(this->video_mode, "KloosterBallGame", sf::Style::Default);
}

Juego::Juego()
{
    InitJuego();
}

Juego::~Juego()
{
    this->ventana.close();
}

bool Juego::primer_nivel()
{
        ///FONDO DEL NIVEL
        TextureManager texturas;
        texturas.cargar_textura("background", "resources\\BackgroundGame.png");
        
        sf::Sprite fondo;
        //fondo.setTexture(texturas.get_textura("background"));
        fondo.setPosition(0, 0);
       

        ///DECLARACION DE COLORES DEL NIVEL
        sf::Color azulcito = sf::Color(117, 137, 191);
        sf::Color cyan = sf::Color(179, 226, 221);
        sf::Color amarillo = sf::Color(255, 237, 81);
        sf::Color naranja = sf::Color(252, 169, 133);
        sf::Color verde = sf::Color(72, 181, 163);

        ///MENSAJES EN PANTALLA
        sf::Text str_maximo_puntaje = sf::Text("MAXPUNTOS:" + std::to_string(puntaje_mas_alto), fuente_de_texto, 40);
        str_maximo_puntaje.setFillColor(verde);
        str_maximo_puntaje.setPosition(40, 5);

        sf::Text str_puntaje = sf::Text("PUNTOS:" + std::to_string(puntaje_total), fuente_de_texto, 40);
        str_puntaje.setFillColor(verde);
        str_puntaje.setPosition(40, 80);

        sf::Text str_bolas_restantes = sf::Text("BOLAS:" + std::to_string(bolas_restantes), fuente_de_texto, 40);
        str_bolas_restantes.setFillColor(verde);
        str_bolas_restantes.setPosition(500, 5);

        sf::Text str_fin_juego = sf::Text("FIN DEL JUEGO", fuente_de_texto, 150);
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
        Rectangulo muro_superior = Rectangulo(sf::Vector2f(18.f, 8.8f) /*ORIGEN*/, sf::Vector2f(17.f, 0.7f)/*EXTENSION MEDIA*/, azulcito/*COLOR*/);

        Rectangulo muro_izquierdo = Rectangulo(sf::Vector2f(0.5f, 27.5f), sf::Vector2f(0.7f, 30.f), azulcito);

        Rectangulo muro_derecho = Rectangulo(sf::Vector2f(35.5f, 27.5f), sf::Vector2f(0.7f, 30.f), azulcito);

        Rectangulo esquina_superior_derecha = Rectangulo(sf::Vector2f(34.8f, 9.8f), sf::Vector2f(0.5f, 0.5f), azulcito);

        Rectangulo esquina_inferior_izquierda = Rectangulo(sf::Vector2f(1.3f, 37.5f), sf::Vector2f(0.5f, 0.5f), azulcito);

        Rectangulo esquina_inferior_derecha = Rectangulo(sf::Vector2f(32.5f, 37.5f), sf::Vector2f(0.5f, 0.5f), azulcito);

        Rectangulo tunel = Rectangulo(sf::Vector2f(30.9f, 34.f), sf::Vector2f(0.2f, 21.f), azulcito);

        ///ENEMIGOS / BUMPERS DEL JUEGO
        EnemigoRedondo eRedondo1 = EnemigoRedondo(sf::Vector2f(10.f, 13.f)/*Posicion*/, 1.7f/*Radio*/, 10/*Puntos*/, cyan/*Color*/);

        EnemigoRedondo eRedondo2 = EnemigoRedondo(sf::Vector2f(27.f, 16.f), 1.7f, 10, amarillo);

        EnemigoRedondo eRedondoGrande1 = EnemigoRedondo(sf::Vector2f(17.5f, 21.f), 2.f, 10, verde);

        EnemigoRedondo eRedondoGrande2 = EnemigoRedondo(sf::Vector2f(6.f, 25.f), 2.f, 10, amarillo);

        EnemigoRedondo eRedondoGrande3 = EnemigoRedondo(sf::Vector2f(28.f, 25.f), 2.f, 10, cyan);

        ///FLIPPERS
        Flippers FlipperIzquierdo(sf::Vector2f(10.f, 44.5f)/*Posicion*/, 0.5f/*Angulo*/, sf::Vector2f(4.5, 0.6f)/*Extension media*/, cyan/*Color*/, true/*EnladoIzquierdo*/);

        Flippers FlipperDerecho(sf::Vector2f(23.f, 44.5f)/*Posicion*/, 0.5f/*Angulo*/, sf::Vector2f(4.5f, 0.6f)/*Extension media*/, cyan/*Color*/, false/*EnladoIzquierdo*/);

        //RAMPAS
        HitBox rampaIzquierda = HitBox(sf::Vector2f(5.5f, 41.f), sf::Vector2f(6.f, 0.5f), 0.6f, azulcito);

        HitBox rampaDerecha = HitBox(sf::Vector2f(27.7f, 41.f), sf::Vector2f(6.f, 0.5f), -0.6f, azulcito);

        ///ENEMIGOS RECTANGULARES
        EnemigoRectangular eRectangular1 = EnemigoRectangular(sf::Vector2f(4.5f, 33.f), sf::Vector2f(0.5f, 2.f), 0.3f, 20, azulcito);

        EnemigoRectangular eRectangular2 = EnemigoRectangular(sf::Vector2f(30.f, 33.f), sf::Vector2f(0.5f, 2.f), -0.3f, 20, azulcito);

        ///Pusheos de los objetos �? xd
        lEnemigosRectangulares.push_back(eRectangular1);    
        lEnemigosRectangulares.push_back(eRectangular2);

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

                //EventosTeclas(FlipperIzquierdo, FlipperDerecho);
                //Al llamar a EventosTeclas se buguea la bola y al lanzarla todo se rompe
                //Al dejarlo como est� ahora, la bola se choca con algo invisible y no funciona

                if (this->evento.type == sf::Event::Closed)
                {
                    this->ventana.close();
                }
                else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape)
                {
                    this->ventana.close();
                }
                else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Space)
                {
                    if (!bool_En_Juego /*la bola no est� en juego*/ && !bool_Fin_Juego/*el juego no termin�*/)
                    {
                        std::cout << "Detecta que no hay bola y lanza otra" << std::endl;

                        sf::Vector2f posicion = sf::Vector2f(34.f, 50.f);

                        sf::Vector2f velocidad = sf::Vector2f(0.f, -60.f);

                        sf::Vector2f aceleracion = sf::Vector2f(0.f, 20.f);

                        Bola bola = Bola(posicion, velocidad, aceleracion, 0.9f);

                        bola.set_color(sf::Color::White);

                        bolas.push_back(bola);

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

            sf::Time intervalo_tiempo = clock.getElapsedTime();

            const unsigned int tiempo_transcurrido = intervalo_tiempo.asMilliseconds();

            if (tiempo_transcurrido >= 10 && !bool_Fin_Juego)
            {
                const float fSegundos = intervalo_tiempo.asSeconds();

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

                    for (lEnemigosRedondosIt = lEnemigosRedondos.begin(); lEnemigosRedondosIt != lEnemigosRedondos.end(); ++lEnemigosRedondosIt) {

                        Multiple m = Multiple(&lEnemigosRedondosIt->cuerpo, &bolasIterador->cuerpo);

                        if (m.CirculoVsCirculo())
                        {
                            puntaje_total += lEnemigosRedondosIt->get_puntos();

                            m.correctPosition();

                            m.aplicarImpulsoRotacional();
                        }
                    }

                    for (lEnemigosRectangularesIt = lEnemigosRectangulares.begin(); lEnemigosRectangularesIt != lEnemigosRectangulares.end(); ++lEnemigosRectangularesIt)
                    {

                        Multiple m = Multiple(&lEnemigosRectangularesIt->cuerpo, &bolasIterador->cuerpo);

                        if (m.CirculoVsOBB())
                        {
                            puntaje_total += lEnemigosRectangularesIt->get_puntos();

                            m.correctPosition();

                            m.aplicarImpulsoRotacional();
                        }
                    }

                    for (lRectangulosIt = lRectangulos.begin(); lRectangulosIt != lRectangulos.end(); ++lRectangulosIt)
                    {

                        Multiple m = Multiple(&lRectangulosIt->cuerpo, &bolasIterador->cuerpo);

                        if (m.CirculoVsRectangulo())
                        {
                            m.correctPosition();

                            m.aplicarImpulsoRotacional();
                        }
                    }

                    for (lHitboxIt = lHitbox.begin(); lHitboxIt != lHitbox.end(); ++lHitboxIt)
                    {
                        Multiple m = Multiple(&lHitboxIt->cuerpo, &bolasIterador->cuerpo);

                        if (m.CirculoVsOBB())
                        {
                            m.correctPosition();

                            m.aplicarImpulsoRotacional();
                        }
                    }

                    Multiple FlipperIzquierdo_Manifold = Multiple(&FlipperDerecho.cuerpo, &bolasIterador->cuerpo);

                    if (FlipperIzquierdo_Manifold.CirculoVsOBB())
                    {
                        FlipperIzquierdo_Manifold.correctPosition();

                        FlipperIzquierdo_Manifold.aplicarImpulsoRotacional();
                    }

                    Multiple FlipperDerecho_Manifold = Multiple(&FlipperIzquierdo.cuerpo, &bolasIterador->cuerpo);

                    if (FlipperDerecho_Manifold.CirculoVsOBB())
                    {
                        FlipperDerecho_Manifold.correctPosition();

                        FlipperDerecho_Manifold.aplicarImpulsoRotacional();
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

            str_puntaje.setString("PUNTOS:" + std::to_string(puntaje_total));

            str_bolas_restantes.setString("BOLAS:" + std::to_string(bolas_restantes));

            str_maximo_puntaje.setString("MAXPUNTOS:" + std::to_string(puntaje_mas_alto));

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
    return false;
}

void Juego::EventosTeclas(Flippers& fliper_1, Flippers& fliper_2)
{
    if (this->evento.type == sf::Event::Closed)
    {
        bool_En_Juego = false;
        bool_Fin_Juego = true;
        this->ventana.close();
    }
    else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape)
    {
        bool_En_Juego = false;
        bool_Fin_Juego = true;
        this->ventana.close();
    }
    else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Space)
    {
        if (!bool_En_Juego /*la bola no est� en juego*/ && !bool_Fin_Juego/*el juego no termin�*/)
        {
            std::cout << "Detecta que no hay bola y lanza otra" << std::endl;

            sf::Vector2f posicion = sf::Vector2f(34.f, 50.f);

            sf::Vector2f velocidad = sf::Vector2f(0.f, -60.f);

            sf::Vector2f aceleracion = sf::Vector2f(0.f, 20.f);

            Bola bola = Bola(posicion, velocidad, aceleracion, 0.9f);

            bola.set_color(sf::Color::White);

            bolas.push_back(bola);

            bool_En_Juego = true;
        }
    }
    else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Z)
    {
        fliper_1.Mover("arriba");
    }
    else if (this->evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::X)
    {
        fliper_2.Mover("arriba");
    }
    else if (this->evento.type == sf::Event::KeyReleased && evento.key.code == sf::Keyboard::Z)
    {
        fliper_1.Mover("abajo");
    }
    else if (this->evento.type == sf::Event::KeyReleased && evento.key.code == sf::Keyboard::X)
    {
        fliper_2.Mover("abajo");
    }
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
