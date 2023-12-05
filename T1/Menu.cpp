#include "Menu.h"
#include "Usuario.h"
#include "Software.h"
#include "GeneroJuego.h"
#include <iostream>

using namespace std;

void Menu::mostrarMenu(Usuario* usuario) {
    cout << "Bienvenido, " << usuario->getNombre() << "!" << endl;
    cout << "Menú de opciones:" << endl;
    cout << "1. Ver software disponible" << endl;
    cout << "2. Acceder a un software" << endl;
    cout << "3. Administrar amigos" << endl;
    cout << "4. Cerrar sesión" << endl;

    int opcion;
    cout << "Seleccione una opción: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            verSoftwareDisponible();
            break;
        case 2:
            accederSoftware(usuario);
            break;
        case 3:
            administrarAmigos(usuario);
            break;
        case 4:
            cerrarSesion(usuario);
            break;
        default:
            cout << "Opción no válida." << endl;
    }
}

void Menu::verSoftwareDisponible() {
    cout << "Software disponible:" << endl;

    for (int i = 0; i < softwareDisponible.size(); i++) {
        Software* software = softwareDisponible[i];
        cout << i + 1 << ". " << software->getNombre() << " - Desarrollador: " << software->getDeveloper() << " - Precio: $" << software->getPrecio() << endl;
    }
}

void Menu::accederSoftware(Usuario* usuario) {
    cout << "Acceder a un software:" << endl;
    cout << "Ingrese el nombre del software que desea acceder: ";
    string nombreSoftware;
    cin.ignore(); // Limpia el buffer de entrada
    getline(cin, nombreSoftware);

    Software* software = buscarSoftwarePorNombre(nombreSoftware);

    if (software != nullptr) {
        if (usuario->tienePermiso(software)) {
            cout << "Acceso concedido a " << software->getNombre() << "." << endl;
        } else {
            cout << "No tiene permisos para acceder a este software." << endl;
        }
    } else {
        cout << "Software no encontrado." << endl;
    }
}

void Menu::administrarAmigos(Usuario* usuario) {
    
    cout << "Administrar amigos:" << endl;
    cout << "1. Agregar amigo" << endl;
    cout << "2. Eliminar amigo" << endl;
    cout << "3. Ver lista de amigos" << endl;
    cout << "4. Volver al menú principal" << endl;

    int opcion;
    cout << "Seleccione una opción: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            agregarAmigo(usuario);
            break;
        case 2:
            eliminarAmigo(usuario);
            break;
        case 3:
            verListaAmigos(usuario);
            break;
        case 4:
            break;
        default:
            cout << "Opción no válida." << endl;
    }
}

void Menu::agregarAmigo(Usuario* usuario) {
    
    cout << "Agregar amigo:" << endl;
    cout << "Ingrese el nombre del amigo que desea agregar: ";
    string nombreAmigo;
    cin.ignore(); // Limpia el buffer de entrada
    getline(cin, nombreAmigo);

    Usuario* amigo = buscarUsuarioPorNombre(nombreAmigo);

    if (amigo != nullptr) {
        if (amigo != usuario) {
            usuario->agregarAmigo(amigo);
            cout << "Amigo agregado con éxito." << endl;
        } else {
            cout << "No puedes agregarte a ti como amigo." << endl;
        }
    } else {
        cout << "Amigo no encontrado en el sistema." << endl;
    }
}

void Menu::eliminarAmigo(Usuario* usuario) {
    
    cout << "Eliminar amigo:" << endl;
    cout << "Ingrese el nombre del amigo que desea eliminar: ";
    string nombreAmigo;
    cin.ignore(); // Limpia el buffer de entrada
    getline(cin, nombreAmigo);

    if (usuario->tieneAmigo(nombreAmigo)) {
        usuario->eliminarAmigo(nombreAmigo);
        cout << "Amigo eliminado con éxito." << endl;
    } else {
        cout << "Amigo no encontrado en tu lista de amigos." << endl;
    }
}

