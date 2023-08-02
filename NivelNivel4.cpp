#include "NivelNivel4.h"
#include <iostream>

NivelNivel4::NivelNivel4() : Nivel(), nivel4Ventana(sf::VideoMode(1280, 720), "Nivel 4"), nivel4Activo(true) {}


void NivelNivel4::inicializar() {
    // Lógica de inicialización para el nivel 4
    std::cout << "Se inializo el nivel 4 desde multiton" << std::endl;
}

void NivelNivel4::actualizar(sf::RenderWindow& ventana) {
    // Lógica de actualización para el nivel 4
    std::cout << "Se esta actualizando el nivel 4" << std::endl;
    if (nivel4Activo) {
        sf::Event event;
        while (nivel4Ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                nivel4Ventana.close(); // Cerramos la ventana si el usuario la cierra
                nivel4Activo = false; // Marcamos la nueva ventana como no activa
            }
        }
    }
}

void NivelNivel4::dibujar(sf::RenderWindow& ventana) {
    std::cout << "Se esta dibujando el nivel 4" << std::endl;
    //Lógica de dibujar para el nivel 4
    if (nivel4Activo) {
        nivel4Ventana.clear(sf::Color::White); // Limpia la ventana del nivel 4 con un color blanco
        // dibujar 
        nivel4Ventana.display(); // Mostramos lo que hemos dibujado en la nueva ventana
    }
}

bool NivelNivel4::estaActivo() const {
    return nivel4Activo; // Devolvemos el estado de la nueva ventana del nivel 4
}
