#ifndef BODEGA_H
#define BODEGA_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Celda.h"
#include "Estados.h"

class Bodega {
private:
    string codigo, nombre;
    int tipo, filas, columnas;
    Celda** matriz;
    Bodega(const Bodega&);
    Bodega& operator=(const Bodega&);
public:
    void destruir();
    Bodega(string cod, string nom, int t, int f, int c);
    ~Bodega();
    string getCodigo() const;
    int getTipo() const;
    bool ocupar(int fila, int columna, Paquete* paquete);
    bool liberar(int fila, int columna);
    bool posicionValida(int fila, int columna) const;
    bool disponible(int fila, int columna) const;
    Paquete* consultar(int fila, int columna) const;
    bool primeraLibre(int& fila, int& columna) const;
    int total() const;
    int ocupadas() const;
    double porcentajeDisponible() const;
    void mostrar() const;
    void mostrarMatriz() const;
    void mostrarDisponibles() const;
};
#endif
