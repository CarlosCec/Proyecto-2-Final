#ifndef NODOBODEGA_H
#define NODOBODEGA_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Bodega.h"

class NodoBodega {
private:
    Bodega* dato;
    NodoBodega* siguiente;
public:
    void destruir();
    ~NodoBodega();
    NodoBodega(Bodega* d);
    NodoBodega* getSiguiente() const;
    void setSiguiente(NodoBodega* nuevo);
    Bodega* getDato() const;
};
#endif
