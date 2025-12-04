#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Deque {
    int datos[MAX];
    int front;
    int size;
};

void inicDeque(struct Deque *dq) {
    dq->front = 0;
    dq->size = 0;
}

void insert_front(struct Deque *dq, int valor) {
    if (dq->size == MAX) {
        printf("La cola está llena\n");
        return;
    }
    dq->front = (dq->front - 1 + MAX) % MAX;
    dq->datos[dq->front] = valor;
    dq->size++;
}

void insert_rear(struct Deque *dq, int valor) {
    if (dq->size == MAX) {
        printf("La cola está llena\n");
        return;
    }
    int rear = (dq->front + dq->size) % MAX;
    dq->datos[rear] = valor;
    dq->size++;
}

void delete_front(struct Deque *dq) {
    if (dq->size == 0) {
        printf("la cola está vacía\n");
        return;
    }
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
}

void delete_rear(struct Deque *dq) {
    if (dq->size == 0) {
        printf("La cola está vacía\n");
        return;
    }
    dq->size--;
}

int peek_front(struct Deque *dq) {
    if (dq->size == 0) {
        printf("La cola está vacía\n");
        return -1;
    }
    return dq->datos[dq->front];
}

int peek_rear(struct Deque *dq) {
    if (dq->size == 0) {
        printf("La cola está vacían");
        return -1;
    }
    int rear = (dq->front + dq->size - 1) % MAX;
    return dq->datos[rear];
}

void printDeque(struct Deque *dq) {
    if (dq->size == 0) {
        printf("la cola esta vacía\n");
        return;
    }
    for (int i = 0; i < dq->size; i++) {
        printf("%d ", dq->datos[(dq->front + i) % MAX]);
    }
    printf("\n");
}

int main() {
    struct Deque dq;
    int choice, value;

    inicDeque(&dq);

    while (1) {
        printf("1. Ingresar al frente\n2. Ingrear al final\n3. Eliminar frente\n4. Eliminar al final\n5. Ver frente\n6. Ver final\n7. Imprimir cola doble\n8.Salir\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("ingresa el valor: ");
                scanf("%d", &value);
                insert_front(&dq, value);
                break;
            case 2:
                printf("ingresa el valor: ");
                scanf("%d", &value);
                insert_rear(&dq, value);
                break;
            case 3:
                delete_front(&dq);
                break;
            case 4:
                delete_rear(&dq);
                break;
            case 5:
                printf("Frente: %d\n", peek_front(&dq));
                break;
            case 6:
                printf("Final: %d\n", peek_rear(&dq));
                break;
            case 7:
                printDeque(&dq);
                break;
            case 8:
                return 0;
            default:
                printf("elección no válida\n");
        }
    }
    
    return 0;
}
