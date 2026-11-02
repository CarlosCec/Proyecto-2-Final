#ifndef LISTASOLICITUDES_H
#define LISTASOLICITUDES_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoSolicitud.h"

class ListaSolicitudes {
private:
    NodoSolicitud* primero;
    ListaSolicitudes(const ListaSolicitudes&);
    ListaSolicitudes& operator=(const ListaSolicitudes&);
public:
    void destruir();
    ListaSolicitudes();
    ~ListaSolicitudes();
    void insertar(SolicitudEnvio* dato);
    SolicitudEnvio* buscar(string clave) const;
    NodoSolicitud* getPrimero() const;
    bool vacia() const;
    void mostrar() const;
};
#endif
