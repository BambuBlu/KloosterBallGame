#include "Juego.h"

Juego::Juego()
{
    TextureManager texturas;
    texturas.loadTexture("background", "resources\\BackgroundGame.png");

    sf::Sprite fondo;
    fondo.setTexture(texturas.getTexture("background"));
    fondo.setPosition(0, 0);

    
    sf::Color azulcito = sf::Color(117,137,191);
    sf::Color cyan = sf::Color(179, 226, 221);
    sf::Color amarillo = sf::Color(255, 237, 81);
    sf::Color naranja = sf::Color(252, 169, 133);
    sf::Color verde = sf::Color(72, 181, 163);


    sf::Font arcadeFont;

    arcadeFont.loadFromFile("Fonts\\SourceCodePro-Italic-VariableFont_wght.ttf");


    sf::Text str_maximo_puntaje = sf::Text("MAXIMO PUNTAJE: " + std::to_string(puntaje_mas_alto), arcadeFont, 60);
    str_maximo_puntaje.setFillColor(redCol);
    str_maximo_puntaje.setPosition(40, 5);

    sf::Text str_puntaje = sf::Text("PUNTAJE: " + std::to_string(puntaje_total), arcadeFont, 60);
    str_puntaje.setFillColor(redCol);
    str_puntaje.setPosition(40, 80);

    sf::Text str_bolas_restantes = sf::Text("BOLAS: " + std::to_string(bolas_restantes), arcadeFont, 60);
    str_bolas_restantes.setFillColor(redCol);
    str_bolas_restantes.setPosition(500, 5);

    sf::Text str_fin_juego = sf::Text("FIN DEL JUEGO", arcadeFont, 150);
    str_fin_juego.setFillColor(sf::Color::Black);
    str_fin_juego.setPosition(100, 400);

    /*
    Randomiser rand;

    std::list<Rect> rects;
    std::list<Rect>::iterator rectIt;

    std::list<OBB> obbs;
    std::list<OBB>::iterator obbIt;


    std::list<RoundBumper> roundBumpers;
    std::list<RoundBumper>::iterator roundBumperIt;

    std::list<RectangleBumper> rectangleBumpers;
    std::list<RectangleBumper>::iterator rectBumperIt;

    Rect topWall = Rect(Vector2D(18, 8.8), Vector2D(17, 0.7), darkBlueCol);
    Rect leftWall = Rect(Vector2D(0.5, 27.5), Vector2D(0.7, 30), darkBlueCol);

    Rect rightWall = Rect(Vector2D(35.5, 27.5), Vector2D(0.7, 30), darkBlueCol);
    Rect topRightCorner = Rect(Vector2D(34.8, 9.8), Vector2D(0.5, 0.5), darkBlueCol);
    Rect tunnel = Rect(Vector2D(32.9, 34), Vector2D(0.2, 21), darkBlueCol);

    RoundBumper roundBumper1 = RoundBumper(Vector2D(10, 13), 1.7, 10, cyanCol);
    RoundBumper roundBumper2 = RoundBumper(Vector2D(27, 16), 1.7, 10, yellowCol);
    RoundBumper largeRoundBumper = RoundBumper(Vector2D(17.5, 21), 2, 10, orangeCol);
    RoundBumper largeRoundBumper2 = RoundBumper(Vector2D(6, 25), 2, 10, yellowCol);
    RoundBumper largeRoundBumper3 = RoundBumper(Vector2D(28, 25), 2, 10, cyanCol);
    */

    Flippers FlipperIzquierdo = Flippers(sf::Vector2f(10, 44.5), sf::Vector2f(4.5, 0.6), 0.5, true, cyanCol);

    Flippers FlipperDerecho = Flippers(sf::Vector2f(23, 44.5), sf::Vector2f(4.5, 0.6), 0.5, false, cyanCol);

    /*
    Rect bottomLeftCorner = Rect(Vector2D(1.3, 37.5), Vector2D(0.5, 0.5), darkBlueCol);
    Rect bottomRightCorner = Rect(Vector2D(32.5, 37.5), Vector2D(0.5, 0.5), darkBlueCol);

    OBB leftRamp = OBB(Vector2D(5.5, 41), Vector2D(6, 0.5), 0.6, darkBlueCol);
    OBB rightRamp = OBB(Vector2D(27.7, 41), Vector2D(6, 0.5), -0.6, darkBlueCol);

    RectangleBumper rectBumper1 = RectangleBumper(Vector2D(4.5, 33), Vector2D(0.5, 2), 0.3, 20, darkBlueCol);
    RectangleBumper rectBumper2 = RectangleBumper(Vector2D(30, 33), Vector2D(0.5, 2), -0.3, 20, darkBlueCol);

    rectangleBumpers.push_back(rectBumper1);
    rectangleBumpers.push_back(rectBumper2);

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

    //obbs.push_back(testOBB);
    */

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

                    bola.setColor(sf::Color::Black);

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
                        Manifold m = Manifold(&bolasIterador->body, &p->body);

                        if (m.CircleVsCircle()) 
                        {
                            m.correctPosition();
                            m.applyRotationalImpulse();
                        }
                    }
                }

                for (roundBumperIt = roundBumpers.begin(); roundBumperIt != roundBumpers.end(); ++roundBumperIt) {

                    Manifold m = Manifold(&roundBumperIt->body, &bolasIterador->body);

                    if (m.CircleVsCircle()) 
                    {
                        puntaje_total += roundBumperIt->getPoints();

                        m.correctPosition();

                        m.applyRotationalImpulse();
                    }
                }

                for (rectBumperIt = rectangleBumpers.begin(); rectBumperIt != rectangleBumpers.end(); ++rectBumperIt) 
                {

                    Manifold m = Manifold(&rectBumperIt->body, &bolasIterador->body);

                    if (m.CircleVsOBB()) 
                    {
                        puntaje_total += rectBumperIt->getPoints();

                        m.correctPosition();

                        m.applyRotationalImpulse();
                    }
                }

                for (rectIt = rects.begin(); rectIt != rects.end(); ++rectIt) 
                {

                    Manifold m = Manifold(&rectIt->body, &bolasIterador->body);

                    if (m.CircleVsRect()) 
                    {
                        m.correctPosition();

                        m.applyRotationalImpulse();
                    }
                }

                for (obbIt = obbs.begin(); obbIt != obbs.end(); ++obbIt) 
                {
                    Manifold m = Manifold(&obbIt->body, &bolasIterador->body);

                    if (m.CircleVsOBB()) 
                    {
                        m.correctPosition();

                        m.applyRotationalImpulse();
                    }
                }

                Manifold FlipperIzquierdo_Manifold = Manifold(&rightPaddle.body, &bolasIterador->body);

                if (FlipperIzquierdo_Manifold.CircleVsOBB())
                {
                    FlipperIzquierdo_Manifold.correctPosition();

                    FlipperIzquierdo_Manifold.applyRotationalImpulse();
                }

                Manifold FlipperDerecho_Manifold = Manifold(&leftPaddle.body, &bolasIterador->body);

                if (FlipperDerecho_Manifold.CircleVsOBB()) 
                {
                    FlipperDerecho_Manifold.correctPosition();

                    FlipperDerecho_Manifold.applyRotationalImpulse();
                }

                bolasIterador->body.update(fSegundos);
            }

            for (roundBumperIt = roundBumpers.begin(); roundBumperIt != roundBumpers.end(); ++roundBumperIt) 
            {
                roundBumperIt->body.update(fSegundos);
            }

            for (rectBumperIt = rectangleBumpers.begin(); rectBumperIt != rectangleBumpers.end(); ++rectBumperIt)
            {
                rectBumperIt->body.update(fSegundos);
            }

            for (rectIt = rects.begin(); rectIt != rects.end(); ++rectIt)
            {
                rectIt->body.update(fSegundos);
            }

            for (obbIt = obbs.begin(); obbIt != obbs.end(); ++obbIt) 
            {
                obbIt->body.update(fSegundos);
            }

            FlipperDerecho.body.update(fSegundos);
            FlipperDerecho.clampPaddle();

            FlipperIzquierdo.body.update(fSegundos);
            FlipperIzquierdo.clampPaddle();

            clock.restart();
        }

        this->ventana.draw(fondo);

        str_puntaje.setString("PUNTAJE: " + std::to_string(puntaje_total));

        str_bolas_restantes.setString("BOLAS: " + std::to_string(bolas_restantes));

        str_maximo_puntaje.setString("PUNTAJE MAS ALTO: " + std::to_string(puntaje_mas_alto));

        loseLife();

        if (bolas_restantes <= 0) 
        {
            bool_Fin_Juego = true;
        }

        if (puntaje_total > puntaje_mas_alto) 
        {
            puntaje_mas_alto = puntaje_total;
        }
        /*
        for (rectIt = rects.begin(); rectIt != rects.end(); ++rectIt)
        {
            window.draw(*rectIt);
        }

        for (obbIt = obbs.begin(); obbIt != obbs.end(); ++obbIt)
        {
            window.draw(*obbIt);
        }
        */
        for (bolasIterador = bolas.begin(); bolasIterador != bolas.end(); ++bolasIterador)
        {
            this->ventana.draw(*bolasIterador);
        }
        /*
        for (roundBumperIt = roundBumpers.begin(); roundBumperIt != roundBumpers.end(); ++roundBumperIt)
        {
            window.draw(*roundBumperIt);
        }

        for (rectBumperIt = rectangleBumpers.begin(); rectBumperIt != rectangleBumpers.end(); ++rectBumperIt)
        {
            window.draw(*rectBumperIt);
        }
        */

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

    for (bolasIterador = bolas.begin(); bolasIterador != bolas.end();) {

        if (bolasIterador->cuerpo.getPosicion().y() > 60) {

            bolasIterador = bolas.erase(bolasIterador);
            bolas_restantes--;
            bool_En_Juego = false;
        }
        else {
            ++bolasIterador;
        }
    }
}
