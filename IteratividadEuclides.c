/*Problema 2: euclides con iteratividad*/

#include <stdio.h>

void ingresoNumeros(int *x, int *y){
    printf("Digite dos numeros: ");
    scanf("%i %i",x,y);
}

int mcd(int x, int y){
    int aux;
    while(y != 0){
        aux = y;
        y = x % y;
        x = aux;
    }
    return x;
}

void ejecutarPrograma(){
    int resultado;
    int numUno = 0,numDos = 0;

    ingresoNumeros(&numUno,&numDos);
    resultado = mcd(numUno,numDos);

    printf("El mcd de %d y %d es: %d",numUno,numDos,resultado);
}

int main(int argc, char const *argv[]) {
    ejecutarPrograma();
    return 0;
}
