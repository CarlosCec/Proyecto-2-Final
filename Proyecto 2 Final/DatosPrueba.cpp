#include <sstream>
#include <iostream>
#include <string>
#include "DatosPrueba.h"
using namespace std;

bool DatosPrueba::cargar(Sistema& s) {
    // Solo se llama al iniciar un sistema vacio; no se repiten los ejemplos.
    if (s.buscarCentro("C1") != NULL || s.buscarCentro("C2") != NULL) return false;
    s.registrarCentro("C1","Perez Zeledon","San Jose","San Isidro centro","27710001");
    s.registrarCentro("C2","Heredia","Heredia","Heredia centro","22610002");
    s.registrarCentro("C3","Centro nuevo","Cartago","Cartago centro","25510003");
    s.registrarClienteFisico("C1","101","Ana Solano","88880001","ana@ejemplo.com");
    s.registrarClienteEmpresa("C1","J201","Libreria Sur","27710004","sur@ejemplo.com","Comercio",15);
    s.registrarClienteFisico("C1","102","Luis Mora","88880002","luis@ejemplo.com");
    s.registrarClienteFisico("C2","101","Carlos Rojas","88880003","carlos@ejemplo.com");
    s.registrarClienteEmpresa("C2","J301","Tecnologia Norte","22610005","norte@ejemplo.com","Tecnologia",100);
    s.registrarColaborador("C1","501","Maria Vega","2026-01-15","Operadora");
    s.registrarColaborador("C1","502","Diego Soto","2026-03-01","Despachador");
    s.registrarColaborador("C2","501","Elena Ruiz","2026-02-10","Operadora");
    s.registrarBodega("C1","G1","Principal",1,2,3);
    s.registrarBodega("C1","G2","Auxiliar",1,3,3);
    s.registrarBodega("C1","F1","Fragiles",2,2,2);
    s.registrarBodega("C1","T1","Tecnologia",3,2,2);
    s.registrarBodega("C1","D1","Documentos",4,1,3);
    s.registrarBodega("C2","G1","Principal Heredia",1,2,2);
    Cliente* ana = s.buscarCliente("C1","101");
    Cliente* empresa = s.buscarCliente("C1","J201");
    Colaborador* maria = s.buscarColaborador("C1","501");
    Colaborador* diego = s.buscarColaborador("C1","502");
    s.registrarPaquete("C1","PK101","Ropa",2.5,1,ana);
    s.registrarPaquete("C1","PK102","Vasos",1,2,empresa);
    s.registrarPaquete("C1","PK103","Zapatos",3,1,ana);
    s.registrarPaquete("C1","PK104","Cuadernos",4,1,empresa);
    s.registrarPaquete("C1","PK105","Teclado",1.2,3,s.buscarCliente("C1","102"));
    s.registrarPaquete("C1","PK106","Documentos legales",0.5,4,ana);
    s.almacenar("PK102","F1",0,0,"2026-10-28",maria);
    s.almacenar("PK103","G1",0,0,"2026-10-28",maria);
    s.crearSolicitud("S103","PK103","101","502","C1","San Jose centro","2026-10-28");
    s.aprobarSolicitud(s.buscarSolicitud("S103"),"DP103","2026-10-29","08:00");
    s.almacenar("PK104","G1",0,0,"2026-10-28",maria);
    s.crearSolicitud("S104","PK104","J201","502","C1","Cartago centro","2026-10-28");
    s.aprobarSolicitud(s.buscarSolicitud("S104"),"DP104","2026-10-28","09:00");
    s.finalizarDespacho("DP104","2026-10-29");
    s.almacenar("PK105","T1",0,0,"2026-10-28",maria);
    s.registrarIncidencia("PK105","2026-10-29",diego);
    s.almacenar("PK106","D1",0,0,"2026-10-28",maria);
    s.crearSolicitud("S106R","PK106","101","501","C1","Alajuela","2026-10-28");
    s.rechazarSolicitud("S106R");
    s.crearSolicitud("S106A","PK106","101","501","C1","Alajuela","2026-10-28");
    s.anularSolicitud("S106A");
    s.crearSolicitud("S106","PK106","101","501","C1","Alajuela","2026-10-29");
    s.registrarPaquete("C2","PK201","Camisa",1,1,s.buscarCliente("C2","101"));
    s.almacenar("PK201","G1",0,0,"2026-10-28",s.buscarColaborador("C2","501"));
    s.crearSolicitud("S201","PK201","101","501","C2","Barva","2026-10-28");
    s.aprobarSolicitud(s.buscarSolicitud("S201"),"DP201","2026-10-28","11:00");
    s.finalizarDespacho("DP201","2026-10-29");
    return true;
}
