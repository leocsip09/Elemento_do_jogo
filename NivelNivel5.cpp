#include "NivelNivel5.h"
#include <iostream>

NivelNivel5::NivelNivel5(const std::string& jugador1, const std::string& jugador2)
    : Nivel(), nivel5Ventana(sf::VideoMode(1280, 720), "Nivel 5"), nivel5Activo(true),
    seleccionJugador1(jugador1), seleccionJugador2(jugador2) {
    imagen = new sf::Texture();
    fondo = new sf::Sprite();
    cerrarNivel5 = new sf::RectangleShape();
    std::cout << "Se inializo el nivel 5 desde multiton" << std::endl;
}


void NivelNivel5::inicializar() {
    // Lógica de inicialización para el nivel 5

}

void NivelNivel5::actualizar(sf::RenderWindow& ventana) {
    // Lógica de actualización para el nivel 5

    if (nivel5Activo) {
        sf::Event event;
        while (nivel5Ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                nivel5Ventana.close(); // Cerramos la ventana si el usuario la cierra
                nivel5Activo = false; // Marcamos la nueva ventana como no activa
            }
        }
        pos_mouse = sf::Mouse::getPosition(nivel5Ventana);
        mouse_coord = nivel5Ventana.mapPixelToCoords(pos_mouse);


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (cerrarNivel5->getGlobalBounds().contains(mouse_coord)) {
                std::cout << "Nivel 5 cerrado" << '\n';
                nivel5Ventana.close();
                nivel5Activo = false;
            }
        }
    }
}

void NivelNivel5::dibujar(sf::RenderWindow& ventana) {

    //Lógica de dibujar para el nivel 4
    if (nivel5Activo) {
        pos_mouse = { 0,0 };

        nivel5Ventana.clear();
        imagen->loadFromFile("./nivel2_fondo.png");
        fondo->setTexture(*imagen);
        nivel5Ventana.draw(*fondo);
        cerrarNivel5->setSize(sf::Vector2f(23, 26));
        cerrarNivel5->setPosition(1178, 39);
        cerrarNivel5->setFillColor(sf::Color::Transparent);
        nivel5Ventana.draw(*cerrarNivel5); // Dibujamos el rectángulo cerrarVentana

        nivel5Ventana.display(); // Mostramos lo que hemos dibujado en la nueva ventana
    }
}

bool NivelNivel5::estaActivo() const {
    return nivel5Activo; // Devolvemos el estado de la nueva ventana del nivel 5
}

NivelNivel5::~NivelNivel5() {
    delete imagen;
    delete fondo;
    delete cerrarNivel5;
}
