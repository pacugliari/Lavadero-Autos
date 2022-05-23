#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "auto.h"
#include "trabajo.h"
#include "cliente.h"

#define TAMM 5
#define TAMC 5
#define TAMS 4
#define TAMA 20
#define TAMT 20
#define TAMCL 5

#define ID_AUTO 10000
#define ID_TRABAJO 30000
#define ASC 1
#define DES 0

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

    eCliente clientes [TAMCL] = {{50000,"Pablo",'m'},
                                 {50001,"Sergio",'m'},
                                 {50002,"Donna",'f'},
                                 {50003,"Mirta",'f'},
                                 {50004,"Beto",'m'}};


    eAuto autos [TAMA];
    eTrabajo trabajos [TAMT];

    inicializarAutos(autos,TAMA);
    inicializarTrabajos(trabajos,TAMT);

    hardcodearAutos(autos,TAMA,5,&idAuto);
    hardcodearTrabajos(trabajos,TAMT,5,&idTrabajo);

    do{
        switch(respuesta=menu()){
            case 'A':
                if(altaAuto(autos,TAMA,marcas,TAMM,colores,TAMC,&idAuto)){
                    printf("Alta de auto de manera exitosa \n\n");
                }else
                    printf("No se pudo realizar el alta \n\n");
                break;
            case 'B':
                if(idAuto != ID_AUTO && modificarAuto(autos,TAMA,marcas,TAMM,colores,TAMC,clientes,TAMCL)){
                    printf("Se modifico el auto de manera exitosa \n");
                }else
                    printf("No se pudo modificar el auto \n");
                break;
            case 'C':
                if(idAuto != ID_AUTO && bajaAuto (autos,TAMA,marcas,TAMM,colores,TAMC,clientes,TAMCL)){
                    printf("Baja de auto de manera exitosa \n\n");
                }else
                    printf("No se pudo realizar la baja \n");
                break;
            case 'D':
                ordenarAutosPorMarcaYPatente(autos,TAMA,marcas,colores,TAMC,TAMM,clientes,TAMCL);
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
                if(altaTrabajo(trabajos,colores,autos,marcas,servicios,clientes,TAMCL,TAMA,TAMS,TAMM,TAMT,TAMC,&idTrabajo)){
                    printf("Alta de trabajo realizada de manera exitosa \n\n");
                }else
                    printf("No se pudo realizar el alta del trabajo \n\n");
                break;
            case 'I':
                listarTrabajos(trabajos,TAMT,autos,TAMA,servicios,TAMS);
                break;
            case 'J':
                listarClientes(clientes,TAMCL);
                break;
            case 'L':
                menuInformes(trabajos,colores,autos,marcas,servicios,clientes,TAMCL,TAMA,TAMS,TAMM,TAMT,TAMC);
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

int menuInformes(eTrabajo trabajos[],eColor colores[],eAuto autos[],eMarca marcas[],eServicio servicios[],eCliente clientes[],int tamCl,int tamA,int tamS,int tamM,int tamT,int tamC){
    int todoOk = 0;
    char respuesta;
    system("cls");

    if(trabajos && servicios && autos && colores && clientes && tamCl> 0 && tamC && tamT >0 && tamS >0 && tamA > 0 && tamM > 0 && marcas){
        do{
            printf("0-Mostrar autos del color seleccionado por el usuario\n");
            printf("1-Mostrar autos de una marca seleccionada.\n");
            printf("2-Informar el o los autos más viejos.\n");
            printf("3-Mostrar un listado de los autos separados por marca.\n");
            printf("4-Elegir un color y una marca y contar cuantos autos hay de ese color y esa marca.\n");
            printf("5-Mostrar la o las marcas más elegidas por los clientes.\n");
            printf("6-Pedir un auto y mostrar todos los trabajos que se le hicieron al mismo.\n");
            printf("7-Pedir un auto e informar la suma de los importes que se le hicieron al mismo.\n");
            printf("8-Pedir un servicio y mostrar los autos a los que se realizo ese servicio y la fecha.\n");
            printf("9-Pedir una fecha y mostrar todos los servicios realizados en la misma.\n");
            printf("S-Salir \n\n");
            scanf("%c",&respuesta);
            fflush(stdin);

            respuesta = toupper(respuesta);

            switch(respuesta){
                case '0':
                        mostrarAutosPorColor(autos,colores,marcas,clientes,tamCl,tamM,tamA,tamC);
                    break;
                case '1':
                        mostrarAutosPorMarca(autos,colores,marcas,clientes,tamCl,tamM,tamA,tamC);
                    break;
                case '2':
                        mostrarAutoViejo (autos,colores,marcas,clientes,tamCl,tamM,tamA,tamC);
                    break;
                case '3':
                        mostrarAutosPorMarcas(autos,colores,marcas,clientes,tamCl,tamM,tamA,tamC);
                    break;
                case '4':
                        mostrarAutosPorColorYMarca(autos,colores,marcas,clientes,tamCl,tamM,tamA,tamC);
                    break;
                case '5':
                        mostrarMarcasMasElegidas(autos,colores,marcas,clientes,tamCl,tamM,tamA,tamC);
                    break;
                case '6':
                        mostrarTrabajosPorAuto(trabajos,colores,autos,marcas,servicios,clientes,tamCl,tamA,tamS,tamM,tamT,tamC);
                    break;
                case '7':
                        mostrarImporteTrabajoDeAuto(trabajos,colores,autos,marcas,servicios,clientes,tamCl,tamA,tamS,tamM,tamT,tamC);
                    break;
                case '8':
                        mostrarTrabajosPorServicio(trabajos,colores,autos,marcas,servicios,clientes,tamCl,tamA,tamS,tamM,tamT,tamC);
                    break;
                case '9':
                        mostrarTrabajosPorFecha(trabajos,colores,autos,marcas,servicios,clientes,tamCl,tamA,tamS,tamM,tamT,tamC);
                    break;
                case 'S':
                    respuesta = 'S';
                    break;
                default:
                    system("cls");
                    printf("Opcion de menu incorrecta \n\n");
                break;
            }

        system("pause");
        system("cls");
    }while (respuesta != 'S');

        todoOk = 1;
    }

    return todoOk;
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
    printf("J-Listar Clientes \n");
    printf("L-Mostrar Menu Informes \n");
    printf("S-Salir \n\n");

    scanf("%c",&respuesta);
    fflush(stdin);

    respuesta = toupper(respuesta);

    return respuesta;

}
