#ifndef MENU_H
#define MENU_H

#include "Usuario.h"
#include "Software.h"

class Menu {
public:
    static void mostrarMenu(Usuario* usuario);
    static void verSoftwareDisponible();
    static void accederSoftware(Usuario* usuario);
    static void administrarAmigos(Usuario* usuario);
    static void verListaAmigos(Usuario* usuario);
    static void eliminarAmigo(Usuario* usuario);
    static void agregarAmigo(Usuario* usuario);
    static void iniciarSesion();
    static void cerrarSesion(Usuario*& usuarioActual);
    static void poblarDatosIniciales();
    
    static Software* buscarSoftwarePorNombre(const std::string& nombre);
};

#endif
