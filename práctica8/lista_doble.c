#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error no se pudo asignar memoria\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = *inicio;

    if (*inicio != NULL) {
        (*inicio)->anterior = nuevo;
    }

    *inicio = nuevo;
    printf("--> Dato %d insertado al inicio\n", valor);
}

void insertarFinal(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: no se pudo asignar memoria\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    
    if (*inicio == NULL) {
        nuevo->anterior = NULL;
        *inicio = nuevo;
        printf("--> dato %d insertado al final\n", valor);
        return;
    }

    struct Nodo *temp = *inicio;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }

    temp->siguiente = nuevo;
    nuevo->anterior = temp;
    printf("--> Dato %d insertado al final\n", valor);
}

void recorrerAdelante(struct Nodo *inicio) {
    struct Nodo *actual = inicio;
    printf("\nRecorrido adelante : ");
    if (actual == NULL) {
        printf("La lista está vacía\n");
        return;
    }
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

void recorrerAtras(struct Nodo *inicio) {
    struct Nodo *actual = inicio;
    printf("Recorrido atrás: ");
    
    if (actual == NULL) {
        printf("La lista está vacía\n");
        return;
    }

    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->anterior;
    }
    printf("\n");
}

void eliminar(struct Nodo **inicio, int valor) {
    struct Nodo *actual = *inicio;

    if (actual == NULL) {
        printf("\nNo se puede eliminar, la lista esta vacía\n", valor);
        return;
    }

    while (actual != NULL && actual->dato != valor) {
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("\nEl valor no fue encontrado\n", valor);
        return;
    }

    if (actual->anterior == NULL) {
        *inicio = actual->siguiente;
        if (*inicio != NULL) {
            (*inicio)->anterior = NULL;
        }
    } 
    else if (actual->siguiente == NULL) {
        actual->anterior->siguiente = NULL;
    }
   
    else {
        actual->anterior->siguiente = actual->siguiente;
        
        actual->siguiente->anterior = actual->anterior;
    }

    free(actual);
    printf("\n** el nodo%d fue eliminado correctamente**\n", valor);
}

void liberar(struct Nodo **inicio) {
    struct Nodo *actual = *inicio;
    struct Nodo *siguiente_temp;

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

    printf("Cuántos elementos iniciales quiere insertar? ");
    if (scanf("%d", &num_elementos) != 1 || num_elementos <= 0) {
        printf("Entrada no válida\n");
    }

    for (i = 0; i < num_elementos; i++) {
        printf("Introduzca el valor para insertar al inicio: ", i + 1);
        if (scanf("%d", &valor_temp) == 1) {
            insertarInicio(&inicio, valor_temp);
        } else {
            printf("error\n");
            break;
        }
    }

    recorrerAdelante(inicio);
    recorrerAtras(inicio);
    insertarFinal(&inicio, 99);
    insertarFinal(&inicio, 100);
    
    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    if (inicio != NULL && inicio->siguiente != NULL) {
        int valor_medio = inicio->siguiente->dato;
        eliminar(&inicio, valor_medio);
        recorrerAdelante(inicio);
        recorrerAtras(inicio);
    } else {
        printf("La lista es muy pequeña\n");
    }

    if (inicio != NULL) {
        int valor_inicio = inicio->dato;
        printf("\nEliminar el elemento del inicio\n", valor_inicio);
        eliminar(&inicio, valor_inicio);
        recorrerAdelante(inicio);
        recorrerAtras(inicio);
    }

    if (inicio != NULL) {
        struct Nodo *ultimo = inicio;
        while (ultimo->siguiente != NULL) {
            ultimo = ultimo->siguiente;
        }
        int valor_final = ultimo->dato;
        eliminar(&inicio, valor_final);
        recorrerAdelante(inicio);
        recorrerAtras(inicio);
    }

    liberar(&inicio);

    return 0;
}
