#include "cliente.h"

int listarClientes (eCliente clientes[],int tamC){
    int todoOk = 0;

    if(clientes && tamC>0){
        system("cls");
        printf("  ***LISTADO DE CLIENTES***\n");
        printf("-------------------------------\n");
        printf("ID\tNombre\t\tSexo\n");
        printf("-------------------------------\n");
        for(int i=0;i<tamC;i++){
            printf("%d\t%-10s\t%c\n",clientes[i].id,clientes[i].nombre,clientes[i].sexo);
        }
        printf("-------------------------------\n\n");
        todoOk= 1;
    }

    return todoOk;
}


int buscarCliente (eCliente clientes[],int tamC,int id,int* pIndice){
    int todoOk = 0;
    if(clientes && tamC >0 && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamC;i++){
            if(clientes[i].id == id){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarCliente (eCliente clientes[],int tamC,int id){
    int todoOk = 0;
    int indice;
    if(clientes && tamC > 0){
        buscarCliente(clientes,tamC,id,&indice);
        if(indice != -1)
            todoOk = 1;
    }
    return todoOk;
}

int cargarNombreCliente (eCliente clientes[],int tamC,int id,char nombre[]){
    int todoOk = 0;
    int indice;
    if(clientes && tamC >0 && nombre && buscarCliente (clientes,tamC,id,&indice)){
        strcpy(nombre,clientes[indice].nombre);
        todoOk = 1;
    }
    return todoOk;
}
