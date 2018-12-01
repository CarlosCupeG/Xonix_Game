//
// Created by zero on 30/11/18.
//

#include "EnemyB.h"

EnemyB::EnemyB()
:Entities("resources/images/enemy_b.png", "") {
    Entities::velocidad = 5;
    Entities::x = 300;
    Entities::y = 300;

    Entities::dx = Entities::velocidad - rand() % 10;
    Entities::dy = Entities::velocidad - rand() % 10;
}

void EnemyB::onEvent(sf::Event &event) {

}

void EnemyB::onUpdate() {
    x += dx;
    if (mapa[(y) / ts][x / ts] == 1) {
        if (y < 0 || y>24)
            mapa[(y) / ts][x / ts] = 0;

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

void EnemyB::onRender(sf::RenderWindow &window) {
    Entities::onRender(window);
}
