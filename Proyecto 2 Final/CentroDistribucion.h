#include <sstream>
#include <iostream>
using namespace std;
 
class ListaDespachos;
class ListaSolicitudes;
class ListaPaquetes;
class ListaBodegas;
class ListaColaboradores;
class ListaClientes;
class CentroDistribucion {
private:
    string codigo, nombre, provincia, direccion, telefono;
    ListaDespachos* despachos;
    ListaSolicitudes* solicitudes;
    ListaPaquetes* paquetes;
    ListaBodegas* bodegas;
    ListaColaboradores* colaboradores;
    ListaClientes* clientes;
    CentroDistribucion(const CentroDistribucion&);
    CentroDistribucion& operator=(const CentroDistribucion&);
public:
    void destruir();
    CentroDistribucion(string codigo, string nombre, string provincia, string direccion, string telefono);
    ~CentroDistribucion();
    string getCodigo() const;
    string getNombre() const;
    string getProvincia() const;
    string getDireccion() const;
    string getTelefono() const;
    ListaDespachos& getDespachos() const;
    ListaSolicitudes& getSolicitudes() const;
    ListaPaquetes& getPaquetes() const;
    ListaBodegas& getBodegas() const;
    ListaColaboradores& getColaboradores() const;
    ListaClientes& getClientes() const;
    bool vacio() const;
    void mostrar() const;
};
