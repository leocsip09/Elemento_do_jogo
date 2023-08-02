#pragma once

#include "Nivel.h"
#include <unordered_map>
#include <memory>

class MultitonNivel {
private:
    // Contenedor para almacenar los smart pointers a las instancias de los niveles
    static std::unordered_map<int, std::unique_ptr<Nivel>> niveles;

public:
    // Método para obtener una instancia del nivel según su número
    static Nivel* getNivel(int numero);
};
