#ifndef LISTARANKING_H
#define LISTARANKING_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoRanking.h"

class ListaRanking {
private:
    NodoRanking* primero;
    ListaRanking(const ListaRanking&);
    ListaRanking& operator=(const ListaRanking&);
public:
    ListaRanking();
    ~ListaRanking();
    void insertar(Cliente* cliente, int cantidad);
    void mostrar() const;
};
#endif
