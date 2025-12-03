#include <stdio.h>
#include <stdlib.h> 

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    
    if (nuevoNodo == NULL) {
        printf("Error: no se pudo asignar memoria para el nuevo nodo\n");
        return;
    }
    
    nuevoNodo->dato = valor;
    
    nuevoNodo->siguiente = *cabeza;
    
    *cabeza = nuevoNodo;
    
    printf("-> Insertado: %d\n", valor);
} 
void recorrer(struct Nodo *cabeza) {
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
  
    printf(" NULL) ");
    printf("\n");
}

void eliminar(struct Nodo **cabeza, int valor) {
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
        printf("Error: El valor %d no se encntró en la lista\n", valor);
        return;
    }

    anterior->siguiente = actual->siguiente;
    free(actual);
    printf("Eliminado\n", valor);
}

void liberar(struct Nodo **cabeza) {
    struct Nodo *actual = *cabeza;
    struct Nodo *siguienteNodo;

    while (actual != NULL) {
        siguienteNodo = actual->siguiente; 
        free(actual);                     
        actual = siguienteNodo;         
    }

    *cabeza = NULL;
    printf("memoria liberada correctamente\n");
}

//lo siento, profesor, no sé cuáles fueron los ejemplos en clase ):

int main() {
    struct Nodo *cabeza = NULL;
    int numValores, valor, valorEliminar;

    printf("Cuántos valores deseas insertar en la lista? ");
    if (scanf("%d", &numValores) != 1 || numValores < 0) {
        printf("inválida\n");
        return 1;
    }
    
    for (int i = 0; i < numValores; i++) {
        printf("Introduce el valor #%d: ", i + 1);
        if (scanf("%d", &valor) != 1) {
            printf("inválido\n");
            liberar(&cabeza);
            return 1;
        }
        insertarInicio(&cabeza, valor);
        recorrer(cabeza);
    }
    
    printf("Estado de la lista antes de eliminar:\n");
    recorrer(cabeza);

    printf("\nQué valor deseas eliminar de la lista? ");
    if (scanf("%d", &valorEliminar) != 1) {
        printf("inválido\n");
        liberar(&cabeza);
        return 1;
    }
    
    eliminar(&cabeza, valorEliminar);
    
    printf("Lista actualizada después de eliminar:\n");
    recorrer(cabeza);

    liberar(&cabeza);
    
    return 0;
}
