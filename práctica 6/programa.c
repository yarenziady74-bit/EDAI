#include <stdio.h>
#include <stdio.h>

#define MAX 5

typedef struct {
    int datos[MAX];
    int frente;
    int final;
    int size;
} ColaCircular;


void inicializar(ColaCircular *c) {
    c->frente = 0;
    c->final = 0;
    c->size = 0;
    printf("Cola circular inicializada\n");
}


int isEmpty(ColaCircular *c) {
    return c->size == 0;
}

int isFull(ColaCircular *c) {
    return c->size == MAX;
}


int enqueue(ColaCircular *c, int valor) {
    if (isFull(c)) {
        printf("La cola está llena\n");
        return 0;
    }

    c->datos[c->final] = valor;
    c->final = (c->final + 1) % MAX;
    c->size++;

    return 1;
}


int dequeue(ColaCircular *c, int *valor) {
    if (isEmpty(c)) {
        printf("La cola está vacía\n");
        return 0;
    }

    *valor = c->datos[c->frente];
    c->frente = (c->frente + 1) % MAX;
    c->size--;

    return 1;
}


int peek(ColaCircular *c, int *valor) {
    if (isEmpty(c)) {
        printf("La cola está vacía.\n");
        return 0;
    }
    *valor = c->datos[c->frente];
    return 1;
}


void printQueue(ColaCircular *c) {
    printf("Estado de la cola: ");

    if (isEmpty(c)) {
        printf("(vacía)\n");
        return;
    }

    int i = c->frente;
    for (int cont = 0; cont < c->size; cont++) {
        printf("%d ", c->datos[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}


int main() {

    ColaCircular cola;
    inicializar(&cola);

    int valor;

  
    printf("\nEncolando 5, 10, 15...\n");
    enqueue(&cola, 5);
    enqueue(&cola, 10);
    enqueue(&cola, 15);
    printQueue(&cola);

    
    printf("\nDesencolando uno...\n");
    dequeue(&cola, &valor);
    printf("Se desencoló: %d\n", valor);
    printQueue(&cola);

    
    printf("\nEncolando 20, 25, 30...\n");
    enqueue(&cola, 20);
    enqueue(&cola, 25);
    enqueue(&cola, 30);
    printQueue(&cola);

    
    return 0;
}

   
