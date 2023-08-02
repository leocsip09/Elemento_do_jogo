#include "NivelNivel3.h"
#include <iostream>

NivelNivel3::NivelNivel3() : Nivel(), nivel3Ventana(sf::VideoMode(1280, 720), "Nivel 3"), nivel3Activo(true) {}


void NivelNivel3::inicializar() {
    // Lógica de inicialización para el nivel 3
    std::cout << "Se inializo el nivel 3 desde multiton" << std::endl;
}

void NivelNivel3::actualizar(sf::RenderWindow& ventana) {
    // Lógica de actualización para el nivel 3
    std::cout << "Se esta actualizando el nivel 3" << std::endl;
    if (nivel3Activo) {
        sf::Event event;
        while (nivel3Ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                nivel3Ventana.close(); // Cerramos la ventana si el usuario la cierra
                nivel3Activo = false; // Marcamos la nueva ventana como no activa
            }
        }
    }
}

void NivelNivel3::dibujar(sf::RenderWindow& ventana) {
    std::cout << "Se esta dibujando el nivel 3" << std::endl;
    //Lógica de dibujar para el nivel 3
    if (nivel3Activo) {
        nivel3Ventana.clear(sf::Color::White); // Limpia la ventana del nivel 3 con un color blanco
        // dibujar 
        nivel3Ventana.display(); // Mostramos lo que hemos dibujado en la nueva ventana
    }
}

bool NivelNivel3::estaActivo() const {
    return nivel3Activo; // Devolvemos el estado de la nueva ventana del nivel 3
}
