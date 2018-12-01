#include <iostream>
#include "GameEngine.h"

int main() {
    GameEngine gameEngine(750, 500, "Game Engine");
    gameEngine.run();

    return 0;
}

// g++ main.cpp Scene.cpp Entities.cpp Game.cpp GameEngine.cpp Menu.cpp Player.cpp settings.h -o main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
// g++ main.cpp Scene.cpp Scene.h Entities.cpp Entities.h Game.cpp Game.h GameEngine.cpp GameEngine.h Menu.h Menu.cpp Player.cpp Player.h settings.h -o main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio