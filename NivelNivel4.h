#pragma once

#include "Nivel.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class NivelNivel4 : public Nivel {
private:
    sf::RenderWindow nivel4Ventana; // Nueva ventana para el nivel 4
    bool nivel4Activo; // Variable para controlar si la nueva ventana est� activa
    sf::Texture* imagen;
    sf::Sprite* fondo;

    sf::RectangleShape* cerrarNivel4;
    sf::Vector2i pos_mouse;
    sf::Vector2f mouse_coord;
    std::string seleccionJugador1;
    std::string seleccionJugador2;
public:
    // Constructor del nivel 4
    NivelNivel4(const std::string& jugador1, const std::string& jugador2);

    // Sobrescribe los m�todos de la clase base
    void inicializar() override;
    void actualizar(sf::RenderWindow& ventana) override;
    void dibujar(sf::RenderWindow& ventana) override;

    // M�todo para verificar si la nueva ventana del nivel 4 est� activa
    bool estaActivo() const override;

    ~NivelNivel4();
};

