#pragma once

#include "Nivel.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class NivelNivel5 : public Nivel {
private:
    sf::RenderWindow nivel5Ventana; // Nueva ventana para el nivel 5
    bool nivel5Activo; // Variable para controlar si la nueva ventana está activa
    sf::Texture* imagen;
    sf::Sprite* fondo;

    sf::RectangleShape* cerrarNivel5;
    sf::Vector2i pos_mouse;
    sf::Vector2f mouse_coord;
    std::string seleccionJugador1;
    std::string seleccionJugador2;
public:
    // Constructor del nivel 5
    NivelNivel5(const std::string& jugador1, const std::string& jugador2);

    // Sobrescribe los métodos de la clase base
    void inicializar() override;
    void actualizar(sf::RenderWindow& ventana) override;
    void dibujar(sf::RenderWindow& ventana) override;

    // Método para verificar si la nueva ventana del nivel 5 está activa
    bool estaActivo() const override;

    ~NivelNivel5();
};

