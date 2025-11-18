/*Problema 5: funcion recursiva de particion*/

#include <stdio.h>

void ingresoNumeros(int *x,int *y){
    printf("Recursividad. Particion P(m, n)\n");
    printf("Digite dos numeros (m , n)");
    scanf("%d %d",x,y);
}

int particion(int m, int n){
    if(m == 1 || n == 1){
        return 1;
    }else if(m < n){
        return particion(m, m);
    }else if(m == n){
        return 1 + particion(m, m - 1 );
    }else if(m > n){
        return particion(m,n-1) + particion(m-n,n);
    }
}

void ejecutarPrograma(){
    int resultado; 
    int numUno = 0,numDos = 0;

    ingresoNumeros(&numUno,&numDos);
    resultado = particion(numUno,numDos);

    printf("la particion de %d y %d es: %d",numUno,numDos,resultado);
}

int main(int argc, char const *argv[]){
    ejecutarPrograma();
    return 0;
}