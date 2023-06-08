#include "Juego.h"

Juego::Juego()
{
    ///FONDO DEL JUEGO
    TextureManager texturas;
    texturas.cargar_textura("background", "resources\\BackgroundGame.png");
    sf::Sprite fondo;
    fondo.setTexture(texturas.get_textura("background"));
    fondo.setPosition(0, 0);

    ///DECLARACION DE COLORES
    sf::Color azulcito = sf::Color(117,137,191);
    sf::Color cyan = sf::Color(179, 226, 221);
    sf::Color amarillo = sf::Color(255, 237, 81);
    sf::Color naranja = sf::Color(252, 169, 133);
    sf::Color verde = sf::Color(72, 181, 163);

    ///FUENTE DE TEXTO
    sf::Font arcadeFont;
    arcadeFont.loadFromFile("Fonts\\SourceCodePro-Italic-VariableFont_wght.ttf");
    
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
    std::list<Rectangulo> rects;
    std::list<Rectangulo>::iterator rectIt;

    std::list<OBB> obbs;
    std::list<OBB>::iterator obbIt;


    std::list<RoundBumper> roundBumpers;
    std::list<RoundBumper>::iterator roundBumperIt;

    std::list<RectangleBumper> rectangleBumpers;
    std::list<RectangleBumper>::iterator rectBumperIt;

    ///MUROS DEL JUEGO
    Rect topWall = Rect(Vector2D(18, 8.8), Vector2D(17, 0.7), darkBlueCol);
    Rect leftWall = Rect(Vector2D(0.5, 27.5), Vector2D(0.7, 30), darkBlueCol);

    Rect rightWall = Rect(Vector2D(35.5, 27.5), Vector2D(0.7, 30), darkBlueCol);
    Rect topRightCorner = Rect(Vector2D(34.8, 9.8), Vector2D(0.5, 0.5), darkBlueCol);
    Rect tunnel = Rect(Vector2D(32.9, 34), Vector2D(0.2, 21), darkBlueCol);

    ///ENEMIGOS / BUMPERS DEL JUEGO
    RoundBumper roundBumper1 = RoundBumper(Vector2D(10, 13), 1.7, 10, cyanCol);
    RoundBumper roundBumper2 = RoundBumper(Vector2D(27, 16), 1.7, 10, yellowCol);
    RoundBumper largeRoundBumper = RoundBumper(Vector2D(17.5, 21), 2, 10, orangeCol);
    RoundBumper largeRoundBumper2 = RoundBumper(Vector2D(6, 25), 2, 10, yellowCol);
    RoundBumper largeRoundBumper3 = RoundBumper(Vector2D(28, 25), 2, 10, cyanCol);

    ///FLIPPERS
    Flippers FlipperIzquierdo(sf::Vector2f(50.f, 200.f), sf::Vector2f(4.5, 0.6), sf::Vector2f(1.f,1.f), 0.5, sf::Vector2f(30.f,30.f), cyan, false);
    Flippers FlipperDerecho(sf::Vector2f(350.f, 200.f), sf::Vector2f(4.5, 0.6), sf::Vector2f(1.f, 1.f), 0.5, sf::Vector2f(30.f, 30.f), cyan, true);

    
    Rect bottomLeftCorner = Rect(Vector2D(1.3, 37.5), Vector2D(0.5, 0.5), darkBlueCol);
    Rect bottomRightCorner = Rect(Vector2D(32.5, 37.5), Vector2D(0.5, 0.5), darkBlueCol);

    OBB leftRamp = OBB(Vector2D(5.5, 41), Vector2D(6, 0.5), 0.6, darkBlueCol);
    OBB rightRamp = OBB(Vector2D(27.7, 41), Vector2D(6, 0.5), -0.6, darkBlueCol);

    ///ENEMIGOS RECTANGULARES
    RectangleBumper rectBumper1 = RectangleBumper(Vector2D(4.5, 33), Vector2D(0.5, 2), 0.3, 20, darkBlueCol);
    RectangleBumper rectBumper2 = RectangleBumper(Vector2D(30, 33), Vector2D(0.5, 2), -0.3, 20, darkBlueCol);

    rectangleBumpers.push_back(rectBumper1);
    rectangleBumpers.push_back(rectBumper2);

    ///ENEMIGOS CIRCULARES
    roundBumpers.push_back(roundBumper1);
    roundBumpers.push_back(roundBumper2);
    roundBumpers.push_back(largeRoundBumper);
    roundBumpers.push_back(largeRoundBumper2);
    roundBumpers.push_back(largeRoundBumper3);


    rects.push_back(topWall);
    rects.push_back(leftWall);
    rects.push_back(rightWall);
    rects.push_back(tunnel);
    rects.push_back(topRightCorner);

    rects.push_back(bottomLeftCorner);
    rects.push_back(bottomRightCorner);

    obbs.push_back(rightRamp);
    obbs.push_back(leftRamp);


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

                    sf::Vector2f pos = Vector2D(34.f, 55.f);
                    sf::Vector2f vel = Vector2D(0.f, -60.f);
                    sf::Vector2f acc = Vector2D(0.f, 20.f);

                    Bola bola = Bola(pos, vel, acc, 0.9);

                    bola.set_color(sf::Color::Black);

                    bola.push_back(bola);

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

                for (roundBumperIt = roundBumpers.begin(); roundBumperIt != roundBumpers.end(); ++roundBumperIt) {

                    Multiple m = Multiple(&roundBumperIt->cuerpo, &bolasIterador->cuerpo);

                    if (m.CircleVsCircle()) 
                    {
                        puntaje_total += roundBumperIt->getPoints();

                        m.correctPosition();

                        m.applyRotationalImpulse();
                    }
                }

                for (rectBumperIt = rectangleBumpers.begin(); rectBumperIt != rectangleBumpers.end(); ++rectBumperIt) 
                {

                    Multiple m = Multiple(&rectBumperIt->cuerpo, &bolasIterador->cuerpo);

                    if (m.CircleVsOBB()) 
                    {
                        puntaje_total += rectBumperIt->getPoints();

                        m.correctPosition();

                        m.applyRotationalImpulse();
                    }
                }

                for (rectIt = rects.begin(); rectIt != rects.end(); ++rectIt) 
                {

                    Multiple m = Multiple(&rectIt->cuerpo, &bolasIterador->cuerpo);

                    if (m.CircleVsRect()) 
                    {
                        m.correctPosition();

                        m.applyRotationalImpulse();
                    }
                }

                for (obbIt = obbs.begin(); obbIt != obbs.end(); ++obbIt) 
                {
                    Multiple m = Multiple(&obbIt->cuerpo, &bolasIterador->cuerpo);

                    if (m.CircleVsOBB()) 
                    {
                        m.correctPosition();

                        m.applyRotationalImpulse();
                    }
                }

                Multiple FlipperIzquierdo_Manifold = Multiple(&rightPaddle.cuerpo, &bolasIterador->cuerpo);

                if (FlipperIzquierdo_Manifold.CircleVsOBB())
                {
                    FlipperIzquierdo_Manifold.correctPosition();

                    FlipperIzquierdo_Manifold.applyRotationalImpulse();
                }

                Multiple FlipperDerecho_Manifold = Multiple(&leftPaddle.cuerpo, &bolasIterador->cuerpo);

                if (FlipperDerecho_Manifold.CircleVsOBB()) 
                {
                    FlipperDerecho_Manifold.correctPosition();

                    FlipperDerecho_Manifold.applyRotationalImpulse();
                }

                bolasIterador->cuerpo.update(fSegundos);
            }

            for (roundBumperIt = roundBumpers.begin(); roundBumperIt != roundBumpers.end(); ++roundBumperIt) 
            {
                roundBumperIt->cuerpo.update(fSegundos);
            }

            for (rectBumperIt = rectangleBumpers.begin(); rectBumperIt != rectangleBumpers.end(); ++rectBumperIt)
            {
                rectBumperIt->cuerpo.update(fSegundos);
            }

            for (rectIt = rects.begin(); rectIt != rects.end(); ++rectIt)
            {
                rectIt->cuerpo.update(fSegundos);
            }

            for (obbIt = obbs.begin(); obbIt != obbs.end(); ++obbIt) 
            {
                obbIt->cuerpo.update(fSegundos);
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
        
        for (rectIt = rects.begin(); rectIt != rects.end(); ++rectIt)
        {
            ventana.draw(*rectIt);
        }

        for (obbIt = obbs.begin(); obbIt != obbs.end(); ++obbIt)
        {
            ventana.draw(*obbIt);
        }
        
        for (bolasIterador = bolas.begin(); bolasIterador != bolas.end(); ++bolasIterador)
        {
            this->ventana.draw(*bolasIterador);
        }
        
        for (roundBumperIt = roundBumpers.begin(); roundBumperIt != roundBumpers.end(); ++roundBumperIt)
        {
            ventana.draw(*roundBumperIt);
        }

        for (rectBumperIt = rectangleBumpers.begin(); rectBumperIt != rectangleBumpers.end(); ++rectBumperIt)
        {
            ventana.draw(*rectBumperIt);
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

        if (bolasIterador->cuerpo.getPosicion().y() > 60) 
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
