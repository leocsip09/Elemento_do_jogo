#pragma once
#include "Personaje.h"
class PersonajeAgua : public Personaje {
public:
    void dibujar(sf::RenderWindow& ventana, sf::Vector2f pos) override;
};
