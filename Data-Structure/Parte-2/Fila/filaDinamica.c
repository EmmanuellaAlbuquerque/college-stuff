/******************************************************************************
* Estrutura de dados: Implementacao de uma fila dinamica.
* FIFO: O primeiro a entrar é o primeiro a sair.
* Aluna: Emmanuella Faustino Albuquerque
*******************************************************************************/

// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Tipos
struct fila{
    struct caixa *inicio;
    struct caixa *fim;
};

struct caixa{
    int dado;
    struct caixa *prox;
};

// Prototipos
void menu();
void criafila(struct fila *fAcessor);
int validaEntrada(char novamente[2]);
int filar(struct fila *fAcessor);
void limpar(struct fila *fAcessor);
int ehVazia(struct fila *fAcessor);
int insereInicio(struct caixa *fAcessor);
int insereFinal(struct fila *fAcessor);
int verificaTopo(struct fila *fila);
int tamanhoFila(struct fila *fAcessor);
int removePrimeiroElemento(struct fila *fAcessor);

/*---------------------------------------- Main -------------------------------------------*/
int main(){

    struct caixa *fila; // fila principal
    struct fila fAcessor;

    criafila(&fAcessor); // cria a fila principal
    char opcao[2]; // variavel de validacao para continuar no programa
    menu(); // apresenta o menu no console

    printf("Digite a opcao desejada: "); // pede a escolha com base no menu
    scanf("%s", opcao); // opcao, pelos indices

    while(validaEntrada(opcao)){ // se a funcao for verdadeira continua

        switch (opcao[0]){ // analisa a opcao escolhida

            case '1': // entrada 2 == inserir no Final
                if(insereFinal(&fAcessor)) printf("Inserido no final da fila com sucesso!\n");
                else printf("Nao foi possivel alocar espaço!\n");
                break;

            case '2': // entrada 3 == remover do Inicio
                if(removePrimeiroElemento(&fAcessor)){
                    printf("Removido do inicio da fila com sucesso!\n");
                    }
                else printf("fila vazia!\n");
                break;

            case '3': // entrada 5 == limpar fila principal
                limpar(&fAcessor);
                break;

            case '4': // entrada 6 == apresentar fila principal no console
                verificaTopo(&fAcessor);
                break;

            case '5': // entrada 6 == apresentar fila principal no console
                tamanhoFila(&fAcessor);
                break;

            case '6': // caso 8, encerra o programa
                printf("PROGRAMA ENCERRADO!\n");
                exit(0); // return(exit(0);

                }

    menu(); // apresenta o menu no console
    printf("Digite a opcao desejada: "); // pede a escolha com base no menu
    scanf("%s", opcao); // opcao, pelos indices
    }

    while(!validaEntrada(opcao)){ // se a funcao for falsa continua
        printf("COMANDO INVALIDO TENTE NOVAMENTE!\n");
        printf("Digite a opcao desejada: "); // pede a escolha com base no menu
        scanf("%s", opcao); // opcao, pelos indices
}
        return 0;
}

/**
* Cria menu para o console.
**/
void menu(){

    // MENU do programa
    printf("|------------------- MENU -----------------|\n");
    printf("|         1. Inserir no fim da fila        |\n");
    printf("|         2. Remover do inicio da fila     |\n");
    printf("|         3. Esvaziar fila                 |\n");
    printf("|         4. Ver topo da fila              |\n");
    printf("|         5. Ver tamanho da fila           |\n");
    printf("|         6. Sair                          |\n");
    printf("|------------------------------------------|\n\n");

    }

/**
* Cria/Constroe fila.
**/
void criafila(struct fila *fAcessor){

    fAcessor->inicio = 0;
    fAcessor->fim = 0;

}

/**
* Exibe o primeiro elemento da fila.
**/
int verificaTopo(struct fila *fila){

    struct caixa *laux; // fila auxiliar
    laux = fila->inicio;

    if(laux == NULL){ // Se a fila estiver vazia. Então, não tem como fila-la.
        printf("fila VAZIA!\n");
        return 0;
        }

    // Apresenta o conteudo da fila no console:
    printf("-- TOPO --\n");
    printf("     %d\n", laux->dado); // mostra o elemento do topo da fila
    printf("-----------\n\n");

    return 1;

}

/***
** Mostra o tamanho da fila
*/
int tamanhoFila(struct fila *fAcessor){

    if(fAcessor == NULL) return 0;
    int count = 0;

    struct caixa *laux = fAcessor->inicio;
    while(laux != NULL){
        count++;
        laux = laux->prox;
    }

    printf("O tamanho da FILA eh %d\n", count);
}

/***
** Verifica se a fila esta vazia.
*/
int ehVazia(struct fila *fila){

    if(fila == 0) return 1; // Se estiver vazia, retorna 1
    else return 0; // Se tiver algo dentro dela, retorna 0

    }

/***
** Limpa/Apaga o conteudo da fila dinamica.
*/
void limpar(struct fila *fAcessor){

    if(fAcessor != NULL){
        struct caixa *laux; // fila auxiliar
        while(fAcessor->inicio != NULL){
            laux = fAcessor->inicio;
            fAcessor->inicio = fAcessor->inicio->prox;
            free(laux);
        }

        free(fAcessor);

    }

    printf("fila esvaziada com sucesso!\n");

    }

/***
** Remove o primeiro elemento da fila dinamica.
*/
int removePrimeiroElemento(struct fila *fAcessor){

    struct caixa *laux; // fila auxiliar

    if(ehVazia(fAcessor)) return 0; // verifica se a fila eh vazia, se for sai da função
    if(fAcessor->inicio == NULL) return 0;

    laux = fAcessor->inicio;
    fAcessor->inicio = fAcessor->inicio->prox;
    printf("Removeu primeiro elemento: %d\n", laux->dado);

    if(fAcessor->inicio == NULL) // fila ficou vazia
        fAcessor->fim = NULL;

    free(laux); // exclui primeiro elemento da fila
    return 1;

    }

/***
** Insere no final da fila dinamica.
*/
int insereFinal(struct fila *fAcessor){

    struct caixa *novo, *laux; // novo elemento, fila aux

    // Aloca espaço para o novo elemento:
    novo = (struct caixa*)malloc(sizeof(struct caixa));
    if(!novo) return 0; // nao foi possivel alocar

    // Recebe o dado que o usuario deseja adicionar no final:
    printf("Digite o numero que deseja adicionar: \n");
    scanf("%d", &novo->dado);
    novo->prox = 0; // e define o novo ponto final

    if(fAcessor->inicio == 0){
        printf("Primeiro elemento da FILA adicionado com sucesso!\n");
        fAcessor->inicio = novo;
        fAcessor->fim = novo;
    }
    else{
        fAcessor->fim->prox = novo;
        fAcessor->fim = novo;
    }
    }

/***
** Valida a condicao de parado do loop principal.
*/
int validaEntrada(char novamente[2]){

    int x, flag; // contador e flag
    flag = 1;

    // inicialmente a entrada eh valida
    for(x = 0; x < strlen(novamente); x++){ // porem, se a entrada n for '0' nem '1'
        if(novamente[x] < '1' || novamente[x] > '8'){
            flag = 0; // entao a entrada eh invalida
            return flag; // retorna invalido, 0
        }
}

        return flag; // retorna valido, 1

}
