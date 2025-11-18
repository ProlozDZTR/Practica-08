/*Problema 10. Iterativo. Coeficiente binomial*/

#include <stdio.h>

void ingresoNumeros(int *x,int *y){
    printf("Iterativo: coeficiente binomial\n");
    printf("Ingrese dos numeros enteros (n y k)  ");
    printf("\"Dato, k no puede ser mayor que n\": ");
    scanf("%d %d",x,y);
}

unsigned long long coeficienteBinomial(int n,int k){
    if (k < 0 || n < 0 || k > n) {
        return 0;
    }

    unsigned long long tabla[n + 1][k + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k && j <= i; j++) {
            
            if (j == 0 || j == i) {
                tabla[i][j] = 1;
            } 
            else {
                tabla[i][j] = tabla[i - 1][j - 1] + tabla[i - 1][j];
            }
        }
    }

    return tabla[n][k];
}

void ejecutarPrograma(){
    unsigned long long resultado;
    int numUno = 0,numDos = 0;

    ingresoNumeros(&numUno,&numDos);
    resultado = coeficienteBinomial(numUno,numDos);

    printf("El coeficiente binomial (n = %d , k = %d) es: %llu\n",numUno,numDos,resultado);
}

int main(int argc,char const *argv[]){
    ejecutarPrograma();
    return 0;
}