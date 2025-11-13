/*Problema 1: funcion recursiva para euclides*/

#include <stdio.h>

void ingresoDeNumeros(int *x ,int *y){
    printf("Digite dos numeros enteros: ");
    scanf("%i %i",x,y);
}
int mcd(int x ,int y){
    if(y == 0){
        return x;
    }else {
        return(y, x%y);
    }
}

void ejecutarFuncion(){
    int resultado;
    int numUno = 0,numDos = 0;
    ingresoDeNumeros(&numUno,&numDos);
    resultado = mcd(numUno,numDos);

    printf("El mcd de  %d y %d es: %d",numUno,numDos,resultado);
}

int main(int argc, char const *argv[]) {
    ejecutarFuncion();
    return 0;
}
