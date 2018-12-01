//
// Created by roosevelt on 26/11/18.
//

#ifndef PROJECT_ENTITIES_H
#define PROJECT_ENTITIES_H

#include "settings.h"

using namespace sf;

class Entities : public Sprite{

protected:
    Texture texture_entity;
    SoundBuffer buffer;
    Sound sound;

    int x, y, dx, dy;
    double velocidad;

public:
    Entities() {};
    Entities(std::string texture, std::string sonido);

    virtual void onEvent(sf::Event &event) = 0;
    virtual void onUpdate() = 0;
    virtual void onRender(sf::RenderWindow &window);

    Sprite* getSprite();
    void setNewTexture(string textureName);

    int getx() { return x; };
    int gety() { return y; };
};



#endif //PROJECT_ENTITIES_H
