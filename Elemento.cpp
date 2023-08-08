#include "Elemento.h"

Elemento::Elemento(const std::string& tipo) : tipo(tipo) {}

const std::string& Elemento::getTipo() const {
    return tipo;
}