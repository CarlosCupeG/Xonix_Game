//
// Created by zero on 01/12/18.
//

#include "Drops.h"

void Drops::onEvent(sf::Event &event) {

}

void Drops::onUpdate() {

}

void Drops::onRender(sf::RenderWindow &window) {
    if (fueUsado() && puntajeRequierement)
        Entities::onRender(window);
}
