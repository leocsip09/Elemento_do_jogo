#pragma once

#include "Nivel.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class NivelNivel3 : public Nivel {
private:
    sf::RenderWindow nivel3Ventana; // Nueva ventana para el nivel 3
    bool nivel3Activo; // Variable para controlar si la nueva ventana está activa

public:
    // Constructor del nivel 3
    NivelNivel3();

    // Sobrescribe los métodos de la clase base
    void inicializar() override;
    void actualizar(sf::RenderWindow& ventana) override;
    void dibujar(sf::RenderWindow& ventana) override;

    // Método para verificar si la nueva ventana del nivel 3 está activa
    bool estaActivo() const override;
};

