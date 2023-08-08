#include "MultitonNivel.h"
#include "NivelNivel1.h" 
#include "NivelNivel2.h"
#include "NivelNivel3.h"
#include "NivelNivel4.h"
#include "NivelNivel5.h"

// Inicializamos el contenedor de instancias de niveles
std::unordered_map<int, std::unique_ptr<Nivel>> MultitonNivel::niveles;

Nivel* MultitonNivel::getNivel(int numero, const std::string& jugador1, const std::string& jugador2) {
    auto it = niveles.find(numero);
    if (it != niveles.end()) {
        return it->second.get();
    }
    else {
        std::unique_ptr<Nivel> nivel = nullptr;
        switch (numero) {
        case 1:
            nivel = std::make_unique<NivelNivel1>(jugador1, jugador2);
            break;
        case 2:
            nivel = std::make_unique<NivelNivel2>(jugador1, jugador2);
            break;
        case 3:
            nivel = std::make_unique<NivelNivel3>(jugador1, jugador2);
            break;
        case 4:
            nivel = std::make_unique<NivelNivel4>(jugador1, jugador2);
            break;
        case 5:
            nivel = std::make_unique<NivelNivel5>(jugador1, jugador2);
            break;
        default:
            break;
        }

        if (nivel) {
            nivel->inicializar();
            niveles[numero] = std::move(nivel);
        }

        return niveles[numero].get();
    }
}
