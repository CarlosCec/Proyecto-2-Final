#ifndef CLIENTE_H
#define CLIENTE_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class CentroDistribucion;
class Cliente {
private:
    string identificacion, nombre, telefono, correo;
    CentroDistribucion* centro;
public:
    virtual void destruir();
    Cliente(string id, string nom, string tel, string email, CentroDistribucion* c);
    virtual ~Cliente();
    string getIdentificacion() const;
    string getNombre() const;
    string getTelefono() const;
    string getCorreo() const;
    CentroDistribucion* getCentro() const;
    virtual string getTipo() const = 0;
    virtual double getDescuento() const;
    virtual string toString() const;
    void mostrar() const;
};
#endif
