// Ex. 3

#include <stdio.h>

int main() {
    int n, i, j, k;

    printf("Digite o número máximo (deve ser ímpar): ");
    scanf("%d", &n);

    if(n % 2 == 0) {
        printf("Número inválido. Deve ser ímpar.\n");
        return 0;
    }

    for(i = 1; i <= n; i++) {
        for(j = 1; j < i; j++) {
            printf(" ");
        }
        for(k = i; k <= n; k++) {
            printf("%d ", k);
        }
        printf("\n");
    }

    return 0;
}
