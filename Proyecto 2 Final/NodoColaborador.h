#ifndef NODOCOLABORADOR_H
#define NODOCOLABORADOR_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Colaborador.h"

class NodoColaborador {
private:
    Colaborador* dato;
    NodoColaborador* siguiente;
public:
    void destruir();
    ~NodoColaborador();
    NodoColaborador(Colaborador* objeto);
    Colaborador* getDato() const;
    NodoColaborador* getSiguiente() const;
    void setSiguiente(NodoColaborador* nuevo);
};
#endif
