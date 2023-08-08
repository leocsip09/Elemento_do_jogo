#include "PlataformaTierra.h"
#include "Tierra.h"
PlataformaTierra::PlataformaTierra() {
    plataformaTierraTexture.loadFromFile("PlataformaTierra.png");
    plataformaTierraSprite.setTexture(plataformaTierraTexture);
}
void PlataformaTierra::dibujar(sf::RenderWindow& ventana, sf::Vector2f pos) {
    plataformaTierraSprite.setPosition(pos);
    ventana.draw(plataformaTierraSprite);
}
std::string PlataformaTierra::getTipo() const {
    return Tierra->getTipo();
}

