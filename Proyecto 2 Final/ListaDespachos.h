#ifndef LISTADESPACHOS_H
#define LISTADESPACHOS_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoDespacho.h"

class ListaDespachos {
private:
    NodoDespacho* primero;
    ListaDespachos(const ListaDespachos&);
    ListaDespachos& operator=(const ListaDespachos&);
public:
    void destruir();
    void insertar(Despacho* dato);
    void anexar(NodoDespacho* nodo);
    ListaDespachos();
    ~ListaDespachos();
    Despacho* buscar(string codigo) const;
    const NodoDespacho* getPrimero() const;
    bool vacia() const;
    void mostrar() const;
};
#endif
