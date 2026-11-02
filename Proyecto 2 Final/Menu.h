#ifndef MENU_H
#define MENU_H
#include <sstream>
#include <iostream>
#include <string>
#include "Sistema.h"
using namespace std;

class Menu {
private:
    Sistema sistema;
    string centroActivo;
    string leerTexto(string etiqueta);
    int leerEntero(string etiqueta, int minimo, int maximo);
    double leerPeso();
    double leerDescuento();
    void mostrarResultado();
    void elegirCentro();
    void menuCentros();
    void menuClientes();
    void menuColaboradores();
    void menuBodegas();
    void menuPaquetes();
    void menuSolicitudes();
    void menuDespachos();
    void menuReportes();
public:
    void destruir();
    ~Menu();
    Menu();
    void ejecutar();
};
#endif
