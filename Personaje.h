#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <string>
#include <memory>

class Personaje {
protected:
    std::string tipo;
    Personaje();

public:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f pos;
    bool enSuelo = false;
    virtual void dibujar(sf::RenderWindow& ventana, sf::Vector2f pos) = 0;
    void actualizar(float deltaTime);
};