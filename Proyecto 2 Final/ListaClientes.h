#ifndef LISTACLIENTES_H
#define LISTACLIENTES_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoCliente.h"

class ListaClientes {
private:
    NodoCliente* primero;
    ListaClientes(const ListaClientes&);
    ListaClientes& operator=(const ListaClientes&);
public:
    ListaClientes();
    ~ListaClientes();
    void insertar(Cliente* dato);
    Cliente* buscar(string clave) const;
    NodoCliente* getPrimero() const;
    bool vacia() const;
    void mostrar() const;
    bool eliminar(string clave);
};
#endif
