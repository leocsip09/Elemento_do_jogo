#pragma once

#include "Nivel.h"
#include <unordered_map>
#include <memory>

class MultitonNivel {
private:
    // Contenedor para almacenar los smart pointers a las instancias de los niveles
    static std::unordered_map<int, std::unique_ptr<Nivel>> niveles;

public:
    // M�todo para obtener una instancia del nivel seg�n su n�mero
    static Nivel* getNivel(int numero, const std::string& jugador1, const std::string& jugador2);
};
