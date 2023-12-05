// main.cpp
#include "Menu.h"
#include "Usuario.h"
#include "Software.h"

int main() {
    // Poblar datos iniciales
    Menu::poblarDatosIniciales();

    Usuario* usuarioActual = nullptr;

    while (true) {
        if (usuarioActual == nullptr) {
            Menu::iniciarSesion();
        } else {
            Menu::mostrarMenu(usuarioActual);
        }
    }

    return 0;
}
