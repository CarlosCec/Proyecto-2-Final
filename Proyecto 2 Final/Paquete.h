#ifndef PAQUETE_H
#define PAQUETE_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Bitacora.h"
#include "Cliente.h"
class Bodega;

class Paquete {
private:
    string codigo, descripcion;
    double peso;
    int categoria, estado;
    Cliente* cliente;
    CentroDistribucion* centro;
    Bodega* bodega;
    int fila, columna;
    Bitacora bitacora;
public:
    Paquete(string cod, string desc, double kg, int cat,
            Cliente* cli, CentroDistribucion* cen);
    string getCodigo() const;
    double getPeso() const;
    int getCategoria() const;
    int getEstado() const;
    Cliente* getCliente() const;
    CentroDistribucion* getCentro() const;
    Bodega* getBodega() const;
    int getFila() const;
    int getColumna() const;
    const Bitacora& getBitacora() const;
    void setUbicacion(Bodega* nuevaBodega, int nuevaFila, int nuevaColumna);
    void registrarCambio(int nuevo, string fecha, Colaborador* responsable);
    void mostrar() const;
};
#endif
