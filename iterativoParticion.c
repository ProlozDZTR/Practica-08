/*6. Particion iterativo*/

#include <stdio.h>

void ingresoNumeros(int *x,int *y){
    printf("Digite dos numeros enteros: ");
    scanf("%d %d",x,y);
}

int particion(int m,int n){
    int aux;
    while(m != 0 || n != 0){
        if(m == 0 || n == 0){
            aux = 1;
        }else if(m < n){
            aux = (m, m);
        }else if(m == n){
            aux = 1 + (m, m - 1);
        }else if(m > n){
            aux = (m,n-1) + (m-n,n);
        }
    }
    return aux; 
}

void ejecutarPrograma(){
    int resultado;
    int numUno = 0,numDos = 0;

    ingresoNumeros(&numUno,&numDos);
    resultado = particion(numUno,numDos);

    printf("La particion de %d y %d es: %d",numUno,numDos,resultado);
}

int main(int argc, char const *argv[]) {
    ejecutarPrograma();
    return 0;
}
