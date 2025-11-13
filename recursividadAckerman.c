/*Problema 3: recursividad ackerman*/

#include <stdio.h>

void ingresoNumeros(int *x,int *y){
    printf("Digite dos numeros enteros: ");
    scanf("%i %i",x,y);
}

int ackermann(int m, int n) {
    if (m == 0){
        return n + 1;
    } else if (n == 0){
        return ackermann(m - 1, 1);
    }else{
        return ackermann(m - 1, ackermann(m, n - 1));
}
}
void ejecutarFuncion(){
    int resultado;
    int numUno = 0,numDos = 0;
    ingresoNumeros(&numUno,&numDos);
    resultado = ackermann(numUno,numDos);

    printf("El resultado de %d y %d es: %d",numUno,numDos,resultado);
}

int main(int argc, char const *argv[]) {
    ejecutarFuncion();
}
