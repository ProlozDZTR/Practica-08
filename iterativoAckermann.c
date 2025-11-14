/*Problema 4: iteratividad ackerman*/

#include <stdio.h>

void ingresoNumeros(int *x,int *y){
    printf("Digite dos numeros: ");
    scanf("%i %i",x,y);
}

int ackermann(int x,int y){
    int aux;
}

void ejecutarPrograma(){
    int resultado;
    int numUno = 0,numDos = 0;

    ingresosNumeros(&numUno,&numDos);
    resultado = ackermann(numUno,numDos);

    printf("El ackermann de %d y %d es: %d",numUno,numDos,resultado);
}

int main(int argc, char const *argv[]) {
    ejecutarPrograma();
    return 0; 
}