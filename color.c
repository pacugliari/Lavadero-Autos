#include "color.h"
#include <string.h>


int listarColores (eColor colores[],int tam){
    int todoOk = 0;

    if(colores && tam>0){
        system("cls");
        printf("  ***LISTADO DE COLORES***\n");
        printf("---------------------------\n");
        printf("ID\tColor\n");
        printf("---------------------------\n");
        for(int i=0;i<tam;i++){
            printf("%d\t%s\n",colores[i].id,colores[i].nombreColor);
        }
        printf("---------------------------\n\n");
        todoOk= 1;
    }

    return todoOk;
}


int buscarColor (eColor colores[],int tamC,int id,int* pIndice){
    int todoOk = 0;
    if(colores && tamC >0 && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamC;i++){
            if(colores[i].id == id){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarColor (eColor colores[],int tamC,int id){
    int todoOk = 0;
    int indice;
    if(colores && tamC > 0){
        buscarColor(colores,tamC,id,&indice);
        if(indice != -1)
            todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionColor (eColor colores[],int tamC,int id,char descripcion[]){
    int todoOk = 0;
    int indice;
    if(colores && tamC >0 && descripcion && buscarColor(colores,tamC,id,&indice)){
        strcpy(descripcion,colores[indice].nombreColor);
        todoOk = 1;
    }
    return todoOk;
}
