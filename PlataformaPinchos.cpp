#include "PlataformaPinchos.h"
PlataformaPinchos::PlataformaPinchos() {
    plataformaPinchosTexture.loadFromFile("PlataformaPinchos.png");
    plataformaPinchosSprite.setTexture(plataformaPinchosTexture);
}



void PlataformaPinchos::dibujar(sf::RenderWindow& ventana, sf::Vector2f pos) {
    plataformaPinchosSprite.setPosition(pos);
    ventana.draw(plataformaPinchosSprite);
}
