#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Nivel {

public:
    // Constructor del nivel
    Nivel();

    // Destructor virtual para que las clases derivadas puedan liberar su memoria correctamente
    virtual ~Nivel();

    // M�todo para inicializar el nivel
    virtual void inicializar() = 0;

    // M�todo para actualizar el nivel (bucle principal del nivel)
    virtual void actualizar(sf::RenderWindow& ventana) = 0;

    // M�todo para dibujar el nivel en la ventana
    virtual void dibujar(sf::RenderWindow& ventana) = 0;

    // M�todo para verificar si el nivel est� activo
    virtual bool estaActivo() const = 0;
};