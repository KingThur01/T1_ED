#ifndef SOFTWARE_H
#define SOFTWARE_H

#include <string>
#include <vector>

using namespace std;

class Permiso; // Declaración adelantada para evitar dependencias circulares

class Software {
protected:
    string nombre;
    string developer;
    string clasificacion_edad;
    int precio;
    vector<Permiso*> permisos;
    int nivelSeguridad;

public:
    Software(string nombre, string developer, string clasificacion_edad, int precio, int _nivelSeguridad);
    string getNombre();
    string getDeveloper();
    string getClasificacion_edad();
    int getPrecio();
    vector<Permiso*> getPermisos();
    virtual void accionEspecial() = 0; // Método virtual puro

    void agregarPermiso(Permiso* permiso);
    void eliminarPermiso(Permiso* permiso);
    virtual string getTipoUsuario() const;
    virtual int getEdadMinima() const;
    int getNivelSeguridad() const;
};

#endif
