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

    for(int i=inicio; i<inicio+tamSubstring; i++){ 
        if(s[i] != s[i+tamSubstring]) return false;
    }

    return true;
}

int main(){
    char input[TAM_MAX];
    char output[TAM_MAX] = "\0";

    printf("Digite a sequencia de letras: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove o \n lido pelo fgets
    int tam_str = strlen(input); // declaracao do tam_str do vetor DIGITADO

    int i=0;
    while(i < tam_str){
        // 1. Tentar encontrar a maior sequencia que se repete.
        //    Pra isso, vamos testando strings de tam_str i (incrementando de 1 em 1)
        
        int menor_tam_de_padrao = 0;
        
        for(int tam_padrao_atual = tam_str/2; tam_padrao_atual>0; tam_padrao_atual--){
            if(repete(input, tam_str, tam_padrao_atual, i)){
                menor_tam_de_padrao = tam_padrao_atual;
            }
        }

        if(menor_tam_de_padrao == 0) {
            // Copia o caractere atual para a saída
            int tam_out = strlen(output);
            output[tam_out] = input[i];
            output[tam_out+1] = '1';
            output[tam_out+2] = '-';
            output[tam_out+3] = '\0';
             
            i++; // incremento de i, para testar a partir da proxima posição
            continue;
        }
        char padrao[TAM_MAX] = "\0";
        strncpy(padrao, input+i,menor_tam_de_padrao); // Copia a substring do padrão encontrado

        // Descobre quantas vezes o padrão se repete
        int qtde_repeticoes = 2;  // 1 ocorrência inicial

        for(int j = i + menor_tam_de_padrao; j + menor_tam_de_padrao <= tam_str; j += menor_tam_de_padrao){
            if(repete(input, tam_str, menor_tam_de_padrao, j)) qtde_repeticoes++;
            else break; // parou de repetir
        }

        
        // Se um padrão foi encontrado, copia ele para a saída, indicando-se q qtde de vezes que se repetiu
        strcat(output, padrao);
        char qtde_str[TAM_MAX]; // ababababaaaaa
        sprintf(qtde_str, "%d-", qtde_repeticoes);
        strcat(output, qtde_str);
        
        i += qtde_repeticoes * menor_tam_de_padrao;
    }

    printf("Compactada: %s\n", output);

    return 0;
}