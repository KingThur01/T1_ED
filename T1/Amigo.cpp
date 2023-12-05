
#include "Amigo.h"
#include "Usuario.h"

Amigo::Amigo(Usuario* usuario1, Usuario* usuario2) {
    this->usuario1 = usuario1;
    this->usuario2 = usuario2;
}

Usuario* Amigo::getAmigo1() {
    return usuario1;
}

Usuario* Amigo::getAmigo2() {
    return usuario2;
}
