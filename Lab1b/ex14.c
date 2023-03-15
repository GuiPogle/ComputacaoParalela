// Ex. 14

#include <stdio.h>
#include <string.h>

void insere_caractere(char str[], int posicao, char caractere) {
    int i;
    int n = strlen(str);
    for (i = n; i >= posicao; i--) {
        str[i + 1] = str[i];
    }
    str[posicao] = caractere;
}