void Menu::verListaAmigos(Usuario* usuario) {
    
    vector<Amigo*> listaAmigos = usuario->getListaAmigos();
    if (!listaAmigos.empty()) {
        cout << "Lista de amigos de " << usuario->getNombre() << ":" << endl;
        for (const Amigo* amigo : listaAmigos) {
            cout << "- " << amigo->getNombre() << endl;
        }
    } else {
        cout << "No tienes amigos en tu lista." << endl;
    }
}


void Menu::iniciarSesion() {
    
    string nombreUsuario;
    string contrasena;

    cout << "Iniciar sesión" << endl;
    cout << "Nombre de usuario: ";
    cin >> nombreUsuario;

    Usuario* usuarioAutenticado = buscarUsuario(nombreUsuario);

    if (usuarioAutenticado != nullptr) {
        cout << "Contraseña: ";
        cin >> contrasena;
        if (usuarioAutenticado->verificarContrasena(contrasena)) {
            cout << "Inicio de sesión exitoso." << endl;
            mostrarMenu(usuarioAutenticado);
        } else {
            cout << "Contraseña incorrecta. Inicio de sesión fallido." << endl;
        }
    } else {
        cout << "Usuario no encontrado. Inicio de sesión fallido." << endl;
    }
}

void Menu::cerrarSesion(Usuario*& usuarioActual) {
    if (usuarioActual != nullptr) {
        delete usuarioActual;
        usuarioActual = nullptr;
        cout << "Sesión cerrada. Hasta luego." << endl;
    } else {
        cout << "No hay una sesión activa para cerrar." << endl;
    }
}

Software* Menu::buscarSoftwarePorNombre(const std::string& nombre) {
    for (Software* software : softwareDisponible) {
        if (software->getNombre() == nombre) {
            return software;
        }
    }
    return nullptr;
}


void Menu::poblarDatosIniciales() {
    // Crear usuarios
    Usuario* administrador = new Usuario("admin", "adminpass", 30, "admin@example.com", TipoUsuario::ADMINISTRADOR);
    Usuario* usuario1 = new Usuario("usuario1", "password1", 25, "user1@example.com", TipoUsuario::NORMAL);
    Usuario* usuario2 = new Usuario("usuario2", "password2", 22, "user2@example.com", TipoUsuario::NORMAL);
    // Agregar más usuarios según tus necesidades

    // Crear software
    Software* juego1 = new Software("Juego1", "Developer1", "18+", 50, TipoSoftware::JUEGO);
    Software* juego2 = new Software("Juego2", "Developer2", "12+", 40, TipoSoftware::JUEGO);
    Software* ofimatica1 = new Software("Ofimatica1", "Developer3", "Todos", 20, TipoSoftware::OFIMATICA);
    Software* social1 = new Software("Social1", "Developer4", "18+", 30, TipoSoftware::SOCIAL);
    // Agregar más software según tus necesidades

    // Crear géneros de juego
    GeneroJuego* generoAccion = new GeneroJuego("Acción");
    GeneroJuego* generoAventura = new GeneroJuego("Aventura");
    // Agregar más géneros de juego según tus necesidades

    // Agregar géneros a juegos
    juego1->agregarGenero(generoAccion);
    juego2->agregarGenero(generoAventura);

    // Crear amigos
    Amigo* amigo1 = new Amigo(usuario1, usuario2);
    Amigo* amigo2 = new Amigo(usuario1, administrador);
    // Agregar más relaciones de amistad según tus necesidades

    // Agregar amigos a usuarios (en la lista de amigos de cada usuario)
    usuario1->agregarAmigo(amigo1);
    usuario1->agregarAmigo(amigo2);
    usuario2->agregarAmigo(amigo1);

    // Asignar permisos a software (dependiendo de tus requisitos específicos)
    Permiso* permiso1 = new Permiso(administrador, TipoPermiso::ACCESO_TOTAL);
    juego1->agregarPermiso(permiso1);
    // Agregar más permisos a software según tus necesidades
}