#ifndef NAVEGADOR_H
#define NAVEGADOR_H

#include "Software.h"

class Navegador : public Software {
private:
    // Declaración de atributos específicos para el historial de navegación.

public:
    Navegador(string nombre, string developer, string clasificacion_edad, int precio);
    // Declaración de métodos específicos para el historial de navegación.
};

#endif // NAVEGADOR_H