#ifndef DATOSPRUEBA_H
#define DATOSPRUEBA_H
#include <sstream>
#include <iostream>
#include <string>
#include "Sistema.h"
using namespace std;

class DatosPrueba {
public:
    void destruir();
    ~DatosPrueba();
    static bool cargar(Sistema& sistema);
};
#endif
