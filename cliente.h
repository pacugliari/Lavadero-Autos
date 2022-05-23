#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int id;
    char nombre[20];
    char sexo;
}eCliente;

#endif // CLIENTE_H_INCLUDED


int listarClientes (eCliente clientes[],int tamC);
int buscarCliente (eCliente clientes[],int tamC,int id,int* pIndice);
int validarCliente (eCliente clientes[],int tamC,int id);
int cargarNombreCliente (eCliente clientes[],int tamC,int id,char nombre[]);
