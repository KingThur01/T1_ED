
#include "Software.h"
#include "Permiso.h"

Software::Software(string nombre, string developer, string clasificacion_edad, int precio, int _nivelSeguridad) {
    this->nombre = nombre;
    this->developer = developer;
    this->clasificacion_edad = clasificacion_edad;
    this->precio = precio;
    this->nivelSeguridad = _nivelSeguridad;
}

string Software::getNombre() {
    return nombre;
}

string Software::getDeveloper() {
    return developer;
}

int Software::getNivelSeguridad() const {
    return nivelSeguridad;
}

string Software::getClasificacion_edad() {
    return clasificacion_edad;
}

int Software::getPrecio() {
    return precio;
}

vector<Permiso*> Software::getPermisos() {
    return permisos;
}

void Software::agregarPermiso(Permiso* permiso) {
    permisos.push_back(permiso);
}

void Software::eliminarPermiso(Permiso* permiso) {
    for (int i = 0; i < permisos.size(); i++) {
        if (permisos[i] == permiso) {
            permisos.erase(permisos.begin() + i);
            delete permisos[i];
            break;
        }
    }
}

string Software::getTipoUsuario() const {
    return tipoUsuario; 
}

int Software::getEdadMinima() const {
    return edadMinima; 
}
