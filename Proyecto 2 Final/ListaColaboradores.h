#ifndef LISTACOLABORADORES_H
#define LISTACOLABORADORES_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoColaborador.h"

class ListaColaboradores {
private:
    NodoColaborador* primero;
    ListaColaboradores(const ListaColaboradores&);
    ListaColaboradores& operator=(const ListaColaboradores&);
public:
    void destruir();
    ListaColaboradores();
    ~ListaColaboradores();
    void insertar(Colaborador* dato);
    Colaborador* buscar(string clave) const;
    NodoColaborador* getPrimero() const;
    bool vacia() const;
    void mostrar() const;
    bool eliminar(string clave);
};
#endif
