#include <stdio.h>
#include <stdlib.h>

int main () {
	int n, m;
	int *arr= NULL;
	int *arr2 = NULL;
	int i; 
	
	printf("Cuántos enteros quieres almacenar?");
	scanf("%d",&n);
	
	arr = (int*)malloc (n* sizeof(int));
	if (arr == NULL){
		printf("Error, no se pudo reservar memoria con malloc\n");
		return 1;
		}
		
		printf ("\nValores iniciales con malloc:\n");
		for (i=0; i<n; i++){
			printf("%d", arr[i]);
				}
			printf("n\n");
			
			arr2 = (int*)calloc (n, sizeof(int));
			
			if (arr2 == NULL) {
				printf("Error: no se pudo reservar memoria con calloc\n");
				free(arr);
				return 1;
			}
			
			printf("valores iniciales con calloc (cero): \n");
			for (i = 0; i<n; i++){
				printf ("%d", arr2[i]);
			}
			printf("n\n");
		
    	printf("Ingresa %d valores:\n", n);

    for (i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    printf("\nArreglo lleno:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n\n");
    
    printf("Ingresa el nuevo tamaño del arreglo: ");
    scanf("%d", &m);

    int *temp = realloc(arr2, m * sizeof(int));
    if (temp == NULL) {
        printf("Error no se pudo redimensionar con realloc\n");
        free(arr);
        free(arr2);
        return 1;
    }
    arr2 = temp;

    if (m > n) {
        printf("\nArreglo agrandado, ingresa los valores extra:\n");
        for (i = n; i < m; i++) {
            printf("Valor %d: ", i + 1);
            scanf("%d", &arr2[i]);
        }
    }

    printf("\nArreglo final después de realloc:\n");
    for (i = 0; i < m; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n\n");

    free(arr);
    free(arr2);

    printf("\nMemoria liberada correctamente\n");

    return 0;
}
			
