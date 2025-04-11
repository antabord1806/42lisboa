// main.c
#include <stdio.h>
#include "libft.h"
#include <ctype.h>

int main() {
    int c;

    // Teste com caracteres diferentes
    c = 'A';
    if (isalnum(c)) {
        printf("'%c' é alfanumérico.\n", c);
    } else {
        printf("'%c' não é alfanumérico.\n", c);
    }

    c = '1';
    if (isalnum(c)) {
        printf("'%c' é alfanumérico.\n", c);
    } else {
        printf("'%c' não é alfanumérico.\n", c);
    }

    c = '@';
    if (isalnum(c)) {
        printf("'%c' é alfanumérico.\n", c);
    } else {
        printf("'%c' não é alfanumérico.\n", c);
    }

    return 0;
}
