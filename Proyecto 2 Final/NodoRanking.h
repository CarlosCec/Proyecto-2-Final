#ifndef NODORANKING_H
#define NODORANKING_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Cliente.h"

class NodoRanking {
private:
    Cliente* cliente;
    int cantidad;
    NodoRanking* siguiente;
public:
    void destruir();
    ~NodoRanking();
    NodoRanking(Cliente* cliente, int cantidad);
    Cliente* getCliente() const;
    int getCantidad() const;
    NodoRanking* getSiguiente() const;
    void setSiguiente(NodoRanking* nuevo);
};
#endif
