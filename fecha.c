#include "fecha.h"

//MESES CON 31- ENERO-MARZO-MAYO-JULIO-AGOSTO-OCTUBRE-DICIEMBRE
//MESES CON 30 --ABRIL-JUNIO-SEPTIEMBRE-NOVIEMBRE
//MESES CON 28 - FEBRERO

int validarFecha(eFecha fecha){
    int todoOk = 0;
    int dia = fecha.dia;
    int mes = fecha.mes;
    int anio = fecha.anio;

    if(anio > (ANIO_ACTUAL-100) && anio <= ANIO_ACTUAL){
        if(mes < 13 && mes > 0){
            if(dia > 0){
                switch(mes){
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                        if(dia < 32)
                            todoOk=1;
                        break;

                    case 2:
                        if(dia < 29)
                            todoOk=1;
                        break;

                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        if(dia < 31)
                            todoOk=1;
                        break;
                }

            }
        }
    }

    return todoOk;

}

int compararFechas(eFecha fecha1,eFecha fecha2){
    int sonIguales = 0;

    if(fecha1.anio == fecha2.anio && fecha1.mes == fecha2.mes && fecha1.dia==fecha2.dia){
        sonIguales = 1;
    }

    return sonIguales;
}
