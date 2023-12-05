#ifndef JUEGO_H
#define JUEGO_H

#include "Software.h"

class Juego : public Software {
private:
    string genero;

public:
    Juego(string nombre, string developer, string clasificacion_edad, int precio, string genero);
    string getGenero();
};

#endif // JUEGO_H
