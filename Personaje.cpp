#include "Personaje.h"

Personaje::Personaje() {}

void Personaje::actualizar(float deltaTime) {
    const float velocidadMovimiento = 200.0f;
    const float gravedad = 1000.0f;
    const float saltoVelocidad = -600.0f;

    sf::Vector2f desplazamiento(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        desplazamiento.x -= velocidadMovimiento;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        desplazamiento.x += velocidadMovimiento;
    }

    /*if (!enSuelo) {
        // Aplicar gravedad solo si no est� en el suelo
        desplazamiento.y += gravedad * deltaTime;
    }

    if (enSuelo && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        // Salto solo si est� en el suelo
        desplazamiento.y = saltoVelocidad;
        enSuelo = false;
    }*/

    // Actualizar posici�n
    pos += desplazamiento * deltaTime;

    // Aqu� debes implementar la detecci�n de colisiones con el suelo y las plataformas

    // Actualizar sprite
    sprite.setPosition(pos);
}