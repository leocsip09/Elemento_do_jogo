#include "NivelNivel5.h"
#include <iostream>

NivelNivel5::NivelNivel5() : Nivel(), nivel5Ventana(sf::VideoMode(1280, 720), "Nivel 5"), nivel5Activo(true) {}


void NivelNivel5::inicializar() {
    // Lógica de inicialización para el nivel 5
    std::cout << "Se inializo el nivel 5 desde multiton" << std::endl;
}

void NivelNivel5::actualizar(sf::RenderWindow& ventana) {
    // Lógica de actualización para el nivel 5
    std::cout << "Se esta actualizando el nivel 5" << std::endl;
    if (nivel5Activo) {
        sf::Event event;
        while (nivel5Ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                nivel5Ventana.close(); // Cerramos la ventana si el usuario la cierra
                nivel5Activo = false; // Marcamos la nueva ventana como no activa
            }
        }
    }
}

void NivelNivel5::dibujar(sf::RenderWindow& ventana) {
    std::cout << "Se esta dibujando el nivel 4" << std::endl;
    //Lógica de dibujar para el nivel 4
    if (nivel5Activo) {
        nivel5Ventana.clear(sf::Color::White); // Limpia la ventana del nivel 5 con un color blanco
        // dibujar 
        nivel5Ventana.display(); // Mostramos lo que hemos dibujado en la nueva ventana
    }
}

bool NivelNivel5::estaActivo() const {
    return nivel5Activo; // Devolvemos el estado de la nueva ventana del nivel 5
}
