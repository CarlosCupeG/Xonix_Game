//
// Created by zero on 30/11/18.
//

#ifndef XONIX_PLAYER_H
#define XONIX_PLAYER_H


#include "Entities.h"

class Player : public Entities{
public:
    Player();

    void onEvent(sf::Event &event) override;
    void onUpdate() override;
    void onRender(sf::RenderWindow &window) override;

    void moveLeft() {
        dx = -1;
        dy = 0;
    }

    void moveRight() {
        dx = 1;
        dy = 0;
    }

    void moveUp() {
        dx = 0;
        dy = -1;
    }

    void moveDown() {
        dx = 0;
        dy = 1;
    }
    float getVelocidad() {
        return velocidad;
    }
    void setVelocidad(float v) {
        velocidad = v;
    }
    int getx() {
        return Entities::getx();
    }
    int gety() {
        return Entities::gety();
    }
    void setx(int newx) {
        x = newx;
    }
    void sety(int newy) {
        y = newy;
    }
    void opConMyN() {
        x += dx;
        y += dy;

        if (x < 0)
            x = 0;
        if (x > N - 1)
            x = N - 1;
        if (y < 0)
            y = 0;
        if (y > M - 1)
            y = M - 1;
    }

    void resetDxDy() {
        dx = dy = 0;
    }
};


#endif //XONIX_PLAYER_H
