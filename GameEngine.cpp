//
// Created by zero on 28/11/18.
//

#include "GameEngine.h"

GameEngine::GameEngine(int resX, int resY, string title)
        : window(sf::VideoMode(resX, resY), title) {
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
}

void GameEngine::init() {
    Scene *menu = new Menu();
    Scene *game = new Game();

    scene.push_back(menu);
    scene.push_back(game);

    scene[0]->init();
    scene[1]->init();

    currentScene = &scene[0];
    cout << "[  OK  ] Escenas cargadas" << endl;
}

void GameEngine::onEvent() {
    sf::Event event;

    while(window.pollEvent(event))
    {
        (*currentScene)->onEvent(event);
        if (event.type == sf::Event::Closed)
            window.close();
    }

}

void GameEngine::onUpdate(){
    int n = (*currentScene)->nextView();

    if (n != -1)
        currentScene = &scene[n];
    (*currentScene)->onUpdate();
}

void GameEngine::onRender() {
    window.clear();

    (*currentScene)->onRender(window);
    window.display();
}


void GameEngine::gameLoop() {
    cout << "[  OK  ] Comienza el Loop" << endl;
    while (window.isOpen())
    {
        onEvent();
        onUpdate();
        onRender();
    }
}


void GameEngine::run() {
    cout << "[  OK  ] Juego Iniciado" << endl;
    init();
    gameLoop();
}
