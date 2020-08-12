#ifndef Conteo_INCLUDED
#define Conteo_INCLUDED

#include "MenuPrincipal.h"
#include "color.h"

//Prototipos de funcion
unsigned long long int factorial ( int num );
unsigned long long int combinaciones ();
unsigned long long int permutaciones ();

//Variables globales 
unsigned int n, r, x;
unsigned long long int n_fact, r_fact, x_fact;
unsigned long long int combinacionesRes, permutacionesRes;

int MenuConteo(){

    system("cls");
    system("mode con: cols=85 lines=33");
    system("Title Conteo"); 
    Color(NEGRO, BLANCO);

    int opcion;

    printf("\n------------------------------------------\n");
    printf("CONTEO\n");
    printf("%20s %15s", "1) Combinaciones", "3) Regresar\n");
    printf("%20s %12s", "2) Permutaciones", "4) Salir\n");
    printf("------------------------------------------\n");
    printf("Ingresa una opci%cn (1-4): ", 162);
    Color(NEGRO, LVERDE);   scanf("%d", &opcion);
    Color(NEGRO, BLANCO);   printf("------------------------------------------\n\n");

    switch(opcion){

        case 1:
            combinacionesRes = combinaciones();
            printf("\n\t\t  %u%c \t     %u%c", n, 33, n, 33);
            printf("\n\t%uC%u = ---------- = ------- = %llu", n, r, combinacionesRes);
            printf("\n\t      %u%c(%u - %u)%c    %u%c%u%c\n", r, 33, n, r, 33, r, 33, (n-r), 33);
            Sleep(3000);
            MenuConteo();
        break;

        case 2:
            permutacionesRes = permutaciones ();
            printf("\n\t\t  %u%c \t     %u%c", n, 33, n, 33);
            printf("\n\t%uP%u = ---------- = ------- = %llu", n, r, permutacionesRes);
            printf("\n\t      (%u - %u)%c \t     %u%c\n", n, r, 33, (n-r), 33);
            Sleep(3000);
            MenuConteo();
        break;

        case 3:
            MenuPrincipal();
        break;

        case 4:
            Salida();
        break;

        default:
            Color(NEGRO, ROJO);   printf("\tOPCI%cN INVALIDA!! \n   Por favor intenta de nuevo", 224);
            Sleep(2000);
            MenuConteo();
            break;
    }

}

//Funcion para factoriales necesarios
unsigned long long int factorial(int num){

    unsigned long long int fact = 1, i;

    for ( i = 1; i <= num; i++ ){
	    fact = fact * i;   
    }
    return fact;
}

//Funcion para combinaciones    C = n! / r!(n - r)!
unsigned long long int combinaciones (){

    printf("Combinaciones\n");
    printf("   Ingrese los valores correspondientes\n");
    printf("\tn = ");
    scanf("%u", &n);
    printf("\tr = ");
    scanf("%u", &r);

    if(n > r){  //Valida que n > r...
        //Llama a la funcion factorial para obtener el factorial de cada valor
        n_fact = factorial( n );
        r_fact = factorial( r );
        x_fact = factorial( n - r );

        //retorna el total de combinaciones
        Color(NEGRO, LVERDE);   return n_fact / (r_fact * x_fact);
    }
    else{   //... en caso contrario imprime un mensaje de error
        Color(NEGRO, ROJO);   printf("Error! Asegurate que n > r\n");
    }
    Sleep(2000);
    MenuConteo();
}

//Funcion para permutaciones    P = n! / (n - r)!
unsigned long long int permutaciones (){

    printf("Permutaciones\n");
    printf("   Ingrese los valores correspondientes\n");
    printf("\tn = ");
    scanf("%u", &n);
    printf("\tr = ");
    scanf("%u", &r);
    if(n > r){
        n_fact = factorial( n );
        x_fact = factorial( n - r );

        Color(NEGRO, LVERDE);   return n_fact /  x_fact;
    }
    else{
        Color(NEGRO, ROJO);   printf("Error! Asegurate que n > r\n");
    }
    Sleep(2000);
    MenuConteo();
}

#endif