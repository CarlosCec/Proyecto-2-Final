#include <sstream>
#include <iostream>
#include "Bodega.h"
#include "Paquete.h"
using namespace std;

Bodega::Bodega(string cod, string nom, int t, int f, int c) {
    this->codigo = cod;
    this->nombre = nom;
    this->tipo = t;
    this->filas = f;
    this->columnas = c;
    this->matriz = NULL;
    this->matriz = new Celda*[this->filas];
    for (int i = 0; i < this->filas; i++) {
        this->matriz[i] = new Celda[this->columnas];
    }
}

Bodega::~Bodega() {
}

void Bodega::destruir() {
    if (this->matriz == NULL) {
        return;
    }
    for (int i = 0; i < this->filas; i++) {
        for (int j = 0; j < this->columnas; j++) {
            this->matriz[i][j].destruir();
        }
        delete[] this->matriz[i];
    }
    delete[] this->matriz;
    this->matriz = NULL;
    this->filas = 0;
    this->columnas = 0;
}

bool Bodega::posicionValida(int f, int c) const {
    return f >= 0 && f < filas && c >= 0 && c < columnas;
}

bool Bodega::disponible(int f, int c) const {
    return posicionValida(f,c) && matriz[f][c].getPaquete() == NULL;
}

Paquete* Bodega::consultar(int f, int c) const {
    if (!posicionValida(f,c)) {
        return NULL;
    }
    return matriz[f][c].getPaquete();
}

bool Bodega::primeraLibre(int& f, int& c) const {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (disponible(i,j)) {
                f = i;
                c = j;
                return true;
            }
        }
    }
    f = -1;
    c = -1;
    return false;
}

int Bodega::total() const {
    return filas * columnas;
}

int Bodega::ocupadas() const {
    int cantidad = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j].getPaquete() != NULL) {
                cantidad++;
            }
        }
    }
    return cantidad;
}

double Bodega::porcentajeDisponible() const {
    return 100.0 * (total() - ocupadas()) / total();
}

void Bodega::mostrar() const {
    cout << codigo << " | " << nombre << " | " << nombreCategoria(tipo) << " | " << filas << " filas x " << columnas << " columnas\n";
}

void Bodega::mostrarMatriz() const {
    mostrar();
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << '[' << codigo << '-' << i << '-' << j << ": ";
            if (matriz[i][j].getPaquete() == NULL) {
                cout << "LIBRE";
            } else {
                cout << matriz[i][j].getPaquete()->getCodigo();
            }
            cout << "] ";
        }
        cout << '\n';
    }
}

bool Bodega::ocupar(int fila, int columna, Paquete* paquete) {
    if (paquete == NULL || !disponible(fila, columna)) {
        return false;
    }
    matriz[fila][columna].setPaquete(paquete);
    return true;
}

bool Bodega::liberar(int fila, int columna) {
    if (!posicionValida(fila, columna)) {
        return false;
    }
    matriz[fila][columna].setPaquete(NULL);
    return true;
}

string Bodega::getCodigo() const {
    return codigo;
}

int Bodega::getTipo() const {
    return tipo;
}

void Bodega::mostrarDisponibles() const {
    mostrar();
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (disponible(i,j)) {
                cout << codigo << '-' << i << '-' << j << " LIBRE\n";
            }
        }
    }
}
