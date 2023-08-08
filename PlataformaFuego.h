#pragma once
#include "Plataforma.h"
#include "Fuego.h"
class PlataformaFuego : public Plataforma {
private:
    sf::Texture plataformaFuegoTexture;
    sf::Sprite plataformaFuegoSprite;
    std::unique_ptr<Fuego> fuego;
public:
    PlataformaFuego();
    void dibujar(sf::RenderWindow& ventana, sf::Vector2f pos);
    std::string getTipo() const override;
    // Atributos y funciones específicas para la plataforma de fuego
};
