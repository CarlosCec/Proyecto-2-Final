#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Celda.h"

void Celda::setPaquete(Paquete* nuevo) { paquete = nuevo; }
Celda::Celda() : paquete(NULL){}
Paquete* Celda::getPaquete() const { return paquete; }
