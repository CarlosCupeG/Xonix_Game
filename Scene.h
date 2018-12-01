//
// Created by zero on 21/11/18.
//

#ifndef XONIXPACMAN_SCENE_H
#define XONIXPACMAN_SCENE_H

#include "settings.h"
#include "Entities.h"


class Scene {
protected:
    int nextV;
    sf::Texture texture_back;
    sf::Sprite background;
    sf::Music music;
    sf::Time time;
    sf::Clock clock;
    vector<Entities *> entity;


public:
    Scene();
    Scene(string name_back);

    virtual void init();

    virtual void onEvent(sf::Event &event);
    virtual void onUpdate() = 0;
    virtual void onRender(sf::RenderWindow &window);

    void addEntity(Entities *newEntity);
    void setNextView(int view);
    virtual int nextView();
    void Musica(std::string musica="Fondo.ogg" );
};


#endif //XONIXPACMAN_SCENE_H
