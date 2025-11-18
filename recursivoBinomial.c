/*Problema 8. Recursivo coeficiente binominial*/

#include <stdio.h>

void ingresoNumeros(int *x,int *y){
    printf("Recursividad: coeficiente binomial. \n");
    printf("Ingrese dos numeros enteros: ");
    scanf("%d %d",x,y);
}

unsigned long long coeficienteBinomial(int n, int k) {
    
    if (k == 0 || k == n) {
        return 1;
    }
    
    if (k > n) {
        return 0; 
    }

    return coeficienteBinomial(n - 1, k - 1) + coeficienteBinomial(n - 1, k);
}

void ejecutarFuncion(){
    unsigned long long resultado;
    int numUno = 0,numDos = 0;

    ingresoNumeros(&numUno,&numDos);
    resultado = coeficienteBinomial(numUno,numDos);

    printf("El coeficiente binomial de %d y %d es: \n %llu",numUno,numDos,resultado);
}

int main(int argc, char const *argv[]){
    ejecutarFuncion();
    return 0;
}