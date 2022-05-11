#include "servicio.h"


int listarServicios (eServicio servicios[],int tam){
    int todoOk = 0;

    if(servicios && tam>0){
        system("cls");
        printf("  ***LISTADO DE SERVICIOS***\n");
        printf("-------------------------------\n");
        printf("ID\tServicio\tPrecio\n");
        printf("-------------------------------\n");
        for(int i=0;i<tam;i++){
            printf("%d\t%10s\t$%0.2f\n",servicios[i].id,servicios[i].descripcion,servicios[i].precio);
        }
        printf("-------------------------------\n\n");
        todoOk= 1;
    }

    return todoOk;
}


int buscarServicio (eServicio servicios[],int tamS,int id,int* pIndice){
    int todoOk = 0;
    if(servicios && tamS >0 && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamS;i++){
            if(servicios[i].id == id){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarServicio (eServicio servicios[],int tamS,int id){
    int todoOk = 0;
    int indice;
    if(servicios && tamS > 0){
        buscarServicio(servicios,tamS,id,&indice);
        if(indice != -1)
            todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionServicio(eServicio servicios[],int tamS,int id,char descripcion[]){
    int todoOk = 0;
    int indice;
    if(servicios && tamS >0 && descripcion && buscarServicio (servicios,tamS,id,&indice)){
        strcpy(descripcion,servicios[indice].descripcion);
        todoOk = 1;
    }
    return todoOk;
}



