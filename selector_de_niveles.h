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
    std::vector<sf::Text> Nombres_P1;
    std::vector<sf::Text> Nombres_P2;
    std::vector<sf::Text> Niveles;
    std::vector<std::unique_ptr<sf::RectangleShape>> cerrarVentana;
    std::unique_ptr<sf::RectangleShape> Fenix1;
    std::unique_ptr<sf::RectangleShape> Poseidon1;
    std::unique_ptr<sf::RectangleShape> Terraneitor1;
    std::unique_ptr<sf::RectangleShape> Alfalfa1;
    std::unique_ptr<sf::RectangleShape> Fenix2;
    std::unique_ptr<sf::RectangleShape> Poseidon2;
    std::unique_ptr<sf::RectangleShape> Terraneitor2;
    std::unique_ptr<sf::RectangleShape> Alfalfa2;
    sf::Text jugador1, jugador2;
 
    int pos;
    bool presionado, laseleccion;

    sf::Vector2i pos_mouse;
    sf::Vector2f mouse_coord;
    std::vector<const char*> niv;
    std::vector<const char*> nom;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Vector2f> coords_nom;
    std::vector<sf::Vector2f> coords_nom2;
    std::vector<std::size_t> tam;
    
    

public:
    SelectorDeNiveles() {

        SeleNiv = std::make_unique<sf::RenderWindow>();
        fuente2 = std::make_unique<sf::Font>();
        imagen = std::make_unique<sf::Texture>();
        fondo = std::make_unique<sf::Sprite>();

        cerrarVentana.push_back(std::make_unique<sf::RectangleShape>());

        Alfalfa1 = std::make_unique<sf::RectangleShape>();
        Fenix1 = std::make_unique<sf::RectangleShape>();
        Poseidon1 = std::make_unique<sf::RectangleShape>();
        Terraneitor1 = std::make_unique<sf::RectangleShape>();

        Alfalfa2 = std::make_unique<sf::RectangleShape>();
        Fenix2 = std::make_unique<sf::RectangleShape>();
        Poseidon2 = std::make_unique<sf::RectangleShape>();
        Terraneitor2 = std::make_unique<sf::RectangleShape>();

        estab_val_Sel();
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
                if (Alfalfa1->getGlobalBounds().contains(mouse_coord)) {
                    std::cout << "Jugador 1 Selecciona a Alfalfa." << '\n';
                    Nombres_P1[0].setOutlineThickness(0);
                    Nombres_P1[1].setOutlineThickness(0);
                    Nombres_P1[2].setOutlineThickness(0);
                    Nombres_P1[3].setOutlineThickness(4);
                    
                }
                else if (Poseidon1->getGlobalBounds().contains(mouse_coord)) {
                    std::cout << "Jugador 1 Selecciona a Poseidon." << '\n';
                    Nombres_P1[0].setOutlineThickness(0);
                    Nombres_P1[1].setOutlineThickness(4);
                    Nombres_P1[2].setOutlineThickness(0);
                    Nombres_P1[3].setOutlineThickness(0);
                    
                }
                else if (Fenix1->getGlobalBounds().contains(mouse_coord)) {
                    std::cout << "Jugador 1 Selecciona a Fenix." << '\n';
                    Nombres_P1[0].setOutlineThickness(4);
                    Nombres_P1[1].setOutlineThickness(0);
                    Nombres_P1[2].setOutlineThickness(0);
                    Nombres_P1[3].setOutlineThickness(0);
                    
                }
                else if (Terraneitor1->getGlobalBounds().contains(mouse_coord)) {
                    std::cout << "Jugador 1 Selecciona a Terraneitor." << '\n';
                    Nombres_P1[0].setOutlineThickness(0);
                    Nombres_P1[1].setOutlineThickness(0);
                    Nombres_P1[2].setOutlineThickness(4);
                    Nombres_P1[3].setOutlineThickness(0);

                }
                else if (Alfalfa2->getGlobalBounds().contains(mouse_coord)) {
                    std::cout << "Jugador 2 Selecciona a Alfalfa." << '\n';
                    Nombres_P2[0].setOutlineThickness(0);
                    Nombres_P2[1].setOutlineThickness(0);
                    Nombres_P2[2].setOutlineThickness(0);
                    Nombres_P2[3].setOutlineThickness(4);

                }
                else if (Poseidon2->getGlobalBounds().contains(mouse_coord)) {
                    std::cout << "Jugador 2 Selecciona a Poseidon." << '\n';
                    Nombres_P2[0].setOutlineThickness(0);
                    Nombres_P2[1].setOutlineThickness(4);
                    Nombres_P2[2].setOutlineThickness(0);
                    Nombres_P2[3].setOutlineThickness(0);

                }
                else if (Fenix2->getGlobalBounds().contains(mouse_coord)) {
                    std::cout << "Jugador 2 Selecciona a Fenix." << '\n';
                    Nombres_P2[0].setOutlineThickness(4);
                    Nombres_P2[1].setOutlineThickness(0);
                    Nombres_P2[2].setOutlineThickness(0);
                    Nombres_P2[3].setOutlineThickness(0);

                }
                else if (Terraneitor2->getGlobalBounds().contains(mouse_coord)) {
                    std::cout << "Jugador 2 Selecciona a Terraneitor." << '\n';
                    Nombres_P2[0].setOutlineThickness(0);
                    Nombres_P2[1].setOutlineThickness(0);
                    Nombres_P2[2].setOutlineThickness(4);
                    Nombres_P2[3].setOutlineThickness(0);

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

        std::vector<std::pair<std::string, sf::Vector2f>> personajes = {
            {"./fenix_d.png", sf::Vector2f(20, 160)},
            {"./poseidon_d.png", sf::Vector2f(180, 160)},
            {"./terraneitor_d.png", sf::Vector2f(30, 375)},
            {"./alfalfa_d.png", sf::Vector2f(190, 380)},
            {"./fenix_d.png", sf::Vector2f(960, 160)},
            {"./poseidon_d.png", sf::Vector2f(1120, 160)},
            {"./terraneitor_d.png", sf::Vector2f(970, 375)},
            {"./alfalfa_d.png", sf::Vector2f(1130, 380)}
        };

        for (const auto& nivel : Niveles) {
            SeleNiv->draw(nivel);
        }

        for (const auto& nombre : Nombres_P1) {
            SeleNiv->draw(nombre);
        }

        for (const auto& nombre : Nombres_P2) {
            SeleNiv->draw(nombre);
        }

        SeleNiv->draw(jugador1);
        SeleNiv->draw(jugador2);

        for (const auto& personaje : personajes) {
            sf::Texture imagen;
            sf::Sprite sprite;
            imagen.loadFromFile(personaje.first);
            sprite.setTexture(imagen);
            sprite.setPosition(personaje.second);
            SeleNiv->draw(sprite);
        }

        SeleNiv->display();
    }

    void run_Selector() {
        
        while (SeleNiv->isOpen()) {
            eventos_bucle();
            
            if (laseleccion && pos >= 1) {
                Nivel* nivelSeleccionado = MultitonNivel::getNivel(pos);
                // Ahora puedes trabajar con el nivel seleccionado, como ejecutar su bucle principal, actualizar y dibujar.
                while (nivelSeleccionado->estaActivo()) {
                    nivelSeleccionado->actualizar(*SeleNiv);
                    nivelSeleccionado->dibujar(*SeleNiv);
                }
                laseleccion = false; // Restablecemos el indicador de selección para futuros usos
            }
            draw_todo();
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
        nom = { "Fenix", "Poseidon", "Terraneitor", "Alfalfa" };

        Nombres_P1.resize(4);
        Nombres_P2.resize(4);
        Niveles.resize(6);
        coords_nom = { {50, 130}, {180, 130}, {20, 375}, {200, 375} };
        coords_nom2 = { {990, 130}, {1120, 130}, {960, 375}, {1140, 375} };
        
        jugador1.setFont(*fuente2);
        jugador1.setString("Jugador 1");
        jugador1.setCharacterSize(25);
        jugador1.setOutlineColor(sf::Color::Black);
        jugador1.setOutlineThickness(4);
        jugador1.setPosition({80, 80});

        jugador2.setFont(*fuente2);
        jugador2.setString("Jugador 2");
        jugador2.setCharacterSize(25);
        jugador2.setOutlineColor(sf::Color::Black);
        jugador2.setOutlineThickness(4);
        jugador2.setPosition({ 1020, 80 });

        coords = { {610,40},{595,170},{595,240}, {595,310}, {595,380}, {595,450} };
        tam = { 17,25,25, 25, 25, 25 };
        for (std::size_t i{}; i < Nombres_P1.size(); ++i) {
            Nombres_P1[i].setFont(*fuente2);
            Nombres_P1[i].setString(nom[i]);
            Nombres_P1[i].setCharacterSize(17);
            Nombres_P1[i].setOutlineColor(sf::Color::Black);
            Nombres_P1[i].setPosition(coords_nom[i]);
            Nombres_P2[i].setFont(*fuente2);
            Nombres_P2[i].setString(nom[i]);
            std::cout << nom[i] << std::endl;
            Nombres_P2[i].setCharacterSize(17);
            Nombres_P2[i].setOutlineColor(sf::Color::Black);
            Nombres_P2[i].setPosition(coords_nom2[i]);
        }
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

        Alfalfa1->setSize(sf::Vector2f(121, 200));
        Alfalfa1->setPosition(sf::Vector2f(200, 375));
        Alfalfa1->setFillColor(sf::Color::Transparent);

        Fenix1->setSize(sf::Vector2f(121, 200));
        Fenix1->setPosition(sf::Vector2f(50, 130));
        Fenix1->setFillColor(sf::Color::Transparent);

        Poseidon1->setSize(sf::Vector2f(121, 200));
        Poseidon1->setPosition(sf::Vector2f(180, 130));
        Poseidon1->setFillColor(sf::Color::Transparent);

        Terraneitor1->setSize(sf::Vector2f(121, 200));
        Terraneitor1->setPosition(sf::Vector2f(20, 375));
        Terraneitor1->setFillColor(sf::Color::Transparent);

        Alfalfa2->setSize(sf::Vector2f(121, 200));
        Alfalfa2->setPosition(sf::Vector2f(1140, 375));
        Alfalfa2->setFillColor(sf::Color::Transparent);

        Fenix2->setSize(sf::Vector2f(121, 200));
        Fenix2->setPosition(sf::Vector2f(990, 130));
        Fenix2->setFillColor(sf::Color::Transparent);

        Poseidon2->setSize(sf::Vector2f(121, 200));
        Poseidon2->setPosition(sf::Vector2f(1120, 130));
        Poseidon2->setFillColor(sf::Color::Transparent);

        Terraneitor2->setSize(sf::Vector2f(121, 200));
        Terraneitor2->setPosition(sf::Vector2f(960, 375));
        Terraneitor2->setFillColor(sf::Color::Transparent);

      
    }
    ~SelectorDeNiveles() {}
};

