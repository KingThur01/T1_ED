#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <vector>
#include "Permiso.h"
#include "Amigo.h"

using namespace std;

class Usuario {
private:
    string nombre;
    string password;
    int edad;
    string email;
    bool log;
    string tipoUsuario; // niño, normal, administrador
    vector<Amigo*> amigos;
    vector<Permiso*> permisos;
    int nivelSeguridad;

public:
    Usuario(string nombre, string password, int edad, string email, bool log, const string& _tipoUsuario, int nivelSeguridad);
    string getNombre();
    string getPassword();
    int getEdad();
    string getEmail();
    bool getLog();
    string getTipoUsuario();
    vector<Amigo*> getAmigos();
    vector<Permiso*> getPermisos();

    void agregarAmigo(Usuario* amigo);
    void eliminarAmigo(Usuario* amigo);
    void agregarPermiso(Permiso* permiso);
    void eliminarPermiso(Permiso* permiso);
    bool tienePermiso(const Software* software) const;
    int getNivelSeguridad() const;
    
};

#endif
