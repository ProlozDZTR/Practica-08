/*Problema 12. Iteratividad torres de Hanoi*/

#include <stdio.h>

#define MAX_PILA 100

void ingresoNumero(int *n){
    printf("Iteratividad: Torres de Hanoi\n");
    printf("Digite el total de discos: ");
    scanf("%d",n);
}

void torresDeHanoi(int n,char origen, char destino,char auxiliar){
    int pilaN[MAX_PILA];
    char pilaOrigen[MAX_PILA];
    char pilaDestino[MAX_PILA];
    char pilaAuxiliar[MAX_PILA];
    
    int tope = 0; 
    char varAux; 

    if (n < 1) {
        printf("Se necesita al menos 1 disco.\n");
        return;
    }

    while (n > 0 || tope > 0) {
        
        while (n > 1) {
            pilaN[tope] = n;
            pilaOrigen[tope] = origen;
            pilaDestino[tope] = destino;
            pilaAuxiliar[tope] = auxiliar;
            tope++;

            n = n - 1;
            varAux = destino;
            destino = auxiliar;
            auxiliar = varAux;
        }

        printf("Mover disco %d de %c a %c\n", n, origen, destino);

        if (tope > 0) {
            tope--;
            n = pilaN[tope];
            origen = pilaOrigen[tope];
            destino = pilaDestino[tope];
            auxiliar = pilaAuxiliar[tope];
            
            printf("Mover disco %d de %c a %c\n", n, origen, destino);

            n = n - 1;
            varAux = origen;
            origen = auxiliar;
            auxiliar = varAux;
        } else {
            n = 0; 
        }
    }
}

void ejecutarPrograma() {
    int n = 0;

    ingresoNumero(&n);
    torresDeHanoi(n,'A','B','C');
}

int main(int argc,char const *argv[]) {
    ejecutarPrograma();
    return 0;
}