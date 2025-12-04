#include <stdio.h>

#define TAM 5   
typedef struct {
    int datos[TAM];
    int tope;
} Pila;

void inicializarPila(Pila *p) {
    p->tope = -1;
}

int push(Pila *p, int valor) {
    if (p->tope == TAM - 1) {
        printf("La pila está llena\n");
        return 0;
    }
    p->datos[++(p->tope)] = valor;
    return 1;
}

int pop(Pila *p, int *valor) {
    if (p->tope == -1) {
        printf("La pila está vacía\n");
        return 0;
    }
    *valor = p->datos[(p->tope)--];
    return 1;
}

void mostrarPila(Pila p) {
    printf("Estado de la pila: ");
    if (p.tope == -1) {
        printf("(vacía)\n");
        return;
    }
    for (int i = 0; i <= p.tope; i++) {
        printf("%d ", p.datos[i]);
    }
    printf("\n");
}

typedef struct {
    int datos[TAM];
    int frente;
    int final;
} Cola;

void inicializarCola(Cola *c) {
    c->frente = 0;
    c->final = -1;
}

int enqueue(Cola *c, int valor) {
    if (c->final == TAM - 1) {
        printf("La cola está llena\n");
        return 0;
    }
    c->datos[++(c->final)] = valor;
    return 1;
}

int dequeue(Cola *c, int *valor) {
    if (c->frente > c->final) {
        printf("la cola está vacía\n");
        return 0;
    }
    *valor = c->datos[(c->frente)++];
    return 1;
}

void mostrarCola(Cola c) {
    printf("Estado de la cola: ");
    if (c.frente > c.final) {
        printf("(vacía)\n");
        return;
    }
    for (int i = c.frente; i <= c.final; i++) {
        printf("%d ", c.datos[i]);
    }
    printf("\n");
}

int main() {
    Pila pila;
    Cola cola;
    int n, i, valor, extraido;


    inicializarPila(&pila);
    printf("Pila inicializada vacía\n\n");


    printf("Cuántos elementos quieres meter a la pila (máximo 5)? ");
    scanf("%d", &n);

    for (i = 0; i < n && i < TAM; i++) {
        printf("Elemento: ", i + 1);
        scanf("%d", &valor);
        push(&pila, valor);
        mostrarPila(pila);
    }


    printf("\nCuántos elementos quieres sacar de la pila? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        if (pop(&pila, &extraido)) {
            printf("Se quitó: %d\n", extraido);
        }
        mostrarPila(pila);
    }


    inicializarCola(&cola);
    printf("\nCola inicializada vacía\n\n");

    printf("Cuántos elementos quieres encolar (máximo 5)? ");
    scanf("%d", &n);

    for (i = 0; i < n && i < TAM; i++) {
        printf("Elemento ingresado: ", i + 1);
        scanf("%d", &valor);
        enqueue(&cola, valor);
        mostrarCola(cola);
    }


    printf("\nCuántos elementos quieres desencolar? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        if (dequeue(&cola, &extraido)) {
            printf("Se quitó: %d\n", extraido);
        }
        mostrarCola(cola);
    }



    return 0;
}
