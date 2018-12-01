//
// Created by zero on 30/11/18.
//

#include "Game.h"
#include "Player.h"

Game::Game()
: Scene("resources/images/back_game.png"){
    vidas = 100;                         //vidas fue declarado en el private
    puntaje = -126;
    progreso = 0;
    nivel = 1;
    freeze = false;
    game = true;
    ts = TS;
}

void Game::init() {
    Scene::init();
    Entities *player = new Player();
    currentPlayer = reinterpret_cast<Player *>(player);
    Scene::addEntity(player);

    font.loadFromFile("cabeza.TTF");

    string stringArray[] = {"Vidas:  ", "Score:  ", "Progreso:", "Nivel:", to_string(puntaje), to_string(vidas), to_string(progreso), to_string(nivel)};

    for(int i = 0; i < 8; i++)
        textArray.push_back(Text(stringArray[i], font, 18));

    crearMapa();
}

void Game::onRender(sf::RenderWindow &window) {
    Scene::onRender(window);

    for(auto iter = textArray.begin(); iter != textArray.end(); iter++)
        window.draw(*iter);

}

void Game::onEvent(sf::Event &event) {
    Scene::onEvent(event);

    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        (currentPlayer)->moveLeft();
        (currentPlayer)->setNewTexture("resources/images/tiles2.png");
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        (currentPlayer)->moveRight();
        (currentPlayer)->setNewTexture("resources/images/tiles1.png");
    }
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        (currentPlayer)->moveUp();
        (currentPlayer)->setNewTexture("resources/images/tiles3.png");
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        (currentPlayer)->moveDown();
        (currentPlayer)->setNewTexture("resources/images/tiles4.png");
    }

    if (event.type == Event::KeyPressed)
        if (event.key.code == Keyboard::Escape) {
            for (int i = 1; i < M - 1; i++)
                for (int j = 1; j < N - 1; j++)
                    mapa[i][j] = 0;
            game = true;
            //sound.stop();
        }
    if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::P) {
            //n = n * (-1);
        }
    }
}

int Game::nextView() {
    return Scene::nextView();
}

