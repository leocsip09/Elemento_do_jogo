#pragma once
#include <memory>
#include <string>
#include "SFML/Graphics.hpp"


class Plataforma {
private:
    sf::Texture plataformaTexture;
    sf::Sprite plataformaSprite;

public:
    Plataforma();
    virtual void dibujar(sf::RenderWindow& ventana, sf::Vector2f pos);
    virtual std::string getTipo() const;
};

