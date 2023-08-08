#pragma once
#include "Plataforma.h"
#include "Agua.h"
class PlataformaAgua : public Plataforma {
private:
    sf::Texture plataformaAguaTexture;
    sf::Sprite plataformaAguaSprite;
    std::unique_ptr<Agua> Agua; 
public:
    PlataformaAgua();
    void dibujar(sf::RenderWindow& ventana, sf::Vector2f pos);
    std::string getTipo() const override;
    // Atributos y funciones específicas para la plataforma de agua

};

