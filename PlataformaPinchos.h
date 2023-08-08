#pragma once
#include "Plataforma.h"
class PlataformaPinchos : public Plataforma
{
private:
    sf::Texture plataformaPinchosTexture;
    sf::Sprite plataformaPinchosSprite;
public:
    PlataformaPinchos();
    void dibujar(sf::RenderWindow& ventana, sf::Vector2f pos) override;
};

