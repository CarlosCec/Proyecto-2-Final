#ifndef MENU_H
#define MENU_H
#include <sstream>
#include <iostream>
#include <string>
#include "Sistema.h"
using namespace std;

class Interfaz {
private:
    Sistema sistema;
    string centroActivo;
    string leerTexto(string etiqueta);
    int leerEntero(string etiqueta, int minimo, int maximo);
    double leerPeso();
    double leerDescuento();
    void mostrarResultado();
    void elegirCentro();
    void interfazCentros();
    void interfazClientes();
    void interfazColaboradores();
    void interfazBodegas();
    void interfazPaquetes();
    void interfazSolicitudes();
    void interfazDespachos();
    void interfazReportes();
public:
    void destruir();
    ~Interfaz();
    Interfaz();
    void ejecutar();
};
#endif
