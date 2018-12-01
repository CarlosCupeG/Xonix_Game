//
// Created by zero on 30/11/18.
//

#include "Game.h"

Game::Game()
: Scene("resources/images/back_game.png"){
    vidas = 100;                         //vidas fue declarado en el private
    puntaje = -126;
    progreso = 0;
    nivel = 1;
    timer = 0;
    freeze = false;
    game = true;
    ts = TS;
}

void Game::init() {
    Scene::init();
    Entities *player = new Player();
    Entities *enemy_1 = new EnemyA();
    Entities *enemy_2 = new EnemyA();
    Entities *enemy_3 = new EnemyA();
    Entities *enemy_4 = new EnemyA();
    Entities *enemy_5 = new EnemyB();
    Entities *enemy_6 = new EnemyB();
    Entities *enemy_7 = new EnemyB();
    Entities *enemy_8 = new EnemyB();
    Entities *helado_9 = new Drops();
    Entities *platano_10 = new Drops();

    currentPlayer = reinterpret_cast<Player *>(player);
    helado = reinterpret_cast<Drops *>(helado_9);
    platano = reinterpret_cast<Drops *>(platano_10);
    Scene::addEntity(player);
    Scene::addEntity(enemy_1);
    Scene::addEntity(enemy_2);
    Scene::addEntity(enemy_3);
    Scene::addEntity(enemy_4);
    Scene::addEntity(enemy_5);
    Scene::addEntity(enemy_6);
    Scene::addEntity(enemy_7);
    Scene::addEntity(enemy_8);
    Scene::addEntity(helado_9);
    Scene::addEntity(platano_10);


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

    timer += clock.getElapsedTime().asSeconds();
    clock.restart();

    if (timer > currentPlayer->getVelocidad()) {
        currentPlayer->opConMyN();

        bool aaa = true;

        if (mapa[currentPlayer->gety()][currentPlayer->getx()] == 2) {
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                    if (mapa[i][j] == 2) {
                        mapa[i][j] = 0;
                    };

            mapa[currentPlayer->gety()][currentPlayer->getx()] = 0;
            game = false;
            aaa = false;
        }
        if (mapa[currentPlayer->gety()][currentPlayer->getx()] == 0) if (aaa == true) mapa[currentPlayer->gety()][currentPlayer->getx()] = 2;
        timer = 0;
    }

    if (freeze == false) {
        for (int i = 1; i < 5; i++) entity[i]->onUpdate();

        for (int j = 5; j < 9; j++) entity[j]->onUpdate();
    }

    //parte posiblemente relacionada con las posiciones y relleno
    if (mapa[currentPlayer->gety()][currentPlayer->getx()] == 1) {
        currentPlayer->resetDxDy();

        //rellena los tiles
        for (int i = 0; i < 5; i++)
            rellenarTiles((entity[i + 1])->gety() / ts, (entity[i + 5])->getx() / ts);

        for (auto &i : mapa) {
            for (int &j : i)
                if (j == -1) j = 0;
                else j = 1;
        }

    }

    for (int i = 0; i < 5; i++) {

        if (mapa[entity[i + 1]->gety() / ts][entity[i + 5]->getx() / ts] == 2) {
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                    if (mapa[i][j] == 2) mapa[i][j] = 0;
            game = false;

        }
    }


    //determina el puntaje
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
        {
            if (mapa[i][j] == 1) {
                puntaje = puntaje + 1;
            }

            if (mapa[i][j] == 0) continue;
            if (mapa[i][j] == 1) (currentPlayer)->setTextureRect(IntRect(0, 0, ts, ts));
            if (mapa[i][j] == 2) (currentPlayer)->setTextureRect(IntRect(54, 0, ts, ts));
            if (mapa[i][j] == 3) (currentPlayer)->setTextureRect(IntRect(72, 0, ts, ts));
            (currentPlayer)->setPosition(j * ts, i * ts);
        }

    (currentPlayer)->setTextureRect(IntRect(18, 0, ts, ts));
    (currentPlayer)->setPosition((currentPlayer)->getx()*ts, (currentPlayer)->gety()*ts);

    progreso = progreso + puntaje * 100 / 874;




    //matienen los muros protegidos
    for (int x = 0; x < 25; x++) {
        if (mapa[x][0] != 1) {
            mapa[x][0] = 1;
        }
        if (mapa[x][39] != 1) {
            mapa[x][39] = 1;
        }
    }

    platano->setPuntaje(puntaje > 100);
    helado->setPuntaje(puntaje > 300);

    //Efectos del plátano (añadir instrucciones al inicio?)
    if ((currentPlayer)->getx() == platano->getx() / 18 && (currentPlayer)->gety() == platano->gety() / 18) {
        platano->usar();
        (currentPlayer)->setVelocidad(0.04);
        effectTimerPlatano = timer;
    }

    //tiempo de uso del platano y vuelta a velocidad normal
    if (platano->fueUsado() && effectTimerPlatano < 1) {
        effectTimerPlatano += 0.001;
    }
    else if (!platano->fueUsado() && effectTimerPlatano == 1) {
        (currentPlayer)->setVelocidad(0.07);
    }

    //Efectos del helado
    if (puntaje > 300 && (currentPlayer)->getx() == helado->getx() / 18 && (currentPlayer)->gety() == helado->gety() / 18) {
        helado->usar();
        effectTimerHelado = timer;
        freeze = true;
    }

    //tiempo de uso del helado y vuelta a movimiento
    if (!helado->fueUsado() && effectTimerHelado < 1) {
        effectTimerHelado += 0.005;
    }
    else if (!helado->fueUsado() && effectTimerHelado >= 1) {
        freeze = false;
    }



    //¿final del juego? no queda claro por qué hay dos casus
    if (progreso > 80) {
        //swin.play();
        //sganaste.setOrigin(-130, -110);
        //window.draw(sganaste);
        game = false;
        //sound.pause();
        vidas = vidas + 1;
        nivel = nivel + 1;

    }
    if (vidas > 0) {
        if (!game) {
            vidas = vidas - 1;
            if (vidas > 0) {
                //ssmuerte.play();
            }
            (currentPlayer)->setx(0); (currentPlayer)->sety(0);
            game = true;
        }
    }
    else {
        //sGameover.setOrigin(-130, -110);
        //sound.pause();
        //ssgaov.play();
        game = false;
    }

    //no quitar - se bugea feo
    progreso = 0;
    puntaje = -126;

}
