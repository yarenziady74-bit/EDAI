#include <stdio.h>
#include <stdlib.h>

int main(){

float *arreglo;
int max, opcion;
float total;

printf("Cuantos estudiantes desea registar?\n");
scanf("%i", &max);
arreglo = (float*) malloc (max * sizeof(float));

if (arreglo == NULL){
    printf("No se pudo asignar la memoria");
    return 1;
}

for (int i=0; i<max; i++){
    printf("Cual es la calificacion del estudiante [%i]\n", i+1);
    scanf ("%f", &arreglo[i]);
    total = total + arreglo[i];
}

float promedio = total/max;

for (int i=0; i<max; i++){
    printf("calificaciones: /n");
    printf("calificacion del estudiante [%i]: %.2f \n", i+1, arreglo[i]);
}
printf("Promedio inicial: %.2f\n", promedio);

printf("�Desea agregar mas estudiantes? si: 1 no:2\n");
scanf("%i", &opcion);

if (opcion == 1){
    int nuevo, nuevomax;
    printf("�Cuantos estudiantes desea agregar?\n");
    scanf ("%i", &nuevo);
    nuevomax = nuevo+max;
    float *arreglotemporal = (float *) realloc (arreglo, nuevomax * sizeof(float));
    if (arreglotemporal == NULL){
        printf("No se pudo asignara memoeria");
        return 1;
    }

    arreglo = arreglotemporal;

    for(int i=max; i<nuevomax; i++){
        printf("Cual es la calificacion del estudiante [%i]\n", i+1);
        scanf ("%f", &arreglo[i]);
        total = total + arreglo[i];
    }
    promedio = total/nuevomax;

    for (int i=0; i<nuevomax; i++){
        printf("Nuevas calificaciones: /n");
        printf("calificacion del estudiante [%i]: %.2f \n", i+1, arreglo[i]);
    }
    printf("Promedio genral : %.2f\n", promedio);

    free (arreglo);

} else {
printf("Usted salio del programa");
free (arreglo);
return 0;
}
return 0;
}
