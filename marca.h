#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{
    int id;
    char descripcion [20];
}eMarca;

#endif // MARCA_H_INCLUDED


int listarMarcas (eMarca marcas[],int tam);
int buscarMarca (eMarca marcas[],int tamM,int id,int* pIndice);
int validarMarca (eMarca marcas[],int tamM,int id);
int cargarDescripcionMarca(eMarca marcas[],int tamM,int id,char descripcion[]);
