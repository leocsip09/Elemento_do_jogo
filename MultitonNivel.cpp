#include "MultitonNivel.h"
#include "NivelNivel1.h" 
#include "NivelNivel2.h"
#include "NivelNivel3.h"
#include "NivelNivel4.h"
#include "NivelNivel5.h"

// Inicializamos el contenedor de instancias de niveles
std::unordered_map<int, Nivel*> MultitonNivel::niveles;

Nivel* MultitonNivel::getNivel(int numero) {
    // Verificamos si el nivel ya ha sido creado
    auto it = niveles.find(numero);
    if (it != niveles.end()) {
        // Si el nivel ya existe, devolvemos la instancia existente
        return it->second;
    }
    else {
        // Si el nivel no existe, lo creamos y lo almacenamos en el contenedor según su número
        Nivel* nivel = nullptr;
        switch (numero) {
        case 1:
            nivel = new NivelNivel1();
            break;
        case 2:
            nivel = new NivelNivel2();
            break;
        case 3:
            nivel = new NivelNivel3();
            break;
        case 4:
            nivel = new NivelNivel4();
            break;
        case 5:
            nivel = new NivelNivel5();
            break;
        default:
            break;
        }

        if (nivel) {
            nivel->inicializar();
            niveles[numero] = nivel;
        }

        return nivel;
    }
}
