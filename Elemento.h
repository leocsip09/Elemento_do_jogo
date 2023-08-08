#pragma once
#include <SFML/Graphics.hpp>

class Elemento {
private:
    std::string tipo;

public:
    Elemento(const std::string& tipo);
    const std::string& getTipo() const;
};
