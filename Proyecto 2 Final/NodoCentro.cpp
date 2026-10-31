#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoCentro.h"


NodoCentro::NodoCentro(CentroDistribucion* objeto) : centro(objeto), siguiente(NULL) {}
CentroDistribucion* NodoCentro::getCentro() const { return centro; }
NodoCentro* NodoCentro::getSiguiente() const { return siguiente; }
void NodoCentro::setSiguiente(NodoCentro* nuevo) { siguiente = nuevo; }
