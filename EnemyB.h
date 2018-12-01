//
// Created by zero on 30/11/18.
//

#ifndef XONIX_ENEMYB_H
#define XONIX_ENEMYB_H


#include "Entities.h"

class EnemyB : public Entities{
private:
    int ts = 18;
    int mapa[25][40];
public:
    EnemyB();

    void move() {}

    void onEvent(sf::Event &event);
    void onUpdate();
    void onRender(sf::RenderWindow &window);

    void setMap(int map[25][40])
    {
        for(int i= 0; i < 25; i++)
        {
            for(int j= 0; j < 40; j++)
            {
                mapa[i][j] = map[i][j];
            }
        }
    }

    int getx() {
        return Entities::getx();
    };
    int gety() {
        return Entities::gety();
    };
};


#endif //XONIX_ENEMYB_H
