#include "NivelNivel2.h"
#include <iostream>

NivelNivel2::NivelNivel2() : Nivel(), nivel2Ventana(sf::VideoMode(1280, 720), "Nivel 2"), nivel2Activo(true) {}


void NivelNivel2::inicializar() {
    // Lógica de inicialización para el nivel 2
    std::cout << "Se inializo el nivel 2 desde multiton" << std::endl;
}

void NivelNivel2::actualizar(sf::RenderWindow& ventana) {
    // Lógica de actualización para el nivel 2
    std::cout << "Se esta actualizando el nivel 2" << std::endl;
    if (nivel2Activo) {
        sf::Event event;
        while (nivel2Ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                nivel2Ventana.close(); // Cerramos la ventana si el usuario la cierra
                nivel2Activo = false; // Marcamos la nueva ventana como no activa
            }
        }
    }
}

void NivelNivel2::dibujar(sf::RenderWindow& ventana) {
    std::cout << "Se esta dibujando el nivel 2" << std::endl;
    //Lógica de dibujar para el nivel 2
    if (nivel2Activo) {
        nivel2Ventana.clear(sf::Color::White); // Limpia la ventana del nivel 2 con un color blanco
        // dibujar 
        // ...
        nivel2Ventana.display(); // Mostramos lo que hemos dibujado en la nueva ventana
    }
}

bool NivelNivel2::estaActivo() const {
    return nivel2Activo; // Devolvemos el estado de la nueva ventana del nivel 2
}
