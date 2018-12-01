//
// Created by zero on 28/11/18.
//

#ifndef PROJECT_GAMEENGINE_H
#define PROJECT_GAMEENGINE_H


#include <vector>
#include "Menu.h"
#include "Game.h"
#include "settings.h"

using namespace std;

class GameEngine {
private:
    vector<Scene *> scene;
    sf::RenderWindow window;
    Scene** currentScene;

public:
    GameEngine();
    GameEngine(int resX, int rexY, string title);

    void run();

    void init();

    void onEvent();
    void onUpdate();
    void onRender();

    void gameLoop();

};


#endif //PROJECT_GAMEENGINE_H
