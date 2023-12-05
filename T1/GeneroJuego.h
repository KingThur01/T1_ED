#ifndef GENEROJUEGO_H
#define GENEROJUEGO_H

#include <string>

using namespace std;

class GeneroJuego {
private:
    string nombreGenero;

public:
    GeneroJuego(string nombreGenero);
    string getNombreGenero();
};

#endif
