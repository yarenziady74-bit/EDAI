#include <stdio.h> // Librería principal de entrada y salida

int main ()(void) { // inicio de la función principal que al llamarla no acepta otros valores
    int a[5] = {2,4,6,8,10}; // El tamaño del arreglo es 5 y sus valores están entre llaves 
    int *p = a; // El puntero guardará la dirección de memoria del arreglo 
    
    printf (" 1 ) a [ 1 ] = % d\n " , a [1] ); // imprime el segundo valor (4)
    printf ( " 2) *(a+3) = %d\n" , *(a+3)); // da la orden de imprimir el valor 3 del arreglo (8)
    printf ( " 3)  *p++= %d\n" , *p++); // imprime todos los valores del arreglo
    printf ( " 4)  *++p= %d\n" , *++p);// imprime desde 4 a 10 
    printf ( " 5)  p[1]= %d\n" , p[1]);// imprime 4 
    printf ( " 6) * (p+2)= %d\n" * (p+=2)); // imprime 6 
    printf ( " 7) p-a=%d\n", p-a); // imprime 2
    
    return 0; // finaliza la función 

}
