/*
TODO: resolver cases abaixo
in: bxcatata
out: b1-x1-c1-at2-a1
 - Primeiro, tá printando só a1 (acho que não ocorria antes)
 - Segundo, a saída deveria ser só "bxc1-at2-a1"

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

#define TAM_MAX 100

int repete(char s[TAM_MAX], int tamStr, int tamSubstring, int inicio){
    if(inicio + (tamSubstring * 2) > tamStr) return 0;

    for(int i=inicio; i<inicio+tamSubstring; i++){ 
        if(s[i] != s[i+tamSubstring]) return 0;
    }

    return 1;
}

int main(){
    char input[TAM_MAX];
    char output[TAM_MAX] = "";

    printf("Digite a sequencia de letras: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove o '\n' lido pelo fgets
    int tam_str = strlen(input);

    // 1. Tentar encontrar a maior sequencia que se repete.
    //    Pra isso, vamos testando strings de tam_str i (incrementando de 1 em 1)
    int i=0;
    while(i < tam_str){
        int menor_tam_de_padrao = 0;
        
        for(int tam_padrao_atual = (tam_str - i)/2; tam_padrao_atual > 0; tam_padrao_atual--){
            if(repete(input, tam_str, tam_padrao_atual, i)){
                menor_tam_de_padrao = tam_padrao_atual;
            }
        }

        if(menor_tam_de_padrao == 0) { // Nenhum padrão encontrado       
            // Copia o caractere atual para a saída 
            int tam_out = strlen(output);
            sprintf(output, "%c1", input[i]); 
            i++; // incremento de i, para teste da próxima sequência
            
            // Adiciona o hífen se não for o fim da string
            if (i < tam_str) {
                strcat(output, "-");
            }
            continue; 
        }
        
        char padrao[TAM_MAX] = "";
        strncat(output, input+i, menor_tam_de_padrao);

        // Contagem de ocorrências do padrão
        int qtde_repeticoes = 2;  

        // For feio da porra kskskskskksks
        for(int j = i + menor_tam_de_padrao; j + menor_tam_de_padrao <= tam_str; j += menor_tam_de_padrao){
            if(repete(input, tam_str, menor_tam_de_padrao, j)) qtde_repeticoes++;
            else break;
        }

        i += qtde_repeticoes * menor_tam_de_padrao;
        char qtde_str[TAM_MAX];

        // Adiciona o hífen se não for o fim da string
        if (i < tam_str) {
            sprintf(qtde_str, "%d-", qtde_repeticoes);
        } else {
            sprintf(qtde_str, "%d", qtde_repeticoes);
        }

        strcat(output, qtde_str);        
    }

    printf("%s\n", output);
    return 0;
}