#pragma once

#include "Nivel.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class NivelNivel1 : public Nivel {
private:
    sf::RenderWindow nivel1Ventana; // Nueva ventana para el nivel 1
    bool nivel1Activo; // Variable para controlar si la nueva ventana est� activa
    sf::Texture* imagen;
    sf::Sprite* fondo;
    bool presionado;
    sf::RectangleShape* cerrarVentana;
    sf::Vector2i pos_mouse;
    sf::Vector2f mouse_coord;
public:
    // Constructor del nivel 1
    NivelNivel1();

    // Sobrescribe los m�todos de la clase base
    void inicializar() override;
    void actualizar(sf::RenderWindow& ventana) override;
    void dibujar(sf::RenderWindow& ventana) override;

    // M�todo para verificar si la nueva ventana del nivel 1 est� activa
    bool estaActivo() const override;

    ~NivelNivel1();
};
