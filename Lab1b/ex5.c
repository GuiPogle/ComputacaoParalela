// Ex. 5

#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;

    printf("Digite o número de linhas e colunas: ");
    scanf("%d %d", &rows, &cols);

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int k;
    printf("Digite o número a ser multiplicado: ");
    scanf("%d", &k);

    int index;
    printf("Digite o índice da linha ou coluna a ser multiplicada (começando em 0): ");
    scanf("%d", &index);

    // Verifica se o índice fornecido é válido
    if (index < 0 || (index >= rows && index >= cols)) {
        printf("Índice inválido!\n");
        return 1;
    }

    if (index < rows) {
        for (int j = 0; j < cols; j++) {
            matrix[index][j] = k;
        }
    } else {
        for (int i = 0; i < rows; i++) {
            matrix[i][index-cols]= k;
        }
    }

    printf("Matriz resultante:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
