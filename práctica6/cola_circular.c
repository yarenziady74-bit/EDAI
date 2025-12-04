#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct ColaCircular {
    int datos[MAX];
    int frente;
    int final;
    int size;
};

void iniciar(struct ColaCircular *q) {
    q->frente = 0;
    q->final = 0;
    q->size = 0;
    printf("Cola circular inicializada\n");
}

int isEmpty(struct ColaCircular *q) {
    return q->size == 0;
}

int isFull(struct ColaCircular *q) {
    return q->size == MAX;
}

void enqueue(struct ColaCircular *q, int v) {
    if (isFull(q)) {
        printf("la cola está llena\n");
        return;
    }
    q->datos[q->final] = v;
    q->final = (q->final + 1) % MAX;
    q->size++;
}

int dequeue(struct ColaCircular *q) {
    if (isEmpty(q)) {
        printf("No hay nada para sacar\n");
        return -1;
    }
    int valor = q->datos[q->frente];
    q->frente = (q->frente + 1) % MAX;
    q->size--;
    printf("\nDesencolado%d\n",valor);
    return valor;
}

void printQueue(struct ColaCircular *q) {
    if (isEmpty(q)) {
        printf("La cola está vacía\n");
        return;
    }
    for (int i = 0; i < q->size; i++) {
        int pos = (q->frente + i) % MAX;
        printf("%d ", q->datos[pos]);
    }
    printf("\n");
}

int peek(struct ColaCircular *q) {
    if (isEmpty(q)) {
        printf("No hay frente\n");
        return -1;
    }
    return q->datos[q->frente];
}

int main() {
    struct ColaCircular cola;
    iniciar(&cola);

    int opc, valor;

    do {
        printf("\n---- MENU DE COLA CIRCULAR ----\n");
        printf("1. Meter dato (enqueue)\n");
        printf("2. Sacar dato(dequeue)\n");
        printf("3. Ver cola\n");
        printf("4. Ver frente(peek)\n");
        printf("5. Salir\n");
        printf("Elige opcion: ");
        scanf("%d", &opc);

        if (opc == 1) {
            printf("Ingresa un valor: ");
            scanf("%d", &valor);
            enqueue(&cola, valor);
        }
        else if (opc == 2) {
            int d = dequeue(&cola);
            if (d != -1) printf("Sacaste: %d\n", d);
        }
        else if (opc == 3) {
            printf("Cola: ");
            printQueue(&cola);
        }
        else if (opc == 4) {
            int fr = peek(&cola);
            if (fr != -1) printf("Frente: %d\n", fr);
        }
        else if (opc != 5) {
            printf("Opcion no valida :/\n");
        }
    } while (opc != 5);

    printf("Fin :)\n");

    return 0;
}

   
