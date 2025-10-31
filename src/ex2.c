// Escreva em C o algoritmo ex2 que descompacta o que foi compactado no item anterior

#include <stdio.h>
#include <string.h>

#define MAX_TAM_STR 50

int parseInt(char c){
    // Subtrai-se 48 p/ consertar a conversao pra int
    // 48 é o código ascii para o digito 0
    
    return (int) c - 48;
}

void descompacta_string(char s[MAX_TAM_STR], char output[MAX_TAM_STR]){
    char descompactada[MAX_TAM_STR];
    
    int i = 0;
    while(i<strlen(s)){
        char c = s[i]; // Caractere a ser concatenado

        // i+1 marca o início do número
        int j = i+1; 

        // j vai marcar o fim do numero + 1
        while(j < strlen(s) && s[j] != '-' ) j++;

        int n = 0; // A quantidade de vezes em que o caractere será concatenado

        int mult = 1;
        for(int k = j-1; k>i; k--){
            n += mult * parseInt(s[k]); 
            
            mult *= 10;
        }

        // Concatena o caractere n vezes no resultado
        for(int k=0; k<n; k++){
            char temp[2]; // O segundo arg de strcat espera um char*
            temp[0] = c;
            temp[1] = '\0';

            strcat(output, temp);
        }

        // Passa para o próximo caractere ou fim da string
        i = j+1;
    }
}

int main() {
    char compac[MAX_TAM_STR];

    // compac[MAX_TAM_STR] = "a7-b5-a10";
    printf("Digite a string compactada: ");
    fgets(compac, sizeof(compac), stdin);
    compac[strcspn(compac, "\n")] = '\0';

    char descompac[MAX_TAM_STR];
    descompac[0] = '\0';

    descompacta_string(compac, descompac);

    printf("String descompactada: %s\n", descompac);
    return 0;
}