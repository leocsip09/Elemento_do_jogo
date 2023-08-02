#pragma once

#include "Nivel.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class NivelNivel2 : public Nivel {
private:
    sf::RenderWindow nivel2Ventana; // Nueva ventana para el nivel 2
    bool nivel2Activo; // Variable para controlar si la nueva ventana est� activa

public:
    // Constructor del nivel 2
    NivelNivel2();

    // Sobrescribe los m�todos de la clase base
    void inicializar() override;
    void actualizar(sf::RenderWindow& ventana) override;
    void dibujar(sf::RenderWindow& ventana) override;

    // M�todo para verificar si la nueva ventana del nivel 2 est� activa
    bool estaActivo() const override;
};