#include "NivelNivel1.h"
#include "Plataforma.h"
#include "PlataformaPinchos.h"
#include <iostream>
#include "selector_de_niveles.h"
#include "PlataformaFuego.h"
#include "PlataformaAgua.h"
#include "PlataformaTierra.h"
#include "PlataformaPlanta.h"
#include "PersonajeFuego.h"
#include "PersonajeTierra.h"
#include "PersonajePlanta.h"
#include "PersonajeAgua.h"


NivelNivel1::NivelNivel1(const std::string& jugador1, const std::string& jugador2)
    : Nivel(), nivel1Ventana(sf::VideoMode(1280, 720), "Nivel 1"), nivel1Activo(true),
    seleccionJugador1(jugador1), seleccionJugador2(jugador2) {
    imagen = std::make_unique<sf::Texture>();
    fondo = std::make_unique<sf::Sprite>();
    cerrarNivel1 = std::make_unique<sf::RectangleShape>();
    std::cout << "Se inicializo el nivel 1 desde multiton" << std::endl;

    if (seleccionJugador1 == "Fenix") {
        personajeJugador1 = std::make_unique<PersonajeFuego>();
    }
    else if (seleccionJugador1 == "Terraneitor") {
        personajeJugador1 = std::make_unique<PersonajeTierra>();
    }
    else if (seleccionJugador1 == "Poseidon") {
        personajeJugador1 = std::make_unique<PersonajeAgua>();
    }
    else if (seleccionJugador1 == "Alfalfa") {
        personajeJugador1 = std::make_unique<PersonajePlanta>();
    }

    if (seleccionJugador2 == "Fenix") {
        personajeJugador2 = std::make_unique<PersonajeFuego>();
    }
    else if (seleccionJugador2 == "Terraneitor") {
        personajeJugador2 = std::make_unique<PersonajeTierra>();
    }
    else if (seleccionJugador2 == "Poseidon") {
        personajeJugador2 = std::make_unique<PersonajeAgua>();
    }
    else if (seleccionJugador2 == "Alfalfa") {
        personajeJugador2 = std::make_unique<PersonajePlanta>();
    }

}


void NivelNivel1::inicializar() {}

void NivelNivel1::actualizar(sf::RenderWindow & ventana){
    if (nivel1Activo) {
        sf::Event event;
        while (nivel1Ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                nivel1Ventana.close();
                nivel1Activo = false;
            }
        }
        pos_mouse = sf::Mouse::getPosition(nivel1Ventana);
        mouse_coord = nivel1Ventana.mapPixelToCoords(pos_mouse);
        
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (cerrarNivel1->getGlobalBounds().contains(mouse_coord)) {
                std::cout << "Nivel 1 cerrado" << '\n';
                nivel1Ventana.close();
                nivel1Activo = false;
            }
        }
        
    }
}

void NivelNivel1::dibujar(sf::RenderWindow& ventana) {
    if (nivel1Activo) {
        
        Plataforma plataforma;
        PlataformaPinchos pinchos;
        pos_mouse = { 0,0 };
        sf::Texture puertaTexture;
        sf::Sprite puertaSprite;
        sf::Texture pisoTexture;
        sf::Sprite pisoSprite;
        puertaTexture.loadFromFile("Puerta.png");
        puertaSprite.setTexture(puertaTexture);
        pisoTexture.loadFromFile("Piso.png");
        pisoSprite.setTexture(pisoTexture);
        pisoSprite.setPosition(0, 0);
        pos_mouse = { 0,0 };

        nivel1Ventana.clear();
        imagen->loadFromFile("./nivel1_fondo.png");
        fondo->setTexture(*imagen);
        nivel1Ventana.draw(*fondo);

        nivel1Ventana.draw(pisoSprite);
        cerrarNivel1->setSize(sf::Vector2f(23, 26));
        cerrarNivel1->setPosition(1178, 39);
        cerrarNivel1->setFillColor(sf::Color::Transparent);
        nivel1Ventana.draw(*cerrarNivel1); // Dibujamos el rect·ngulo cerrarVentana

        personajeJugador1->dibujar(nivel1Ventana, { 0, 500 });
        personajeJugador2->dibujar(nivel1Ventana, { 0, 500 });
        

        plataforma.dibujar(nivel1Ventana, { 200, 600 });
        plataforma.dibujar(nivel1Ventana, { 322, 600 });
        pinchos.dibujar(nivel1Ventana, { 444, 600 });
        plataforma.dibujar(nivel1Ventana, { 566, 600 });
        plataforma.dibujar(nivel1Ventana, { 700, 530 });
        plataforma.dibujar(nivel1Ventana, { 822, 530 });
        plataforma.dibujar(nivel1Ventana, { 970, 450 });
        plataforma.dibujar(nivel1Ventana, { 822, 350 });
        pinchos.dibujar(nivel1Ventana, { 1100, 665 });

        if (seleccionJugador1 == "Fenix") {
            PlataformaFuego fuego;
            fuego.dibujar(nivel1Ventana, { 700, 350 });
        }
        else if (seleccionJugador1 == "Poseidon") {
            PlataformaAgua agua;
            agua.dibujar(nivel1Ventana, { 700, 350 });
        }
        else if (seleccionJugador1 == "Terraneitor") {
            PlataformaTierra tierra;
            tierra.dibujar(nivel1Ventana, { 700, 350 });
        }
        else if (seleccionJugador1 == "Alfalfa") {
            PlataformaPlanta planta;
            planta.dibujar(nivel1Ventana, { 700, 350 });
        }
        plataforma.dibujar(nivel1Ventana, { 576, 350 });
        plataforma.dibujar(nivel1Ventana, { 332, 350 });
        plataforma.dibujar(nivel1Ventana, { 190, 270 });
        pinchos.dibujar(nivel1Ventana, { 50, 350 });
        plataforma.dibujar(nivel1Ventana, { 340, 160 });
        if (seleccionJugador2 == "Fenix") {
            PlataformaFuego fuego2;
            fuego2.dibujar(nivel1Ventana, { 462, 160 });
        }
        else if (seleccionJugador2 == "Poseidon") {
            PlataformaAgua agua2;
            agua2.dibujar(nivel1Ventana, { 462, 160 });
        }
        else if (seleccionJugador2 == "Terraneitor") {
            PlataformaTierra tierra2;
            tierra2.dibujar(nivel1Ventana, { 462, 160 });
        }
        else if (seleccionJugador2 == "Alfalfa") {
            PlataformaPlanta planta2;
            planta2.dibujar(nivel1Ventana, { 462, 160 });
        }
        plataforma.dibujar(nivel1Ventana, { 584, 160 });
        plataforma.dibujar(nivel1Ventana, { 828, 160 });
        plataforma.dibujar(nivel1Ventana, { 1072, 160 });
        
        puertaSprite.setPosition(1082, 40);
        nivel1Ventana.draw(puertaSprite);

        cerrarNivel1->setSize(sf::Vector2f(23, 26));
        cerrarNivel1->setPosition(1178, 39);
        cerrarNivel1->setFillColor(sf::Color::Transparent);
        nivel1Ventana.draw(*cerrarNivel1); // Dibujamos el rect√°ngulo cerrarVentana

        nivel1Ventana.display(); // Mostramos lo que hemos dibujado en la nueva ventana
    }
}

bool NivelNivel1::estaActivo() const {
    return nivel1Activo; // Devolvemos el estado de la nueva ventana del nivel 1
}


NivelNivel1::~NivelNivel1() {}


