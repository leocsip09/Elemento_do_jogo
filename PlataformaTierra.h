#pragma once
#include "Plataforma.h"
#include "Tierra.h"
class PlataformaTierra : public Plataforma {
private:
    sf::Texture plataformaTierraTexture;
    sf::Sprite plataformaTierraSprite;
    std::unique_ptr<Tierra> Tierra;
public:
    PlataformaTierra();
    void dibujar(sf::RenderWindow& ventana, sf::Vector2f pos);
    std::string getTipo() const override;
    // Atributos y funciones específicas para la plataforma de tierra

};

