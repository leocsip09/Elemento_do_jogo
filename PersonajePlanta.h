#pragma once
#include "Personaje.h"
class PersonajePlanta : public Personaje {
public:
    void dibujar(sf::RenderWindow& ventana, sf::Vector2f pos) override;
};

