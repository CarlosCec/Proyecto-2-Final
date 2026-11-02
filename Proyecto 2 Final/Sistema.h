#ifndef SISTEMA_H
#define SISTEMA_H
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "ListaCentros.h"
#include "ListaBodegas.h"
#include "ListaPaquetes.h"
#include "ListaDespachos.h"
#include "ListaClientes.h"
#include "ListaColaboradores.h"
#include "ListaSolicitudes.h"

class Sistema {
private:
    ListaCentros centros;
    string mensaje;
    NodoCentro* buscarNodoCentro(string codigo) const;
    bool resultado(bool valor, string texto);
    bool responsableValido(Paquete* p, Colaborador* c) const;
    bool ubicacionCorrecta(Paquete* p) const;
    void cambiarEstado(Paquete* p, int nuevo, string fecha, Colaborador* c);
    Sistema(const Sistema&);
    Sistema& operator=(const Sistema&);
public:
    void destruir();
    bool registrarCentro(string codigo, string nombre, string provincia, string direccion, string telefono);
    CentroDistribucion* buscarCentro(string codigo) const;
    void mostrarCentros() const;
    bool eliminarCentro(string codigo);
    bool registrarClienteFisico(string centro, string id, string nombre, string telefono, string correo);
    bool registrarClienteEmpresa(string centro, string id, string nombre, string telefono, string correo, string actividad, double descuento);
    Cliente* buscarCliente(string centro, string id) const;
    void mostrarClientes(string centro) const;
    bool eliminarCliente(string centro, string id);
    bool registrarColaborador(string centro, string id, string nombre, string fecha, string puesto);
    Colaborador* buscarColaborador(string centro, string id) const;
    void mostrarColaboradores(string centro) const;
    bool eliminarColaborador(string centro, string id);
    bool crearSolicitud(string codigo, string paquete, string cliente, string colaborador, string centro, string destino, string fecha);
    SolicitudEnvio* buscarSolicitud(string codigo) const;
    void mostrarSolicitudes(string centro) const;
    bool rechazarSolicitud(string codigo);
    bool anularSolicitud(string codigo);
    bool tieneSolicitudes(Paquete* paquete) const;
    int cantidadFinalizados(string centro, Cliente* cliente) const;
    void reporteHistorial(string centro, string cliente) const;
    void reporteRanking(string centro) const;
    void reporteColaborador(string centro, string colaborador) const;
    Sistema();
    ~Sistema();
    string getMensaje() const;
    bool usaCliente(Cliente* cliente) const;
    bool usaColaborador(Colaborador* colaborador) const;
    const ListaDespachos* getDespachos(string centro) const;
    bool registrarBodega(string centro, string codigo, string nombre, int tipo, int filas, int columnas);
    Bodega* buscarBodega(string centro, string codigo) const;
    void mostrarBodegas(string centro) const;
    bool eliminarBodega(string centro, string codigo);
    bool registrarPaquete(string centro, string codigo, string descripcion, double peso, int categoria, Cliente* cliente);
    Paquete* buscarPaquete(string codigo) const;
    // Busqueda GLOBAL.
    void mostrarPaquetes(string centro) const;
    bool eliminarPaquete(string codigo);
    Bodega* recomendar(string paquete, int& fila, int& columna) const;
    void mostrarCompatibles(string paquete) const;
    bool almacenar(string paquete, string bodega, int fila, int columna, string fecha, Colaborador* responsable);
    bool reubicar(string paquete, string bodega, int fila, int columna);
    bool registrarIncidencia(string paquete, string fecha, Colaborador* responsable);
    bool resolverIncidencia(string paquete, string fecha, Colaborador* responsable);
    bool aprobarSolicitud(SolicitudEnvio* solicitud, string codigoDespacho, string fecha, string hora);
    Despacho* buscarDespacho(string codigo) const;
    Despacho* despachoDePaquete(Paquete* paquete) const;
    bool finalizarDespacho(string codigo, string fecha);
    void mostrarDespachos(string centro) const;
    void reporteBitacora(string paquete) const;
    void reporteDespachoPaquete(string paquete) const;
    void reporteOcupacion(string centro) const;
};
#endif
