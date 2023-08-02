#include "NivelNivel1.h"
#include <iostream>

NivelNivel1::NivelNivel1() : Nivel(), nivel1Ventana(sf::VideoMode(1280, 720), "Nivel 1"), nivel1Activo(true) {
    imagen = new sf::Texture();
    fondo = new sf::Sprite();
    cerrarVentana = new sf::RectangleShape();
}


void NivelNivel1::inicializar() {
    // Lógica de inicialización para el nivel 1
    std::cout << "Se inializo el nivel 1 desde multiton" << std::endl;
    
}

void NivelNivel1::actualizar(sf::RenderWindow& ventana) {
    // Lógica de actualización para el nivel 1
    std::cout << "Se esta actualizando el nivel 1" << std::endl;
    if (nivel1Activo) {
        sf::Event event;
        while (nivel1Ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                nivel1Ventana.close(); // Cerramos la ventana si el usuario la cierra
                nivel1Activo = false; // Marcamos la nueva ventana como no activa
            }
        }
        pos_mouse = sf::Mouse::getPosition(nivel1Ventana);
        mouse_coord = nivel1Ventana.mapPixelToCoords(pos_mouse);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (cerrarVentana->getGlobalBounds().contains(mouse_coord)) {
                std::cout << "Nivel 1 cerrado" << '\n';
                nivel1Ventana.close();
                nivel1Activo = false;
            }
        }
    }
}

void NivelNivel1::dibujar(sf::RenderWindow& ventana) {
    std::cout << "Se esta dibujando el nivel 1" << std::endl;
     //Lógica de dibujar para el nivel 1
    if (nivel1Activo) {
        presionado = false;
        std::cout << "Selector de niveles abierto" << std::endl;
        nivel1Ventana.clear();
        imagen->loadFromFile("./nivel1_fondo.png");
        fondo->setTexture(*imagen);
        nivel1Ventana.draw(*fondo);
        
        cerrarVentana->setSize(sf::Vector2f(23, 26));
        cerrarVentana->setPosition(1178, 39);
        cerrarVentana->setFillColor(sf::Color::Black);
        
        nivel1Ventana.display(); // Mostramos lo que hemos dibujado en la nueva ventana
    }
}

bool NivelNivel1::estaActivo() const {
    return nivel1Activo; // Devolvemos el estado de la nueva ventana del nivel 1
}

NivelNivel1::~NivelNivel1() {
    delete imagen;
    delete fondo;
    delete cerrarVentana;
}
