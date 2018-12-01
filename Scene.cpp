//
// Created by zero on 21/11/18.
//

#include "Scene.h"

Scene::Scene(string backgroundName) {
    texture_back.loadFromFile(backgroundName);
}

void Scene::init() {
    background.setTexture(texture_back);
    nextV = -1;
}

void Scene::onEvent(sf::Event &event) {
    for(auto iter = entity.begin(); iter != entity.end(); iter++)
        (*iter)->onEvent(event);
}

void Scene::onRender(sf::RenderWindow &window) {
    window.draw(background);
    for(auto iter = entity.begin(); iter != entity.end(); iter++)
        (*iter)->onRender(window);
}


void Scene::addEntity(Entities *newEntity) {
    entity.push_back(newEntity);
}


/*
 * void Scene::Musica(std::string musica) {
    //Cargamos la musica de fondo
    music.openFromFile(musica);
    music.setLoop(true);
    music.play();
}
 * */
void Scene::setNextView(int view) {
    nextV = view;
}

int Scene::nextView() {
    int n = nextV;
    nextV = -1;
    return n;
}
