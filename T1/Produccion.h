#ifndef PRODUCCION_H
#define PRODUCCION_H

#include "Software.h"

class Produccion : public Software {
private:
    string tipo;

public:
    Produccion(string nombre, string developer, string clasificacion_edad, int precio, string tipo);
    string getTipo();
};

#endif // PRODUCCION_H