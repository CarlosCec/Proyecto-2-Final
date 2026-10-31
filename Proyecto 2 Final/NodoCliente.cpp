#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoCliente.h"


NodoCliente::NodoCliente(Cliente* objeto) : dato(objeto), siguiente(NULL) {}
Cliente* NodoCliente::getDato() const { return dato; }
NodoCliente* NodoCliente::getSiguiente() const { return siguiente; }
void NodoCliente::setSiguiente(NodoCliente* nuevo) { siguiente = nuevo; }
