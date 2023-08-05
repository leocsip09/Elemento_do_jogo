#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Personaje {
private:
    static Personaje* instance;
    sf::Texture texture;
    sf::Sprite sprite;

    // Constructor privado para evitar la creaci�n de instancias desde fuera de la clase
    Personaje();

public:
    // M�todo para obtener la instancia �nica del personaje
    static Personaje* getInstance();

    // Cargar la textura y configurar el sprite del personaje
    void cargarTextura(const std::string& rutaTextura);

    // Dibujar el personaje en la ventana del nivel 1
    void dibujar(sf::RenderWindow& ventana);

    // Otros m�todos y funciones del personaje...
};
