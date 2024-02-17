#include <stdio.h>
#include <stdlib.h>//rand() es una función de esta biblioteca
#include <time.h>

int main() {
    int num,caporal,i,j,k;
    int arreglo[200];
    srand(time(NULL));//asegura que cada vez que ejecutas el programa, se obtenga una secuencia diferente de números aleatorios

    printf("Numeros aleatorios:\n");
    for (i=0;i<10;i++) {
        num = rand() % 101; // el modulo de dividir cualquier número entre 101 siempre estará entre 0 y 100
        arreglo[i]=num;
        printf("%d ", arreglo[i]);
    }

    for(j=0;j<10;j++){
        for(k=0;k<10;k++){
            if(arreglo[k]>arreglo[k+1]){
                caporal=arreglo[k];
                arreglo[k]=arreglo[k+1];
                arreglo[k+1]=caporal;
            }
        }
    }

    printf("\n\nNumeros ordenados papa dio:\n");
    for (i=0;i<10;i++) 
        printf("%d ", arreglo[i]);

    return 0;
}