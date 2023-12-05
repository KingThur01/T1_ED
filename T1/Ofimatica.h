#ifndef OFIMATICA_H
#define OFIMATICA_H

#include "Software.h"

class Ofimatica : public Software {
private:
    int cantArch;

public:
    Ofimatica(string nombre, string developer, string clasificacion_edad, int precio, int cantArch);
    int getCantArch();
    void crearArchivo();
};

#endif // OFIMATICA_H