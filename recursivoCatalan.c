/*7. recursivo catalan*/

#include <stdio.h>

void ingresoNumeros(int *x){
    printf("Recursividad. catalan\n");
    printf("Digite un numero entero: ");
    scanf("%d",x);
}

unsigned long long catalan(int n){
    if(n == 0){
        return 1;
    }
    unsigned long long suma = 0;
    int i;

    for (i = 0; i < n; i++){
        suma = suma + (catalan(i) * catalan(n - i - 1));
    }

    return suma;
}

void ejecutarFuncion(){
    unsigned long long resultado;
    int n = 0;

    ingresoNumeros(&n);
    resultado = catalan(n);

    printf("El catalan de %d es : %llu",n,resultado);
}

int main(int argc, char const *argv[]){
    ejecutarFuncion();
    return 0;
}