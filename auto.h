#include "marca.h"
#include "color.h"
#include "cliente.h"

#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct{
    int id;
    int idMarca;
    int idColor;
    int idCliente;
    char patente[8];
    char caja;
    int isEmpty;
}eAuto;

#endif // AUTO_H_INCLUDED

int inicializarAutos(eAuto autos[],int tamA);
int altaAuto (eAuto autos[],int tamA,eMarca marcas[],int tamM,eColor colores[],int tamC,int* pId);
int buscarAutoLibre (eAuto autos[],int tamA,int* pIndice);
int hardcodearAutos (eAuto autos[],int tamA,int cantidad,int* pId);
int modificarAuto (eAuto autos[],int tamA,eMarca marcas[],int tamM,eColor colores[],int tamC,eCliente clientes[],int tamCl);
int cargarDescripcionPatente (eAuto autos[],int tamA,int id,char descripcion[]);
int ordenarAutosPorMarcaYPatente(eAuto autos[],int tamA,eMarca marcas[],eColor colores[],int tamC,int tamM,eCliente clientes[],int tamCl);
int validarAuto (eAuto autos[],int tamA,int id);
int mostrarAuto(eAuto autoI,eMarca marcas[],int tamM,eColor colores[],int tamC,eCliente clientes[],int tamCl);
int listarAutos (eAuto autos[],int tamA,eMarca marcas[],int tamM,eColor colores[],int tamC,eCliente clientes[],int tamCl);
int bajaAuto (eAuto autos[],int tamA,eMarca marcas[],int tamM,eColor colores[],int tamC,eCliente clientes[],int tamCl);

//LISTADOS
int mostrarAutosPorColor(eAuto autos[],eColor colores[],eMarca marcas[],eCliente clientes[],int tamCl,int tamM,int tamA,int tamC);
int mostrarAutosPorMarca (eAuto autos[],eColor colores[],eMarca marcas[],eCliente clientes[],int tamCl,int tamM,int tamA,int tamC);
int mostrarAutoViejo (eAuto autos[],eColor colores[],eMarca marcas[],eCliente clientes[],int tamCl,int tamM,int tamA,int tamC);
int mostrarAutosPorMarcas (eAuto autos[],eColor colores[],eMarca marcas[],eCliente clientes[],int tamCl,int tamM,int tamA,int tamC);
int mostrarAutosPorColorYMarca (eAuto autos[],eColor colores[],eMarca marcas[],eCliente clientes[],int tamCl,int tamM,int tamA,int tamC);
int mostrarMarcasMasElegidas (eAuto autos[],eColor colores[],eMarca marcas[],eCliente clientes[],int tamCl,int tamM,int tamA,int tamC);

//ORDENAMIENTO
int ordearAutosPorPatente (eAuto autos[],eColor colores[],eMarca marcas[],int tamM,int tamA,int tamC,int orden);
