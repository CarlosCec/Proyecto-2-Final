#ifndef LISTACENTROS_H
#define LISTACENTROS_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoCentro.h"

class ListaCentros {
private:
    NodoCentro* primero;
    ListaCentros(const ListaCentros&);
    ListaCentros& operator=(const ListaCentros&);
public:
    void destruir();
    ListaCentros();
    ~ListaCentros();
    void insertar(CentroDistribucion* dato);
    CentroDistribucion* buscar(string clave) const;
    NodoCentro* getPrimero() const;
    bool vacia() const;
    void mostrar() const;
    bool eliminar(string clave);
};
#endif
