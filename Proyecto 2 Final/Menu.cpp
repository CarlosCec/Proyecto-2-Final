#include <sstream>
#include <iostream>
#include <string>
#include <cmath>
#include "Menu.h"
#include "DatosPrueba.h"
#include "Tarifas.h"
using namespace std;

Menu::Menu() : centroActivo("") {}
string Menu::leerTexto(string etiqueta) {
    string texto;
    while (true) {
        cout << etiqueta;
        if (!getline(cin,texto)) return "";
        if (texto != "") return texto;
        cout << "El dato es obligatorio.\n";
    }
}
int Menu::leerEntero(string etiqueta, int minimo, int maximo) {
    while (true) {
        string texto = leerTexto(etiqueta);
        if (!cin) return minimo;
        istringstream entrada(texto);
        int valor;
        char extra;
        if ((entrada >> valor) && !(entrada >> extra) && valor >= minimo && valor <= maximo) return valor;
        cout << "Digite un entero entre " << minimo << " y " << maximo << ".\n";
    }
}
double Menu::leerPeso() {
    while (true) {
        string texto = leerTexto("Peso en kg (punto decimal): ");
        if (!cin) return 0;
        istringstream entrada(texto);
        double peso;
        char extra;
        if ((entrada >> peso) && !(entrada >> extra) && isfinite(peso) && peso > 0) return peso;
        cout << "Digite un peso numerico mayor que cero.\n";
    }
}
double Menu::leerDescuento() {
    while (true) {
        string texto = leerTexto("Descuento entre 0 y 100 (punto decimal): ");
        if (!cin) return 0;
        istringstream entrada(texto);
        double descuento;
        char extra;
        if ((entrada >> descuento) && !(entrada >> extra) && isfinite(descuento) && descuento >= 0 && descuento <= 100)
            return descuento;
        cout << "Porcentaje invalido.\n";
    }
}
void Menu::mostrarResultado() { cout << sistema.getMensaje() << '\n'; }
void Menu::elegirCentro() {
    sistema.mostrarCentros();
    string codigo = leerTexto("Codigo del centro a seleccionar: ");
    if (!cin) return;
    if (sistema.buscarCentro(codigo) == NULL) cout << "Centro inexistente; se conserva la seleccion.\n";
    else {
        centroActivo = codigo;
        cout << "Centro seleccionado: " << centroActivo << '\n';
    }
}
void Menu::menuCentros() {
    int opcion;
    do {
        cout << "\nCENTROS\n1 Registrar\n2 Buscar\n3 Mostrar todos\n4 Eliminar\n5 Seleccionar centro\n0 Volver\n";
        opcion = leerEntero("Opcion: ",0,5);
        if (!cin) return;
        if (opcion == 1) {
            string codigo = leerTexto("Codigo: ");
            string nombre = leerTexto("Nombre: ");
            string provincia = leerTexto("Provincia: ");
            string direccion = leerTexto("Direccion: ");
            string telefono = leerTexto("Telefono: ");
            if (!cin) return;
            if (sistema.registrarCentro(codigo,nombre,provincia,direccion,telefono) && centroActivo == "")
                centroActivo = codigo;
            mostrarResultado();
        } else if (opcion == 2) {
            string codigo = leerTexto("Codigo del centro: ");
            if (!cin) return;
            CentroDistribucion* c = sistema.buscarCentro(codigo);
            if (c == NULL) cout << "Centro inexistente.\n";
            else c->mostrar();
        } else if (opcion == 3) sistema.mostrarCentros();
        else if (opcion == 4) {
            string codigo = leerTexto("Codigo del centro a eliminar: ");
            if (!cin) return;
            if (sistema.eliminarCentro(codigo) && centroActivo == codigo) centroActivo = "";
            mostrarResultado();
        } else if (opcion == 5) elegirCentro();
    } while (opcion != 0 && cin);
}
void Menu::menuClientes() {
    int opcion;
    do {
        cout << "\nCLIENTES | Centro " << centroActivo
             << "\n1 Registrar persona fisica\n2 Registrar empresa\n3 Buscar\n4 Mostrar\n5 Eliminar\n0 Volver\n";
        opcion = leerEntero("Opcion: ",0,5);
        if (!cin) return;
        if (opcion == 1 || opcion == 2) {
            string id = leerTexto("Identificacion: ");
            string nombre = leerTexto("Nombre: ");
            string telefono = leerTexto("Telefono: ");
            string correo = leerTexto("Correo: ");
            if (!cin) return;
            if (opcion == 1) sistema.registrarClienteFisico(centroActivo,id,nombre,telefono,correo);
            else {
                string actividad = leerTexto("Actividad economica: ");
                double descuento = leerDescuento();
                if (!cin) return;
                sistema.registrarClienteEmpresa(centroActivo,id,nombre,telefono,correo,actividad,descuento);
            }
            mostrarResultado();
        } else if (opcion == 4) sistema.mostrarClientes(centroActivo);
        else if (opcion == 3 || opcion == 5) {
            string id = leerTexto("Identificacion del cliente: ");
            if (!cin) return;
            if (opcion == 5) { sistema.eliminarCliente(centroActivo,id); mostrarResultado(); }
            else {
                Cliente* c = sistema.buscarCliente(centroActivo,id);
                if (c == NULL) cout << "Cliente inexistente.\n";
                else c->mostrar();
            }
        }
    } while (opcion != 0 && cin);
}
void Menu::menuColaboradores() {
    int opcion;
    do {
        cout << "\nCOLABORADORES | Centro " << centroActivo
             << "\n1 Registrar\n2 Buscar\n3 Mostrar\n4 Eliminar\n0 Volver\n";
        opcion = leerEntero("Opcion: ",0,4);
        if (!cin) return;
        if (opcion == 1) {
            string id = leerTexto("Identificacion: ");
            string nombre = leerTexto("Nombre completo: ");
            string fecha = leerTexto("Fecha de ingreso: ");
            string puesto = leerTexto("Puesto: ");
            if (!cin) return;
            sistema.registrarColaborador(centroActivo,id,nombre,fecha,puesto);
            mostrarResultado();
        } else if (opcion == 3) sistema.mostrarColaboradores(centroActivo);
        else if (opcion == 2 || opcion == 4) {
            string id = leerTexto("Identificacion del colaborador: ");
            if (!cin) return;
            if (opcion == 4) { sistema.eliminarColaborador(centroActivo,id); mostrarResultado(); }
            else {
                Colaborador* c = sistema.buscarColaborador(centroActivo,id);
                if (c == NULL) cout << "Colaborador inexistente.\n";
                else c->mostrar();
            }
        }
    } while (opcion != 0 && cin);
}
void Menu::menuBodegas() {
    int opcion;
    do {
        cout << "\nBODEGAS | Centro " << centroActivo
             << "\n1 Registrar\n2 Buscar\n3 Mostrar\n4 Ver matriz\n5 Eliminar\n6 Consultar celda\n0 Volver\n";
        opcion = leerEntero("Opcion: ",0,6);
        if (!cin) return;
        if (opcion == 1) {
            string codigo = leerTexto("Codigo propio: ");
            string nombre = leerTexto("Nombre: ");
            int tipo = leerEntero("Tipo: 1 General, 2 Fragil, 3 Tecnologia, 4 Documentos: ",1,4);
            int filas = leerEntero("Filas: ",1,2147483647);
            int columnas = leerEntero("Columnas: ",1,2147483647);
            if (!cin) return;
            sistema.registrarBodega(centroActivo,codigo,nombre,tipo,filas,columnas);
            mostrarResultado();
        } else if (opcion == 3) sistema.mostrarBodegas(centroActivo);
        else if (opcion != 0) {
            string codigo = leerTexto("Codigo de bodega: ");
            if (!cin) return;
            Bodega* b = sistema.buscarBodega(centroActivo,codigo);
            if (opcion == 5) { sistema.eliminarBodega(centroActivo,codigo); mostrarResultado(); }
            else if (b == NULL) cout << "Bodega inexistente.\n";
            else if (opcion == 2) b->mostrar();
            else if (opcion == 4) b->mostrarMatriz();
            else {
                int fila = leerEntero("Fila (desde 0): ",0,2147483647);
                int columna = leerEntero("Columna (desde 0): ",0,2147483647);
                if (!cin) return;
                if (!b->posicionValida(fila,columna)) cout << "Posicion fuera de la matriz.\n";
                else if (b->disponible(fila,columna)) cout << "Celda LIBRE.\n";
                else b->consultar(fila,columna)->mostrar();
            }
        }
    } while (opcion != 0 && cin);
}
void Menu::menuPaquetes() {
    int opcion;
    do {
        cout << "\nPAQUETES | Centro " << centroActivo
             << "\n1 Registrar\n2 Buscar global\n3 Mostrar del centro\n4 Eliminar global"
             << "\n5 Almacenar / resolver incidencia sin celda\n6 Reubicar"
             << "\n7 Registrar incidencia\n8 Resolver incidencia con celda o en ruta\n0 Volver\n";
        opcion = leerEntero("Opcion: ",0,8);
        if (!cin) return;
        if (opcion == 1) {
            string codigo = leerTexto("Codigo unico global: ");
            string descripcion = leerTexto("Descripcion: ");
            double peso = leerPeso();
            int categoria = leerEntero("Categoria: 1 General, 2 Fragil, 3 Tecnologia, 4 Documentos: ",1,4);
            sistema.mostrarClientes(centroActivo);
            string id = leerTexto("Identificacion del cliente propietario: ");
            if (!cin) return;
            sistema.registrarPaquete(centroActivo,codigo,descripcion,peso,categoria,sistema.buscarCliente(centroActivo,id));
            mostrarResultado();
        } else if (opcion == 3) sistema.mostrarPaquetes(centroActivo);
        else if (opcion != 0) {
            string codigo = leerTexto("Codigo del paquete (global): ");
            if (!cin) return;
            Paquete* p = sistema.buscarPaquete(codigo);
            if (opcion == 2) {
                if (p == NULL) cout << "Paquete inexistente.\n";
                else p->mostrar();
            } else if (opcion == 4) { sistema.eliminarPaquete(codigo); mostrarResultado(); }
            else if (p == NULL || p->getCentro()->getCodigo() != centroActivo)
                cout << "Seleccione un paquete del centro activo.\n";
            else if (opcion == 5 || opcion == 6) {
                sistema.mostrarCompatibles(codigo);
                string bodega;
                int fila = -1, columna = -1;
                bool aceptar = false;
                if (opcion == 5) {
                    Bodega* b = sistema.recomendar(codigo,fila,columna);
                    if (b == NULL) { cout << "No existe recomendacion para el paquete y su estado actual.\n"; continue; }
                    cout << "Recomendacion: " << b->getCodigo() << '-' << fila << '-' << columna << '\n';
                    aceptar = leerEntero("1 Aceptar, 0 Elegir otra: ",0,1) == 1;
                    if (aceptar) bodega = b->getCodigo();
                }
                if (!aceptar) {
                    bodega = leerTexto("Bodega destino: ");
                    fila = leerEntero("Fila desde 0: ",0,2147483647);
                    columna = leerEntero("Columna desde 0: ",0,2147483647);
                }
                if (!cin) return;
                if (opcion == 5) {
                    string fecha = leerTexto("Fecha del almacenamiento: ");
                    sistema.mostrarColaboradores(centroActivo);
                    string id = leerTexto("Identificacion del colaborador: ");
                    if (!cin) return;
                    sistema.almacenar(codigo,bodega,fila,columna,fecha,sistema.buscarColaborador(centroActivo,id));
                } else sistema.reubicar(codigo,bodega,fila,columna);
                mostrarResultado();
            } else {
                string fecha = leerTexto("Fecha: ");
                sistema.mostrarColaboradores(centroActivo);
                string id = leerTexto("Identificacion del colaborador: ");
                if (!cin) return;
                Colaborador* col = sistema.buscarColaborador(centroActivo,id);
                if (opcion == 7) sistema.registrarIncidencia(codigo,fecha,col);
                else sistema.resolverIncidencia(codigo,fecha,col);
                mostrarResultado();
            }
        }
    } while (opcion != 0 && cin);
}
void Menu::menuSolicitudes() {
    int opcion;
    do {
        cout << "\nSOLICITUDES | Centro " << centroActivo
             << "\n1 Crear\n2 Buscar global\n3 Mostrar del centro\n4 Aprobar y crear despacho"
             << "\n5 Rechazar\n6 Anular\n7 Ver tarifas\n0 Volver\n";
        opcion = leerEntero("Opcion: ",0,7);
        if (!cin) return;
        if (opcion == 1) {
            string codigo = leerTexto("Codigo unico de solicitud: ");
            string paquete = leerTexto("Codigo del paquete Almacenado: ");
            string cliente = leerTexto("Identificacion del propietario: ");
            sistema.mostrarColaboradores(centroActivo);
            string colaborador = leerTexto("Identificacion del colaborador: ");
            string destino = leerTexto("Direccion de entrega: ");
            string fecha = leerTexto("Fecha de solicitud: ");
            if (!cin) return;
            if (sistema.crearSolicitud(codigo,paquete,cliente,colaborador,centroActivo,destino,fecha))
                sistema.buscarSolicitud(codigo)->mostrar();
            mostrarResultado();
        } else if (opcion == 3) sistema.mostrarSolicitudes(centroActivo);
        else if (opcion == 7) {
            for (int i = 1; i <= 4; i++)
                cout << nombreCategoria(i) << ": CRC " << Tarifas::porKilogramo(i) << " por kg\n";
            cout << "Las empresas aplican su descuento al costo base.\n";
        } else if (opcion != 0) {
            string codigo = leerTexto("Codigo de solicitud (global): ");
            if (!cin) return;
            SolicitudEnvio* s = sistema.buscarSolicitud(codigo);
            if (opcion == 2) {
                if (s == NULL) cout << "Solicitud inexistente.\n";
                else s->mostrar();
            } else if (opcion == 4) {
                string despacho = leerTexto("Codigo unico del despacho: ");
                string fecha = leerTexto("Fecha de despacho: ");
                string hora = leerTexto("Hora: ");
                if (!cin) return;
                sistema.aprobarSolicitud(s,despacho,fecha,hora);
                mostrarResultado();
            } else {
                if (opcion == 5) sistema.rechazarSolicitud(codigo);
                else sistema.anularSolicitud(codigo);
                mostrarResultado();
            }
        }
    } while (opcion != 0 && cin);
}
void Menu::menuDespachos() {
    int opcion;
    do {
        cout << "\nDESPACHOS | Centro " << centroActivo
             << "\n1 Buscar global\n2 Mostrar del centro\n3 Finalizar entrega\n0 Volver\n";
        opcion = leerEntero("Opcion: ",0,3);
        if (!cin) return;
        if (opcion == 2) sistema.mostrarDespachos(centroActivo);
        else if (opcion != 0) {
            string codigo = leerTexto("Codigo del despacho (global): ");
            if (!cin) return;
            if (opcion == 1) {
                Despacho* d = sistema.buscarDespacho(codigo);
                if (d == NULL) cout << "Despacho inexistente.\n";
                else d->mostrar();
            } else {
                string fecha = leerTexto("Fecha de entrega: ");
                if (!cin) return;
                sistema.finalizarDespacho(codigo,fecha);
                mostrarResultado();
            }
        }
    } while (opcion != 0 && cin);
}
void Menu::menuReportes() {
    int opcion;
    do {
        cout << "\nREPORTES | Centro " << centroActivo
             << "\n1 Historial de cliente\n2 Clientes por envios finalizados\n3 Bitacora de paquete"
             << "\n4 Despacho de paquete\n5 Ocupacion de bodegas\n6 Despachos por colaborador\n0 Volver\n";
        opcion = leerEntero("Opcion: ",0,6);
        if (!cin) return;
        if (opcion == 1) {
            string id = leerTexto("Identificacion del cliente: ");
            if (!cin) return;
            sistema.reporteHistorial(centroActivo,id);
        } else if (opcion == 2) sistema.reporteRanking(centroActivo);
        else if (opcion == 3 || opcion == 4) {
            string codigo = leerTexto("Codigo del paquete (global): ");
            if (!cin) return;
            if (opcion == 3) sistema.reporteBitacora(codigo);
            else sistema.reporteDespachoPaquete(codigo);
        } else if (opcion == 5) sistema.reporteOcupacion(centroActivo);
        else if (opcion == 6) {
            string id = leerTexto("Identificacion del colaborador: ");
            if (!cin) return;
            sistema.reporteColaborador(centroActivo,id);
        }
    } while (opcion != 0 && cin);
}
void Menu::ejecutar() {
    cout << "TICOPACK LOGISTICS\n1 Iniciar con datos de prueba\n0 Iniciar vacio\n";
    int cargar = leerEntero("Opcion: ",0,1);
    if (!cin) return;
    if (cargar == 1 && DatosPrueba::cargar(sistema)) centroActivo = "C1";
    int opcion;
    do {
        cout << "\nTICOPACK | Centro activo: " << (centroActivo == "" ? "Ninguno" : centroActivo)
             << "\n1 Centros\n2 Clientes\n3 Colaboradores\n4 Bodegas\n5 Paquetes"
             << "\n6 Solicitudes\n7 Despachos\n8 Reportes\n9 Cambiar centro\n0 Salir\n";
        opcion = leerEntero("Opcion: ",0,9);
        if (!cin) break;
        if (opcion == 1) menuCentros();
        else if (opcion == 9) elegirCentro();
        else if (opcion != 0 && centroActivo == "") cout << "Registre o seleccione un centro primero.\n";
        else if (opcion == 2) menuClientes();
        else if (opcion == 3) menuColaboradores();
        else if (opcion == 4) menuBodegas();
        else if (opcion == 5) menuPaquetes();
        else if (opcion == 6) menuSolicitudes();
        else if (opcion == 7) menuDespachos();
        else if (opcion == 8) menuReportes();
    } while (opcion != 0 && cin);
    cout << "Sistema cerrado.\n";
}
