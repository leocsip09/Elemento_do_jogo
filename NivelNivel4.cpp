#include "NivelNivel4.h"
#include <iostream>

NivelNivel4::NivelNivel4(const std::string& jugador1, const std::string& jugador2)
    : Nivel(), nivel4Ventana(sf::VideoMode(1280, 720), "Nivel 4"), nivel4Activo(true),
    seleccionJugador1(jugador1), seleccionJugador2(jugador2) {
    imagen = new sf::Texture();
    fondo = new sf::Sprite();
    cerrarNivel4 = new sf::RectangleShape();
    std::cout << "Se inializo el nivel 4 desde multiton" << std::endl;
}


void NivelNivel4::inicializar() {
    // Lógica de inicialización para el nivel 4

}

void NivelNivel4::actualizar(sf::RenderWindow& ventana) {
    // Lógica de actualización para el nivel 4

    if (nivel4Activo) {
        sf::Event event;
        while (nivel4Ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                nivel4Ventana.close(); // Cerramos la ventana si el usuario la cierra
                nivel4Activo = false; // Marcamos la nueva ventana como no activa
            }
        }
        pos_mouse = sf::Mouse::getPosition(nivel4Ventana);
        mouse_coord = nivel4Ventana.mapPixelToCoords(pos_mouse);


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (cerrarNivel4->getGlobalBounds().contains(mouse_coord)) {
                std::cout << "Nivel 4 cerrado" << '\n';
                nivel4Ventana.close();
                nivel4Activo = false;
            }
        }
    }
}

void NivelNivel4::dibujar(sf::RenderWindow& ventana) {

    //Lógica de dibujar para el nivel 4
    if (nivel4Activo) {
        pos_mouse = { 0,0 };

        nivel4Ventana.clear();
        imagen->loadFromFile("./nivel2_fondo.png");
        fondo->setTexture(*imagen);
        nivel4Ventana.draw(*fondo);
        cerrarNivel4->setSize(sf::Vector2f(23, 26));
        cerrarNivel4->setPosition(1178, 39);
        cerrarNivel4->setFillColor(sf::Color::Transparent);
        nivel4Ventana.draw(*cerrarNivel4); // Dibujamos el rectángulo cerrarVentana

        nivel4Ventana.display(); // Mostramos lo que hemos dibujado en la nueva ventana
    }
}

bool NivelNivel4::estaActivo() const {
    return nivel4Activo; // Devolvemos el estado de la nueva ventana del nivel 1
}

NivelNivel4::~NivelNivel4() {
    delete imagen;
    delete fondo;
    delete cerrarNivel4;
}
