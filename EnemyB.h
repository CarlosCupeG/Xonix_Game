//
// Created by zero on 30/11/18.
//

#ifndef XONIX_ENEMYB_H
#define XONIX_ENEMYB_H


#include "Entities.h"

class EnemyB : public Entities{
private:
    int ts = 18;
public:
    EnemyB();

    void move() {}

    void onEvent(sf::Event &event);
    void onUpdate();
    void onRender(sf::RenderWindow &window);

    int getx() {
        return Entities::getx();
    };
    int gety() {
        return Entities::gety();
    };
};


#endif //XONIX_ENEMYB_H
