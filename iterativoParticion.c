/*problema 6. Iterativo partición*/

#include <stdio.h>

void ingresoNumeros(int *x,int *y){
    printf("Iteratividad. Particion P(m, n)\n");
    printf("Digite dos numeros: (m y n)");
    scanf("%d %d",x,y);
}

unsigned long long particion(int m,int n){
    unsigned long long tabla[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            
            if (i == 0 || j == 0) {
                tabla[i][j] = 1;
            } 
            else if (j > i) {
                tabla[i][j] = tabla[i][i];
            } 
            else if (j == i) {
                tabla[i][j] = 1 + tabla[i][j - 1];
            } 
            else { 
                tabla[i][j] = tabla[i][j - 1] + tabla[i - j][j];
            }
        }
    }

    unsigned long long resultado = tabla[m][n];

    return resultado;
}

void ejecutarPrograma(){
    unsigned long long resultado;
    int numUno = 0,numDos = 0;

    ingresoNumeros(&numUno,&numDos);
    resultado = particion(numUno,numDos);

    printf("La particion de (m=%d , n=%d) es: %llu",numUno,numDos,resultado);
}

int main(int argc,char const *argv[]){
    ejecutarPrograma();
    return 0;
}