#ifndef COLABORADOR_H
#define COLABORADOR_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
class CentroDistribucion;

class Colaborador {
private:
    string identificacion, nombre, fechaIngreso, puesto;
    CentroDistribucion* centro;
public:
    Colaborador(string id, string nombre, string fecha, string puesto, CentroDistribucion* centro);
    string getIdentificacion() const;
    string getNombre() const;
    string getFechaIngreso() const;
    string getPuesto() const;
    CentroDistribucion* getCentro() const;
    void mostrar() const;
};
#endif
