#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Personaje {
private:
    static Personaje* instance;
    sf::Texture texture;
    sf::Sprite sprite;

    // Constructor privado para evitar la creación de instancias desde fuera de la clase
    Personaje();

public:
    // Método para obtener la instancia única del personaje
    static Personaje* getInstance();

    // Cargar la textura y configurar el sprite del personaje
    void cargarTextura(const std::string& rutaTextura);

    // Dibujar el personaje en la ventana del nivel 1
    void dibujar(sf::RenderWindow& ventana);

    // Otros métodos y funciones del personaje...
};
