#ifndef PERMISO_H
#define PERMISO_H

class Usuario; // Declaración adelantada para evitar dependencias circulares
class Software;

class Permiso {
private:
    Usuario* usuario;
    Software* software;
    bool permisoEliminar;

public:
    Permiso(Usuario* usuario, Software* software, bool permisoEliminar);
    Usuario* getUsuario();
    Software* getSoftware();
    bool tienePermisoEliminar();
};

#endif
