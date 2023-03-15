// Ex. 1

#include <stdio.h>

int main() {
  int arr[3][3];
  int menor = 0;
  int menor_linha = 1;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("Digite o elemento de [%d][%d]: ", i, j);
      scanf("%d", &arr[i][j]);
      if (i == 0 && j == 0)
          menor = arr[i][j];

      if (arr[i][j] < menor) {
        menor = arr[i][j];
        menor_linha = i + 1;
      }
    }
  }

  printf("O menor número está na linha %d\n", menor_linha);

  return 0;
}
