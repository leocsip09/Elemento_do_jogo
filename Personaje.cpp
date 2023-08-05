#include "Personaje.h"

Personaje* Personaje::instance = nullptr;

Personaje::Personaje() {
    // Constructor privado para evitar la creación de instancias desde fuera de la clase
}

Personaje* Personaje::getInstance() {
    if (!instance) {
        instance = new Personaje();
    }
    return instance;
}

void Personaje::cargarTextura(const std::string& rutaTextura) {
    if (!texture.loadFromFile(rutaTextura)) {
        // Manejar el error si la carga de la textura falla
    }
    sprite.setTexture(texture);
}

void Personaje::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(sprite);
}

// Otros métodos y funciones del personaje...

