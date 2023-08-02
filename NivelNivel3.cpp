#include "NivelNivel3.h"
#include <iostream>

NivelNivel3::NivelNivel3() : Nivel(), nivel3Ventana(sf::VideoMode(1280, 720), "Nivel 3"), nivel3Activo(true) {
    imagen = new sf::Texture();
    fondo = new sf::Sprite();
    cerrarNivel3 = new sf::RectangleShape();
    std::cout << "Se inializo el nivel 3 desde multiton" << std::endl;
}


void NivelNivel3::inicializar() {
    // Lógica de inicialización para el nivel 3

}

void NivelNivel3::actualizar(sf::RenderWindow& ventana) {
    // Lógica de actualización para el nivel 3

    if (nivel3Activo) {
        sf::Event event;
        while (nivel3Ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                nivel3Ventana.close(); // Cerramos la ventana si el usuario la cierra
                nivel3Activo = false; // Marcamos la nueva ventana como no activa
            }
        }
        pos_mouse = sf::Mouse::getPosition(nivel3Ventana);
        mouse_coord = nivel3Ventana.mapPixelToCoords(pos_mouse);


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (cerrarNivel3->getGlobalBounds().contains(mouse_coord)) {
                std::cout << "Nivel 3 cerrado" << '\n';
                nivel3Ventana.close();
                nivel3Activo = false;
            }
        }
    }
}

void NivelNivel3::dibujar(sf::RenderWindow& ventana) {

    //Lógica de dibujar para el nivel 3
    if (nivel3Activo) {
        pos_mouse = { 0,0 };

        nivel3Ventana.clear();
        imagen->loadFromFile("./nivel3_fondo.png");
        fondo->setTexture(*imagen);
        nivel3Ventana.draw(*fondo);
        cerrarNivel3->setSize(sf::Vector2f(23, 26));
        cerrarNivel3->setPosition(1178, 39);
        cerrarNivel3->setFillColor(sf::Color::Transparent);
        nivel3Ventana.draw(*cerrarNivel3); // Dibujamos el rectángulo cerrarVentana

        nivel3Ventana.display(); // Mostramos lo que hemos dibujado en la nueva ventana
    }
}

bool NivelNivel3::estaActivo() const {
    return nivel3Activo; // Devolvemos el estado de la nueva ventana del nivel 1
}

NivelNivel3::~NivelNivel3() {
    delete imagen;
    delete fondo;
    delete cerrarNivel3;
}
