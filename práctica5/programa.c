#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int tope;
} Pila;

void inicializarPila(Pila *p) {
    p->tope = -1;
    printf("\nPila inicializada vacía\n");
}

int estaLlena(Pila *p) {
    return p->tope == MAX_SIZE - 1;
}

int estaVacia(Pila *p) {
    return p->tope == -1;
}

void push(Pila *p, int elemento) {
    if (estaLlena(p)) {
        printf("error pila llena\n", elemento);
        return;
    }
    p->tope++;
    p->items[p->tope] = elemento;
    printf("Elemento insertado\n", elemento);
}

int pop(Pila *p) {
    if (estaVacia(p)) {
        printf("Error, pila vacía\n");
        return 0;
    }
    int elementoExtraido = p->items[p->tope];
    p->tope--;
    return elementoExtraido;
}

void mostrarEstadoPila(Pila *p) {
    if (estaVacia(p)) {
        printf("Estado actual de la pila\n");
        return;
    }

    printf("Estado actual de la pila ", p->tope);
    for (int i = 0; i <= p->tope; i++) {
        printf("%d", p->items[i]);
        if (i < p->tope) {
            printf(", ");
        }
    }
    printf(" ] <- TOPE\n");
    // 
}

int main() {
    Pila miPila;
    int opcion, elemento, valorExtraido;
    
    inicializarPila(&miPila); 

    do {
        printf("1. Insertar elemento (push)\n");
        printf("2. Extraer elemento (pop)\n");
        printf("3. Mostrar estado actual de la pila\n");
        printf("4. Salir\n");
        printf("Selecciona una opción: ");

        if (scanf("%d", &opcion) != 1) {
            printf("\n error, introduce un número\n");
            while (getchar() != '\n');
            opcion = 0;
            continue;
        }

        switch (opcion) {
            case 1:
                if (estaLlena(&miPila)) {
                    printf("No se puede insertar, la pila ya está llena\n", MAX_SIZE);
                    break;
                }
                printf("Introduce el valor a ingresar: ");
                if (scanf("%d", &elemento) != 1) {
                    printf("Error\n");
                    while (getchar() != '\n');
                    break;
                }
                push(&miPila, elemento);
                mostrarEstadoPila(&miPila);
                break;

            case 2:
                valorExtraido = pop(&miPila);
                if (valorExtraido != 0) {
                    printf("Elemento extraído\n", valorExtraido);
                    mostrarEstadoPila(&miPila);
                }
                break;

            case 3:
                mostrarEstadoPila(&miPila);
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
