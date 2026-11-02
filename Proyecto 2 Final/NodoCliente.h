#ifndef NODOCLIENTE_H
#define NODOCLIENTE_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Cliente.h"

class NodoCliente {
private:
    Cliente* dato;
    NodoCliente* siguiente;
public:
    void destruir();
    ~NodoCliente();
    NodoCliente(Cliente* objeto);
    Cliente* getDato() const;
    NodoCliente* getSiguiente() const;
    void setSiguiente(NodoCliente* nuevo);
};
#endif
