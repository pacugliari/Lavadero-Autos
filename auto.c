#include "auto.h"
#include "marca.h"
#include "color.h"
#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include <ctype.h>


int inicializarAutos(eAuto autos[],int tamA){
    int todoOk = 0;
    if(autos && tamA >0){
        for(int i=0;i<tamA;i++){
            autos[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;

}

int buscarAutoLibre (eAuto autos[],int tamA,int* pIndice){
    int todoOk = 0;
    if(autos && tamA && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamA;i++){
            if(autos[i].isEmpty){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaAuto (eAuto autos[],int tamA,eMarca marcas[],int tamM,eColor colores[],int tamC,int* pId){
    int todoOk = 0;
    int indice;
    eAuto autoNuevo;

    if(autos && marcas && colores && tamA >0 && tamM >0 && tamC >0 && pId){
        buscarAutoLibre(autos,tamA,&indice);
        if(indice != -1){
            //INGRESO DE DATOS
            listarMarcas(marcas,tamM);
            printf("Ingrese el ID de la marca \n");
            scanf("%d",&autoNuevo.idMarca);
            fflush(stdin);

            while(!validarMarca(marcas,tamM,autoNuevo.idMarca)){
                printf("Error en la ID de la marca.Vuelva a ingresar \n");
                scanf("%d",&autoNuevo.idMarca);
                fflush(stdin);
            }

            listarColores(colores,tamC);
            printf("Ingrese el ID del color \n");
            scanf("%d",&autoNuevo.idColor);
            fflush(stdin);

            while(!validarColor(colores,tamC,autoNuevo.idColor)){
                printf("Error en la ID del color.Vuelva a ingresar \n");
                scanf("%d",&autoNuevo.idColor);
                fflush(stdin);
            }

            system("cls");

            printf("Ingrese el tipo de caja, 'm' para manual y 'a' para automatica \n");
            scanf("%c",&autoNuevo.caja);
            fflush(stdin);

            while(autoNuevo.caja != 'm' && autoNuevo.caja != 'a'){
                printf("Error en el tipo de caja ingresada.Vuelva a ingresar \n");
                scanf("%c",&autoNuevo.caja);
                fflush(stdin);
            }

            system("cls");

            printf("Ingrese la patente hasta 7 caracteres ej: ABXXXDD \n");
            gets(autoNuevo.patente);

            while(strlen(autoNuevo.patente) > 7){
                printf("Error en patente.Ingrese la patente hasta 7 caracteres \n");
                gets(autoNuevo.patente);
            }

            system("cls");

            autoNuevo.isEmpty = 0;
            autoNuevo.id = *pId;
            autos[indice] = autoNuevo;
            (*pId)++;
            todoOk = 1;
        }else{
            printf("No hay espacio disponible para el alta \n");
        }
    }else{
        printf("Error en los parametros del alta \n");
    }

    return todoOk = 1;
}

int ordenarAutosPorMarcaYPatente(eAuto autos[],int tamA,eMarca marcas[],int tamM){
    int todoOk = 0;
    char descripcionMarcaActual[20];
    char descripcionMarcaSiguiente[20];
    eAuto autoAux;

    if(autos && marcas && tamA >0 && tamM > 0){
        for(int i=0;i<tamA-1;i++){
            for(int j=i+1;j<tamA;j++){
                if(!autos[i].isEmpty){
                    cargarDescripcionMarca(marcas,tamM,autos[i].idMarca,descripcionMarcaActual);
                    cargarDescripcionMarca(marcas,tamM,autos[j].idMarca,descripcionMarcaSiguiente);
                    if((strcmp(descripcionMarcaActual,descripcionMarcaSiguiente) > 0)  ||
                        ((strcmp(descripcionMarcaActual,descripcionMarcaSiguiente) == 0) && (strcmp(autos[i].patente,autos[j].patente) > 0))){
                        autoAux = autos[i];
                        autos[i] = autos[j];
                        autos[j] = autoAux;
                    }
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int listarAutos (eAuto autos[],int tamA,eMarca marcas[],int tamM,eColor colores[],int tamC){
    int todoOk = 0;
    int hayAutos = 0;

    if(autos && marcas && colores && tamA >0 && tamM >0 && tamC >0 ){
        eAuto autosAux [tamA];
        for(int i=0;i<tamA;i++){
            autosAux[i] = autos[i];
        }
        ordenarAutosPorMarcaYPatente(autosAux,tamA,marcas,tamM);
        system("cls");
        printf("\t     ***LISTADO DE AUTOS***\n");
        printf("-------------------------------------------------------\n");
        printf("ID\t   Marca\tColor\t   Patente\tCaja\n");
        printf("-------------------------------------------------------\n");
        for(int i=0;i<tamA;i++){
            if(!autosAux[i].isEmpty){
                mostrarAuto(autosAux[i],marcas,tamM,colores,tamC);
                hayAutos = 1;
            }

        }
        if(!hayAutos){
            printf("\t     No hay autos cargados \n");
        }
        printf("-------------------------------------------------------\n\n");
        todoOk= 1;
        todoOk = 1;
    }
    return todoOk;
}

int hardcodearAutos (eAuto autos[],int tamA,int cantidad,int* pId){
    int todoOk = 0;
    eAuto autosHard [] = {{10000,1001,5003,"AB676DD",'m',0},
                          {10001,1001,5001,"AA000AA",'a',0},
                          {10002,1003,5002,"AA860AA",'m',0},
                          {10003,1004,5004,"AC195AA",'a',0},
                          {10004,1000,5000,"AE070AA",'m',0},};

    if (autos && tamA && pId && cantidad > 0 && cantidad <= tamA){
        for(int i=0;i<cantidad;i++){
            autos[i] = autosHard[i];
            autos[i].id = (*pId);
            (*pId)++;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarAuto (eAuto autos[],int tamA,int id,int* pIndice){
    int todoOk = 0;
    if(autos && tamA >0 && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamA;i++){
            if(autos[i].id == id){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int buscarAutoPorPatente (eAuto autos[],int tamA,char patente[],int* pIndice){
    int todoOk = 0;
    if(autos && tamA >0 && pIndice && patente){
        *pIndice = -1;
        for(int i=0;i<tamA;i++){
            if(!strcmp(patente,autos[i].patente)){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarAuto(eAuto autoI,eMarca marcas[],int tamM,eColor colores[],int tamC){
    int todoOk = 0;
    char descripcionMarca [20];
    char descripcionColor [20];
    char descripcionCaja[20]={"Automatica"};

    if(marcas && colores && tamM >0 && tamC >0){
        cargarDescripcionMarca(marcas,tamM,autoI.idMarca,descripcionMarca);
        cargarDescripcionColor(colores,tamC,autoI.idColor,descripcionColor);
        if(autoI.caja == 'm'){
            strcpy(descripcionCaja,"Manual");
        }
        printf("%d%10s\t  %10s\t%10s\t%s\n",autoI.id,descripcionMarca,descripcionColor,autoI.patente,descripcionCaja);
        todoOk = 1;
    }
    return todoOk;
}


int bajaAuto (eAuto autos[],int tamA,eMarca marcas[],int tamM,eColor colores[],int tamC){
    int todoOk = 0;
    int indice;
    int idIngresado;
    char respuestaBorrado='n';

    if(autos && marcas && colores && tamA >0 && tamM >0 && tamC >0 ){
        printf("Ingrese la ID a dar de baja: ");
        scanf("%d",&idIngresado);
        fflush(stdin);
        if(buscarAuto(autos,tamA,idIngresado,&indice)){
            if(indice != -1){
                printf("-------------------------------------------------------\n");
                printf("ID\t   Marca\tColor\t   Patente\tCaja\n");
                printf("-------------------------------------------------------\n");
                mostrarAuto(autos[indice],marcas,tamM,colores,tamC);
                printf("\nConfirma baja? s-SI \n");
                scanf("%c",&respuestaBorrado);
                fflush(stdin);

                if(respuestaBorrado == 's'){
                    autos[indice].isEmpty = 1;
                    todoOk = 1;
                }else{
                    printf("\nBaja cancelada \n");
                }

            }else
                printf("\nNo exite el auto con el id: %d \n",idIngresado);
        }else{
            printf("\nProblema al buscar el auto \n");
        }

    }else{
        printf("\nError en los parametros de la baja \n");
    }

    return todoOk;
}


char menuModificar (){
    char respuesta;

    printf("\n1) Color \n");
    printf("2) Modelo \n");
    printf("S) Salir \n");
    scanf("%c",&respuesta);
    fflush(stdin);

    respuesta = toupper(respuesta);

    return respuesta;
}


int modificarAuto (eAuto autos[],int tamA,eMarca marcas[],int tamM,eColor colores[],int tamC){
    int todoOk = 0;
    int indice;
    char patenteIngresada[8];
    char respuestaModificar='n';

    if(autos && marcas && colores && tamA >0 && tamM >0 && tamC >0 ){
        printf("Ingrese la patente del auto a modificar hasta 7 caracteres ej: ABXXXDD: ");
        gets(patenteIngresada);

        while(strlen(patenteIngresada) > 7){
            printf("Error en patente.Ingrese la patente hasta 7 caracteres \n");
            gets(patenteIngresada);
        }

        if(buscarAutoPorPatente (autos,tamA,patenteIngresada,&indice)){
            if(indice != -1){
                printf("-------------------------------------------------------\n");
                printf("ID\t   Marca\tColor\t   Patente\tCaja\n");
                printf("-------------------------------------------------------\n");
                mostrarAuto(autos[indice],marcas,tamM,colores,tamC);

                do{
                    switch(menuModificar()){
                        case '1':
                            listarColores(colores,tamC);
                            printf("Ingrese el ID del color \n");
                            scanf("%d",&autos[indice].idColor);
                            fflush(stdin);

                            while(!validarColor(colores,tamC,autos[indice].idColor)){
                                printf("Error en la ID del color.Vuelva a ingresar \n");
                                scanf("%d",&autos[indice].idColor);
                                fflush(stdin);
                            }
                            printf("Color modificado de manera exitosa \n");
                            break;
                        case '2':
                            listarMarcas(marcas,tamM);
                            printf("Ingrese el ID de la marca \n");
                            scanf("%d",&autos[indice].idMarca);
                            fflush(stdin);

                            while(!validarMarca(marcas,tamM,autos[indice].idMarca)){
                                printf("Error en la ID de la marca.Vuelva a ingresar \n");
                                scanf("%d",&autos[indice].idMarca);
                                fflush(stdin);
                            }
                            printf("Marca modificada de manera exitosa \n");
                            break;
                        case 'S':
                            respuestaModificar = 'S';
                        break;
                    }

                }while(respuestaModificar != 'S');
                todoOk = 1;

            }else
                printf("\nNo exite el auto con la patente: %s \n",patenteIngresada);
        }else{
            printf("\nProblema al buscar el auto \n");
        }

    }else{
        printf("\nError en los parametros de la baja \n");
    }

    return todoOk;
}


int cargarDescripcionPatente (eAuto autos[],int tamA,int id,char descripcion[]){
    int todoOk = 0;
    int indice;
    if(autos && tamA >0 && descripcion && buscarAuto (autos,tamA,id,&indice)){
        strcpy(descripcion,autos[indice].patente);
        todoOk = 1;
    }
    return todoOk;
}



