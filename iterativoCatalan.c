/*Problema 8. Iterativo catalan*/

#include <stdio.h>

void ingresoNumero(int *x){
    printf("Iteratividad catalan\n");
    printf("Digite un numero entero: ");
    scanf("%d",x);
}

unsigned long long catalan(int n){
    if (n < 0) return 0;

    unsigned long long tabla[n + 1];

    tabla[0] = 1;

    for (int i = 1; i <= n; i++) {
        
        tabla[i] = 0;
        
        for (int j = 0; j < i; j++) {
            tabla[i] = tabla[i] + (tabla[j] * tabla[i - j - 1]);
        }
    }

    return tabla[n];
}

void ejecutarPrograma(){
    unsigned long long resultado;
    int n = 0;

    ingresoNumero(&n);
    resultado = catalan(n);

    printf("El catalan de %d es: %llu\n",n,resultado);
}

int main(int argc, char const *argv[]){
    ejecutarPrograma();
    return 0;
}