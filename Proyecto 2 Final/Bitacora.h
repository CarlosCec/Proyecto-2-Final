#include <sstream>
#include <iostream>
#include "NodoBitacora.h"
#include "Estados.h"
using namespace std;

class Bitacora {
private:
    NodoBitacora* primero;
    Bitacora(const Bitacora&);
    Bitacora& operator=(const Bitacora&);
public:
    void destruir();
    void agregar(int anterior, int nuevo, string fecha, Colaborador* responsable);
    Bitacora();
    ~Bitacora();
    void mostrar() const;
    bool usaColaborador(Colaborador* colaborador) const;
    int cantidad() const;
};

