#ifndef LISTAPAQUETES_H
#define LISTAPAQUETES_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoPaquete.h"

class ListaPaquetes {
private:
    NodoPaquete* primero;
    ListaPaquetes(const ListaPaquetes&);
    ListaPaquetes& operator=(const ListaPaquetes&);
public:
    void destruir();
    void insertar(Paquete* dato);
    void anexar(NodoPaquete* nodo);
    bool eliminar(string codigo);
    ListaPaquetes();
    ~ListaPaquetes();
    Paquete* buscar(string codigo) const;
    const NodoPaquete* getPrimero() const;
    bool vacia() const;
    void mostrar() const;
};
#endif
