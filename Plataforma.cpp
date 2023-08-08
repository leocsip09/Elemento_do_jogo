#include "Plataforma.h"

Plataforma::Plataforma() {
    plataformaTexture.loadFromFile("Plataforma.png");
    plataformaSprite.setTexture(plataformaTexture);
}

void Plataforma::dibujar(sf::RenderWindow& ventana, sf::Vector2f pos) {
    plataformaSprite.setPosition(pos);
    ventana.draw(plataformaSprite);
    
}

std::string Plataforma::getTipo() const {
    return "ninguno";
}