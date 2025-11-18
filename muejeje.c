#include <stdio.h>
#include <stdlib.h> // Para atoi (convertir texto a numero)
#include <pthread.h> // <--- 1. La librería de hilos
#include <time.h>    // Para medir el tiempo

// --- La misma función ineficiente de Fibonacci ---
unsigned long long fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

// --- 2. Función "envoltorio" para el hilo ---
// pthread_create necesita una función que tome (void*) y devuelva (void*)
void* run_fib_thread(void* arg) {
    // Convertimos el argumento de vuelta a un entero
    int n = *(int*)arg;
    
    //printf("Hilo %lu iniciando fib(%d)...\n", pthread_self(), n);
    unsigned long long result = fib(n);
    //printf("Hilo %lu terminó con resultado %llu.\n", pthread_self(), result);
    
    return NULL;
}

int main() {
    int n_test, num_threads;
    clock_t start_t, end_t;
    double total_t;

    printf("--- Prueba de Estres de TODOS los Nucleos (Fibonacci + Hilos) ---\n");
    
    // --- 3. Preguntamos los parámetros ---
    printf("Digite el numero 'n' para calcular Fibonacci(n) (ej. 45): ");
    scanf("%d", &n_test);

    printf("Digite el numero de hilos a lanzar (ej. 16 para un Ryzen 9): ");
    scanf("%d", &num_threads);

    // Creamos un arreglo para guardar la info de cada hilo
    pthread_t thread_ids[num_threads];

    printf("\n¡Iniciando %d hilos para calcular Fibonacci(%d)!\n", num_threads, n_test);
    printf("¡Abre tu monitor de sistema (como htop) AHORA!\n");
    printf("Calculando...\n");

    // --- 4. Medimos el tiempo y lanzamos los hilos ---
    start_t = clock(); // Inicia el reloj

    for (int i = 0; i < num_threads; i++) {
        // Creamos cada hilo y le decimos que ejecute 'run_fib_thread'
        if (pthread_create(&thread_ids[i], NULL, run_fib_thread, &n_test) != 0) {
            perror("Error al crear el hilo");
            return 1;
        }
    }

    // --- 5. Esperamos a que TODOS los hilos terminen ---
    for (int i = 0; i < num_threads; i++) {
        pthread_join(thread_ids[i], NULL);
    }

    end_t = clock(); // Detiene el reloj
    // -------------------------------------------------

    printf("\n¡TODOS LOS HILOS TERMINARON!\n");
    
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    
    printf("Tiempo total de ejecucion: %f segundos\n", total_t);
    
    return 0;
}