#ifndef Estadistica_INCLUDED
#define Estadistica_INCLUDED

#include <string.h>
#include "color.h"
#include "Grabar_resultados.h"

//prototipos de funcion
float ordenar(float datos[], unsigned int longitud);
float media( float datos[], unsigned int longitud);
float mediana( float datos[], unsigned int longitud);
float moda(float datos[], unsigned int longitud);
float varianza(float datos[], unsigned int longitud);
float desviacion( float varianza );
float cuartiles( int k, float datos[], unsigned int longitud);
float percentiles( int k, float datos[], unsigned int longitud);

//Variables globales
float temp = 0;   //variable para almacenamiento temporal
int i = 0;  //contador
int j = 0;  //contador

int MenuEstadistica(){

    system("cls");
    system("mode con: cols=85 lines=33");
    system("Title Estadistica");
    Color(NEGRO, BLANCO); 

//------------------------------------------------------------------------------------
char Archivo_ubicacion[100];
i = 0;

//Lee ubicacion del archivo arrastrandolo a la ventana   
    printf("NOTA:\n");
    printf("+ Tanto el archivo como la ubicacion de este no deben contener espacios en el nombre\n");
    printf("+ El archivo debe contener al menos 30 datos\n");
    printf("+ Los datos contenidos en dicho archivo deben estar separados por comas \n"
           "  Por ejemplo: 1,2,3,4,5,...,n ");
    Sleep(3000);
    system("cls");
    printf("Arrastra el archivo aqui (s para salir): ");
    Color(NEGRO, LVERDE);   scanf("%s", Archivo_ubicacion); //lee una línea entera, con espacios incluidos, hasta que pulse intro
    Color(NEGRO, BLANCO);

    if(Archivo_ubicacion[0] == 's' || Archivo_ubicacion[0] == 'S')
        MenuPrincipal();   

//ALMACENAR LOS DATOS DEL TXT EN UN ARRELGO
    FILE *myFile;   //puntero tipo archivo, para comunicacion entre archivo y programa
    myFile = fopen(Archivo_ubicacion, "r"); //abre el archivo en modo lectura

    if (myFile == NULL){    //comprobamos que el archivo se haya abierto; si myFile es igual a NULL el archivo no se abrio
        Color(NEGRO, ROJO);   printf("Error leyendo el archivo\n");
        printf("Asegurate que el archivo cumpla con los requisitos\n");
        Sleep(3000);
        free(myFile);
        MenuEstadistica();
    }

    //Lee el total de datos en el txt
    while(!feof(myFile)){
        fscanf( myFile, "%f,", &temp );
        i+=1;
    }

    if( i < 30){
        printf("Asegurate que el archivo contenga al menos 30 datos");
        Sleep(3000);
        MenuEstadistica();
    }

    //crea el arreglo con el tamaño necesario
    float datos[i];

    if(i > 100)
        system("mode con: cols=85 lines=41");

    //Mueve el cursor al inicio del archivo
    rewind(myFile);

    printf("\nEl archivo contiene %d elementos\n\n", i);

    //Lee los datos del archivo y los almacena en el arreglo
    for (j = 0; j < i; j++){
        fscanf( myFile, "%f,", &datos[j] );
    }

    printf("Los cuales son:\n");
    for (j = 0; j < i; j++){
        Color(NEGRO, MORADO);   printf("%.2f ", datos[j]);
    }
    printf("\n\n");

fclose(myFile); //cierra el archivo
//------------------------------------------------------------------------------------

    unsigned int longitud = i;   //obtiene el tamaño del arreglo

    ordenar(datos, longitud);   //ordena arreglo de menor a mayor

    Color(NEGRO, BLANCO);   printf("En orden ascendente:\n");
    for (i = 0; i < longitud; i++){
        Color(NEGRO, AMARILLO);   printf("%.2f ", datos[i]);
    }
    Color(NEGRO, BLANCO);   printf("\n\n");

    printf("Media = %.2f\n", media( datos, longitud )); //Llama a la funcion mediana e imprime el valor retornado

    printf( "Mediana = %.2f\n", mediana( datos, longitud ) );   //Llama a la funcion mediana e imprime el valor retornado

    printf("Moda = %.2f\n", moda(datos, longitud)); // llama a la funcion moda e imprime el valor retornado
    
    float varianza1 = varianza( datos, longitud );    //Llama a la funcion varianza y almacena el valor retornado en una variable
    printf("Varianza = %.2f\n", varianza1);

    printf( "Desviaci%cn est%cndar = %.2f\n", 162, 160, desviacion( varianza1 ) ); // llama a la funcion desviacion estandar e imprime el valor retornado

    printf( "Q1 = %.2f\n"
            "Q2 = %.2f\n" 
            "Q3 = %.2f\n",
            cuartiles( 1, datos, longitud), cuartiles( 2, datos, longitud), cuartiles( 3, datos, longitud) );

    printf( "P30 = %.2f\n"
            "P90 = %.2f\n\n",
            percentiles( 30, datos, longitud), percentiles( 90, datos, longitud) );

    //Guardar datos en txt
    char opcion;
    printf("%cDesea guardar los resultados en un archivo de texto? [S/N]: ");
    scanf("%s", &opcion);

    if(opcion == 'S' || opcion == 's'){
        Guardar_estadistica(Archivo_ubicacion, datos, longitud, varianza1);
        MenuPrincipal();
    }
    else{
    MenuPrincipal();
    }  
}

