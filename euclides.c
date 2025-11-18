#include <stdio.h>
#include <time.h> // <--- 1. Incluimos la librería de tiempo

/*
 * Función recursiva de Euclides
 * Usa 'unsigned long long' (tipo sin signo de 64 bits)
 * para manejar los números más grandes posibles.
 */
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    // Caso base: si b es 0, el mcd es a
    if (b == 0) {
        return a;
    }
    // Paso recursivo
    return gcd(b, a % b);
}

int main() {
    // Variables para los números
    unsigned long long num1, num2;
    
    // --- 2. Variables para el tiempo ---
    clock_t start_t, end_t;
    double total_t;
    // ----------------------------------

    printf("Digite dos numeros enteros (muy grandes): ");
    
    // Usamos scanf con el especificador de formato "%llu"
    scanf("%llu %llu", &num1, &num2);

    printf("\nCalculando...\n");
    
    // --- 3. Medimos el tiempo ---
    start_t = clock(); // Inicia el reloj
    
    // Calculamos el resultado
    unsigned long long result = gcd(num1, num2);
    
    end_t = clock(); // Detiene el reloj
    // --------------------------

    // Imprimimos el resultado
    printf("El MCD de %llu y %llu es: %llu\n", num1, num2, result);
    
    // --- 4. Calculamos e imprimimos el tiempo total ---
    // Convertimos los "ticks" a segundos
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    
    printf("Tiempo de ejecucion: %f segundos\n", total_t);
    // ------------------------------------------------
    
    return 0;
}