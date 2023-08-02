#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
# include "Nivel.h"
# include "MultitonNivel.h"
# include <memory>

class SelectorDeNiveles {
private:
    std::unique_ptr<sf::RenderWindow> SeleNiv;
    std::unique_ptr<sf::Font> fuente2;
    std::unique_ptr<sf::Texture> imagen;
    std::unique_ptr<sf::Sprite> fondo;
    std::vector<sf::Text> Niveles;
    std::vector<std::unique_ptr<sf::RectangleShape>> cerrarVentana;
    
    int pos;
    bool presionado, laseleccion;
    
    
    sf::Vector2i pos_mouse;
    sf::Vector2f mouse_coord;
    std::vector<const char*> niv;
    std::vector<sf::Vector2f> coords;
    std::vector<std::size_t> tam;
    


public:
    SelectorDeNiveles() {

        SeleNiv = std::make_unique<sf::RenderWindow>();
        fuente2 = std::make_unique<sf::Font>();
        imagen = std::make_unique<sf::Texture>();
        fondo = std::make_unique<sf::Sprite>();
        cerrarVentana.push_back(std::make_unique<sf::RectangleShape>());
        estab_val_Sel();
        // Aquí puedes inicializar los miembros de la clase si es necesario
    }

    void eventos_bucle() {
        sf::Event event;
        while (SeleNiv->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                SeleNiv->close();
            }
            pos_mouse = sf::Mouse::getPosition(*SeleNiv);
            mouse_coord = SeleNiv->mapPixelToCoords(pos_mouse);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (cerrarVentana[0]->getGlobalBounds().contains(mouse_coord)) {
                    std::cout << "De regreso al menu principal" << '\n';
                    SeleNiv->close();
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !presionado) {
                if (pos < 5) {
                    ++pos;
                    presionado = true;
                    Niveles[pos].setOutlineThickness(4);
                    Niveles[pos - 1].setOutlineThickness(0);
                    presionado = false;
                    laseleccion = false;
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !presionado) {
                if (pos > 1) {
                    --pos;
                    presionado = true;
                    Niveles[pos].setOutlineThickness(4);
                    Niveles[pos + 1].setOutlineThickness(0);
                    presionado = false;
                    laseleccion = false;
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !laseleccion) {
                laseleccion = true;
                
                std::cout << niv[pos] << '\n';

            }
        }
    }
    void draw_todo() {
        SeleNiv->clear();
        SeleNiv->draw(*fondo);
        for (auto t : Niveles) {
            SeleNiv->draw(t);
        }
        SeleNiv->display();
    }

    void run_Selector() {
        while (SeleNiv->isOpen()) {
            eventos_bucle();
            draw_todo();
            if (laseleccion && pos >= 1) {
                Nivel* nivelSeleccionado = MultitonNivel::getNivel(pos);
                // Ahora puedes trabajar con el nivel seleccionado, como ejecutar su bucle principal, actualizar y dibujar.
                while (nivelSeleccionado->estaActivo()) {
                    nivelSeleccionado->actualizar(*SeleNiv);
                    nivelSeleccionado->dibujar(*SeleNiv);
                }
                laseleccion = false; // Restablecemos el indicador de selección para futuros usos
            }

        }
    }

    void estab_val_Sel() {
        std::cout << "Selector de niveles abierto" << std::endl;
        SeleNiv->create(sf::VideoMode(1280, 720), "Selector Niveles", sf::Style::Titlebar | sf::Style::Close);
        SeleNiv->setPosition(sf::Vector2i(0, 0));

        pos = 0;
        presionado = laseleccion = false;
        fuente2->loadFromFile("./ethn.otf");
        imagen->loadFromFile("./niveles.png");

        fondo->setTexture(*imagen);

        pos_mouse = { 0,0 };
        mouse_coord = { 0, 0 };

        niv = { "Selector", "Nivel 1", "Nivel 2", "Nivel 3", "Nivel 4", "Nivel 5" };
        Niveles.resize(6);
        coords = { {590,40},{595,170},{595,240}, {595,310}, {595,380}, {595,450} };
        tam = { 17,25,25, 25, 25, 25 };

        for (std::size_t i{}; i < Niveles.size(); ++i) {
            Niveles[i].setFont(*fuente2);
            Niveles[i].setString(niv[i]);
            Niveles[i].setCharacterSize(tam[i]);
            Niveles[i].setOutlineColor(sf::Color::Black);
            Niveles[i].setPosition(coords[i]);
        }
        Niveles[1].setOutlineThickness(4);
        pos = 1;
        cerrarVentana[0]->setSize(sf::Vector2f(23, 26));
        cerrarVentana[0]->setPosition(1178, 39);
        cerrarVentana[0]->setFillColor(sf::Color::Transparent);
      
    }
    ~SelectorDeNiveles() {}
};

