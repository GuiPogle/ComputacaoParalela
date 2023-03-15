// Ex. 7 

#include <stdio.h>
#include <string.h>

#define MAX_PESSOAS 3
#define MAX_NOME 50

struct Pessoa {
    char nome[MAX_NOME];
    int idade;
    float peso;
    float altura;
};

int main() {
    struct Pessoa pessoas[MAX_PESSOAS];
    int i;

    printf("Digite os dados de %d pessoas:\n", MAX_PESSOAS);

    for(i = 0; i < MAX_PESSOAS; i++) {
        printf("\nPessoa %d:\n", i+1);

        printf("Nome: ");
        fgets(pessoas[i].nome, MAX_NOME, stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = '\0';

        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);

        printf("Peso: ");
        scanf("%f", &pessoas[i].peso);

        printf("Altura: ");
        scanf("%f", &pessoas[i].altura);

        getchar();
    }

    printf("\nDados das pessoas:\n");

    for(i = 0; i < MAX_PESSOAS; i++) {
        printf("\nPessoa %d:\n", i+1);

        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d anos\n", pessoas[i].idade);
        printf("Peso: %.2f kg\n", pessoas[i].peso);
        printf("Altura: %.2f m\n", pessoas[i].altura);
    }

    return 0;
}

Conversar em @guichiare
