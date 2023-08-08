#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Nivel {

public:
    // Constructor del nivel
    Nivel();

    // Destructor virtual para que las clases derivadas puedan liberar su memoria correctamente
    virtual ~Nivel();

    // Método para inicializar el nivel
    virtual void inicializar() = 0;

    // Método para actualizar el nivel (bucle principal del nivel)
    virtual void actualizar(sf::RenderWindow& ventana) = 0;

    // Método para dibujar el nivel en la ventana
    virtual void dibujar(sf::RenderWindow& ventana) = 0;

    // Método para verificar si el nivel está activo
    virtual bool estaActivo() const = 0;
};