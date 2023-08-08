#include "PlataformaAgua.h"
#include "Agua.h"
PlataformaAgua::PlataformaAgua() {
    plataformaAguaTexture.loadFromFile("PlataformaAgua.png");
    plataformaAguaSprite.setTexture(plataformaAguaTexture);
}
void PlataformaAgua::dibujar(sf::RenderWindow& ventana, sf::Vector2f pos) {
    plataformaAguaSprite.setPosition(pos);
    ventana.draw(plataformaAguaSprite);
}
std::string PlataformaAgua::getTipo() const {
    return Agua->getTipo();
}