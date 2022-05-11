#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
    int id;
    char nombreColor [20];
}eColor;


#endif // COLOR_H_INCLUDED


int listarColores (eColor colores[],int tam);
int buscarColor (eColor colores[],int tamC,int id,int* pIndice);
int validarColor (eColor colores[],int tamC,int id);
int cargarDescripcionColor (eColor colores[],int tamC,int id,char descripcion[]);
