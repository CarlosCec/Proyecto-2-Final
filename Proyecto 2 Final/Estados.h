#ifndef ESTADOS_B_H
#define ESTADOS_B_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

const int RECIBIDO = 0;
const int ALMACENADO = 1;
const int EN_TRANSITO = 2;
const int ENTREGADO = 3;
const int INCIDENCIA = 4;
string nombreCategoria(int tipo);
string nombreEstado(int estado);
#endif
