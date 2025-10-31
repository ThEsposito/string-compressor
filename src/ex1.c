// Escreva em C o algoritmo ex1 que compacta elementos contíguos repetidos

#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 100

int main() {
    char entrada[MAX_TAMANHO];
    int cont = 1;
    

    printf("Digite a sequencia de letras: ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = '\0'; // remove o \n lido pelo fgets
    int tamanho = strlen(entrada); // declaracao do tamanho do vetor DIGITADO


    // LEITURA DE CADA CARACTERE + CONTAGEM
    printf("[ ");
    for(int i = 0; i < tamanho; i++){
        while(entrada[i] == entrada[i+1]){ // enquanto a "letra lida" for IGUAL a proxima letra
            cont++;
            i++;
        }
        printf("%c%d ", entrada[i], cont);
        cont = 1;
    }
    printf("]");

    return 0;
}