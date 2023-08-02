#pragma once

#include "Nivel.h"
#include <unordered_map>

class MultitonNivel {
private:
    // Contenedor para almacenar los punteros a las instancias de los niveles
    static std::unordered_map<int, Nivel*> niveles;

public:
    // M�todo para obtener una instancia del nivel seg�n su n�mero
    static Nivel* getNivel(int numero);
};
