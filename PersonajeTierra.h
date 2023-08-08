#pragma once
#include "Personaje.h"
class PersonajeTierra : public Personaje {
public:
    void dibujar(sf::RenderWindow& ventana, sf::Vector2f pos) override;
};

