/*Problema 10. Recursivo Hanoi*/

#include <stdio.h>

void ingresoNumeros(int *x){
    printf("Recursividad: torres de Hanoi \n");
    printf("Digite el numero de discos: ");
    scanf("%d",x);
}

void torresDeHanoi(int n, char origen, char destino, char auxiliar) {
    
    if (n == 1) {
        printf("Mover disco 1 de %c a %c\n", origen, destino);
        return;
    }

    torresDeHanoi(n - 1, origen, auxiliar, destino);

    printf("Mover disco %d de %c a %c\n", n, origen, destino);

    torresDeHanoi(n - 1, auxiliar, destino, origen);
}

void ejecutarFuncion(){
    int n = 0;
    
    ingresoNumeros(&n);
    torresDeHanoi(n,'A','B','C');
}

int main(int argc,char const *argv[]){
    ejecutarFuncion();
    return 0;
}

