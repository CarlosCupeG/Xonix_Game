//
// Created by zero on 30/11/18.
//

#include "Player.h"

Player::Player()
: Entities("resources/images/tiles1.png", "not") {
    x = 0;
    y = 0;
    dx = 0;
    dy = 0;
    velocidad = 0.07;
/*
    //Establecemos la posición del entity en el centro de la ventana

    this->setPosition(WIDTH/2.0f, HEIGHT/2.0f);

    //Establecemos su velocidad
    this->speed.x = 300.0f;
    this->speed.y = 300.0f;*/
}

void Player::onEvent(sf::Event &event) {

}

void Player::onRender(sf::RenderWindow &window) {
    Entities::onRender(window);
}

void Player::onUpdate() {
}
