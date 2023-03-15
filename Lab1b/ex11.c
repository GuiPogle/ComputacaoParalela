// Ex. 11

#include <stdio.h>

void soma_linhas(int matriz[][3], int l1, int l2) {
    int j;
    for (j = 0; j < 3; j++) {
        matriz[l2][j] = matriz[l1][j] + matriz[l2][j];
    }
}

void multiplica_linhas(int matriz[][3], int l1, int l2) {
    int j;
    for (j = 0; j < 3; j++) {
        matriz[l2][j] = matriz[l1][j] * matriz[l2][j];
    }
}
