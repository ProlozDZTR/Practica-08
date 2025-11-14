/*Problema 4: iteratividad ackerman*/

#include <stdio.h>

#define MAX_PILA 100

void ingresoNumeros(int *x,int *y){
    printf("Digite dos numeros: ");
    scanf("%d %d",x,y);
}

int ackermann(int m,int n){
    int stack[MAX_PILA];
    int top = 0; 
    long long n_actual = n; 
    int m_actual = m;

    if (m < 0 || n < 0) {
        printf("Error: Los numeros deben ser no negativos.\n");
        return -1;
    }

    stack[top++] = m_actual; 

    while (top > 0) {
        m_actual = stack[top - 1]; 
        
        if (m_actual == 0) {
            n_actual = n_actual + 1;
            top--; 
            
        } else if (n_actual == 0) {
            stack[top - 1] = m_actual - 1; 
            n_actual = 1; 
            
        } else {
            n_actual = n_actual - 1; 

            if (top >= MAX_PILA) {
                printf("\nERROR: Desbordamiento de pila. Los numeros son muy grandes.\n");
                return -1; 
            }
            stack[top++] = m_actual - 1;
        }
    }
    
    return n_actual;
}

void ejecutarPrograma(){
    long long resultado;
    int numUno = 0,numDos = 0;

    ingresoNumeros(&numUno,&numDos);
    resultado = ackermann(numUno,numDos);

    printf("El ackermann de %d y %d es: %lld",numUno,numDos,resultado);
}

int main(int argc, char const *argv[]) {
    ejecutarPrograma();
    return 0; 
}