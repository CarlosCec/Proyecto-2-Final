#ifndef BITACORA_H
#define BITACORA_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "NodoBitacora.h"
#include "Estados.h"

class Bitacora {
private:
    NodoBitacora* primero;
    Bitacora(const Bitacora&);
    Bitacora& operator=(const Bitacora&);
public:
    void agregar(int anterior, int nuevo, string fecha, Colaborador* responsable);
    Bitacora();
    ~Bitacora();
    void mostrar() const;
    bool usaColaborador(Colaborador* colaborador) const;
    int cantidad() const;
};
#endif
