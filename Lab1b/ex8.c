// Ex. 8

#include <stdio.h>
#include <stdlib.h>

void transposta(int matriz, int transposta, int linhas, int colunas) {
    int i, j;

    for (i = 0; i < colunas; i++) {
        for (j = 0; j < linhas; j++) {
            transposta[i][j] = matriz[j][i];
        }
    }
}

int main() {
    int linhas, colunas, i, j;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    int matriz = (int ) malloc(linhas * sizeof(int ));
    for (i = 0; i < linhas; i++) {
        matriz[i] = (int) malloc(colunas * sizeof(int));
    }

    printf("Digite os valores da matriz:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int transposta = (int ) malloc(colunas * sizeof(int ));
    for (i = 0; i < colunas; i++) {
        transposta[i] = (int) malloc(linhas * sizeof(int));
    }

    transposta(matriz, transposta, linhas, colunas);

    printf("A matriz transposta é:\n");
    for (i = 0; i < colunas; i++) {
        for (j = 0; j < linhas; j++) {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    for (i = 0; i < colunas; i++) {
        free(transposta[i]);
    }
    free(transposta);

    return 0;
}

