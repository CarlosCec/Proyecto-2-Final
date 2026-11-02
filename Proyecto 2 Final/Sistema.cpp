#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "Sistema.h"
#include <cmath>
#include "ClienteFisico.h"
#include "ClienteEmpresa.h"
#include "Tarifas.h"
#include "ListaRanking.h"

Sistema::Sistema() {
}

Sistema::~Sistema() {
}

void Sistema::destruir() {
    this->centros.destruir();
}

bool Sistema::resultado(bool valor, string texto) {
    mensaje = texto;
    return valor;
}

NodoCentro* Sistema::buscarNodoCentro(string codigo) const {
    NodoCentro* actual = centros.getPrimero();
    while (actual != NULL) {
        if (actual->getCentro()->getCodigo() == codigo) {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return NULL;
}

bool Sistema::usaCliente(Cliente* cliente) const {
    if (cliente == NULL) {
        return false;
    }
    NodoCentro* c = centros.getPrimero();
    while (c != NULL) {
        const NodoPaquete* n = c->getCentro()->getPaquetes().getPrimero();
        while (n != NULL) {
            if (n->getDato()->getCliente() == cliente) {
                return true;
            }
            n = n->getSiguiente();
        }
        NodoSolicitud* solicitud = c->getCentro()->getSolicitudes().getPrimero();
        while (solicitud != NULL) {
            if (solicitud->getDato()->getCliente() == cliente) {
                return true;
            }
            solicitud = solicitud->getSiguiente();
        }
        const NodoDespacho* despacho = c->getCentro()->getDespachos().getPrimero();
        while (despacho != NULL) {
            if (despacho->getDato()->getCliente() == cliente) {
                return true;
            }
            despacho = despacho->getSiguiente();
        }
        c = c->getSiguiente();
    }
    return false;
}

bool Sistema::usaColaborador(Colaborador* colaborador) const {
    if (colaborador == NULL) {
        return false;
    }
    NodoCentro* c = centros.getPrimero();
    while (c != NULL) {
        const NodoPaquete* p = c->getCentro()->getPaquetes().getPrimero();
        while (p != NULL) {
            if (p->getDato()->getBitacora().usaColaborador(colaborador)) {
                return true;
            }
            p = p->getSiguiente();
        }
        const NodoDespacho* d = c->getCentro()->getDespachos().getPrimero();
        while (d != NULL) {
            if (d->getDato()->getResponsable() == colaborador) {
                return true;
            }
            d = d->getSiguiente();
        }
        NodoSolicitud* solicitud = c->getCentro()->getSolicitudes().getPrimero();
        while (solicitud != NULL) {
            if (solicitud->getDato()->getResponsable() == colaborador) {
                return true;
            }
            solicitud = solicitud->getSiguiente();
        }
        c = c->getSiguiente();
    }
    return false;
}

const ListaDespachos* Sistema::getDespachos(string centro) const {
    NodoCentro* c = buscarNodoCentro(centro);
    return c == NULL ? NULL : &c->getCentro()->getDespachos();
}

bool Sistema::registrarBodega(string centro, string codigo, string nombre, int tipo, int filas, int columnas) {
    NodoCentro* c = buscarNodoCentro(centro);
    if (c == NULL) {
        return resultado(false,"Centro inexistente.");
    }
    if (codigo == "" || nombre == "" || tipo < 1 || tipo > 4 || filas <= 0 || columnas <= 0) {
        return resultado(false,"Datos de bodega invalidos.");
    }
    // Evita desbordar los contadores int de Visual Studio al multiplicar dimensiones.
    if (filas > 2147483647 / columnas) {
        return resultado(false,"La cantidad de celdas excede el rango de int.");
    }
    int totalCentro = 0;
    const NodoBodega* existente = c->getCentro()->getBodegas().getPrimero();
    while (existente != NULL) {
        totalCentro += existente->getDato()->total();
        existente = existente->getSiguiente();
    }
    if (filas * columnas > 2147483647 - totalCentro) {
        return resultado(false,"El total de celdas del centro excede el rango de int.");
    }
    if (c->getCentro()->getBodegas().buscar(codigo) != NULL) {
        return resultado(false,"Codigo repetido en el centro.");
    }
    c->getCentro()->getBodegas().insertar(new Bodega(codigo,nombre,tipo,filas,columnas));
    return resultado(true,"Bodega registrada.");
}

Bodega* Sistema::buscarBodega(string centro, string codigo) const {
    NodoCentro* c = buscarNodoCentro(centro);
    return c == NULL ? NULL : c->getCentro()->getBodegas().buscar(codigo);
}

void Sistema::mostrarBodegas(string centro) const {
    NodoCentro* c = buscarNodoCentro(centro);
    if (c != NULL) {
        c->getCentro()->getBodegas().mostrar();
    } else {
        cout << "Centro inexistente.\n";
    }
}

bool Sistema::eliminarBodega(string centro, string codigo) {
    NodoCentro* c = buscarNodoCentro(centro);
    Bodega* b = buscarBodega(centro,codigo);
    if (b == NULL) {
        return resultado(false,"Bodega inexistente.");
    }
    if (b->ocupadas() != 0) {
        return resultado(false,"La bodega tiene celdas ocupadas.");
    }
    const NodoPaquete* p = c->getCentro()->getPaquetes().getPrimero();
    while (p != NULL) {
        if (p->getDato()->getBodega() == b) {
            return resultado(false,"Un paquete tiene esta bodega asignada.");
        }
        p = p->getSiguiente();
    }
    c->getCentro()->getBodegas().eliminar(codigo);
    return resultado(true,"Bodega eliminada.");
}

bool Sistema::registrarPaquete(string centro, string codigo, string descripcion, double peso, int categoria, Cliente* cliente) {
    NodoCentro* c = buscarNodoCentro(centro);
    if (c == NULL || cliente == NULL || cliente->getCentro() != c->getCentro() || cliente->getIdentificacion() == "" || c->getCentro()->getClientes().buscar(cliente->getIdentificacion()) != cliente) {
        return resultado(false,"El cliente debe existir y pertenecer al centro.");
    }
    if (codigo == "" || descripcion == "" || !isfinite(peso) || peso <= 0 || categoria < 1 || categoria > 4) {
        return resultado(false,"Datos de paquete invalidos.");
    }
    if (buscarPaquete(codigo) != NULL) {
        return resultado(false,"Codigo de paquete repetido en el sistema.");
    }
    c->getCentro()->getPaquetes().insertar(new Paquete(codigo,descripcion,peso,categoria,cliente,c->getCentro()));
    return resultado(true,"Paquete registrado en Recibido.");
}

Paquete* Sistema::buscarPaquete(string codigo) const {
    NodoCentro* c = centros.getPrimero();
    while (c != NULL) {
        Paquete* p = c->getCentro()->getPaquetes().buscar(codigo);
        if (p != NULL) {
            return p;
        }
        c = c->getSiguiente();
    }
    return NULL;
}

void Sistema::mostrarPaquetes(string centro) const {
    NodoCentro* c = buscarNodoCentro(centro);
    if (c != NULL) {
        c->getCentro()->getPaquetes().mostrar();
    } else {
        cout << "Centro inexistente.\n";
    }
}

bool Sistema::eliminarPaquete(string codigo) {
    Paquete* p = buscarPaquete(codigo);
    if (p == NULL) {
        return resultado(false,"Paquete inexistente.");
    }
    if (p->getEstado() != RECIBIDO || p->getBodega() != NULL || despachoDePaquete(p) != NULL || tieneSolicitudes(p)) {
        return resultado(false,"Solo se elimina un Recibido sin ubicacion, solicitudes ni despacho.");
    }
    buscarNodoCentro(p->getCentro()->getCodigo())->getCentro()->getPaquetes().eliminar(codigo);
    return resultado(true,"Paquete eliminado.");
}

bool Sistema::responsableValido(Paquete* p, Colaborador* c) const {
    return p != NULL && c != NULL && c->getCentro() == p->getCentro() && c->getIdentificacion() != "" && p->getCentro()->getColaboradores().buscar(c->getIdentificacion()) == c;
}

bool Sistema::ubicacionCorrecta(Paquete* p) const {
    return p != NULL && p->getBodega() != NULL && p->getBodega()->consultar(p->getFila(),p->getColumna()) == p;
}

void Sistema::cambiarEstado(Paquete* p, int nuevo, string fecha, Colaborador* c) {
    // Solo se llama despues de validar la operacion especifica.
    p->registrarCambio(nuevo,fecha,c);
}

Bodega* Sistema::recomendar(string codigo, int& fila, int& columna) const {
    fila = -1;
    columna = -1;
    Paquete* p = buscarPaquete(codigo);
    if (p == NULL) {
        return NULL;
    }
    if (p->getEstado() != RECIBIDO && !(p->getEstado() == INCIDENCIA && p->getBodega() == NULL && despachoDePaquete(p) == NULL)) {
        return NULL;
    }
    NodoCentro* c = buscarNodoCentro(p->getCentro()->getCodigo());
    const NodoBodega* n = c->getCentro()->getBodegas().getPrimero();
    Bodega* mejor = NULL;
    while (n != NULL) {
        Bodega* b = n->getDato();
        if (b->getTipo() == p->getCategoria() && b->porcentajeDisponible() > 0 && (mejor == NULL || b->porcentajeDisponible() > mejor->porcentajeDisponible())) {
            mejor = b;
        }
        n = n->getSiguiente();
    }
    if (mejor != NULL) {
        mejor->primeraLibre(fila,columna);
    }
    return mejor;
}

void Sistema::mostrarCompatibles(string codigo) const {
    Paquete* p = buscarPaquete(codigo);
    if (p == NULL) {
        cout << "Paquete inexistente.\n";
        return;
    }
    const NodoBodega* n = buscarNodoCentro(p->getCentro()->getCodigo())->getCentro()->getBodegas().getPrimero();
    bool hay = false;
    while (n != NULL) {
        if (n->getDato()->getTipo() == p->getCategoria() && n->getDato()->porcentajeDisponible() > 0) {
            hay = true;
            n->getDato()->mostrarDisponibles();
        }
        n = n->getSiguiente();
    }
    if (!hay) {
        cout << "No hay bodegas compatibles con espacio.\n";
    }
}

bool Sistema::almacenar(string codigo, string bodega, int fila, int columna, string fecha, Colaborador* responsable) {
    Paquete* p = buscarPaquete(codigo);
    if (!responsableValido(p,responsable) || fecha == "") {
        return resultado(false,"Paquete, colaborador o fecha invalidos.");
    }
    if (p->getBodega() != NULL || despachoDePaquete(p) != NULL || (p->getEstado() != RECIBIDO && p->getEstado() != INCIDENCIA)) {
        return resultado(false,"El paquete no puede almacenarse desde su situacion actual.");
    }
    Bodega* b = buscarBodega(p->getCentro()->getCodigo(),bodega);
    if (b == NULL || b->getTipo() != p->getCategoria() || !b->disponible(fila,columna)) {
        return resultado(false,"Destino inexistente, incompatible u ocupado.");
    }
    cambiarEstado(p,ALMACENADO,fecha,responsable);
    b->ocupar(fila,columna,p);
    p->setUbicacion(b,fila,columna);
    return resultado(true,"Paquete almacenado.");
}

bool Sistema::reubicar(string codigo, string bodega, int fila, int columna) {
    Paquete* p = buscarPaquete(codigo);
    if (p == NULL || p->getEstado() != ALMACENADO || !ubicacionCorrecta(p)) {
        return resultado(false,"Se necesita un paquete Almacenado con ubicacion valida.");
    }
    Bodega* destino = buscarBodega(p->getCentro()->getCodigo(),bodega);
    if (destino == NULL || destino->getTipo() != p->getCategoria() || !destino->disponible(fila,columna)) {
        return resultado(false,"Destino invalido. Se conserva la ubicacion original.");
    }
    // No se libera el origen hasta haber validado todo el destino.
    p->getBodega()->liberar(p->getFila(),p->getColumna());
    destino->ocupar(fila,columna,p);
    p->setUbicacion(destino,fila,columna);
    return resultado(true,"Paquete reubicado. No cambia el estado.");
}

bool Sistema::registrarIncidencia(string codigo, string fecha, Colaborador* responsable) {
    Paquete* p = buscarPaquete(codigo);
    if (!responsableValido(p,responsable) || fecha == "") {
        return resultado(false,"Paquete, colaborador o fecha invalidos.");
    }
    if (p->getEstado() != RECIBIDO && p->getEstado() != ALMACENADO && p->getEstado() != EN_TRANSITO) {
        return resultado(false,"No se permite registrar incidencia en ese estado.");
    }
    cambiarEstado(p,INCIDENCIA,fecha,responsable);
    return resultado(true,"Incidencia registrada. Se conserva la ubicacion si existe.");
}

bool Sistema::resolverIncidencia(string codigo, string fecha, Colaborador* responsable) {
    Paquete* p = buscarPaquete(codigo);
    if (!responsableValido(p,responsable) || fecha == "" || p->getEstado() != INCIDENCIA) {
        return resultado(false,"Datos invalidos o paquete sin incidencia.");
    }
    Despacho* d = despachoDePaquete(p);
    if (p->getBodega() != NULL && ubicacionCorrecta(p) && d == NULL) {
        cambiarEstado(p,ALMACENADO,fecha,responsable);
        return resultado(true,"Incidencia resuelta. Conserva su celda.");
    }
    if (p->getBodega() == NULL && d != NULL && !d->estaFinalizado()) {
        cambiarEstado(p,EN_TRANSITO,fecha,responsable);
        return resultado(true,"Incidencia resuelta. Continua el despacho.");
    }
    return resultado(false,"Incidencia sin celda: use almacenar para asignarle una.");
}

Despacho* Sistema::buscarDespacho(string codigo) const {
    NodoCentro* c = centros.getPrimero();
    while (c != NULL) {
        Despacho* d = c->getCentro()->getDespachos().buscar(codigo);
        if (d != NULL) {
            return d;
        }
        c = c->getSiguiente();
    }
    return NULL;
}

Despacho* Sistema::despachoDePaquete(Paquete* paquete) const {
    NodoCentro* c = centros.getPrimero();
    while (c != NULL) {
        const NodoDespacho* n = c->getCentro()->getDespachos().getPrimero();
        while (n != NULL) {
            if (n->getDato()->getPaquete() == paquete) {
                return n->getDato();
            }
            n = n->getSiguiente();
        }
        c = c->getSiguiente();
    }
    return NULL;
}

bool Sistema::aprobarSolicitud(SolicitudEnvio* s, string codigo, string fecha, string hora) {
    if (s == NULL || buscarSolicitud(s->getCodigo()) != s || s->getEstado() != "Pendiente" || s->getCodigo() == "" || s->getDestino() == "" || s->getFecha() == "" || codigo == "" || fecha == "" || hora == "") {
        return resultado(false,"Solicitud o datos de despacho invalidos.");
    }
    Paquete* p = s->getPaquete();
    // Primero se comprueba que el puntero corresponda a un paquete registrado.
    bool encontrado = false;
    NodoCentro* centro = centros.getPrimero();
    while (centro != NULL) {
        const NodoPaquete* n = centro->getCentro()->getPaquetes().getPrimero();
        while (n != NULL) {
            if (n->getDato() == p) {
                encontrado = true;
            }
            n = n->getSiguiente();
        }
        centro = centro->getSiguiente();
    }
    if (!encontrado || !responsableValido(p,s->getResponsable())) {
        return resultado(false,"Paquete o colaborador no valido para este centro.");
    }
    if (p->getEstado() != ALMACENADO || !ubicacionCorrecta(p) || s->getCentro() != p->getCentro() || s->getCliente() != p->getCliente() || despachoDePaquete(p) != NULL || buscarDespacho(codigo) != NULL) {
        return resultado(false,"No se cumplen las condiciones de aprobacion.");
    }
    // Impide reutilizar la misma solicitud (o su codigo) para otro despacho.
    centro = centros.getPrimero();
    while (centro != NULL) {
        const NodoDespacho* n = centro->getCentro()->getDespachos().getPrimero();
        while (n != NULL) {
            if (n->getDato()->getSolicitud()->getCodigo() == s->getCodigo()) {
                return resultado(false,"La solicitud ya tiene despacho.");
            }
            n = n->getSiguiente();
        }
        centro = centro->getSiguiente();
    }
    Despacho* despacho = new Despacho(codigo,s,fecha,hora);
    NodoDespacho* nodo = new NodoDespacho(despacho);
    cambiarEstado(p,EN_TRANSITO,fecha,s->getResponsable());
    buscarNodoCentro(p->getCentro()->getCodigo())->getCentro()->getDespachos().anexar(nodo);
    p->getBodega()->liberar(p->getFila(),p->getColumna());
    p->setUbicacion(NULL,-1,-1);
    s->cambiarEstado("Aprobada");
    return resultado(true,"Solicitud aprobada y despacho creado. Celda liberada.");
}

bool Sistema::finalizarDespacho(string codigo, string fecha) {
    Despacho* d = buscarDespacho(codigo);
    if (d == NULL || d->estaFinalizado() || d->getPaquete()->getEstado() != EN_TRANSITO || fecha == "") {
        return resultado(false,"Se requiere despacho En proceso y paquete En transito.");
    }
    if (d->getPaquete()->getBodega() != NULL) {
        return resultado(false,"El paquete en ruta no debe tener celda.");
    }
    cambiarEstado(d->getPaquete(),ENTREGADO,fecha,d->getResponsable());
    d->finalizar();
    return resultado(true,"Entrega finalizada.");
}

void Sistema::mostrarDespachos(string centro) const {
    NodoCentro* c = buscarNodoCentro(centro);
    if (c != NULL) {
        c->getCentro()->getDespachos().mostrar();
    } else {
        cout << "Centro inexistente.\n";
    }
}

void Sistema::reporteBitacora(string codigo) const {
    Paquete* p = buscarPaquete(codigo);
    if (p == NULL) {
        cout << "Paquete inexistente.\n";
    } else {
        p->mostrar();
        p->getBitacora().mostrar();
    }
}

void Sistema::reporteDespachoPaquete(string codigo) const {
    Paquete* p = buscarPaquete(codigo);
    if (p == NULL) {
        cout << "Paquete inexistente.\n";
        return;
    }
    Despacho* d = despachoDePaquete(p);
    if (d == NULL) {
        cout << "El paquete no posee despacho.\n";
        return;
    }
    cout << "Solicitud: " << d->getSolicitud()->getCodigo() << " | Fecha: " << d->getSolicitud()->getFecha() << " | " << d->getSolicitud()->getEstado() << '\n';
    d->mostrar();
}

void Sistema::reporteOcupacion(string codigo) const {
    NodoCentro* c = buscarNodoCentro(codigo);
    if (c == NULL) {
        cout << "Centro inexistente.\n";
        return;
    }
    cout << "Centro: " << codigo << '\n';
    int total = 0, ocupadas = 0;
    const NodoBodega* n = c->getCentro()->getBodegas().getPrimero();
    while (n != NULL) {
        int t = n->getDato()->total(), o = n->getDato()->ocupadas();
        total += t;
        ocupadas += o;
        cout << n->getDato()->getCodigo() << " | Total: " << t << " | Ocupadas: " << o << " | Libres: " << t-o << " | Ocupacion: " << 100.0*o/t << "% | Disponible: " << 100.0*(t-o)/t << "%\n";
        n = n->getSiguiente();
    }
    cout << "TOTAL CENTRO | Total: " << total << " | Ocupadas: " << ocupadas << " | Libres: " << total-ocupadas << " | Ocupacion: " << (total == 0 ? 0 : 100.0*ocupadas/total) << "% | Disponible: " << (total == 0 ? 0 : 100.0*(total-ocupadas)/total) << "%\n";
}

string Sistema::getMensaje() const {
    return mensaje;
}

bool Sistema::registrarCentro(string codigo, string nombre, string provincia, string direccion, string telefono) {
    if (codigo == "" || nombre == "" || provincia == "" || direccion == "" || telefono == "") {
        return resultado(false,"Complete todos los datos del centro.");
    }
    if (buscarCentro(codigo) != NULL) {
        return resultado(false,"Codigo de centro repetido.");
    }
    centros.insertar(new CentroDistribucion(codigo,nombre,provincia,direccion,telefono));
    return resultado(true,"Centro registrado.");
}

CentroDistribucion* Sistema::buscarCentro(string codigo) const {
    return centros.buscar(codigo);
}

void Sistema::mostrarCentros() const {
    centros.mostrar();
}

bool Sistema::eliminarCentro(string codigo) {
    CentroDistribucion* centro = buscarCentro(codigo);
    if (centro == NULL) {
        return resultado(false,"Centro inexistente.");
    }
    if (!centro->vacio()) {
        return resultado(false,"El centro tiene datos asociados.");
    }
    centros.eliminar(codigo);
    return resultado(true,"Centro eliminado.");
}

bool Sistema::registrarClienteFisico(string centro, string id, string nombre, string telefono, string correo) {
    CentroDistribucion* c = buscarCentro(centro);
    if (c == NULL) {
        return resultado(false,"Centro inexistente.");
    }
    if (id == "" || nombre == "" || telefono == "" || correo == "") {
        return resultado(false,"Complete los datos obligatorios del cliente.");
    }
    if (c->getClientes().buscar(id) != NULL) {
        return resultado(false,"Identificacion repetida en el centro.");
    }
    c->getClientes().insertar(new ClienteFisico(id,nombre,telefono,correo,c));
    return resultado(true,"Cliente fisico registrado.");
}

bool Sistema::registrarClienteEmpresa(string centro, string id, string nombre, string telefono, string correo, string actividad, double descuento) {
    CentroDistribucion* c = buscarCentro(centro);
    if (c == NULL) {
        return resultado(false,"Centro inexistente.");
    }
    if (id == "" || nombre == "" || telefono == "" || correo == "" || actividad == "" || !isfinite(descuento) || descuento < 0 || descuento > 100) {
        return resultado(false,"Datos invalidos: el descuento debe estar entre 0 y 100.");
    }
    if (c->getClientes().buscar(id) != NULL) {
        return resultado(false,"Identificacion repetida en el centro.");
    }
    c->getClientes().insertar(new ClienteEmpresa(id,nombre,telefono,correo,c,actividad,descuento));
    return resultado(true,"Cliente empresa registrado.");
}

Cliente* Sistema::buscarCliente(string centro, string id) const {
    CentroDistribucion* c = buscarCentro(centro);
    return c == NULL ? NULL : c->getClientes().buscar(id);
}

void Sistema::mostrarClientes(string centro) const {
    CentroDistribucion* c = buscarCentro(centro);
    if (c == NULL) {
        cout << "Centro inexistente.\n";
    } else {
        c->getClientes().mostrar();
    }
}

bool Sistema::eliminarCliente(string centro, string id) {
    Cliente* cliente = buscarCliente(centro,id);
    if (cliente == NULL) {
        return resultado(false,"Cliente inexistente.");
    }
    if (usaCliente(cliente)) {
        return resultado(false,"Cliente con paquetes, solicitudes o despachos.");
    }
    buscarCentro(centro)->getClientes().eliminar(id);
    return resultado(true,"Cliente eliminado.");
}

bool Sistema::registrarColaborador(string centro, string id, string nombre, string fecha, string puesto) {
    CentroDistribucion* c = buscarCentro(centro);
    if (c == NULL) {
        return resultado(false,"Centro inexistente.");
    }
    if (id == "" || nombre == "" || fecha == "" || puesto == "") {
        return resultado(false,"Complete los datos obligatorios del colaborador.");
    }
    if (c->getColaboradores().buscar(id) != NULL) {
        return resultado(false,"Identificacion repetida en el centro.");
    }
    c->getColaboradores().insertar(new Colaborador(id,nombre,fecha,puesto,c));
    return resultado(true,"Colaborador registrado.");
}

Colaborador* Sistema::buscarColaborador(string centro, string id) const {
    CentroDistribucion* c = buscarCentro(centro);
    return c == NULL ? NULL : c->getColaboradores().buscar(id);
}

void Sistema::mostrarColaboradores(string centro) const {
    CentroDistribucion* c = buscarCentro(centro);
    if (c == NULL) {
        cout << "Centro inexistente.\n";
    } else {
        c->getColaboradores().mostrar();
    }
}

bool Sistema::eliminarColaborador(string centro, string id) {
    Colaborador* colaborador = buscarColaborador(centro,id);
    if (colaborador == NULL) {
        return resultado(false,"Colaborador inexistente.");
    }
    if (usaColaborador(colaborador)) {
        return resultado(false,"Colaborador con solicitudes, despachos o bitacoras.");
    }
    buscarCentro(centro)->getColaboradores().eliminar(id);
    return resultado(true,"Colaborador eliminado.");
}

SolicitudEnvio* Sistema::buscarSolicitud(string codigo) const {
    NodoCentro* actual = centros.getPrimero();
    while (actual != NULL) {
        SolicitudEnvio* solicitud = actual->getCentro()->getSolicitudes().buscar(codigo);
        if (solicitud != NULL) {
            return solicitud;
        }
        actual = actual->getSiguiente();
    }
    return NULL;
}

bool Sistema::tieneSolicitudes(Paquete* paquete) const {
    NodoCentro* actual = centros.getPrimero();
    while (actual != NULL) {
        NodoSolicitud* nodo = actual->getCentro()->getSolicitudes().getPrimero();
        while (nodo != NULL) {
            if (nodo->getDato()->getPaquete() == paquete) {
                return true;
            }
            nodo = nodo->getSiguiente();
        }
        actual = actual->getSiguiente();
    }
    return false;
}

bool Sistema::crearSolicitud(string codigo, string paquete, string cliente, string colaborador, string centro, string destino, string fecha) {
    CentroDistribucion* c = buscarCentro(centro);
    Paquete* p = buscarPaquete(paquete);
    Cliente* cli = buscarCliente(centro,cliente);
    Colaborador* col = buscarColaborador(centro,colaborador);
    if (codigo == "" || destino == "" || fecha == "") {
        return resultado(false,"Codigo, destino y fecha son obligatorios.");
    }
    if (buscarSolicitud(codigo) != NULL) {
        return resultado(false,"Codigo de solicitud repetido en el sistema.");
    }
    if (c == NULL || p == NULL || cli == NULL || col == NULL || p->getCentro() != c || p->getCliente() != cli) {
        return resultado(false,"Revise centro, propietario del paquete y colaborador.");
    }
    if (p->getEstado() != ALMACENADO || despachoDePaquete(p) != NULL) {
        return resultado(false,"Se necesita un paquete Almacenado sin despacho.");
    }
    NodoSolicitud* nodo = c->getSolicitudes().getPrimero();
    while (nodo != NULL) {
        if (nodo->getDato()->getPaquete() == p && nodo->getDato()->getEstado() == "Pendiente") {
            return resultado(false,"El paquete ya tiene una solicitud Pendiente.");
        }
        nodo = nodo->getSiguiente();
    }
    double descuento = cli->getDescuento();
    double base = p->getPeso() * Tarifas::porKilogramo(p->getCategoria());
    double costo = base - base * descuento / 100.0;
    if (!isfinite(base) || !isfinite(costo) || !isfinite(descuento) || descuento < 0 || descuento > 100) {
        return resultado(false,"El costo o descuento esta fuera del rango permitido.");
    }
    c->getSolicitudes().insertar(new SolicitudEnvio(codigo,p,cli,col,c,destino,fecha,costo));
    return resultado(true,"Solicitud creada en Pendiente. Costo estimado guardado.");
}

void Sistema::mostrarSolicitudes(string centro) const {
    CentroDistribucion* c = buscarCentro(centro);
    if (c == NULL) {
        cout << "Centro inexistente.\n";
    } else {
        c->getSolicitudes().mostrar();
    }
}

bool Sistema::rechazarSolicitud(string codigo) {
    SolicitudEnvio* s = buscarSolicitud(codigo);
    if (s == NULL || !s->cambiarEstado("Rechazada")) {
        return resultado(false,"Se requiere una solicitud Pendiente.");
    }
    return resultado(true,"Solicitud Rechazada.");
}

bool Sistema::anularSolicitud(string codigo) {
    SolicitudEnvio* s = buscarSolicitud(codigo);
    if (s == NULL || !s->cambiarEstado("Anulada")) {
        return resultado(false,"Se requiere una solicitud Pendiente.");
    }
    return resultado(true,"Solicitud Anulada.");
}

int Sistema::cantidadFinalizados(string centro, Cliente* cliente) const {
    CentroDistribucion* c = buscarCentro(centro);
    if (c == NULL) {
        return 0;
    }
    int cantidad = 0;
    const NodoDespacho* nodo = c->getDespachos().getPrimero();
    while (nodo != NULL) {
        if (nodo->getDato()->getCliente() == cliente && nodo->getDato()->estaFinalizado()) {
            cantidad++;
        }
        nodo = nodo->getSiguiente();
    }
    return cantidad;
}

void Sistema::reporteHistorial(string centro, string cliente) const {
    Cliente* cli = buscarCliente(centro,cliente);
    if (cli == NULL) {
        cout << "Cliente o centro inexistente.\n";
        return;
    }
    CentroDistribucion* c = buscarCentro(centro);
    cout << "HISTORIAL | Centro: " << centro << " | Cliente: " << cliente << '\n';
    bool hay = false;
    NodoSolicitud* solicitud = c->getSolicitudes().getPrimero();
    while (solicitud != NULL) {
        if (solicitud->getDato()->getCliente() == cli) {
            solicitud->getDato()->mostrar();
            hay = true;
        }
        solicitud = solicitud->getSiguiente();
    }
    const NodoDespacho* despacho = c->getDespachos().getPrimero();
    while (despacho != NULL) {
        if (despacho->getDato()->getCliente() == cli) {
            despacho->getDato()->mostrar();
            hay = true;
        }
        despacho = despacho->getSiguiente();
    }
    if (!hay) {
        cout << "Sin solicitudes ni despachos para este cliente.\n";
    }
}

void Sistema::reporteRanking(string centro) const {
    CentroDistribucion* c = buscarCentro(centro);
    if (c == NULL) {
        cout << "Centro inexistente.\n";
        return;
    }
    ListaRanking ranking;
    NodoCliente* nodo = c->getClientes().getPrimero();
    while (nodo != NULL) {
        ranking.insertar(nodo->getDato(),cantidadFinalizados(centro,nodo->getDato()));
        nodo = nodo->getSiguiente();
    }
    cout << "CLIENTES POR ENVIOS FINALIZADOS | Centro: " << centro << '\n';
    ranking.mostrar();
    ranking.destruir();
}

void Sistema::reporteColaborador(string centro, string colaborador) const {
    Colaborador* col = buscarColaborador(centro,colaborador);
    if (col == NULL) {
        cout << "Colaborador o centro inexistente.\n";
        return;
    }
    cout << "DESPACHOS POR COLABORADOR | Centro: " << centro << " | Colaborador: " << colaborador << '\n';
    const NodoDespacho* nodo = buscarCentro(centro)->getDespachos().getPrimero();
    bool hay = false;
    while (nodo != NULL) {
        if (nodo->getDato()->getResponsable() == col) {
            nodo->getDato()->mostrar();
            hay = true;
        }
        nodo = nodo->getSiguiente();
    }
    if (!hay) {
        cout << "Sin despachos para este colaborador.\n";
    }
}
