#ifndef Color_INCLUDED
#define Color_INCLUDED

#include <windows.h>
//Definicion de los colores
#define NEGRO 0
#define OSCURO 128
#define LVERDE 10
#define BLANCO 7
#define ROJO 12
#define AMARILLO 14
#define MORADO 13
#define BLANCO_ROJO 252

void Color(int Background, int Text){ // Función para cambiar el color del fondo y/o pantalla

 HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.

 // Para cambiar el color, se utilizan números desde el 0 hasta el 255.
 // Pero, para convertir los colores a un valor adecuado, se realiza el siguiente cálculo.
 int    New_Color= Text + (Background * 16);

 SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.
}

#endif