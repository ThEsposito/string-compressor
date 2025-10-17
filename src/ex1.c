// Escreva em C o algoritmo ex1 que compacta elementos contíguos repetidos

#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 100

int main() {
    char entrada[MAX_TAMANHO];

    printf("Digite a sequencia de letras: ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = '\0'; // remove o \n lido pelo fgets

    printf("%s", entrada); // teste para ver se esta lendo

    return 0;
}
