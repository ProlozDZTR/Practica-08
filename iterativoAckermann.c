/*Problema 4: iteratividad ackerman*/

#include <stdio.h>

#define MAX_PILA 100000

void ingresoNumeros(int *x,unsigned long long *y){
    printf("Iteratividad. Ackermann\n");
    printf("Digite dos numeros: ");
    scanf("%d %llu",x,y);
}

unsigned long long ackermann(int m,unsigned long long n){
long long stack[MAX_PILA];
    int top = 0; 
    
    unsigned long long n_actual = n; 
    int m_actual = m;

    if (m < 0 || n < 0) {
        printf("Error: Los numeros deben ser no negativos.\n");
        return -1;
    }

    stack[top++] = m_actual; 

    while (top > 0) {
        
        m_actual = stack[--top]; 
        
        if (m_actual == 0) {
            n_actual = n_actual + 1;
            
        } else if (n_actual == 0) {
            stack[top++] = m_actual - 1; 
            n_actual = 1; 
            
        } else {
            
            if (top + 2 >= MAX_PILA) {
                printf("\nERROR: Desbordamiento de pila. Los numeros son muy grandes.\n");
                return -1; 
            }
            
            stack[top++] = m_actual - 1;
            
            stack[top++] = m_actual;
            
            n_actual = n_actual - 1; 
        }
    }
    
    return n_actual;
}

void ejecutarPrograma(){
    unsigned long long resultado;
    int numUno = 0;
    unsigned long long numDos = 0; 

    ingresoNumeros(&numUno, &numDos);
    
    resultado = ackermann(numUno, numDos);
    
    if (resultado != -1) {
        printf("El ackermann de %d y %llu es: %llu\n", numUno, numDos, resultado);
    }
}

int main(int argc, char const *argv[]) {
    ejecutarPrograma();
    return 0; 
}