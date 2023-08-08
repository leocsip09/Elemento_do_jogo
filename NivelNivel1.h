#pragma once

#include "Nivel.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Personaje.h"

class NivelNivel1 : public Nivel {
private:
    sf::RenderWindow nivel1Ventana;
    bool nivel1Activo;
    std::unique_ptr<sf::Texture> imagen;
    std::unique_ptr<sf::Sprite> fondo;
    std::unique_ptr<sf::RectangleShape> cerrarNivel1;
    sf::Vector2i pos_mouse;
    sf::Vector2f mouse_coord;
    std::string seleccionJugador1;
    std::string seleccionJugador2;
    std::unique_ptr<Personaje> personajeJugador1;
    std::unique_ptr<Personaje> personajeJugador2;
    
public:
    
    sf::Clock clock; // Crear un reloj para medir el tiempo
    float deltaTime = 0.0f; // Inicializar deltaTime
    NivelNivel1(const std::string& jugador1, const std::string& jugador2);
    void inicializar() override;
    void actualizar(sf::RenderWindow& ventana) override;
    void dibujar(sf::RenderWindow& ventana) override;
    bool estaActivo() const override;
    ~NivelNivel1();
};
