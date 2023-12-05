#include "Juego.h"

Juego::Juego(string nombre, string developer, string clasificacion_edad, int precio, string _genero)
    : Software(nombre, developer, clasificacion_edad, precio) {
    genero = _genero;
}

string Juego::getGenero() {
    return genero;
}
