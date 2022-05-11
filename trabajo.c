#include "trabajo.h"
#include "auto.h"
#include "marca.h"
#include "servicio.h"
#include <stdio.h>
#include <stdlib.h>


int inicializarTrabajos (eTrabajo trabajos[],int tamT){
    int todoOk = 0;
    if(trabajos && tamT >0){
        for(int i=0;i<tamT;i++){
            trabajos[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;

}


int buscarTrabajoLibre (eTrabajo trabajos[],int tamT,int* pIndice){
    int todoOk = 0;
    if(trabajos && tamT && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamT;i++){
            if(trabajos[i].isEmpty){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int altaTrabajo (eTrabajo trabajos[],eColor colores[],eAuto autos[],eMarca marcas[],eServicio servicios[],int tamA,int tamS,int tamM,int tamT,int tamC,int* pId){
    int todoOk = 0;
    int indice;
    int indiceAuto;
    eTrabajo trabajoNuevo;
    char patenteIngresada[8];


    if(trabajos && servicios && autos && colores && tamC && tamT >0 && tamS >0 && tamA > 0 && tamM > 0 && marcas && pId){
        buscarTrabajoLibre (trabajos,tamT,&indice);
        if(indice != -1){
            //INGRESO DE DATOS
            listarAutos(autos,tamA,marcas,tamM,colores,tamC);
            printf("Ingrese la patente  \n");
            gets(patenteIngresada);

            while(strlen(patenteIngresada) > 7){
                printf("Error en patente.Ingrese la patente hasta 7 caracteres\n");
                gets(patenteIngresada);
            }

            buscarAutoPorPatente(autos,tamA,patenteIngresada,&indiceAuto);

            while(indiceAuto == -1){
                printf("No exite el auto con la patente: %s \n",patenteIngresada);
                printf("Ingrese la patente  \n");
                gets(patenteIngresada);

                while(strlen(patenteIngresada) > 7){
                    printf("Error en patente.Ingrese la patente hasta 7 caracteres\n");
                    gets(patenteIngresada);
                }
                buscarAutoPorPatente(autos,tamA,patenteIngresada,&indiceAuto);
            }

            trabajoNuevo.idAuto = autos[indiceAuto].id;

            listarServicios(servicios,tamS);
            printf("Ingrese el ID del servicio \n");
            scanf("%d",&trabajoNuevo.idServicio);
            fflush(stdin);

            while(!validarServicio(servicios,tamS,trabajoNuevo.idServicio)){
                printf("Error en la ID del servicio.Vuelva a ingresar \n");
                scanf("%d",&trabajoNuevo.idServicio);
                fflush(stdin);
            }

            printf("Ingrese la fecha ej: XX/XX/XXXX: ");
            scanf("%d/%d/%d",&trabajoNuevo.fecha.dia,&trabajoNuevo.fecha.mes,&trabajoNuevo.fecha.anio);
            fflush(stdin);

            while(!validarFecha(trabajoNuevo.fecha)){
                printf("Error en la fecha.Ingrese la fecha ej: XX/XX/XXXX: ");
                scanf("%d/%d/%d",&trabajoNuevo.fecha.dia,&trabajoNuevo.fecha.mes,&trabajoNuevo.fecha.anio);
                fflush(stdin);
            }

            trabajoNuevo.isEmpty = 0;
            trabajoNuevo.id = *pId;
            trabajos[indice] = trabajoNuevo;
            (*pId)++;
            todoOk = 1;

        }else{
            printf("No hay espacio disponible para el alta de trabajo\n");
        }
    }else{
        printf("Error en los parametros del alta de trabajo\n");
    }

    return todoOk = 1;
}



int mostrarTrabajo (eTrabajo trabajoI,eServicio servicios[],int tamS,eAuto autos[],int tamA){
    int todoOk = 0;
    char descripcionServicio [20];
    char descripcionPatente [20];

    if(autos && servicios && tamS >0 && tamA >0){
        cargarDescripcionServicio (servicios,tamS,trabajoI.idServicio,descripcionServicio);
        cargarDescripcionPatente (autos,tamA,trabajoI.idAuto,descripcionPatente);

        printf("%d   %10s    %10s        %02d/%02d/%02d \n",trabajoI.id,descripcionPatente,descripcionServicio,trabajoI.fecha.dia,trabajoI.fecha.mes,trabajoI.fecha.anio);
        todoOk = 1;
    }
    return todoOk;
}


int listarTrabajos (eTrabajo trabajos[],int tamT,eAuto autos[],int tamA,eServicio servicios[],int tamS){
    int todoOk = 0;
    int hayTrabajos = 0;
    if(autos && servicios && trabajos && tamT >0 && tamA >0 && tamS >0 ){
        system("cls");
        printf("\t     ***LISTADO DE TRABAJOS***\n");
        printf("-------------------------------------------------------\n");
        printf("ID\t   Patente\tServicio\tFecha\n");
        printf("-------------------------------------------------------\n");
        for(int i=0;i<tamT;i++){
            if(!trabajos[i].isEmpty){
                mostrarTrabajo(trabajos[i],servicios,tamS,autos,tamA);
                hayTrabajos = 1;
            }

        }
        if(!hayTrabajos){
            printf("\t     No hay trabajos cargados \n");
        }
        printf("-------------------------------------------------------\n\n");
        todoOk= 1;
    }
    return todoOk;
}


int hardcodearTrabajos (eTrabajo trabajos[],int tamT,int cantidad,int* pId){
    int todoOk = 0;
    eTrabajo trabajosHard [] = {{30000,10000,20003,{10,5,2022},0}};

    if (trabajos && tamT && pId && cantidad > 0 && cantidad <= tamT){
        for(int i=0;i<cantidad;i++){
            trabajos[i] = trabajosHard[i];
            trabajos[i].id = (*pId);
            (*pId)++;
        }
        todoOk = 1;
    }
    return todoOk;
}
