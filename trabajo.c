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


int altaTrabajo (eTrabajo trabajos[],eColor colores[],eAuto autos[],eMarca marcas[],eServicio servicios[],eCliente clientes[],int tamCl,int tamA,int tamS,int tamM,int tamT,int tamC,int* pId){
    int todoOk = 0;
    int indice;
    int indiceAuto;
    eTrabajo trabajoNuevo;
    char patenteIngresada[8];


    if(trabajos && servicios && autos && colores && tamC && tamT >0 && tamS >0 && tamA > 0 && tamM > 0 && marcas && pId && clientes && tamCl>0){
        buscarTrabajoLibre (trabajos,tamT,&indice);
        if(indice != -1){
            //INGRESO DE DATOS
            listarAutos(autos,tamA,marcas,tamM,colores,tamC,clientes,tamCl);
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

    return todoOk;
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
    eTrabajo trabajosHard [] = {{30000,10000,20001,{22,5,2022},0},
                                {30001,10001,20002,{22,5,2022},0},
                                {30002,10002,20000,{13,6,2021},0},
                                {30003,10003,20003,{19,9,2021},0},
                                {30004,10004,20001,{16,5,2022},0}};

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


int mostrarTrabajosPorAuto (eTrabajo trabajos[],eColor colores[],eAuto autos[],eMarca marcas[],eServicio servicios[],eCliente clientes[],int tamCl,int tamA,int tamS,int tamM,int tamT,int tamC){
    int todoOk = 0;
    int idAuto;
    int hayTrabajos = 0;
    char patenteAuto [10];

    if(trabajos && servicios && autos && colores &&clientes && tamCl>0 && tamC && tamT >0 && tamS >0 && tamA > 0 && tamM > 0 && marcas ){

        listarAutos(autos,tamA,marcas,tamM,colores,tamC,clientes,tamCl);
        printf("Ingrese el ID del auto \n");
        scanf("%d",&idAuto);
        fflush(stdin);

        while(!validarAuto(autos,tamA,idAuto)){
                printf("Error en la ID del auto.Vuelva a ingresar \n");
                scanf("%d",&idAuto);
                fflush(stdin);
        }

        system("cls");
        printf("\t     ***LISTADO DE TRABAJOS***\n");
        printf("-------------------------------------------------------\n");
        printf("ID\t   Patente\tServicio\tFecha\n");
        printf("-------------------------------------------------------\n");
        for(int i=0;i<tamT;i++){
            if(trabajos[i].idAuto == idAuto && !trabajos[i].isEmpty){
               mostrarTrabajo(trabajos[i],servicios,tamS,autos,tamA);
               hayTrabajos = 1;
            }
        }
        cargarDescripcionPatente(autos,tamA,idAuto,patenteAuto);
        if(!hayTrabajos)
            printf("No hay trabajos realizados para el auto con patente: %s \n",patenteAuto);

        todoOk = 1;
    }
    return todoOk;
}


int mostrarImporteTrabajoDeAuto (eTrabajo trabajos[],eColor colores[],eAuto autos[],eMarca marcas[],eServicio servicios[],eCliente clientes[],int tamCl,int tamA,int tamS,int tamM,int tamT,int tamC){
    int todoOk = 0;
    int idAuto;
    int hayTrabajos = 0;
    char patenteAuto [10];
    float sumaImportes = 0;
    int indiceServicio;

    if(trabajos && servicios && autos && colores && clientes && tamCl >0 && tamC && tamT >0 && tamS >0 && tamA > 0 && tamM > 0 && marcas ){

        listarAutos(autos,tamA,marcas,tamM,colores,tamC,clientes,tamCl);
        printf("Ingrese el ID del auto \n");
        scanf("%d",&idAuto);
        fflush(stdin);

        while(!validarAuto(autos,tamA,idAuto)){
                printf("Error en la ID del auto.Vuelva a ingresar \n");
                scanf("%d",&idAuto);
                fflush(stdin);
        }

        system("cls");
        for(int i=0;i<tamT;i++){
            if(trabajos[i].idAuto == idAuto && !trabajos[i].isEmpty){
                buscarServicio(servicios,tamS,trabajos[i].idServicio,&indiceServicio);
                sumaImportes += servicios[indiceServicio].precio;
                hayTrabajos = 1;
            }
        }
        cargarDescripcionPatente(autos,tamA,idAuto,patenteAuto);
        if(!hayTrabajos)
            printf("No hay trabajos realizados para el auto con patente: %s \n",patenteAuto);
        else
            printf("La suma de importes de los trabajos realizados para el auto con patente: %s es $%0.2f \n",patenteAuto,sumaImportes);

        todoOk = 1;
    }
    return todoOk;
}



int mostrarTrabajosPorServicio (eTrabajo trabajos[],eColor colores[],eAuto autos[],eMarca marcas[],eServicio servicios[],eCliente clientes[],int tamCl,int tamA,int tamS,int tamM,int tamT,int tamC){
    int todoOk = 0;
    int idServicio;
    int hayTrabajos = 0;
    char descripcionServicio[20];

    if(trabajos && servicios && autos && colores && tamC && tamT >0 && tamS >0 && tamA > 0 && tamM > 0 && marcas ){
        listarServicios(servicios,tamS);
        printf("Ingrese el ID del servicio \n");
        scanf("%d",&idServicio);
        fflush(stdin);

        while(!validarServicio(servicios,tamS,idServicio)){
            printf("Error en la ID del servicio.Vuelva a ingresar \n");
            scanf("%d",&idServicio);
            fflush(stdin);
        }

        system("cls");
        printf("\t     ***LISTADO DE TRABAJOS***\n");
        printf("-------------------------------------------------------\n");
        printf("ID\t   Patente\tServicio\tFecha\n");
        printf("-------------------------------------------------------\n");
        for(int i=0;i<tamT;i++){
            if(trabajos[i].idServicio == idServicio){
                mostrarTrabajo(trabajos[i],servicios,tamS,autos,tamA);
                hayTrabajos = 1;
            }
        }
        cargarDescripcionServicio(servicios,tamS,idServicio,descripcionServicio);
        if(!hayTrabajos)
            printf("No hay trabajos para el servicio de %s \n",descripcionServicio);



        todoOk = 1;
    }
    return todoOk;
}


int mostrarTrabajosPorFecha (eTrabajo trabajos[],eColor colores[],eAuto autos[],eMarca marcas[],eServicio servicios[],eCliente clientes[],int tamCl,int tamA,int tamS,int tamM,int tamT,int tamC){
    int todoOk = 0;
    eFecha fecha;
    int hayTrabajos = 0;

    if(trabajos && servicios && autos && colores && tamC && tamT >0 && tamS >0 && tamA > 0 && tamM > 0 && marcas ){
        printf("Ingrese la fecha ej: XX/XX/XXXX: ");
        scanf("%d/%d/%d",&fecha.dia,&fecha.mes,&fecha.anio);
        fflush(stdin);

        while(!validarFecha(fecha)){
            printf("Error en la fecha.Ingrese la fecha ej: XX/XX/XXXX: ");
            scanf("%d/%d/%d",&fecha.dia,&fecha.mes,&fecha.anio);
            fflush(stdin);
        }

        system("cls");
        printf("\t     ***LISTADO DE TRABAJOS***\n");
        printf("-------------------------------------------------------\n");
        printf("ID\t   Patente\tServicio\tFecha\n");
        printf("-------------------------------------------------------\n");
        for(int i=0;i<tamT;i++){
            if(compararFechas(fecha,trabajos[i].fecha)){
                mostrarTrabajo(trabajos[i],servicios,tamS,autos,tamA);
                hayTrabajos=1;
            }
        }
        if(!hayTrabajos)
            printf("No hay trabajos para la fecha %d/%d/%d \n",fecha.dia,fecha.mes,fecha.anio);

        todoOk = 1;
    }
    return todoOk;
}
