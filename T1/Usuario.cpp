#include "Usuario.h"
#include "Software.h"


Usuario::Usuario(string nombre, string password, int edad, string email, bool log, const string& _tipoUsuario, int nivelSeguridad) {
    this->nombre = nombre;
    this->password = password;
    this->edad = edad;
    this->email = email;
    this->log = log;
    this->tipoUsuario = _tipoUsuario;
    this->nivelSeguridad = nivelSeguridad;
}

string Usuario::getNombre() {
    return nombre;
}

string Usuario::getPassword() {
    return password;
}

int Usuario::getEdad() {
    return edad;
}

string Usuario::getEmail() {
    return email;
}

bool Usuario::getLog() {
    return log;
}

string Usuario::getTipoUsuario() {
    return tipoUsuario;
}

vector<Amigo*> Usuario::getAmigos() {
    return amigos;
}

vector<Permiso*> Usuario::getPermisos() {
    return permisos;
}

void Usuario::agregarAmigo(Usuario* amigo) {
    Amigo* nuevaAmistad = new Amigo(this, amigo);
    amigos.push_back(nuevaAmistad);
}

void Usuario::eliminarAmigo(Usuario* amigo) {
    for (int i = 0; i < amigos.size(); i++) {
        if (amigos[i]->getAmigo2() == amigo) {
            amigos.erase(amigos.begin() + i);
            delete amigos[i];
            break;
        }
    }
}

void Usuario::agregarPermiso(Permiso* permiso) {
    permisos.push_back(permiso);
}

void Usuario::eliminarPermiso(Permiso* permiso) {
    for (int i = 0; i < permisos.size(); i++) {
        if (permisos[i] == permiso) {
            permisos.erase(permisos.begin() + i);
            delete permisos[i];
            break;
        }
    }
}

bool Usuario::tienePermiso(const Software* software) const {
    if (this->tipoUsuario == "administrador") {
        return true;
    }

    if (software->getTipoUsuario() == "todos") {
        return true;
    }

    int edadUsuario = this->edad;
    int edadMinima = software->getEdadMinima();
    if (edadUsuario < edadMinima) {
        return false;
    }

    int nivelSeguridadUsuario = this->nivelSeguridad;
    int nivelSeguridadRequerido = software->getNivelSeguridad();
    if (nivelSeguridadUsuario >= nivelSeguridadRequerido) {
        return true;
    }
    return false;
}

int Usuario::getNivelSeguridad() const {
    return nivelSeguridad;
}

