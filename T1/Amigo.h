#ifndef AMIGO_H
#define AMIGO_H

class Usuario; // Declaración adelantada para evitar dependencias circulares

class Amigo {
private:
    Usuario* usuario1;
    Usuario* usuario2;

public:
    Amigo(Usuario* usuario1, Usuario* usuario2);
    Usuario* getAmigo1();
    Usuario* getAmigo2();
};

#endif
