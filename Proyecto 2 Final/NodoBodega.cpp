#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoBodega.h"

NodoBodega* NodoBodega::getSiguiente() const { return siguiente; }
void NodoBodega::setSiguiente(NodoBodega* nuevo) { siguiente = nuevo; }
Bodega* NodoBodega::getDato() const { return dato; }
NodoBodega::NodoBodega(Bodega* d) : dato(d), siguiente(NULL){}
