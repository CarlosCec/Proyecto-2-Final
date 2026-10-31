#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoSolicitud.h"


NodoSolicitud::NodoSolicitud(SolicitudEnvio* objeto) : dato(objeto), siguiente(NULL) {}
SolicitudEnvio* NodoSolicitud::getDato() const { return dato; }
NodoSolicitud* NodoSolicitud::getSiguiente() const { return siguiente; }
void NodoSolicitud::setSiguiente(NodoSolicitud* nuevo) { siguiente = nuevo; }
