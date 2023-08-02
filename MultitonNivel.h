#pragma once

#include "Nivel.h"
#include <unordered_map>

class MultitonNivel {
private:
    // Contenedor para almacenar los punteros a las instancias de los niveles
    static std::unordered_map<int, Nivel*> niveles;

public:
    // Método para obtener una instancia del nivel según su número
    static Nivel* getNivel(int numero);
};
