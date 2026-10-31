#ifndef LISTABODEGAS_H
#define LISTABODEGAS_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoBodega.h"

class ListaBodegas {
private:
    NodoBodega* primero;
    ListaBodegas(const ListaBodegas&);
    ListaBodegas& operator=(const ListaBodegas&);
public:
    void insertar(Bodega* dato);
    void anexar(NodoBodega* nodo);
    bool eliminar(string codigo);
    ListaBodegas();
    ~ListaBodegas();
    Bodega* buscar(string codigo) const;
    const NodoBodega* getPrimero() const;
    bool vacia() const;
    void mostrar() const;
};
#endif
