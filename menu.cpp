#include "menu.h"
#include "selector_de_niveles.h"
Menu::Menu() {
    ventana = new sf::RenderWindow();
    cerrarVentana = new sf::RectangleShape();
    fuente = new sf::Font();
    imagen = new sf::Texture();
    fondo = new sf::Sprite();

    estab_valores();
}

Menu::~Menu() {
    delete ventana;
    delete cerrarVentana;
    delete fuente;
    delete imagen;
    delete fondo;
}

void Menu::estab_valores() {
    ventana->create(sf::VideoMode(1280, 720), "Elemento do Jogo", sf::Style::Titlebar | sf::Style::Close);
    ventana->setPosition(sf::Vector2i(0, 0));

    pos = 0;
    presionado = laseleccion = false;
    fuente->loadFromFile("./ethn.otf");
    imagen->loadFromFile("./menu.png");

    fondo->setTexture(*imagen);

    pos_mouse = { 0,0 };
    mouse_coord = { 0, 0 };

    opciones = { "Elemento do Jogo", "Jugar", "Salir"};
    textos.resize(3);
    coords = { {575,45},{590,255},{595,387} };
    tam = { 14,35,35};

    for (std::size_t i{}; i < textos.size(); ++i) {
        textos[i].setFont(*fuente);
        textos[i].setString(opciones[i]);
        textos[i].setCharacterSize(tam[i]);
        textos[i].setOutlineColor(sf::Color::Black);
        textos[i].setPosition(coords[i]);
    }
    textos[1].setOutlineThickness(4);
    pos = 1;

    cerrarVentana->setSize(sf::Vector2f(23, 26));
    cerrarVentana->setPosition(1178, 39);
    cerrarVentana->setFillColor(sf::Color::Transparent);

}

void Menu::eventos_bucle() {
    sf::Event event;
    while (ventana->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            ventana->close();
        }

        pos_mouse = sf::Mouse::getPosition(*ventana);
        mouse_coord = ventana->mapPixelToCoords(pos_mouse);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !presionado) {
            if (pos < 2) {
                ++pos;
                presionado = true;
                textos[pos].setOutlineThickness(4);
                textos[pos - 1].setOutlineThickness(0);
                presionado = false;
                laseleccion = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !presionado) {
            if (pos > 1) {
                --pos;
                presionado = true;
                textos[pos].setOutlineThickness(4);
                textos[pos + 1].setOutlineThickness(0);
                presionado = false;
                laseleccion = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !laseleccion) {
            laseleccion = true;
            if (pos == 2) {
                std::cout << "Juego cerrado" << '\n';
                ventana->close();
            }
            std::cout << opciones[pos] << '\n';
            
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (cerrarVentana->getGlobalBounds().contains(mouse_coord)) {
                std::cout << "Juego cerrado" << '\n';
                ventana->close();
            }
        }
    }
}

void Menu::draw_todo() {
    ventana->clear();
    ventana->draw(*fondo);
    for (auto t : textos) {
        ventana->draw(t);
    }
    ventana->display();
}

void Menu::run_menu() {
    while (ventana->isOpen()) {
        eventos_bucle();
        draw_todo();
        if (laseleccion && pos == 1) {
            // Aquí abrimos la ventana del selector de niveles
            SelectorDeNiveles selector;
            selector.run_Selector();
            laseleccion = false; // Restablecemos el indicador de selección para futuros usos
        }
    }
}
