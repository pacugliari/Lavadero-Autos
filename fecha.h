#define ANIO_ACTUAL 2022


#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;


#endif // FECHA_H_INCLUDED

int validarFecha(eFecha fecha);
int compararFechas(eFecha fecha1,eFecha fecha2);
