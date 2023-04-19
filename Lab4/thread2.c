#include <stdio.h>
#include <pthread.h>

// define a matriz 
#define NUM_THREADS 3
int matriz[3][3] = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}};
int vetor[3][3] = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}};
int resultado[3][3] = {{0, 0, 0},
                       {0, 0, 0},
                       {0, 0, 0}};

// função que separa uma linha para cada thread multiplicar
void *multiplicacao(void *thread_id) {
    int id = *((int*) thread_id); // extrai o ID da thread
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            resultado[id][i] += matriz[id][j] * vetor[j][i];
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int t;
    int thread_ids[NUM_THREADS];

    // cria as threads
    for (t = 0; t < NUM_THREADS; t++) {
        thread_ids[t] = t;
        int rc = pthread_create(&threads[t], NULL, multiplicacao, (void*) &thread_ids[t]);
        if (rc) {
            printf("Erro ao criar a thread %d\n", t);
            return -1;
        }
    }

    // espera as threads terminarem
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    // imprime o resultado
    printf("Resultado (threads 2):\n");
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    pthread_exit(NULL);
}
