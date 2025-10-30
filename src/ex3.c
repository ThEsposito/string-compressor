/*
Escreva em C o algoritmo ex3 que compacta elementos contíguos repetidos do seguinte
modo:

Listing 3: Exemplo de entrada do "ex3".
1 ex3 " ababababababababababab "
2 >" ab11 "
3
4 ex3 " ababababababaaaaaaaaaaaaaaa "
5 >" ab6−a15 "
6
7 ex3 " abcabcabcabcxyxyxyccccccc "
8 >" abc4−xy3−c7 "
9
10 ex3 " a nt o n i o a nt o n i o a nt o n i o c a r l o s c a r l o s "
11 >" antonio3 −c a r l o s 2 "
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TAMANHO 100

// FUNCAO QUE CONFERE SE HA PADRAO NA SEQUENCIA DIGITADA
bool repete(){

}

int main(){
    char entrada[MAX_TAMANHO];
    int cont1 = 1; // contador de letra repetida
    int cont2 = 1; // contador de conjunto repetido
    

    printf("Digite a sequencia de letras: ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = '\0'; // remove o \n lido pelo fgets
    int tamanho = strlen(entrada); // declaracao do tamanho do vetor DIGITADO

    for(int i = 0; i < tamanho; i++){
        while(entrada[i] == entrada[i+1]){ // se for 'aaaaa' por exemplo
            cont1++;
        }

    }

    return 0;
}