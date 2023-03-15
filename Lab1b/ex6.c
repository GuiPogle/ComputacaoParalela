// Ex. 6

#include <stdio.h>

#define MAX 100

int main() {
    int mat[MAX][MAX], transposta[MAX][MAX];
    int m, n, i, j;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &m);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &n);

    printf("Digite os elementos da matriz:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Matriz digitada:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("Transposta:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            transposta[i][j] = mat[j][i];
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}
