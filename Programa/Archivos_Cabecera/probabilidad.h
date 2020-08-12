#ifndef probabilidad_INCLUDED
#define probabilidad_INCLUDED

#include "color.h"
#include "Grabar_resultados.h"

float probabilidad(){

    system("cls"); 
    system("mode con: cols=85 lines=33");
    system("Title Probabilidad");

    //definición de las variables
    char opcion;
    int longitud = 0, i = 0, A = 0, B = 0, C = 0;
    float probA, probB, probC;
    float interAB, interAC, interBC;
    float condAB, condAC, condBC;
    float bayesBA, bayesCA, bayesCB;

    printf("Ingresa el tama%co del espacio muestral (-1 para salir): ", 164);
    scanf("%d", &longitud);
    if(longitud == -1)
        MenuPrincipal(); 

    int Espacio[longitud];

    for(i = 0; i < longitud; i++){
        Color(NEGRO, BLANCO);   printf("Ingresa el dato %d: ", (i+1));
        Color(NEGRO, LVERDE);   scanf("%d", &Espacio[i]);
    }

    Color(NEGRO, BLANCO);   printf("\nn(U) = ");
    Color(NEGRO, AMARILLO); printf("%d", longitud);

    //Imprime el espacio muestral
    Color(NEGRO, BLANCO);   printf("\n\n\tU = {");
    for(i = 0; i < longitud; i++){
        Color(NEGRO, AMARILLO);   printf("%d,", Espacio[i]);
    }
    Color(NEGRO, BLANCO);   printf("}\n\n");

    //Obtiene el valor de A, B y C
    int repA = 0, repB = 0, repC = 0;
    A = Espacio[0];

    for ( i = 0; i < longitud; i++ ){
        if(Espacio[i] != A){
            if(Espacio[i] != C){
                if(B == 0){
                    B = Espacio[i];
                }
                else{
                    if(Espacio[i] != B && C == 0){
                       C = Espacio[i]; 
                    }
                }
            }
        }
    }

    //Veces que se repiten A, B y C
    for ( i = 0; i < longitud; i++ ){
        if(Espacio[i] == A)
            repA++;
        if(Espacio[i] == B)
            repB++;
        if(Espacio[i] == C)
            repC++;
    }
    Color(NEGRO, BLANCO);
    printf("\nEventos\n");
    printf(" A = %d\tAparece %d veces\n", A, repA);
    printf(" B = %d\tAparece %d veces\n", B, repB);
    printf(" C = %d\tAparece %d veces\n", C, repC);

    //Operaciones de las probabilidades
    probA = trunc(( (float)repA / longitud ) * 1000.0) / 1000.0;
    probB = trunc(( (float)repB / longitud) * 1000.0) / 1000.0;
    probC = trunc(( (float)repC / longitud) * 1000.0) / 1000.0;
    interAB = trunc((probA * probB) * 1000.0) / 1000.0;
    interAC = trunc((probA * probC) * 1000.0) / 1000.0;
    interBC = trunc((probB * probC) * 1000.0) / 1000.0;
    condAB = trunc((interAB / probB) * 1000.0) / 1000.0;
    condAC = trunc((interAC / probC) * 1000.0) / 1000.0;
    condBC = trunc((interBC / probC) * 1000.0) / 1000.0;
    bayesBA = trunc(((condAB * probB) / probA) * 1000.0) / 1000.0;
    bayesCA = trunc(((condAC * probC) / probA) * 1000.0) / 1000.0;
    bayesCB = trunc(((condBC * probC) / probB) * 1000.0) / 1000.0;

    Color(NEGRO, BLANCO);   //regresa los colores de la ventana a los valores por defecto

    //Probabilidades individuales
    printf("\nProbabilidad de cada evento.\n");
    printf(" P(A): %.2f\n", probA);
    printf(" P(B): %.2f\n", probB);
    printf(" P(C): %.2f\n\n", probC);

    //Intersecciones
    printf("Intersecci%cn de los eventos.\n", 162);
    printf(" AnB: %.2f\n", interAB);
    printf(" AnC: %.2f\n", interAC);
    printf(" BnC: %.2f\n\n", interBC);

    //Probabilidad Condicional
    printf("Probabilidad de los eventos utilizando la probabilidad condicional.\n");
    printf(" P(A|B): %.2f\n", condAB);
    printf(" P(A|C): %.2f\n", condAC);
    printf(" P(B|C): %.2f\n\n", condBC);

    //Teorema de Bayes
    printf("Probabilidad de los eventos utilizando el teorema de Bayes.\n");
    printf(" P(B|A): %.2f\n", bayesBA);
    printf(" P(C|A): %.2f\n", bayesCA);
    printf(" P(C|B): %.2f\n\n", bayesCB);

    //Guardar datos en txt
    printf("%cDesea guardar los resultados en un archivo de texto? [S/N]: ");
    scanf("%s", &opcion);

    if(opcion == 'S' || opcion == 's'){
        Guardar_probabilidad(Espacio, longitud, A, B, C, probA, probB, probC, interAB, interAC, interBC, condAB, condAC, condBC, bayesBA, bayesCA, bayesCB);
        probabilidad();
    }
    else
    probabilidad();
}

#endif