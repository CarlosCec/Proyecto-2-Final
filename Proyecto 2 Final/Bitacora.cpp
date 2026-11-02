#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Bitacora.h"

Bitacora::Bitacora() {
    this->primero = NULL;
}

Bitacora::~Bitacora() {
}

void Bitacora::destruir() {
    while (primero != NULL) {
        NodoBitacora* borrar = primero;
        primero = primero->getSiguiente();
        borrar->destruir();
        delete borrar;
    }
}

void Bitacora::agregar(int anterior, int nuevo, string fecha, Colaborador* responsable) {
    NodoBitacora* nodo = new NodoBitacora(anterior, nuevo, fecha, responsable);
    if (primero == NULL) {
        primero = nodo;
    } else {
        NodoBitacora* actual = primero;
        while (actual->getSiguiente() != NULL) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nodo);
    }
}

void Bitacora::mostrar() const {
    if (primero == NULL) {
        cout << "Sin cambios de estado.\n";
    }
    NodoBitacora* actual = primero;
    while (actual != NULL) {
        cout << nombreEstado(actual->getAnterior()) << " -> " << nombreEstado(actual->getNuevo()) << " | " << actual->getFecha() << " | Colaborador: " << actual->getResponsable()->getIdentificacion() << '\n';
        actual = actual->getSiguiente();
    }
}

bool Bitacora::usaColaborador(Colaborador* colaborador) const {
    NodoBitacora* actual = primero;
    while (actual != NULL) {
        if (actual->getResponsable() == colaborador) {
            return true;
        }
        actual = actual->getSiguiente();
    }
    return false;
}

int Bitacora::cantidad() const {
    int n = 0;
    NodoBitacora* actual = primero;
    while (actual != NULL) {
        n++;
        actual = actual->getSiguiente();
    }
    return n;
}
