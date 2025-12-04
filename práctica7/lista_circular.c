#include <stdio.h>
#include <stdlib.h> 
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

void insertarInicioSimple(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: no se pudo asignar memoria\n");
        return;
    }
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;
    printf("-> Insertado: %d\n", valor);
}

void recorrerSimple(struct Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("La lista está vacía\n");
        return;
    }
    printf("\nContenido de la lista: ");
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        printf(" (%d -> ", actual->dato); 
        actual = actual->siguiente;
    }
    printf(" NULL \n");
}

void eliminarSimple(struct Nodo **cabeza, int valor) {
    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = NULL; 

    if (actual == NULL) {
        printf("La lista está vacía, no se puede eliminar %d\n", valor);
        return;
    }

    if (actual->dato == valor) {
        *cabeza = actual->siguiente;
        free(actual);
        printf("Eliminado %d\n", valor);
        return;
    }

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;          
        actual = actual->siguiente; 
    }

    if (actual == NULL) {
        printf("Error, el valor no se encontró en la lista\n", valor);
        return;
    }

    anterior->siguiente = actual->siguiente;
    free(actual);
    printf("Eliminado %d\n", valor);
}

void liberarSimple(struct Nodo **cabeza) {
    struct Nodo *actual = *cabeza;
    struct Nodo *siguienteNodo;
    while (actual != NULL) {
        siguienteNodo = actual->siguiente;
        free(actual);
        actual = siguienteNodo;
    }
    *cabeza = NULL;
    printf("Memoria liberada correctamente\n");
}

int main() {
    struct Nodo *cabezaSimple = NULL;
    int numValores, valor, valorEliminar;

    printf("Cuántos valores deseas insertar? ");
    if (scanf("%d", &numValores) != 1 || numValores < 0) return 1;
    
    for (int i = 0; i < numValores; i++) {
        printf("Introduce el valor: ", i + 1);
        if (scanf("%d", &valor) != 1) return 1;
        insertarInicioSimple(&cabezaSimple, valor);
        recorrerSimple(cabezaSimple);
    }
    
    printf("Estado actual de la lista:\n");
    recorrerSimple(cabezaSimple);
    
    printf("\nQué valor deseas eliminar de la lista? ");
    if (scanf("%d", &valorEliminar) != 1) return 1;
    
    eliminarSimple(&cabezaSimple, valorEliminar);
    printf("Lista actualizada:\n");
    recorrerSimple(cabezaSimple);

    liberarSimple(&cabezaSimple);
    
    return 0;
}
