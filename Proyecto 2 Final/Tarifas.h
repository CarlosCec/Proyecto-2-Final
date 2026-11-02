#ifndef TARIFAS_H
#define TARIFAS_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class Tarifas {
private:
    static double general;
    static double fragil;
    static double tecnologia;
    static double documentos;
public:
    void destruir();
    ~Tarifas();
    static double porKilogramo(int categoria);
};
#endif
