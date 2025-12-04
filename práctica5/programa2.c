#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 

typedef struct {
    int elementos[MAX_SIZE];
    int frente;   
    int final;
    int contador;
} Cola;

void inicializarCola(Cola *c) {
    c->frente = 0;
    c->final = -1;
    c->contador = 0;
    printf("\nCola inicializada vacía\n");
}

int estaLlena(Cola *c) {
    return c->contador == MAX_SIZE; 
}

int estaVacia(Cola *c) {
    return c->contador == 0; 
}

void encolar(Cola *c, int valor) {
    if (estaLlena(c)) {
        printf("Error, cola llena\n", valor);
        return;
    }
    
    c->final = (c->final + 1) % MAX_SIZE;
    
    c->elementos[c->final] = valor;
    
    c->contador++;
    
    printf("Valor insertado al final\n", valor);
}

int desencolar(Cola *c) {
    if (estaVacia(c)) {
        printf("Error, cola vacía\n");
        return 0;
    }
    
    int valorExtraido = c->elementos[c->frente];
    
    c->frente = (c->frente + 1) % MAX_SIZE;
    
    c->contador--;
    
    return valorExtraido;
}

void mostrarEstadoCola(Cola *c) {
    if (estaVacia(c)) {
        printf("Estado actual: vacía\n");
        return;
    }

    printf("Estado actual [ ", c->contador);
    
    int i = c->frente;
    for (int k = 0; k < c->contador; k++) {
        printf("%d", c->elementos[i]);
        if (k < c->contador - 1) {
            printf(", ");
        }
        i = (i + 1) % MAX_SIZE; 
    }
    
    printf(" ]\n");
    // 
}

int main() {
    Cola miCola;
    int opcion, valorExtraido;
    
    inicializarCola(&miCola); 

    do {
        printf("1. Encolar\n");
        printf("2. Desencolar\n");
        printf("3. Ver el estado cola\n");
        printf("4. Salir\n");
        printf("Seleccione una opción");

        if (scanf("%d", &opcion) != 1) {
            printf("\nOpción no válida\n");
            while (getchar() != '\n');
            opcion = 0;
            continue;
        }

        switch (opcion) {
            case 1:
                int valorAInsertar;
                printf("Introduce el valor ");
                if (scanf("%d", &valorAInsertar) != 1) {
                    printf("Error\n");
                    while (getchar() != '\n');
                    break;
                }
                
                encolar(&miCola, valorAInsertar);
                mostrarEstadoCola(&miCola);
                break;

            case 2:
                valorExtraido = desencolar(&miCola);
                
                if (valorExtraido != 0) { 
                    printf("Valor extrido\n", valorExtraido);
                    mostrarEstadoCola(&miCola);
                }
                break;

            case 3:
                mostrarEstadoCola(&miCola);
                break;

            case 4:
                printf("\nFin\n");
                break;

            default:
                printf("\nError\n");
                break;
        }

    } while (opcion != 4);

    return 0;
}
