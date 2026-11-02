#ifndef NODOCENTRO_H
#define NODOCENTRO_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "CentroDistribucion.h"

class NodoCentro {
private:
    CentroDistribucion* centro;
    NodoCentro* siguiente;
public:
    void destruir();
    ~NodoCentro();
    NodoCentro(CentroDistribucion* objeto);
    CentroDistribucion* getCentro() const;
    NodoCentro* getSiguiente() const;
    void setSiguiente(NodoCentro* nuevo);
};
#endif
