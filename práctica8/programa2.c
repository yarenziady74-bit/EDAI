#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

void insertarFinalCircular(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error, no se pudo asignar memoria\n");
        return;
    }
    nuevo->dato = valor;

    if (*inicio == NULL) {
        *inicio = nuevo;
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        printf("--> primer nodo de la lita circular\n", valor);
        return;
    }

    struct Nodo *ultimo = (*inicio)->anterior;

    nuevo->siguiente = *inicio;
    nuevo->anterior = ultimo;

    (*inicio)->anterior = nuevo;
    ultimo->siguiente = nuevo;

    printf("--> Dato insertado al final de la lista\n", valor);
}

void recorrerCircular(struct Nodo *inicio) {
    if (inicio == NULL) {
        printf("\n recorrido, la lista está vacía\n");
        return;
    }

    struct Nodo *actual = inicio;
    do {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    } while (actual != inicio);

    printf("\n");
    printf("  - El primero (%d) tiene como anterior a: %d\n", inicio->dato, inicio->anterior->dato);
    printf("  - El último (%d) tiene como siguiente a: %d\n", inicio->anterior->dato, inicio->siguiente->dato);
}

void eliminarCircular(struct Nodo **inicio, int valor) {
    if (*inicio == NULL) {
        printf("\nEl valor no se puede eliminar\n", valor);
        return;
    }

    struct Nodo *actual = *inicio;
    int encontrado = 0;

    do {
        if (actual->dato == valor) {
            encontrado = 1;
            break;
        }
        actual = actual->siguiente;
    } while (actual != *inicio);

    if (!encontrado) {
        printf("\nEl valor no fue encontrado en la lista\n", valor);
        return;
    }

    if (actual == *inicio && actual->siguiente == *inicio) {
        free(actual);
        *inicio = NULL;
        printf("\n** el nodo fue eliminado, la lista ha quedado vacía**\n", valor);
        return;
    }

    if (actual == *inicio) {
        *inicio = actual->siguiente;
    }

    struct Nodo *anterior_temp = actual->anterior;
    struct Nodo *siguiente_temp = actual->siguiente;

    anterior_temp->siguiente = siguiente_temp;
    siguiente_temp->anterior = anterior_temp;

    free(actual);
    printf("\n** el nodo fue eliminado correctamente **\n", valor);
}

void liberarCircular(struct Nodo **inicio) {
    if (*inicio == NULL) {
        printf("\nMemoria liberada\n");
        return;
    }

    struct Nodo *actual = *inicio;
    struct Nodo *siguiente_temp;
    
    (*inicio)->anterior->siguiente = NULL;
    
    while (actual != NULL) {
        siguiente_temp = actual->siguiente;
        free(actual);
        actual = siguiente_temp;
    }

    *inicio = NULL; 
    printf("\nMemoria liberada correctamente\n");
}


int main() {
    struct Nodo *inicio = NULL;
    int num_elementos, i, valor_temp;

    printf("Cuántos elementos quiere insertar al final? ");
    if (scanf("%d", &num_elementos) != 1 || num_elementos <= 0) {
        printf("Entrada no válida\n");
        return 0; 
    }

    for (i = 0; i < num_elementos; i++) {
        printf("Introduce el valor para insertar: ", i + 1);
        if (scanf("%d", &valor_temp) == 1) {
            insertarFinalCircular(&inicio, valor_temp);
        } else {
            printf("error\n");
            while (getchar() != '\n'); 
            break;
        }
    }

    
    if (inicio != NULL) {
        int valor_a_eliminar = inicio->anterior->dato;
        eliminarCircular(&inicio, valor_a_eliminar);
        recorrerCircular(inicio);
    }

    if (inicio != NULL) {
        int valor_inicio = inicio->dato;
        eliminarCircular(&inicio, valor_inicio);
        recorrerCircular(inicio);
    }
    
    liberarCircular(&inicio);

    return 0;
}
