#include "auto.h"
#include "marca.h"
#include "color.h"
#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include <ctype.h>


int inicializarAutos(eAuto autos[],int tamA){
    int todoOk = 0;
    if(autos && tamA >0){
        for(int i=0;i<tamA;i++){
            autos[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;

}

int buscarAutoLibre (eAuto autos[],int tamA,int* pIndice){
    int todoOk = 0;
    if(autos && tamA && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamA;i++){
            if(autos[i].isEmpty){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaAuto (eAuto autos[],int tamA,eMarca marcas[],int tamM,eColor colores[],int tamC,int* pId){
    int todoOk = 0;
    int indice;
    eAuto autoNuevo;

    if(autos && marcas && colores && tamA >0 && tamM >0 && tamC >0 && pId){
        buscarAutoLibre(autos,tamA,&indice);
        if(indice != -1){
            //INGRESO DE DATOS
            listarMarcas(marcas,tamM);
            printf("Ingrese el ID de la marca \n");
            scanf("%d",&autoNuevo.idMarca);
            fflush(stdin);

            while(!validarMarca(marcas,tamM,autoNuevo.idMarca)){
                printf("Error en la ID de la marca.Vuelva a ingresar \n");
                scanf("%d",&autoNuevo.idMarca);
                fflush(stdin);
            }

            listarColores(colores,tamC);
            printf("Ingrese el ID del color \n");
            scanf("%d",&autoNuevo.idColor);
            fflush(stdin);

            while(!validarColor(colores,tamC,autoNuevo.idColor)){
                printf("Error en la ID del color.Vuelva a ingresar \n");
                scanf("%d",&autoNuevo.idColor);
                fflush(stdin);
            }

            system("cls");

            printf("Ingrese el tipo de caja, 'm' para manual y 'a' para automatica \n");
            scanf("%c",&autoNuevo.caja);
            fflush(stdin);

            while(autoNuevo.caja != 'm' && autoNuevo.caja != 'a'){
                printf("Error en el tipo de caja ingresada.Vuelva a ingresar \n");
                scanf("%c",&autoNuevo.caja);
                fflush(stdin);
            }

            system("cls");

            printf("Ingrese la patente hasta 7 caracteres ej: ABXXXDD \n");
            gets(autoNuevo.patente);

            while(strlen(autoNuevo.patente) > 7){
                printf("Error en patente.Ingrese la patente hasta 7 caracteres \n");
                gets(autoNuevo.patente);
            }

            system("cls");

            autoNuevo.isEmpty = 0;
            autoNuevo.id = *pId;
            autos[indice] = autoNuevo;
            (*pId)++;
            todoOk = 1;
        }else{
            printf("No hay espacio disponible para el alta \n");
        }
    }else{
        printf("Error en los parametros del alta \n");
    }

    return todoOk = 1;
}

int ordenarAutosPorMarcaYPatente(eAuto autos[],int tamA,eMarca marcas[],eColor colores[],int tamC,int tamM,eCliente clientes[],int tamCl){
    int todoOk = 0;
    char descripcionMarcaActual[20];
    char descripcionMarcaSiguiente[20];
    eAuto autoAux;

    if(autos && marcas && tamA >0 && tamM > 0 && tamC > 0 && colores && clientes && tamCl > 0){
        eAuto autosAux [tamA];
        for(int i=0;i<tamA;i++){
            autosAux[i] = autos[i];
        }

        for(int i=0;i<tamA-1;i++){
            for(int j=i+1;j<tamA;j++){
                if(!autosAux[i].isEmpty){
                    cargarDescripcionMarca(marcas,tamM,autosAux[i].idMarca,descripcionMarcaActual);
                    cargarDescripcionMarca(marcas,tamM,autosAux[j].idMarca,descripcionMarcaSiguiente);
                    if((strcmp(descripcionMarcaActual,descripcionMarcaSiguiente) > 0)  ||
                        ((strcmp(descripcionMarcaActual,descripcionMarcaSiguiente) == 0) && (strcmp(autosAux[i].patente,autosAux[j].patente) > 0))){
                        autoAux = autosAux[i];
                        autosAux[i] = autosAux[j];
                        autosAux[j] = autoAux;
                    }
                }
            }
        }
        listarAutos(autosAux,tamA,marcas,tamM,colores,tamC,clientes,tamCl);
        todoOk = 1;
    }
    return todoOk;
}




int listarAutos (eAuto autos[],int tamA,eMarca marcas[],int tamM,eColor colores[],int tamC,eCliente clientes[],int tamCl){
    int todoOk = 0;
    int hayAutos = 0;

    if(autos && marcas && colores && tamA >0 && tamM >0 && tamC >0 ){
        system("cls");
        printf("\t     ***LISTADO DE AUTOS***\n");
        printf("-----------------------------------------------------------------------\n");
        printf("ID\t   Marca\tColor\t   Patente\tCaja\t\tCliente\n");
        printf("-----------------------------------------------------------------------\n");
        for(int i=0;i<tamA;i++){
            if(!autos[i].isEmpty){
                mostrarAuto(autos[i],marcas,tamM,colores,tamC,clientes,tamCl);
                hayAutos = 1;
            }

        }
        if(!hayAutos){
            printf("\t     No hay autos cargados \n");
        }
        printf("-----------------------------------------------------------------------\n\n");
        todoOk= 1;
        todoOk = 1;
    }
    return todoOk;
}

int hardcodearAutos (eAuto autos[],int tamA,int cantidad,int* pId){
    int todoOk = 0;
    eAuto autosHard [] = {{10000,1001,5003,50000,"AB676DD",'m',0},
                          {10001,1003,5001,50001,"AA000AA",'a',0},
                          {10002,1003,5002,50002,"AA860AA",'m',0},
                          {10003,1001,5004,50003,"AC195AA",'a',0},
                          {10004,1000,5000,50004,"AE070AA",'m',0},};

    if (autos && tamA && pId && cantidad > 0 && cantidad <= tamA){
        for(int i=0;i<cantidad;i++){
            autos[i] = autosHard[i];
            autos[i].id = (*pId);
            (*pId)++;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarAuto (eAuto autos[],int tamA,int id,int* pIndice){
    int todoOk = 0;
    if(autos && tamA >0 && pIndice){
        *pIndice = -1;
        for(int i=0;i<tamA;i++){
            if(autos[i].id == id && !autos[i].isEmpty){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int buscarAutoPorPatente (eAuto autos[],int tamA,char patente[],int* pIndice){
    int todoOk = 0;
    if(autos && tamA >0 && pIndice && patente){
        *pIndice = -1;
        for(int i=0;i<tamA;i++){
            if(!strcmp(patente,autos[i].patente) && !autos[i].isEmpty){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarAuto(eAuto autoI,eMarca marcas[],int tamM,eColor colores[],int tamC,eCliente clientes[],int tamCl){
    int todoOk = 0;
    char descripcionMarca [20];
    char descripcionColor [20];
    char nombreCliente [20];
    char descripcionCaja[20]={"Automatica"};

    if(marcas && colores && clientes && tamCl >0 && tamM >0 && tamC >0){
        cargarDescripcionMarca(marcas,tamM,autoI.idMarca,descripcionMarca);
        cargarDescripcionColor(colores,tamC,autoI.idColor,descripcionColor);
        cargarNombreCliente(clientes,tamCl,autoI.idCliente,nombreCliente);
        if(autoI.caja == 'm'){
            strcpy(descripcionCaja,"Manual");
        }
        printf("%d%10s\t  %10s\t%10s\t%-10s\t%s\n",autoI.id,descripcionMarca,descripcionColor,autoI.patente,descripcionCaja,nombreCliente);
        todoOk = 1;
    }
    return todoOk;
}


int bajaAuto (eAuto autos[],int tamA,eMarca marcas[],int tamM,eColor colores[],int tamC,eCliente clientes[],int tamCl){
    int todoOk = 0;
    int indice;
    int idIngresado;
    char respuestaBorrado='n';

    if(autos && marcas && colores && clientes && tamCl>0 &&  tamA >0 && tamM >0 && tamC >0 ){
        printf("Ingrese la ID a dar de baja: ");
        scanf("%d",&idIngresado);
        fflush(stdin);
        if(buscarAuto(autos,tamA,idIngresado,&indice)){
            if(indice != -1){
                printf("-----------------------------------------------------------------------\n");
                printf("ID\t   Marca\tColor\t   Patente\tCaja\t\tCliente\n");
                printf("-----------------------------------------------------------------------\n");
                mostrarAuto(autos[indice],marcas,tamM,colores,tamC,clientes,tamCl);
                printf("\nConfirma baja? s-SI \n");
                scanf("%c",&respuestaBorrado);
                fflush(stdin);

                if(respuestaBorrado == 's'){
                    autos[indice].isEmpty = 1;
                    todoOk = 1;
                }else{
                    printf("\nBaja cancelada \n");
                }

            }else
                printf("\nNo exite el auto con el id: %d \n",idIngresado);
        }else{
            printf("\nProblema al buscar el auto \n");
        }

    }else{
        printf("\nError en los parametros de la baja \n");
    }

    return todoOk;
}


char menuModificar (){
    char respuesta;

    printf("\n1) Color \n");
    printf("2) Modelo \n");
    printf("S) Salir \n");
    scanf("%c",&respuesta);
    fflush(stdin);

    respuesta = toupper(respuesta);

    return respuesta;
}


int modificarAuto (eAuto autos[],int tamA,eMarca marcas[],int tamM,eColor colores[],int tamC,eCliente clientes[],int tamCl){
    int todoOk = 0;
    int indice;
    char patenteIngresada[8];
    char respuestaModificar='n';

    if(autos && marcas && colores && clientes && tamCl>0 && tamA >0 && tamM >0 && tamC >0 ){
        printf("Ingrese la patente del auto a modificar hasta 7 caracteres ej: ABXXXDD: ");
        gets(patenteIngresada);

        while(strlen(patenteIngresada) > 7){
            printf("Error en patente.Ingrese la patente hasta 7 caracteres \n");
            gets(patenteIngresada);
        }

        if(buscarAutoPorPatente (autos,tamA,patenteIngresada,&indice)){
            if(indice != -1){
                printf("-----------------------------------------------------------------------\n");
                printf("ID\t   Marca\tColor\t   Patente\tCaja\t\tCliente\n");
                printf("-----------------------------------------------------------------------\n");
                mostrarAuto(autos[indice],marcas,tamM,colores,tamC,clientes,tamCl);

                do{
                    switch(menuModificar()){
                        case '1':
                            listarColores(colores,tamC);
                            printf("Ingrese el ID del color \n");
                            scanf("%d",&autos[indice].idColor);
                            fflush(stdin);

                            while(!validarColor(colores,tamC,autos[indice].idColor)){
                                printf("Error en la ID del color.Vuelva a ingresar \n");
                                scanf("%d",&autos[indice].idColor);
                                fflush(stdin);
                            }
                            printf("Color modificado de manera exitosa \n");
                            break;
                        case '2':
                            listarMarcas(marcas,tamM);
                            printf("Ingrese el ID de la marca \n");
                            scanf("%d",&autos[indice].idMarca);
                            fflush(stdin);

                            while(!validarMarca(marcas,tamM,autos[indice].idMarca)){
                                printf("Error en la ID de la marca.Vuelva a ingresar \n");
                                scanf("%d",&autos[indice].idMarca);
                                fflush(stdin);
                            }
                            printf("Marca modificada de manera exitosa \n");
                            break;
                        case 'S':
                            respuestaModificar = 'S';
                        break;
                    }

                }while(respuestaModificar != 'S');
                todoOk = 1;

            }else
                printf("\nNo exite el auto con la patente: %s \n",patenteIngresada);
        }else{
            printf("\nProblema al buscar el auto \n");
        }

    }else{
        printf("\nError en los parametros de la baja \n");
    }

    return todoOk;
}


int cargarDescripcionPatente (eAuto autos[],int tamA,int id,char descripcion[]){
    int todoOk = 0;
    int indice;
    if(autos && tamA >0 && descripcion && buscarAuto (autos,tamA,id,&indice)){
        strcpy(descripcion,autos[indice].patente);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarAutosPorColor(eAuto autos[],eColor colores[],eMarca marcas[],eCliente clientes[],int tamCl,int tamM,int tamA,int tamC){
    int todoOk = 0;
    int idColor;

    if(autos && colores && marcas && clientes && tamCl> 0 && tamA > 0 && tamC > 0 && tamM > 0){
        eAuto autosAux [tamA];
        inicializarAutos(autosAux,tamA);
        listarColores(colores,tamC);
        printf("Ingrese el ID del color \n");
        scanf("%d",&idColor);
        fflush(stdin);

        while(!validarColor(colores,tamC,idColor)){
            printf("Error en la ID del color.Vuelva a ingresar \n");
            scanf("%d",&idColor);
            fflush(stdin);
        }

        for(int i=0;i<tamA;i++){
            if(autos[i].idColor == idColor && !autos[i].isEmpty){
                autosAux[i] = autos[i];
            }
        }

        listarAutos(autosAux,tamA,marcas,tamM,colores,tamC,clientes,tamCl);

       todoOk = 1;
    }
    return todoOk;
}


int mostrarAutosPorMarca (eAuto autos[],eColor colores[],eMarca marcas[],eCliente clientes[],int tamCl,int tamM,int tamA,int tamC){
    int todoOk = 0;
    int idMarca;

    if(autos && colores && marcas && clientes && tamCl > 0&& tamA > 0 && tamC > 0 && tamM > 0){
        eAuto autosAux [tamA];
        inicializarAutos(autosAux,tamA);
        listarMarcas(marcas,tamM);
        printf("Ingrese el ID de la marca \n");
        scanf("%d",&idMarca);
        fflush(stdin);

        while(!validarMarca(marcas,tamM,idMarca)){
            printf("Error en la ID de la marca.Vuelva a ingresar \n");
            scanf("%d",&idMarca);
            fflush(stdin);
        }

        for(int i=0;i<tamA;i++){
            if(autos[i].idMarca == idMarca && !autos[i].isEmpty){
                autosAux[i] = autos[i];
            }
        }

        listarAutos(autosAux,tamA,marcas,tamM,colores,tamC,clientes,tamCl);

       todoOk = 1;
    }
    return todoOk;
}

int mostrarAutoViejo (eAuto autos[],eColor colores[],eMarca marcas[],eCliente clientes[],int tamCl,int tamM,int tamA,int tamC){
    int todoOk = 0;
    eAuto autoViejo;
    int esPrimero = 1;

    if(autos && colores && marcas && clientes && tamCl> 0 && tamA > 0 && tamC > 0 && tamM > 0){

        autoViejo = autos[0];
        for(int i=1;i<tamA;i++){
            if(!autos[i].isEmpty && (strcmp(autos[i].patente,autoViejo.patente) >0 || esPrimero)){
                autoViejo = autos[i];
                esPrimero = 0;
            }
        }

        printf("El auto mas viejo es: (es 1 solo auto ya que las patentes son unicas ) \n");
        printf("-----------------------------------------------------------------------\n");
        printf("ID\t   Marca\tColor\t   Patente\tCaja\t\tCliente\n");
        printf("-----------------------------------------------------------------------\n");
        mostrarAuto(autoViejo,marcas,tamM,colores,tamC,clientes,tamCl);
        printf("\n\n");

       todoOk = 1;
    }
    return todoOk;
}

int mostrarAutosPorMarcas (eAuto autos[],eColor colores[],eMarca marcas[],eCliente clientes[],int tamCl,int tamM,int tamA,int tamC){
    int todoOk = 0;
    char descripcionMarca[20];
    int hayAutos;

    if(autos && colores && marcas && clientes && tamCl>0 &&  tamA > 0 && tamC > 0 && tamM > 0){
        for(int i=0;i<tamM;i++){
            hayAutos = 0;
            printf("     ***LISTADO DE AUTOS DE LA MARCA %s ***\n",marcas[i].descripcion);
            printf("-----------------------------------------------------------------------\n");
            printf("ID\t   Marca\tColor\t   Patente\tCaja\t\tCliente\n");
            printf("-----------------------------------------------------------------------\n");
            for(int j=0;j<tamA;j++){
                if(marcas[i].id == autos[j].idMarca){
                   mostrarAuto(autos[j],marcas,tamM,colores,tamC,clientes,tamCl);
                   hayAutos=1;
                }
            }
            if(!hayAutos)
                printf("No hay autos de la marca %s \n",marcas[i].descripcion);
            printf("\n\n");
        }


       todoOk = 1;
    }
    return todoOk;
}


int mostrarAutosPorColorYMarca (eAuto autos[],eColor colores[],eMarca marcas[],eCliente clientes[],int tamCl,int tamM,int tamA,int tamC){
    int todoOk = 0;
    char descripcionMarca[20];
    char descripcionColor[20];
    int idMarca;
    int idColor;
    int contador = 0;

    if(autos && colores && marcas && clientes && tamCl>0 && tamA > 0 && tamC > 0 && tamM > 0){

        listarColores(colores,tamC);
        printf("Ingrese el ID del color \n");
        scanf("%d",&idColor);
        fflush(stdin);

        while(!validarColor(colores,tamC,idColor)){
            printf("Error en la ID del color.Vuelva a ingresar \n");
            scanf("%d",&idColor);
            fflush(stdin);
        }

        listarMarcas(marcas,tamM);
        printf("Ingrese el ID de la marca \n");
        scanf("%d",&idMarca);
        fflush(stdin);

        while(!validarMarca(marcas,tamM,idMarca)){
            printf("Error en la ID de la marca.Vuelva a ingresar \n");
            scanf("%d",&idMarca);
            fflush(stdin);
        }

        for(int i=0;i<tamA;i++){
            if(autos[i].idColor == idColor && autos[i].idMarca == idMarca && !autos[i].isEmpty){
                contador++;
            }
        }
        cargarDescripcionMarca(marcas,tamM,idMarca,descripcionMarca);
        cargarDescripcionColor(colores,tamC,idColor,descripcionColor);
        printf("Hay %d autos de la marca %s y color %s \n",contador,descripcionMarca,descripcionColor);

       todoOk = 1;
    }
    return todoOk;
}


int mostrarMarcasMasElegidas (eAuto autos[],eColor colores[],eMarca marcas[],eCliente clientes[],int tamCl,int tamM,int tamA,int tamC){
    int todoOk = 0;
    int contadoresMarcas[tamM];
    int descripcionMarcas[tamM][20];
    int indice = 0;
    int cantidadMarcaMayor;

    if(autos && colores && marcas && tamA > 0 && tamC > 0 && tamM > 0){
        for(int i=1;i<tamM;i++){
            contadoresMarcas[i]=0;
        }
        for(int i=0;i<tamA;i++){
            if(buscarMarca(marcas,tamM,autos[i].idMarca,&indice) && !autos[i].isEmpty){
                cargarDescripcionMarca(marcas,tamM,autos[i].idMarca,descripcionMarcas[indice]);
                contadoresMarcas[indice]++;
            }
        }
        cantidadMarcaMayor = contadoresMarcas[0];
        for(int i=1;i<tamM;i++){
            if(contadoresMarcas[i] > cantidadMarcaMayor){
                cantidadMarcaMayor = contadoresMarcas[i];
            }
        }

        printf("Las marcas de autos mas elegidas son: \n");
        for(int i=0;i<tamM;i++){
            if(contadoresMarcas[i] == cantidadMarcaMayor){
                printf("-%s \n",descripcionMarcas[i]);
            }
        }
        printf("\n\n");

       todoOk = 1;
    }
    return todoOk;
}


int validarAuto (eAuto autos[],int tamA,int id){
    int todoOk = 0;
    int indice;
    if(autos && tamA > 0){
        buscarAuto(autos,tamA,id,&indice);
        if(indice != -1)
            todoOk = 1;
    }
    return todoOk;
}





