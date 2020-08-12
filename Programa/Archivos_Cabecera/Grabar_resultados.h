#ifndef Grabar_resultados_INCLUDED
#define Grabar_resultados_INCLUDED

#include <stdio.h>
#include <windows.h>
#include <sys/stat.h>
#include <time.h>
#include <math.h>

float ordenar2(float datos[], unsigned int longitud);
float media2( float datos[], unsigned int longitud);
float mediana2( float datos[], unsigned int longitud);
float moda2(float datos[], unsigned int longitud);
float desviacion2( float varianza1 );
float cuartiles2( int k, float datos[], unsigned int longitud);
float percentiles2( int k, float datos[], unsigned int longitud);

int count1 = 0;
int count2 = 0;

float Guardar_estadistica(char Archivo_ubicacion, float datos[], unsigned int longitud, float varianza1){ 

    float Media1 = media2( datos, longitud );
    float Mediana1 = mediana2( datos, longitud );
    float Moda1 = moda2(datos, longitud);
    float desviacion1 = desviacion2( varianza1 );
    float Q1 = cuartiles2( 1, datos, longitud);
    float Q2 = cuartiles2( 2, datos, longitud);
    float Q3 = cuartiles2( 3, datos, longitud);
    float P30 = percentiles2( 30, datos, longitud);
    float P90 = percentiles2( 90, datos, longitud);

    mkdir("Resultados");    //Crea carpeta

    //definir nombre de archivo con fecha y hora
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char Nombre_Archivo[128];
    strftime(Nombre_Archivo,128,"Resultados/Estadistica_%d-%m-%y_%H-%M-%S.txt",tlocal);

    //crea el archivo de texto y lo abre en modo escritura 
    FILE *fptr = fopen(Nombre_Archivo, "w"); 
    if (fptr == NULL) 
    { 
        printf("No se pudo abrir el archivo"); 
        return 0; 
    }
    fprintf(fptr, "\nEl archivo contiene %u elementos\n\n", longitud);
    fprintf(fptr, "Los cuales son:\n");
    for (count1 = 0; count1 < longitud; count1++){
        fprintf(fptr, "%.2f ", datos[count1]);
    }
    fprintf(fptr, "\n\nMedia = %.2f\n", Media1);
    fprintf( fptr, "Mediana = %.2f\n", Mediana1 );
    fprintf(fptr, "Moda = %.2f\n", Moda1);
    fprintf(fptr, "Varianza = %.2f\n", varianza1);
    fprintf(fptr, "Desviación estándar = %.2f\n", desviacion1);
    fprintf( fptr, "Q1 = %.2f\nQ2 = %.2f\nQ3 = %.2f\n", Q1, Q2, Q3);
    fprintf( fptr, "P30 = %.2f\nP90 = %.2f\n\n", P30, P90);

    fclose(fptr); 
    printf("\nLos resultados fueron guardados en %s\n", Nombre_Archivo);
    Sleep(2000);
    return 0; 
}

float media2( float datos[], unsigned int longitud){
    
    float sumatoria = 0;

    for (count1 = 0; count1 < longitud; count1++){
        sumatoria += datos[count1];    //suma todos los elementos del arreglo
    }
    return sumatoria / longitud;    //divide la suma entre el total de elementos obteniendo asi la media
}//Fin funcion

float mediana2( float datos[], unsigned int longitud){

    if (longitud % 2 == 0){ //si es par...
        return( (datos[(longitud/2) - 1] + datos[longitud/2]) / 2.00 ); //...suma los dos valores centrales y obtiene su promedio
    }
    else{   //si es impar...
        return datos[longitud/2];   //...Devuelve el valor central
    }
}//fin funcion

float desviacion2( float varianza ){
    return sqrt(varianza);
}//fin funcion

float cuartiles2( int k, float datos[], unsigned int longitud){

    float Q = 0;

    //determina que formula utiizar
    if( longitud%2 == 0){   //si el total de datos es par...
        Q = (k * longitud) / 4.00;  //..utiliza esta formula para obtener posicion del cuartil solicitado
    }
    else    //sino...
        Q = ( k * (longitud+1) ) / 4.00;  //...utiliza esta formula para obtener posicion del cuartil solicitado

    //devuelve el resultado
    if ( (k * longitud) % 4 == 0 ){
        if(longitud % 2 == 0){
            return ( datos[(int)Q] + datos[(int)Q - 1]) / 2;
        }
        else{
            return datos[(int)Q - 1];
        }
    }
    else{   //interpolamos  Q = d2(d3) + d1
        float d1 = datos[(int)Q - 1];    //Valor que se encuentra en la posicion de la parte entera
        float d2 = Q - (int)Q;  //Parte decimal
        float d3 = datos[(int)Q] - datos[(int)Q - 1];   // (Q + 1) - Q
        return d2*(d3) + d1;
    }
}//fin funcion

