//
// Created by zero on 01/12/18.
//

#ifndef XONIX_DROPS_H
#define XONIX_DROPS_H


#include "Entities.h"
#include "settings.h"

class Drops : public Entities{
private:
    bool yaFueUsado;
    bool puntajeRequierement;
public:
    Drops()
    :Entities("resources/images/plata.png", "")
    {
        x = rand() % 700 - 18;
        y = rand() % 380 - 18;
        yaFueUsado = true;
        puntajeRequierement = false;
    }

    void move(){}

    void onEvent(sf::Event &event);
    void onUpdate();
    void onRender(sf::RenderWindow &window);

    void usar() {
        yaFueUsado = false;
    }

    bool fueUsado() {
        return yaFueUsado;
    }

    void setPuntaje(bool val)
    {
        puntajeRequierement = val;
    }
};


#endif //XONIX_DROPS_H
