#include <stdio.h>

int main() {
  
    // declara as matrizes
    int matriz[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
    int vetor[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
    int resultado[3][3] = {{0, 0, 0},
                           {0, 0, 0},
                           {0, 0, 0}};
    int i, j, k;

    // multiplica a matriz por vetor
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                resultado[i][j] += matriz[i][k] * vetor[k][j];
            }
        }
    }

    // imprime o resultado
    printf("Resultado (serial 2):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
