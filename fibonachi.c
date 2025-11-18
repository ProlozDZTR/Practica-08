#include <stdio.h>
#include <time.h> // <--- 1. Incluimos la librería de tiempo

/*
 * Función recursiva de Fibonacci (¡Muy ineficiente!)
 * Esta es la función que causa la "explosión" de cálculos
 * para estresar el CPU.
 * Usamos 'unsigned long long' para poder almacenar resultados grandes.
 */
unsigned long long fib(int n) {
    if (n <= 1) {
        return n;
    }
    // Cada llamada genera OTRAS DOS llamadas
    return fib(n - 1) + fib(n - 2);
}

int main() {
    // Variable para el número 'n' que digitará el usuario
    int n_test;
    
    // --- 2. Variables para el tiempo ---
    clock_t start_t, end_t;
    double total_t;
    // ----------------------------------
    
    printf("--- Prueba de Estres de CPU (Fibonacci) ---\n");
    printf("Digite un numero 'n' para calcular Fibonacci(n):\n");
    printf("Recomendados: 40 (rapido), 45 (lento), 47 (muy lento)\n");
    printf("Advertencia: n > 47 puede tardar VARIOS MINUTOS.\n");
    printf("Digite n: ");
    
    // Pedimos el número al usuario
    scanf("%d", &n_test);

    printf("\nIniciando calculo recursivo para Fibonacci(%d)...\n", n_test);
    printf("Esto puede tardar. Observa tu monitor de CPU.\n");
    
    // --- 3. Medimos el tiempo ---
    start_t = clock(); // Inicia el reloj
    
    // Calculamos el resultado (¡Aquí ocurre el trabajo pesado!)
    unsigned long long result = fib(n_test);
    
    end_t = clock(); // Detiene el reloj
    // --------------------------

    printf("\n¡Calculo terminado!\n");
    
    // Imprimimos el resultado
    printf("El resultado de Fibonacci(%d) es: %llu\n", n_test, result);
    
    // --- 4. Calculamos e imprimimos el tiempo total ---
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    
    printf("Tiempo total de ejecucion: %f segundos\n", total_t);
    // ------------------------------------------------
    
    return 0;
}