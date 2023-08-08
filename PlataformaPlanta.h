#pragma once
#include "Plataforma.h"
#include "Planta.h"
class PlataformaPlanta : public Plataforma {
private:
    sf::Texture plataformaPlantaTexture;
    sf::Sprite plataformaPlantaSprite;
    std::unique_ptr<Planta> Planta;
public:
    PlataformaPlanta();
    void dibujar(sf::RenderWindow& ventana, sf::Vector2f pos);
    std::string getTipo() const override;
    // Atributos y funciones específicas para la plataforma de planta
};

