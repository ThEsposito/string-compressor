// Escreva em C o algoritmo ex1 que compacta elementos contíguos repetidos

#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 100

int main() {
    char entrada[MAX_TAMANHO];
    int cont = 0; 

    printf("Digite a sequencia de letras: ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = '\0'; // remove o \n lido pelo fgets

    printf("%s", entrada); // teste para ver se esta lendo coretamente

    // LEITURA DE CADA CARACTERE + CONTAGEM
    for(int i = 0; i < sizeof(entrada); i++){
        while(entrada[i] = entrada[i+1]){ // enquanto a "letra lida" for IGUAL a proxima letra
            cont++;
        }
    }

    return 0;
}
