#include "PersonajeFuego.h"
#include <iostream>
void PersonajeFuego::dibujar(sf::RenderWindow& ventana, sf::Vector2f pos) {
    if (!texture.loadFromFile("fenix_d.png")) {
        std::cout << "No se pudo cargar la imagen" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(pos);
    ventana.draw(sprite);
}