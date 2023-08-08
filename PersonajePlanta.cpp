#include "PersonajePlanta.h"
#include <iostream>

void PersonajePlanta::dibujar(sf::RenderWindow& ventana, sf::Vector2f pos) {
    if (!texture.loadFromFile("alfalfa_d.png")) {
        std::cout << "No se pudo cargar la imagen" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(pos);
    ventana.draw(sprite);
}