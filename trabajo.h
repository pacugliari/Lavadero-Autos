#include "fecha.h"
#include "auto.h"
#include "servicio.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int id;
    int idAuto;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

#endif // TRABAJO_H_INCLUDED

int altaTrabajo (eTrabajo trabajos[],eColor colores[],eAuto autos[],eMarca marcas[],eServicio servicios[],eCliente clientes[],int tamCl,int tamA,int tamS,int tamM,int tamT,int tamC,int* pId);
int listarTrabajos (eTrabajo trabajos[],int tamT,eAuto autos[],int tamA,eServicio servicios[],int tamS);
int hardcodearTrabajos (eTrabajo trabajos[],int tamT,int cantidad,int* pId);


//INFORMES
int mostrarTrabajosPorAuto (eTrabajo trabajos[],eColor colores[],eAuto autos[],eMarca marcas[],eServicio servicios[],eCliente clientes[],int tamCl,int tamA,int tamS,int tamM,int tamT,int tamC);
int mostrarImporteTrabajoDeAuto (eTrabajo trabajos[],eColor colores[],eAuto autos[],eMarca marcas[],eServicio servicios[],eCliente clientes[],int tamCl,int tamA,int tamS,int tamM,int tamT,int tamC);
int mostrarTrabajosPorServicio (eTrabajo trabajos[],eColor colores[],eAuto autos[],eMarca marcas[],eServicio servicios[],eCliente clientes[],int tamCl,int tamA,int tamS,int tamM,int tamT,int tamC);
int mostrarTrabajosPorFecha (eTrabajo trabajos[],eColor colores[],eAuto autos[],eMarca marcas[],eServicio servicios[],eCliente clientes[],int tamCl,int tamA,int tamS,int tamM,int tamT,int tamC);
