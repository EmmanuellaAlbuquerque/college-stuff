/******************************************************************************
* Estrutura de dados: Implementacao de uma lista dinamica.
* -> listar, inserir, remover.
* Aluna: Emmanuella Faustino Albuquerque
*******************************************************************************/

// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Tipos
struct caixa{
int dado;
struct caixa *prox;
};

// Prototipos
void menu();
void criaLista(struct caixa **lista);
int validaEntrada(char novamente[2]);
int listar(struct caixa **lista);
int listar(struct caixa **lista);
void limpar(struct caixa **lista);
int ehVazia(struct caixa **lista);
int insereInicio(struct caixa **lista);
int insereFinal(struct caixa **lista);
int removeUltimoElemento(struct caixa **lista);
int removePrimeiroElemento(struct caixa **lista);
int contatenaLista(struct caixa **lista1, struct caixa **lista2);
void criaListaPContatenacao(struct caixa **lista1, struct caixa **lista2);

/*---------------------------------------- Main -------------------------------------------*/
int main(){

    struct caixa *lista, *lista1, *lista2; // lista principal e lista2
    criaLista(&lista); // cria a lista principal
    criaListaPContatenacao(&lista1, &lista2); // cria uma lista auxiliar de concatenacao

    char opcao[2]; // variavel de validacao para continuar no programa
    menu(); // apresenta o menu no console

    printf("Digite a opcao desejada: "); // pede a escolha com base no menu
    scanf("%s", opcao); // opcao, pelos indices

    while(validaEntrada(opcao)){ // se a funcao for verdadeira continua

        switch (opcao[0]){ // analisa a opcao escolhida

            case '1': // entrada 1 == inserir no Inicio
                if(insereInicio(&lista)) printf("Inserido no inicio da lista com sucesso!\n");
                else printf("Nao foi possivel alocar espaço!\n");
                break;

            case '2': // entrada 2 == inserir no Final
                if(insereFinal(&lista)) printf("Inserido no final da lista com sucesso!\n");
                else printf("Nao foi possivel alocar espaço!\n");
                break;

            case '3': // entrada 3 == remover do Inicio
                if(removePrimeiroElemento(&lista)){
                    printf("Removido do inicio da lista com sucesso!\n");
                    }
                else printf("Lista vazia!\n");
                break;

            case '4': // entrada 4 == remover do Final
                if(removeUltimoElemento(&lista)) printf("Removido do final da lista com sucesso!\n");
                else printf("Lista vazia!\n");
                break;

            case '5': // entrada 5 == limpar lista principal
                limpar(&lista);
                break;

            case '6': // entrada 6 == apresentar lista principal no console
                listar(&lista);
                break;

            case '7': // entrada 7 == concatenar lista principal com uma outra lista
                contatenaLista(&lista1, &lista2);
                break;

            case '8': // caso 8, encerra o programa
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
    printf("\\------------------- MENU ------------------\\ \n");
    printf("|         1. Inserir no inicio da lista     |\n");
    printf("|         2. Inserir no fim da lista        |\n");
    printf("|         3. Remover do inicio da lista     |\n");
    printf("|         4. Remover do fim da lista        |\n");
    printf("|         5. Esvaziar lista                 |\n");
    printf("|         6. Ver conteudo da lista          |\n");
    printf("|         7. Concatenar listas              |\n");
    printf("|         8. Sair                           |\n");
    printf("\\-------------------------------------------\\ \n\n");

    }

/**
* Cria/Constroe lista.
**/
void criaLista(struct caixa **lista){

    *lista = 0; // colocando NULL ou 0.

}

/**
* Exibe o conteudo da lista.
**/
int listar(struct caixa **lista){

    struct caixa *laux; // lista auxiliar
    int i; // contador
    laux = *lista;

    if(laux == NULL){ // Se a lista estiver vazia. Então, não tem como lista-la.
        printf("LISTA VAZIA!\n");
        return 0;
        }

    // Apresenta o conteudo da lista no console:
    printf("------------------- Lista ---------------------\n");

    // Enquando existir elementos na lista:
    for(laux = *lista, i = 1; laux!=0; laux = laux->prox, i++){
            printf("%d - %d\n", i, laux->dado); // mostra o elemento e o contador
    }
    printf("-----------------------------------------------\n\n");
    return 1;

}

/***
** Verifica se a lista esta vazia.
*/
int ehVazia(struct caixa **lista){

    if(*lista == 0) return 1; // Se estiver vazia, retorna 1
    else return 0; // Se tiver algo dentro dela, retorna 0

    }

/***
** Limpa/Apaga o conteudo da lista dinamica.
*/
void limpar(struct caixa **lista){

    struct caixa *laux; // lista auxiliar

    for(laux = *lista; laux != 0; laux = *lista){ // Percorre toda a lista ate remover tudo
    *lista = laux->prox; // atualiza a lista para o proximo elemento
    free(laux);          // remove o elemento anterior
    }

    printf("Lista esvaziada com sucesso!\n");

    }

/***
** Remove o ultimo elemento da lista dinamica.
 */
int removeUltimoElemento(struct caixa **lista){

    struct caixa *laux, *anterior; // lista auxiliar e lista auxiliar anterior

    if(ehVazia(lista)) return 0; // verifica se a lista eh vazia, se for sai da função

    for(laux = *lista; laux->prox != 0; anterior = laux, laux = laux->prox); // vai até o ultimo elemento da lista
        printf("Removeu ultimo elemento: %d\n", laux->dado);

        if(laux == *lista) *lista = 0; // se tiver somente um elemento
        else anterior->prox = 0; // Se tiver mais elementos, atualiza ponteiro do elemento anterior para zero

        free(laux); // libera o ultimo elemento da lista

}

/***
** Remove o primeiro elemento da lista dinamica.
*/
int removePrimeiroElemento(struct caixa **lista){

    struct caixa *laux; // lista auxiliar

    if(ehVazia(lista)) return 0; // verifica se a lista eh vazia, se for sai da função

    laux = *lista; // atualiza lista auxiliar com o elemento que lista aponta
    printf("Removeu primeiro elemento: %d\n", laux->dado);
    *lista = laux->prox; // lista aponta para o proximo elemento
    free(laux); // exclui primeiro elemento da lista

    }

/***
** Insere no inicio da lista dinamica.
*/
int insereInicio(struct caixa **lista){

    struct caixa *laux; // lista auxiliar

    // Aloca espaço para a lista aux:
    laux = (struct caixa*)malloc(sizeof(struct caixa));

    if(!laux){ // Verifica se foi alocado.
        printf("Memoria Indisponivel!");
        return 0; // se nao houve inserçao retorna 0
    }

    // Pega o numero inserido pelo usuario para adicionar na lista:
    printf("Digite o numero que deseja adicionar: ");
    scanf("%d", &laux->dado);
    laux->prox = *lista; // adiciona o elemento ao resto da lista aux

    *lista = laux; // atualiza a lista com o novo primeiro elemento.
    return 1; // se a insercao ocorreu bem retorna 1.

}

/***
** Insere no final da lista dinamica.
*/
int insereFinal(struct caixa **lista){

    struct caixa *novo, *laux; // novo elemento, lista aux

    // Aloca espaço para o novo elemento:
    novo = (struct caixa*)malloc(sizeof(struct caixa));
    if(!novo) return 0; // nao foi possivel alocar

    if(ehVazia(lista)){ // se nao tem nenhum elemento na lista
        insereInicio(lista); // entao eh a mesma coisa de add no inicio ou fim
        return 1; // retorna 1 se add com sucesso
    }

    // Recebe o dado que o usuario deseja adicionar no final:
    printf("Digite o numero que deseja adicionar: ");
    scanf("%d", &novo->dado);

    for(laux = *lista; laux->prox != 0; laux = laux->prox); // vai até o ultimo elemento da lista
    laux->prox = novo; // adiciona um novo elemento ao final da lista
    novo->prox = 0; // e define o novo ponto final

    return 1; // retorna 1 se add com sucesso

    }

/**
* Cria/Constroe lista de contatenacao.
**/
void criaListaPContatenacao(struct caixa **lista1, struct caixa **lista2){

     struct caixa *lAux1, *lAux2; // lista auxiliar

     // Aloca lista1
     *lista1 = (struct caixa*)malloc(sizeof(struct caixa));

        if(!*lista1){ // Caso a alocacao nao funcione.
            printf("Memoria Indisponivel!");
            exit(0);
            }

    // cria uma mini lista:
    lAux1->dado = 666;
    lAux1->prox = 0;
    *lista1 = lAux1;

     // Aloca lista2
     *lista2 = (struct caixa*)malloc(sizeof(struct caixa));

        if(!*lista2){ // Caso a alocacao nao funcione.
            printf("Memoria Indisponivel!");
            exit(0);
            }

    // cria uma mini lista:
    lAux2->dado = 222;
    lAux2->prox = 0;
    *lista2 = lAux2;
}

/**
* Concatena listas. Nesse caso, 2 mini-listas.
**/
int contatenaLista(struct caixa **lista1, struct caixa **lista2){

    struct caixa *listaPrint, *lAux; // lista auxiliar

    if(ehVazia(lista1) == 0 && ehVazia(lista2) == 0){ // se nenhuma das 2 lista for vazias

    for(listaPrint = *lista1; listaPrint->prox != 0; listaPrint = listaPrint->prox); // vai até o ultimo elemento da lista
    lAux = *lista2;
    listaPrint->prox = *lista2; // adiciona um novo elemento ao final da lista

    printf("Concatenacao bem sucedida!\n");
    listar(&listaPrint); // mostra a lista concatenada no console

    listaPrint->prox = 0;
    free(lista1);
    free(lista2);

    return 1; // retorna 1, se concatenacao bem sucedida.

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

