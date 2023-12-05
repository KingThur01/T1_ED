
#include "Permiso.h"
#include "Usuario.h"
#include "Software.h"

Permiso::Permiso(Usuario* usuario, Software* software, bool permisoEliminar) {
    this->usuario = usuario;
    this->software = software;
    this->permisoEliminar = permisoEliminar;
}

Usuario* Permiso::getUsuario() {
    return usuario;
}

Software* Permiso::getSoftware() {
    return software;
}

bool Permiso::tienePermisoEliminar() {
    return permisoEliminar;
}
