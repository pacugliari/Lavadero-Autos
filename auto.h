#include "marca.h"
#include "color.h"

#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct{
    int id;
    int idMarca;
    int idColor;
    char patente[8];
    char caja;
    int isEmpty;
}eAuto;

#endif // AUTO_H_INCLUDED

int inicializarAutos(eAuto autos[],int tamA);
int altaAuto (eAuto autos[],int tamA,eMarca marcas[],int tamM,eColor colores[],int tamC,int* pId);
int buscarAutoLibre (eAuto autos[],int tamA,int* pIndice);
int hardcodearAutos (eAuto autos[],int tamA,int cantidad,int* pId);
int modificarAuto (eAuto autos[],int tamA,eMarca marcas[],int tamM,eColor colores[],int tamC);
int cargarDescripcionPatente (eAuto autos[],int tamA,int id,char descripcion[]);
