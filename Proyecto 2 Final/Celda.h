#ifndef CELDA_H
#define CELDA_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class Paquete;
class Celda {
private:
    Paquete* paquete;
public:
    void destruir();
    ~Celda();
    Celda();
    void setPaquete(Paquete* nuevo);
    Paquete* getPaquete() const;
};
#endif