void Game::onUpdate() {

    string stringArray[] = {"Vidas:  ", "Score:  ", "Progreso:", "Nivel:", to_string(puntaje), to_string(vidas), to_string(progreso), to_string(nivel)};

    for(int i = 0; i < 8; i++)
    {
        textArray[i] = Text(stringArray[i], font, 18);
        textArray[i].setPosition(textPosX[i], textPosY[i]);

        if (i < 4)
            textArray[i].setFillColor(Color::Yellow);
        else
            textArray[i].setFillColor(Color::White);
    }


    //qué son estos? -> reemplazar por el size()
    int enemyCount = 4;
    int enemy2222 = 4;

    //set timer
    double timer = 0;

    float effectTimerPlatano = 0;
    float effectTimerHelado = 0;


    int n = 1;
    //loop del juego
    while (window.isOpen()) {

        //uso del timer (para que la velocidad funcione bien)
        timer += clock.getElapsedTime().asSeconds();
        clock.restart();


        if (!Game) continue;

        if (timer > jugador->getVelocidad()) {
            jugador->opConMyN();

            bool aaa = true;

            if (mapa[jugador->gety()][jugador->getx()] == 2) {
                for (int i = 0; i < M; i++)
                    for (int j = 0; j < N; j++)
                        if (mapa[i][j] == 2) {
                            mapa[i][j] = 0;
                        };

                mapa[jugador->gety()][jugador->getx()] = 0;
                Game = false;
                aaa = false;
            }
            if (mapa[jugador->gety()][jugador->getx()] == 0) if (aaa == true) mapa[jugador->gety()][jugador->getx()] = 2;
            timer = 0;
        }

        //mover a los enemigos
        if (freeze == false) {
            for (int i = 0; i < enemyCount; i++) arrayEnemy1[i].move();

            for (int j = 0; j < enemy2222; j++) arrayEnemy2[j].move();
        }

        //parte posiblemente relacionada con las posiciones y relleno - en todo caso, IMPORTANTE!
        if (mapa[jugador->gety()][jugador->getx()] == 1) {
            jugador->resetDxDy();

            //rellena los tiles
            for (int i = 0; i < enemyCount; i++)
                rellenarTiles((arrayEnemy1[i]).gety() / ts, (arrayEnemy2[i]).getx() / ts);

            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                    if (mapa[i][j] == -1) mapa[i][j] = 0;
                    else mapa[i][j] = 1;
        }

        for (int i = 0; i < enemyCount; i++) {

            if (mapa[arrayEnemy1[i].gety() / ts][arrayEnemy1[i].getx() / ts] == 2) {
                for (int i = 0; i < M; i++)
                    for (int j = 0; j < N; j++)
                        if (mapa[i][j] == 2) mapa[i][j] = 0;
                Game = false;

            }
        }
        /////////draw//////////


        //determina el puntaje
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
            {
                if (mapa[i][j] == 1) {
                    puntaje = puntaje + 1;
                }

                if (mapa[i][j] == 0) continue;
                if (mapa[i][j] == 1) sPlayer.setTextureRect(IntRect(0, 0, ts, ts));
                if (mapa[i][j] == 2) sPlayer.setTextureRect(IntRect(54, 0, ts, ts));
                if (mapa[i][j] == 3) sPlayer.setTextureRect(IntRect(72, 0, ts, ts));
                sPlayer.setPosition(j * ts, i * ts);

            }

        //no es lo mismo que el anterior? qué hace?
        sPlayer.setTextureRect(IntRect(18, 0, ts, ts));
        sPlayer.setPosition(jugador->getx()*ts, jugador->gety()*ts);


        progreso = progreso + puntaje * 100 / 874;

        for (int i = 0; i < enemyCount; i++) {
            sEnemy.setPosition(arrayEnemy1[i].getx(), arrayEnemy1[i].gety());
            window.draw(sEnemy);
        }
        for (int j = 0; j < enemyCount; j++) {
            senemy2.setPosition(arrayEnemy2[j].getx(), arrayEnemy2[j].gety());
            window.draw(senemy2);
        }

        //aparición de los drops
        if (puntaje > 100 && Platano.fueUsado() == true) {
            window.draw(sPlatano);
        }
        if (puntaje > 300 && Helado.fueUsado() == true) {
            window.draw(sHelado);
        }

        //Efectos del plátano (añadir instrucciones al inicio?)
        if (jugador->getx() == Platano.getx() / 18 && jugador->gety() == Platano.gety() / 18) {
            Platano.usar();
            jugador->setVelocidad(0.04);
            effectTimerPlatano = timer;
        }

        //tiempo de uso del platano y vuelta a velocidad normal
        if (!Platano.fueUsado() && effectTimerPlatano < 1) {
            effectTimerPlatano += 0.001;
        }
        else if (!Platano.fueUsado() && effectTimerPlatano == 1) {
            jugador->setVelocidad(0.07);
        }

        //Efectos del helado
        if (puntaje > 300 && jugador->getx() == Helado.getx() / 18 && jugador->gety() == Helado.gety() / 18) {
            Helado.usar();
            effectTimerHelado = timer;
            freeze = true;
        }

        //tiempo de uso del helado y vuelta a movimiento
        if (!Helado.fueUsado() && effectTimerHelado < 1) {
            effectTimerHelado += 0.005;
        }
        else if (!Helado.fueUsado() && effectTimerHelado >= 1) {
            freeze = false;
        }

        //matienen los muros protegidos
        for (int x = 0; x < 25; x++) {
            if (mapa[x][0] != 1) {
                mapa[x][0] = 1;
            }
            if (mapa[x][39] != 1) {
                mapa[x][39] = 1;
            }
        }


        //¿final del juego? no queda claro por qué hay dos casus
        if (progreso > 80) {
            swin.play();
            sganaste.setOrigin(-130, -110);
            window.draw(sganaste);
            Game = false;
            sound.pause();
            vidas = vidas + 1;
            nivel = nivel + 1;

        }
        if (vidas > 0) {
            if (!Game) {
                vidas = vidas - 1;
                cadena = to_string(vidas);
                if (vidas > 0) {
                    ssmuerte.play();
                }
                jugador->setx(0); jugador->sety(0);
                Game = true;
            }
        }
        else {
            sGameover.setOrigin(-130, -110);
            window.draw(sGameover);
            sound.pause();
            ssgaov.play();
            Game = false;
        }

        //no quitar - se bugea feo
        progreso = 0;
        puntaje = -126;
    }



}
