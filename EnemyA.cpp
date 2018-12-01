//
// Created by zero on 30/11/18.
//

#include "EnemyA.h"

EnemyA::EnemyA()
:Entities("resources/images/enemy_a.png", ""){
    Entities::velocidad = 5;
    Entities::x = 300;
    Entities::y = 300;

    Entities::dx = Entities::velocidad - rand() % 10;
    Entities::dy = Entities::velocidad - rand() % 10;
}

void EnemyA::onEvent(sf::Event &event) {

}

void EnemyA::onUpdate() {
    x += dx;
    if (mapa[(y) / ts][x / ts] == 1) {
        dx = -dx;
        x += dx;
    }
    y += dy;
    if (mapa[(y) / ts][x / ts] == 1) {
        dy = -dy;
        y += dy;
    }

    this->setPosition(x, y);
}

void EnemyA::onRender(sf::RenderWindow &window) {
    Entities::onRender(window);
}
