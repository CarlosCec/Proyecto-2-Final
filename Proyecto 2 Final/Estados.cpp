#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Estados.h"

string nombreCategoria(int tipo) {
    switch (tipo) {
        case 1:
        return "General";
        case 2:
        return "Fragil";
        case 3:
        return "Tecnologia";
        case 4:
        return "Documentos";
        default:
        return "Invalida";
    }
}

string nombreEstado(int estado) {
    switch (estado) {
        case RECIBIDO:
        return "Recibido";
        case ALMACENADO:
        return "Almacenado";
        case EN_TRANSITO:
        return "En transito";
        case ENTREGADO:
        return "Entregado";
        case INCIDENCIA:
        return "Incidencia";
        default:
        return "Invalido";
    }
}
