#include "MultitonNivel.h"
#include "NivelNivel1.h" 
#include "NivelNivel2.h"
#include "NivelNivel3.h"
#include "NivelNivel4.h"
#include "NivelNivel5.h"

// Inicializamos el contenedor de instancias de niveles
std::unordered_map<int, std::unique_ptr<Nivel>> MultitonNivel::niveles;

Nivel* MultitonNivel::getNivel(int numero) {
    // Verificamos si el nivel ya ha sido creado
    auto it = niveles.find(numero);
    if (it != niveles.end()) {
        // Si el nivel ya existe, devolvemos la instancia existente
        return it->second.get();
    }
    else {
        // Si el nivel no existe, lo creamos y lo almacenamos en el contenedor según su número
        std::unique_ptr<Nivel> nivel = nullptr;
        switch (numero) {
        case 1:
            nivel = std::make_unique<NivelNivel1>();
            break;
        case 2:
            nivel = std::make_unique<NivelNivel2>();
            break;
        case 3:
            nivel = std::make_unique<NivelNivel3>();
            break;
        case 4:
            nivel = std::make_unique<NivelNivel4>();
            break;
        case 5:
            nivel = std::make_unique<NivelNivel5>();
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
