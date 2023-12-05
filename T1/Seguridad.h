#ifndef SEGURIDAD_H
#define SEGURIDAD_H

#include "Software.h"

class Seguridad : public Software {
private:
    string tipo;

public:
    Seguridad(string nombre, string developer, string clasificacion_edad, int precio, string tipo);
    string getTipo();
};

#endif // SEGURIDAD_H