#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Menu {
    int pos;
    bool presionado, laseleccion;

    sf::RenderWindow* ventana;
    sf::RectangleShape* cerrarVentana;
    sf::Font* fuente;
    sf::Texture* imagen;
    sf::Sprite* fondo;

    sf::Vector2i pos_mouse;
    sf::Vector2f mouse_coord;

    std::vector<const char*> opciones;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Text> textos;
    std::vector<std::size_t> tam;

protected:
    void estab_valores();
    void eventos_bucle();
    void draw_todo();

public:
    Menu();
    ~Menu();
    void run_menu();
};
