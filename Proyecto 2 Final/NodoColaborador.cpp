#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoColaborador.h"


NodoColaborador::NodoColaborador(Colaborador* objeto) : dato(objeto), siguiente(NULL) {}
Colaborador* NodoColaborador::getDato() const { return dato; }
NodoColaborador* NodoColaborador::getSiguiente() const { return siguiente; }
void NodoColaborador::setSiguiente(NodoColaborador* nuevo) { siguiente = nuevo; }
