#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoRanking.h"


NodoRanking::NodoRanking(Cliente* c, int n) : cliente(c), cantidad(n), siguiente(NULL) {}
Cliente* NodoRanking::getCliente() const { return cliente; }
int NodoRanking::getCantidad() const { return cantidad; }
NodoRanking* NodoRanking::getSiguiente() const { return siguiente; }
void NodoRanking::setSiguiente(NodoRanking* nuevo) { siguiente = nuevo; }
