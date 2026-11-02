#ifndef NODOPAQUETE_H
#define NODOPAQUETE_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Paquete.h"

class NodoPaquete {
private:
    Paquete* dato;
    NodoPaquete* siguiente;
public:
    void destruir();
    ~NodoPaquete();
    NodoPaquete(Paquete* d);
    NodoPaquete* getSiguiente() const;
    void setSiguiente(NodoPaquete* nuevo);
    Paquete* getDato() const;
};
#endif