float percentiles2( int k, float datos[], unsigned int longitud){

    float P = 0;

    if(longitud%2 == 0){   //si el total de datos es par...
        P = (k * longitud) / 100.00;  //..utiliza esta formula para obtener posicion del percentil solicitado
    }
    else    //sino...
        P = ( k * (longitud+1) ) / 100.00;  //...utiliza esta formula para obtener posicion del percentil solicitado
    
    if ( (k * longitud) % 100 == 0 ){
        return datos[(int)P - 1];
    }
    else{
        float d1 = datos[(int)P - 1];
        float d2 = P - (int)P;
        float d3 = datos[(int)P] - datos[(int)P - 1]; 
        return d2*(d3) + d1;
    }
}//fin funcion

float moda2(float datos[], unsigned int longitud){

    float count=0; 
    float max_conteo=0; 
    float max_variable=0;

    for(count1=0;count1<longitud;++count1){

        count1=0;
        while(count1<longitud) {
            count2=0;
            count=0;
            while(count2<longitud) {
                if(datos[count1]==datos[count2]) {
                    count++;
                }
                    if (count>max_conteo) {
                        max_conteo=count;
                        max_variable=datos[count1];
                    }
                count2++;
            }
            count1++;
        }
    }
    return max_variable;
}//fin funcion

//-----------------------------------------------------------------------------------------------------------------------

float Guardar_probabilidad(int Espacio[], int longitud, int A, int B, int C, float probA, float probB, float probC, 
                           float interAB, float interAC, float interBC, 
                           float condAB, float condAC, float condBC, float bayesBA, 
                           float bayesCA, float bayesCB){ 

    mkdir("Resultados");

    //definir nombre de archivo con fecha y hora
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char Nombre_Archivo[128];
    strftime(Nombre_Archivo,128,"Resultados/Probabilidad_%d-%m-%y_%H-%M-%S.txt",tlocal);

    //crea el archivo de texto y lo abre en modo escritura 
    FILE *fptr = fopen(Nombre_Archivo, "w"); 
    if (fptr == NULL) 
    { 
        printf("No se pudo abrir el archivo"); 
        return 0; 
    } 
    
    int i = 0;

    fprintf(fptr, "\n\tU = {");
    for(i = 0; i < longitud; i++){
        fprintf(fptr, "%d,", Espacio[i]);
    }
    fprintf(fptr, "}\n\n");

    fprintf(fptr, "A = %d\n", A);
    fprintf(fptr, "B = %d\n", B);
    fprintf(fptr, "C = %d\n\n", C);

    fprintf(fptr, "Probabilidad de cada evento.\n");
    fprintf(fptr," P(A): %.2f\n", probA);
    fprintf(fptr," P(B): %.2f\n", probB);
    fprintf(fptr," P(C): %.2f\n\n", probC);

    fprintf(fptr,"Intersección de los eventos.\n");
    fprintf(fptr," AnB: %.2f\n", interAB);
    fprintf(fptr," AnC: %.2f\n", interAC);
    fprintf(fptr," BnC: %.2f\n\n", interBC);

    fprintf(fptr,"Probabilidad de los eventos utilizando la probabilidad condicional.\n");
    fprintf(fptr," P(A|B): %.2f\n", condAB);
    fprintf(fptr," P(A|C): %.2f\n", condAC);
    fprintf(fptr," P(B|C): %.2f\n\n", condBC);

    fprintf(fptr,"Probabilidad de los eventos utilizando el teorema de Bayes.\n");
    fprintf(fptr," P(B|A): %.2f\n", bayesBA);
    fprintf(fptr," P(C|A): %.2f\n", bayesCA);
    fprintf(fptr," P(C|B): %.2f\n\n", bayesCB);

    fclose(fptr); 

    printf("\nLos resultados fueron guardados en %s\n", Nombre_Archivo);
    Sleep(2000);
    return 0; 
}

#endif