#include "Ofimatica.h"

Ofimatica::Ofimatica(string nombre, string developer, string clasificacion_edad, int precio, int _cantArch)
    : Software(nombre, developer, clasificacion_edad, precio) {
    cantArch = _cantArch;
}

int Ofimatica::getCantArch() {
    return cantArch;
}

void Ofimatica::crearArchivo() {
    // Implementa la lógica para crear un archivo aquí.
}