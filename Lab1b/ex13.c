//Ex. 13

#include <stdio.h>
#include <string.h>

void remove_caractere(char str[], int posicao) {
    int i;
    int n = strlen(str);
    for (i = posicao; i < n - 1; i++) {
        str[i] = str[i + 1];
    }
    str[n - 1] = '\0';
}
