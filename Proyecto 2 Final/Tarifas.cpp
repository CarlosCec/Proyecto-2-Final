#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Tarifas.h"


double Tarifas::general = 1500;
double Tarifas::fragil = 2000;
double Tarifas::tecnologia = 2500;
double Tarifas::documentos = 1000;
double Tarifas::porKilogramo(int categoria) {
    switch (categoria) {
    case 1: return general;
    case 2: return fragil;
    case 3: return tecnologia;
    case 4: return documentos;
    default: return 0;
    }
}
