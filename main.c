#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "auto.h"
#include "trabajo.h"


#define TAMM 5
#define TAMC 5
#define TAMS 4
#define TAMA 20
#define TAMT 20

#define ID_AUTO 10000
#define ID_TRABAJO 30000

char menu();


int main()
{
    char respuesta = 'N';
    int idAuto = ID_AUTO;
    int idTrabajo = ID_TRABAJO;

    eMarca marcas [TAMM] = {{1000,"Renault"},
                            {1001,"Ford"},
                            {1002,"Fiat"},
                            {1003,"Chevrolet"},
                            {1004,"Peugeot"}};

    eColor colores [TAMC] = {{5000,"Negro"},
                             {5001,"Blanco"},
                             {5002,"Rojo"},
                             {5003,"Gris"},
                             {5004,"Azul"}};

    eServicio servicios [TAMS] = {{20000,"Lavado",450},
                                  {20001,"Pulido",500},
                                  {20002,"Encerado",600},
                                  {20003,"Completo",900}};


    eAuto autos [TAMA];
    eTrabajo trabajos [TAMT];

    inicializarAutos(autos,TAMA);
    inicializarTrabajos(trabajos,TAMT);

    hardcodearAutos(autos,TAMA,5,&idAuto);
    hardcodearTrabajos(trabajos,TAMT,1,&idTrabajo);

    do{
        switch(respuesta=menu()){
            case 'A':
                if(altaAuto(autos,TAMA,marcas,TAMM,colores,TAMC,&idAuto)){
                    printf("Alta de auto de manera exitosa \n\n");
                }else
                    printf("No se pudo realizar el alta \n\n");
                break;
            case 'B':
                if(idAuto != ID_AUTO && modificarAuto(autos,TAMA,marcas,TAMM,colores,TAMC)){
                    printf("Se modifico el auto de manera exitosa \n");
                }else
                    printf("No se pudo modificar el auto \n");
                break;
            case 'C':
                if(idAuto != ID_AUTO && bajaAuto (autos,TAMA,marcas,TAMM,colores,TAMC)){
                    printf("Baja de auto de manera exitosa \n\n");
                }else
                    printf("No se pudo realizar la baja \n");
                break;
            case 'D':
                listarAutos(autos,TAMA,marcas,TAMM,colores,TAMC);
                break;
            case 'E':
                listarMarcas(marcas,TAMM);
                break;
            case 'F':
                listarColores(colores,TAMC);
                break;
            case 'G':
                listarServicios(servicios,TAMS);
                break;
            case 'H':
                if(altaTrabajo(trabajos,colores,autos,marcas,servicios,TAMA,TAMS,TAMM,TAMT,TAMC,&idTrabajo)){
                    printf("Alta de trabajo realizada de manera exitosa \n\n");
                }else
                    printf("No se pudo realizar el alta del trabajo \n\n");
                break;
            case 'I':
                listarTrabajos(trabajos,TAMT,autos,TAMA,servicios,TAMS);
                break;
            case 'S':
                respuesta = 'S';
                break;
            default:
                system("cls");
                printf("Opcion de menu incorrecta \n\n");
            break;
        }
        if(idAuto == ID_AUTO && (respuesta == 'B' || respuesta == 'C')){
            printf("Debe ingresar al menos 1 auto para ingresar a esta opcion \n\n");
        }

        system("pause");
        system("cls");
    }while (respuesta != 'S');

    return 0;
}

char menu(){
    char respuesta;

    printf("A-Alta Auto \n");
    printf("B-Modificar Auto \n");
    printf("C-Baja Auto \n");
    printf("D-Listar Autos \n");
    printf("E-Listar Marcas \n");
    printf("F-Listar Colores \n");
    printf("G-Listar Servicios \n");
    printf("H-Alta Trabajo \n");
    printf("I-Listar Trabajos \n");
    printf("S-Salir \n\n");

    scanf("%c",&respuesta);
    fflush(stdin);

    respuesta = toupper(respuesta);

    return respuesta;

}
