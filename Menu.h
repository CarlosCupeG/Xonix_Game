//
// Created by zero on 30/11/18.
//

#ifndef XONIX_MENU_H
#define XONIX_MENU_H


#include "Scene.h"
#include "settings.h"


class Menu : public Scene{
public:
    Menu();
    void init() override;
    void onEvent(sf::Event &event) override;
    void onUpdate() {}
    void onRender(sf::RenderWindow &window) override;

    int nextView() override;
};


#endif //XONIX_MENU_H
