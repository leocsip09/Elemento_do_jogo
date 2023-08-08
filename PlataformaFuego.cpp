#include "PlataformaFuego.h"
#include "Fuego.h"
PlataformaFuego::PlataformaFuego() {
    plataformaFuegoTexture.loadFromFile("PlataformaFuego.png");
    plataformaFuegoSprite.setTexture(plataformaFuegoTexture);
}
void PlataformaFuego::dibujar(sf::RenderWindow& ventana, sf::Vector2f pos) {
    plataformaFuegoSprite.setPosition(pos);
    ventana.draw(plataformaFuegoSprite);
}
std::string PlataformaFuego::getTipo() const {
    return fuego->getTipo();
}
