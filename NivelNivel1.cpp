#include "NivelNivel1.h"
#include <iostream>

NivelNivel1::NivelNivel1() : Nivel(), nivel1Ventana(sf::VideoMode(1280, 720), "Nivel 1"), nivel1Activo(true) {
    imagen = new sf::Texture();
    fondo = new sf::Sprite();
    cerrarNivel1 = new sf::RectangleShape();
    std::cout << "Se inializo el nivel 1 desde multiton" << std::endl;
}


void NivelNivel1::inicializar() {
    // Lógica de inicialización para el nivel 1
   
}

void NivelNivel1::actualizar(sf::RenderWindow& ventana) {
    // Lógica de actualización para el nivel 1
    
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
            if (cerrarNivel1->getGlobalBounds().contains(mouse_coord)) {
                std::cout << "Nivel 1 cerrado" << '\n';
                nivel1Ventana.close();
                nivel1Activo = false;
            }
        }
    }
}

void NivelNivel1::dibujar(sf::RenderWindow& ventana) {
    
     //Lógica de dibujar para el nivel 1
    if (nivel1Activo) {
        pos_mouse = { 0,0 };
        
        nivel1Ventana.clear();
        imagen->loadFromFile("./nivel1_fondo.png");
        fondo->setTexture(*imagen);
        nivel1Ventana.draw(*fondo);
        cerrarNivel1->setSize(sf::Vector2f(23, 26));
        cerrarNivel1->setPosition(1178, 39);
        cerrarNivel1->setFillColor(sf::Color::Transparent);
        nivel1Ventana.draw(*cerrarNivel1); // Dibujamos el rectángulo cerrarVentana

        nivel1Ventana.display(); // Mostramos lo que hemos dibujado en la nueva ventana
    }
}

bool NivelNivel1::estaActivo() const {
    return nivel1Activo; // Devolvemos el estado de la nueva ventana del nivel 1
}

NivelNivel1::~NivelNivel1() {
    delete imagen;
    delete fondo;
    delete cerrarNivel1;
}
