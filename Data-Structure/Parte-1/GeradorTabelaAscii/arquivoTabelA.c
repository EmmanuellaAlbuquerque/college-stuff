/* Programa que gera o decimal e o
/* caractere associado da tabela ASCII.
/* Aluna: Emmanuella Faustino Albuquerque
/***********************************************/

// Includes
#include<stdio.h>
#include<stdlib.h>

// Prototipos
void titulo(FILE *arq);
void linha(FILE *arq);

int main(void){

    FILE *arq; // ponteiro do arquivo lido
    int i; // variavel para iteracao

    // Cria um arquivo texto para leitura e gravacao. Se o arquivo existir, o conteudo anterior sera destruido. Se não existir, será criado.
    arq = fopen("tabela.txt", "w+"); // r,w ou a
	if(!arq){ // arq == 0, se nao existe ou nao foi encontrado
	printf("Arquivo nao encontrado!");
	return 0; // encerra
	}

    titulo(arq); // inicio da gravacao do arquivo

    for(i = 0; i < 255; i++){
      if(i % 10 == 0){ // quando a divisao por 10 nao tiver resto, pula uma linha
        linha(arq); // separa a tabela com uma linha apos 10 iteracoes
      }

    // Na tabela ASCII os 32 primeiros elementos não sao caracteres que possam ser impressos.
    fprintf(arq, "%d = %c\t", i, i); // decimal seguido por seu caractere com tabulacao, espacamento
    printf("%d = %c\t", i, i); // para base de testes represetacao no console

   }

    linha(arq); // fecha a tabela com uma
    fclose(arq); // fecha o arquivo
    return 0;
}

/**
*   Define o começo do arquivo e do console(para base de testes)
**/
void titulo(FILE *arq){
    fprintf(arq, "******************************** TABELA ASCII ***********************************\n");
    fprintf(arq, "Decimal/Caractere: ");
    printf("******************************** TABELA ASCII ***********************************\n");
    printf("Decimal/Caractere: ");
}

/**
*   Linha que separa caracteres na tabela.
**/
void linha(FILE *arq){
    fprintf(arq, "\n--------------------------------------------------------------------------------\n");
    printf("\n--------------------------------------------------------------------------------\n");
}
