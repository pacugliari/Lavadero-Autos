#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
    int id;
    char descripcion [25];
    float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED

int listarServicios (eServicio servicios[],int tam);
int buscarServicio (eServicio servicios[],int tamS,int id,int* pIndice);
int validarServicio (eServicio servicios[],int tamS,int id);
int cargarDescripcionServicio(eServicio servicios[],int tamS,int id,char descripcion[]);
