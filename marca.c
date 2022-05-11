#include "marca.h"
#include "stdlib.h"
#include "stdio.h"
#include <string.h>


int listarMarcas (eMarca marcas[],int tam){
    int todoOk = 0;

    if(marcas && tam>0){
        system("cls");
        printf("  ***LISTADO DE MARCAS***\n");
        printf("---------------------------\n");
        printf("ID\tMarca\n");
        printf("---------------------------\n");
        for(int i=0;i<tam;i++){
            printf("%d\t%s\n",marcas[i].id,marcas[i].descripcion);
        }
        printf("---------------------------\n\n");
        todoOk= 1;
    }

    return todoOk;
}


int buscarMarca (eMarca marcas[],int tamM,int id,int* pIndice){
    int todoOk = 0;
    if(marcas && tamM >0 && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamM;i++){
            if(marcas[i].id == id){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarMarca (eMarca marcas[],int tamM,int id){
    int todoOk = 0;
    int indice;
    if(marcas && tamM > 0){
        buscarMarca(marcas,tamM,id,&indice);
        if(indice != -1)
            todoOk = 1;
    }
    return todoOk;
}


int cargarDescripcionMarca(eMarca marcas[],int tamM,int id,char descripcion[]){
    int todoOk = 0;
    int indice;
    if(marcas && tamM >0 && descripcion && buscarMarca(marcas,tamM,id,&indice)){
        strcpy(descripcion,marcas[indice].descripcion);
        todoOk = 1;
    }
    return todoOk;
}
