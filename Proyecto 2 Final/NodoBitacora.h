#ifndef NODOBITACORA_H
#define NODOBITACORA_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Colaborador.h"

class NodoBitacora {
private:
    int anterior, nuevo;
    string fecha;
    Colaborador* responsable;
    // Referencia: no se destruye aqui.
    NodoBitacora* siguiente;
public:
    void destruir();
    ~NodoBitacora();
    NodoBitacora(int a, int n, string f, Colaborador* r);
    NodoBitacora* getSiguiente() const;
    void setSiguiente(NodoBitacora* nuevo);
    int getAnterior() const;
    int getNuevo() const;
    string getFecha() const;
    Colaborador* getResponsable() const;
};
#endif
