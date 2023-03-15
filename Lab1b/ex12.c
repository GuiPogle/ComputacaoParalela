// Ex. 12

#include <stdio.h>
#include <string.h>

int posicao_caractere(char str[], char ch) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            return i;
        }
    }
    return -1;
}
