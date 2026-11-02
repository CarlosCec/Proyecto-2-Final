#ifndef NODODESPACHO_H
#define NODODESPACHO_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Despacho.h"

class NodoDespacho {
private:
    Despacho* dato;
    NodoDespacho* siguiente;
public:
    void destruir();
    ~NodoDespacho();
    NodoDespacho(Despacho* d);
    NodoDespacho* getSiguiente() const;
    void setSiguiente(NodoDespacho* nuevo);
    Despacho* getDato() const;
};
#endif
