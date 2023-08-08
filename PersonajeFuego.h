#pragma once
#include "Personaje.h"
class PersonajeFuego : public Personaje {
public:
    
    void dibujar(sf::RenderWindow& ventana, sf::Vector2f pos) override;
};
