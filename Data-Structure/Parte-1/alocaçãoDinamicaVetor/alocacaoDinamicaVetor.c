/* Alocacao dinamica de memoria com ponteiro para ponteiro.
/* Aluna: Emmanuella Faustino Albuquerque
/***********************************************/

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*############################################  MAIN ###################################### */
int main(){

    char **nomes, palavra[30]; // ponteiro para um ponteiro e uma string
    int indice, quantidade;    // contador e numero de palavras

    // Pergunta a quantidade de nomes a serem alocados:
	printf("Digite a quantidade de nomes a serem alocados: ");
	scanf("%d", &quantidade);

    // Aqui você aloca a 'quantidade' de ponteiros de char, ou seja, 'quantidade' de strings **vazias**, ainda **não alocadas**.
    nomes = malloc(sizeof(char*)*quantidade);

    // Verifica se o alocamento anterior foi bem sucedido
    if(!nomes){ // Nao alocou o vetor
	printf("Memoria Indisponivel");
	return 0; // encerra o programa
	}

    // Loop para percorrer todos os indices do seu "vetor" de strings[ponteiros que apontaram para strings]
    for(indice = 0; indice < quantidade; indice++){ // dada a quantidade digitada pelo usuario
    printf("Digite o nome: ");                // e os nomes
	scanf("%s", palavra);

    // eh alocado espaço para os diferentes tamanhos de Strings de cada indice do vetor de ponteiros
	printf("Palavra: %s | Tamanho p/ alocar: %d\n", palavra, strlen(palavra)+1); // tamanho da string + 1(representa o \0)
    nomes[indice]=malloc(sizeof(char)*(strlen(palavra)+1)); //String Dinâmica Normal

    // Verifica se o alocamento anterior foi bem sucedido
    if(!nomes[indice]){ // nao alocou a strig
	printf("Nome nao alocado!");
	return 0; // encerra o programa
	}

    // Apos alocaçao, copia o conteudo da string digitada pelo usuario, para a memoria alocada
    strcpy(nomes[indice], palavra);

    }

    printf("----------- PALAVRAS ALOCADAS ----------\n");
    for(indice = 0; indice < quantidade; indice++){ //Percorre o "Vetor" de strings
    printf("%s\n", nomes[indice]); // mostra a palavra alocada na memoria
    free(nomes[indice]); //Libera uma String/palavra ao decorrer do loop
    }

    free(nomes); //No término do Loop, libera o "Vetor" de strings


}

