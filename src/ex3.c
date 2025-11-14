/*
Escreva em C o algoritmo ex3 que compacta elementos contíguos repetidos do seguinte
modo:

Listing 3: Exemplo de entrada do "ex3".
1 ex3 "ababababababababababab"
2 >" ab11 "
3
4 ex3 "ababababababaaaaaaaaaaaaaaa"
5 >"ab6−a15"
6
7 ex3 " abcabcabcabcxyxyxyccccccc "
8 >"abc4−xy3−c7"
9
10 ex3 "antonioantonioantoniocarloscarlos"
11 >"antonio3−carlos2"
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TAM_MAX 100


bool repete(char s[TAM_MAX], int tamStr, int tamSubstring, int inicio){
    if(inicio+tamSubstring >= tamStr) return false;

    for(int i=inicio; inicio<inicio+tamSubstring; i++){ // <= ???
        if(s[i] != s[i+tamSubstring]) return false;
    }

    return true;
}

int main(){
    char input[TAM_MAX];
    char output[TAM_MAX];

    printf("Digite a sequencia de letras: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove o \n lido pelo fgets
    int tam_str = strlen(input); // declaracao do tam_str do vetor DIGITADO

    for(int i = 0; i < tam_str; i++){
        // 1. Tentar encontrar a maior sequencia que se repete.
        //    Pra isso, vamos testando strings de tam_str i (incrementando de 1 em 1)
        
        int menor_tam_de_padrao = 0;
        
        for(int tam_padrao_atual = tam_str/2; tam_padrao_atual>=0; tam_padrao_atual--){
            if(repete(input, tam_str, tam_padrao_atual, i)){
                menor_tam_de_padrao = tam_padrao_atual;
            }
        }

        if(menor_tam_de_padrao == 0) continue; // incremento de i, para testar a partir da proxima posição

        // Se um padrão foi encontrado, copia ele para a saída, indicando-se q qtde de vezes que se repetiu
    }

    return 0;
}