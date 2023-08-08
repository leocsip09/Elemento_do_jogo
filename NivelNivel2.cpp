#include "NivelNivel2.h"
#include <iostream>

NivelNivel2::NivelNivel2(const std::string& jugador1, const std::string& jugador2)
    : Nivel(), nivel2Ventana(sf::VideoMode(1280, 720), "Nivel 2"), nivel2Activo(true),
    seleccionJugador1(jugador1), seleccionJugador2(jugador2) {
    imagen = new sf::Texture();
    fondo = new sf::Sprite();
    cerrarNivel2 = new sf::RectangleShape();
    std::cout << "Se inializo el nivel 2 desde multiton" << std::endl;
}


void NivelNivel2::inicializar() {
    // Lógica de inicialización para el nivel 2

}

void NivelNivel2::actualizar(sf::RenderWindow& ventana) {
    // Lógica de actualización para el nivel 2

    if (nivel2Activo) {
        sf::Event event;
        while (nivel2Ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                nivel2Ventana.close(); // Cerramos la ventana si el usuario la cierra
                nivel2Activo = false; // Marcamos la nueva ventana como no activa
            }
        }
        pos_mouse = sf::Mouse::getPosition(nivel2Ventana);
        mouse_coord = nivel2Ventana.mapPixelToCoords(pos_mouse);


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (cerrarNivel2->getGlobalBounds().contains(mouse_coord)) {
                std::cout << "Nivel 2 cerrado" << '\n';
                nivel2Ventana.close();
                nivel2Activo = false;
            }
        }
    }
}

void NivelNivel2::dibujar(sf::RenderWindow& ventana) {

    //Lógica de dibujar para el nivel 2
    if (nivel2Activo) {
        pos_mouse = { 0,0 };

        nivel2Ventana.clear();
        imagen->loadFromFile("./nivel2_fondo.png");
        fondo->setTexture(*imagen);
        nivel2Ventana.draw(*fondo);
        cerrarNivel2->setSize(sf::Vector2f(26, 26));
        cerrarNivel2->setPosition(1178, 39);
        cerrarNivel2->setFillColor(sf::Color::Transparent);
        nivel2Ventana.draw(*cerrarNivel2); // Dibujamos el rectángulo cerrarVentana

        nivel2Ventana.display(); // Mostramos lo que hemos dibujado en la nueva ventana
    }
}

bool NivelNivel2::estaActivo() const {
    return nivel2Activo; // Devolvemos el estado de la nueva ventana del nivel 1
}

NivelNivel2::~NivelNivel2() {
    delete imagen;
    delete fondo;
    delete cerrarNivel2;
}
