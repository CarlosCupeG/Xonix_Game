//
// Created by zero on 30/11/18.
//

#include "Menu.h"

Menu::Menu()
: Scene("resources/images/back_inicio_1.png"){
}

void Menu::init() {
    Scene::init();
}

void Menu::onRender(sf::RenderWindow &window) {
    Scene::onRender(window);

}

void Menu::onEvent(sf::Event &event) {
    Scene::onEvent(event);

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space)
            Scene::setNextView(1);
    }

}

int Menu::nextView() {
    return Scene::nextView();
}
