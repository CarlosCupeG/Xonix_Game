//
// Created by roosevelt on 26/11/18.
//

#include "Entities.h"

Entities::Entities(std::string texture, std::string sonido) {
    //Cargamos la imagen
    texture_entity.loadFromFile(texture);
    texture_entity.setSmooth(true);
    this->setTexture(texture_entity);

    //Cargamos su sonido
    //this->buffer.loadFromFile(sonido);
    //this->sound.setBuffer(buffer);

    // Establecemos el origen de cordenas del entity en su centro
    //this->setOrigin(this->getLocalBounds().width/2.0f, this->getLocalBounds().height/2.0f);
}

void Entities::onRender(sf::RenderWindow &window) {
    window.draw(*this);
}

Sprite* Entities::getSprite() {
    return this;
}

void Entities::setNewTexture(string textureName) {
    texture_entity.loadFromFile(textureName);
}
