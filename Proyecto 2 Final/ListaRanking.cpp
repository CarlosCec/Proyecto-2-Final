#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "ListaRanking.h"


ListaRanking::ListaRanking() : primero(NULL) {}
ListaRanking::~ListaRanking() {
    while (primero != NULL) {
        NodoRanking* borrar = primero;
        primero = primero->getSiguiente();
        delete borrar; // El cliente pertenece al centro, no al ranking.
    }
}
void ListaRanking::insertar(Cliente* cliente, int cantidad) {
    NodoRanking* nuevo = new NodoRanking(cliente, cantidad);
    if (primero == NULL || cantidad > primero->getCantidad()) {
        nuevo->setSiguiente(primero);
        primero = nuevo;
    } else {
        NodoRanking* actual = primero;
        // El >= inserta despues de los empatados y conserva su orden original.
        while (actual->getSiguiente() != NULL && actual->getSiguiente()->getCantidad() >= cantidad)
            actual = actual->getSiguiente();
        nuevo->setSiguiente(actual->getSiguiente());
        actual->setSiguiente(nuevo);
    }
}
void ListaRanking::mostrar() const {
    if (primero == NULL) cout << "Sin clientes.\n";
    NodoRanking* actual = primero;
    while (actual != NULL) {
        cout << actual->getCliente()->getIdentificacion() << " | "
             << actual->getCliente()->getNombre() << " | Finalizados: "
             << actual->getCantidad() << '\n';
        actual = actual->getSiguiente();
    }
}