//funcion para ordenar arreglo de menor a mayor
float ordenar(float datos[], unsigned int longitud){
    temp = 0;

    for(i = 0; i < (longitud - 1); i++){
        for(j = i + 1; j < longitud; j++){
            if( datos[j] < datos[i] ){
                temp = datos[j];
                datos[j] = datos[i];
                datos[i] = temp;
            }//fin if
        }//fin for anidado
    }//fin for
    return longitud;
}//fin funcion


//Funcion para calcular media
float media( float datos[], unsigned int longitud){
    
    float sumatoria = 0;

    for (i = 0; i < longitud; i++){
        sumatoria += datos[i];    //suma todos los elementos del arreglo
    }
    return sumatoria / longitud;    //divide la suma entre el total de elementos obteniendo asi la media
}//Fin funcion

//funcion calcular mediana
float mediana( float datos[], unsigned int longitud){

    if (longitud % 2 == 0){ //si es par...
        return( (datos[(longitud/2) - 1] + datos[longitud/2]) / 2.00 ); //...suma los dos valores centrales y obtiene su promedio
    }
    else{   //si es impar...
        return datos[longitud/2];   //...Devuelve el valor central
    }
}//fin funcion

//Funcion calcular varianza (Xn-media)^2 / n
float varianza(float datos[], unsigned int longitud){
    
    float media1 = media( datos, longitud );
    float sumatoria = 0;

    for (i = 0; i < longitud; i++){
        sumatoria += pow( (datos[i] - media1), 2);    //Sumatoria (x - media)^2
    } 
    return sumatoria / longitud;    //divide la sumatoria entre el total de elementos obteniendo asi la media    
}//Fin funcion

//funcion calcular desviacion estandar 
float desviacion( float varianza ){
    return sqrt(varianza);
}//fin funcion

//Funcion calcular cuartiles Qk = (k * n) / 4
float cuartiles( int k, float datos[], unsigned int longitud){

    float Q = 0;

    //determina que formula utiizar
    if( longitud%2 == 0){   //si el total de datos es par...
        Q = (k * longitud) / 4.00;  //..utiliza esta formula para obtener posicion del cuartil solicitado
    }
    else    //sino...
        Q = ( k * (longitud+1) ) / 4.00;  //...utiliza esta formula para obtener posicion del cuartil solicitado

    //devuelve el resultado
    if ( (k * longitud) % 4 == 0 ){
        //if(longitud % 2 == 0){
        if(k == 2){
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

//Funcion calcular percentiles Pk = (k * n) / 100
float percentiles( int k, float datos[], unsigned int longitud){

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

//Funcion para calcular moda
float moda(float datos[], unsigned int longitud){

    float count=0; 
    float max_conteo=0; 
    float max_variable=0;

    for(i=0;i<longitud;++i){

        i=0;
        while(i<longitud) {
            j=0;
            count=0;
            while(j<longitud) {
                if(datos[i]==datos[j]) {
                    count++;
                }
                    if (count>max_conteo) {
                        max_conteo=count;
                        max_variable=datos[i];
                    }
                j++;
            }
            i++;
        }
    }
    return max_variable;
}//fin funcion

#endif