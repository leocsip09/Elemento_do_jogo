#include "PlataformaPlanta.h"
#include "Planta.h"

PlataformaPlanta::PlataformaPlanta() {
    plataformaPlantaTexture.loadFromFile("PlataformaPlanta.png");
    plataformaPlantaSprite.setTexture(plataformaPlantaTexture);
}
void PlataformaPlanta::dibujar(sf::RenderWindow& ventana, sf::Vector2f pos) {
    plataformaPlantaSprite.setPosition(pos);
    ventana.draw(plataformaPlantaSprite);
}
std::string PlataformaPlanta::getTipo() const {
    return Planta->getTipo();
}
