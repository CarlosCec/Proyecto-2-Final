#ifndef NODOSOLICITUD_H
#define NODOSOLICITUD_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "SolicitudEnvio.h"

class NodoSolicitud {
private:
    SolicitudEnvio* dato;
    NodoSolicitud* siguiente;
public:
    NodoSolicitud(SolicitudEnvio* objeto);
    SolicitudEnvio* getDato() const;
    NodoSolicitud* getSiguiente() const;
    void setSiguiente(NodoSolicitud* nuevo);
};
#endif
