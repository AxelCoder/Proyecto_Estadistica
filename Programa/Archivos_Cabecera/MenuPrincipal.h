#ifndef MenuPrincipal_INCLUDED
#define MenuPrincipal_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Estadistica.h"
#include "probabilidad.h"
#include "Conteo.h"
#include "color.h"

int MenuPrincipal(){    //Inicio menu

    system("cls");  //limpia contenido de la consola
    system("mode con: cols=85 lines=33");   //modifica el tamaño de la consola
    system("Title Menu Principal"); //asigna un titulo a la ventana
    Color(NEGRO, BLANCO);   //cambia el color de la consola
    
    int opcion = 0;

//Menu de selección
    printf("\n------------------------------------------\n");
    printf("[1]Estad%cstica\n", 161);
    printf("[2]Probabilidad\n");
    printf("[3]Conteo\n\n");
    printf("[4]Salir\n");
    printf("------------------------------------------\n");
    printf("Ingresa una opci%cn: ", 162);
    Color(NEGRO, LVERDE);   scanf("%d", &opcion);
    Color(NEGRO, BLANCO);   printf("------------------------------------------\n\n");

    switch (opcion) {   //inicio switch

        case 1:
            MenuEstadistica();
        break;

        case 2:
            probabilidad();
        break;

        case 3:
            MenuConteo();
        break;

        case 4:
            Salida();
        break;

        default:
            Color(NEGRO, ROJO);   printf("\tOPCI%cN INVALIDA!! \n   Por favor intenta de nuevo", 224);
            Sleep(2000);
            MenuPrincipal();
    }//fin switch
}//fin menu

int Salida(){

    system("cls");  //limpia contenido de la pantalla
    printf("\t\t\t%c Gracias por utilizar este programa %c\n", 186, 186);
    printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 
          200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 
          205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    printf("\n\n\n\n\n\n\n");
    printf("                                   ####                     \n");
    printf("                                  ####       ##             \n");
    printf("                           #      ###       ###             \n");
    printf("                         ###      ###      ###              \n");
    printf("                         ###      ###     ####              \n");
    printf("                         ###      ##      ###         ##    \n");
    printf("                         ###              #           ##    \n");
    printf("                          ###                        ###    \n");
    printf("                           ###                      ###     \n");
    printf("                             ###                  ####      \n");
    printf("                               ###            ######        \n");
    printf("                                   ##############		 \n");
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t   Desarrolladores:\n");
    printf("\t\t\t\t\t\t   Alem%cn Delgado Axel Issai\n", 160);
    printf("\t\t\t\t\t\t   Mart%cnez Dorantes Orlando Samuel\n", 161);
    printf("Versi%cn Final\t\t\t\t\t   Cervantes Cabrera Jos%c Rodolfo", 162, 130);
    Sleep(2000);
    exit(0);

}

#endif