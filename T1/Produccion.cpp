#include "Produccion.h"

Produccion::Produccion(string nombre, string developer, string clasificacion_edad, int precio, string _tipo)
    : Software(nombre, developer, clasificacion_edad, precio) {
    tipo = _tipo;
}

string Produccion::getTipo() {
    return tipo;
}



