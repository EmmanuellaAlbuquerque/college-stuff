/******************************************************************************
* Estrutura de dados: Implementacao de uma lista dinamica duplamente encadeada.
* Aluna: Emmanuella Faustino Albuquerque
*******************************************************************************/

// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Tipos
struct caixa{
struct caixa *ant;
float dado;
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
int insereInicio(float valor, struct caixa **lista);
int insereFinal(float valor, struct caixa **lista);
int insereOrdenado(float valor, struct caixa **lista);
int inverteLista(struct caixa **lista);
int removeUltimoElemento(struct caixa **lista);
int removePrimeiroElemento(struct caixa **lista);
int contatenaLista(struct caixa **lista1, struct caixa **lista2);
void criaListaPContatenacao(struct caixa **lista1, struct caixa **lista2);

/*------------------------------------------------ MAIN -------------------------------------------------*/
int main(){

    float valor;
    struct caixa *lista, *lista1, *lista2; // lista principal e lista2
    criaLista(&lista); // cria a lista principal

    int opcao; // variavel de validacao para continuar no programa
    menu(); // apresenta o menu no console

    printf("Digite a opcao desejada: "); // pede a escolha com base no menu
    scanf("%d", &opcao); // opcao, pelos indices

    while(opcao != 10){ // se a funcao for verdadeira continua

        switch (opcao){ // analisa a opcao escolhida

            case 1: // inserir no Inicio
                printf("Digite o valor que deseja inserir de forma ordenada: ");
                scanf("%f", &valor);
                if(insereInicio(valor, &lista)) printf(" ");
                else printf("Nao foi possivel alocar espaço!\n");
                lista->ant = 0;
                break;

            case 2: // inserir no Final
                printf("Digite o valor que deseja inserir de forma ordenada: ");
                scanf("%f", &valor);
                if(insereFinal(valor, &lista)) printf("Inserido no final da lista com sucesso!\n");
                else printf("Nao foi possivel alocar espaço!\n");
                break;

            case 3: // remover do Inicio
                if(removePrimeiroElemento(&lista)){
                    printf("Removido do inicio da lista com sucesso!\n");
                    }
                else printf("Lista vazia!\n");
                break;

            case 4: // remover do Final
                if(removeUltimoElemento(&lista)) printf("Removido do final da lista com sucesso!\n");
                else printf("Lista vazia!\n");
                break;

            case 5: // limpar lista principal
                limpar(&lista);
                break;

            case 6: // apresentar lista principal no console
                listar(&lista);
                break;

            case 7: //
                printf("Digite o valor que deseja inserir de forma ordenada: ");
                scanf("%f", &valor);
                insereOrdenado(valor, &lista);
                break;

            case 8: //
                inverteLista(&lista);
                break;

            case 9:
                criaListaPContatenacao(&lista1, &lista2); // cria uma duas listas auxiliares para concatenacao
                contatenaLista(&lista1, &lista2); // concatena as 2 listas criadas
                break;

            case 10: // caso 9, encerra o programa
                printf("PROGRAMA ENCERRADO!\n");
                exit(0); // return(exit(0);

                }

    menu(); // apresenta o menu no console
    printf("Digite a opcao desejada: "); // pede a escolha com base no menu
    scanf("%d", &opcao); // opcao, pelos indices

    }

    return 0;
}

/*---------------------------------------- CRIA MENU PARA O CONSOLE ------------------------------------*/
void menu(){

    // MENU do programa
    printf("|------------------- MENU ------------------|\n");
    printf("|         1. Inserir no inicio da lista     |\n");
    printf("|         2. Inserir no fim da lista        |\n");
    printf("|         3. Remover do inicio da lista     |\n");
    printf("|         4. Remover do fim da lista        |\n");
    printf("|         5. Esvaziar lista                 |\n");
    printf("|         6. Ver conteudo da lista          |\n");
    printf("|         7. Insere de forma ordenada       |\n");
    printf("|         8. Inverte a ordem da Lista       |\n");
    printf("|         9. Inverte a ordem da Lista       |\n");
    printf("|         10. Sair                           |\n");
    printf("|-------------------------------------------|\n\n");

    }


/*---------------------------------------------- CRIA LISTA ---------------------------------------------*/
void criaLista(struct caixa **lista){

    *lista = 0; // colocando NULL ou 0.

}

void criaListaPContatenacao(struct caixa **lista1, struct caixa **lista2){

    *lista1 = 0;
    *lista2 = 0;

    insereOrdenado(1, lista1);
    insereOrdenado(2, lista1);
    insereOrdenado(3, lista1);

    insereOrdenado(4, lista2);
    insereOrdenado(5, lista2);
    insereOrdenado(6, lista2);

}

/*---------------------------------------- EXIBE O CONTEUDO DA LISTA ------------------------------------*/
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
            printf("%d - %f\n", i, laux->dado); // mostra o elemento e o contador
    }
    printf("-----------------------------------------------\n\n");
    return 1;

}

/*-------------------------------------- VERIFICA SE A LISTA ESTA VAZIA ---------------------------------*/
int ehVazia(struct caixa **lista){

    if(*lista == 0) return 1; // Se estiver vazia, retorna 1
    else return 0; // Se tiver algo dentro dela, retorna 0

    }

/*------------------------------------ LIMPA/APAGA O CONTEUDO DA LISTA -----------------------------------*/
void limpar(struct caixa **lista){

    struct caixa *laux; // lista auxiliar

    for(laux = *lista; laux != 0; laux = *lista){ // Percorre toda a lista ate remover tudo
    *lista = laux->prox; // atualiza a lista para o proximo elemento
    free(laux);          // remove o elemento anterior
    }

    printf("Lista esvaziada com sucesso!\n");

    }

/*----------------------------------- REMOVE O ULTIMO ELEMENTO DA LISTA ----------------------------------*/
int removeUltimoElemento(struct caixa **lista){

    struct caixa *laux, *anterior; // lista auxiliar e lista auxiliar anterior

    if(ehVazia(lista)) return 0; // verifica se a lista eh vazia, se for sai da função

    for(laux = *lista; laux->prox != 0; anterior = laux, laux = laux->prox); // vai até o ultimo elemento da lista
        printf("Removeu ultimo elemento: %f\n", laux->dado);

        if(laux == *lista) *lista = 0; // se tiver somente um elemento
        else anterior->prox = 0; // Se tiver mais elementos, atualiza ponteiro do elemento anterior para zero

        free(laux); // libera o ultimo elemento da lista

}


/*----------------------------------- REMOVE O PRIMEIRO ELEMENTO DA LISTA --------------------------------*/
int removePrimeiroElemento(struct caixa **lista){

    struct caixa *laux; // lista auxiliar

    if(ehVazia(lista)) return 0; // verifica se a lista eh vazia, se for sai da função

    laux = *lista; // atualiza lista auxiliar com o elemento que lista aponta
    printf("Removeu primeiro elemento: %f\n", laux->dado);
    *lista = laux->prox; // lista aponta para o proximo elemento
    free(laux); // exclui primeiro elemento da lista

    }


/*------------------------------------- INSERE NO INICIO DA LISTA ----------------------------------------*/
int insereInicio(float valor, struct caixa **lista){

    struct caixa *laux; // lista auxiliar

    // Aloca espaço para a lista aux:
    laux = (struct caixa*)malloc(sizeof(struct caixa));

    if(!laux){ // Verifica se foi alocado.
        printf("Memoria Indisponivel!");
        return 0; // se nao houve inserçao retorna 0
    }
    if(*lista == NULL){ // caso seja o primeiro elemento a ser adicionado
        laux->ant = NULL;
        laux->dado = valor;
        laux->prox = *lista;
        printf("-> LISTA CRIADA COM SUCESSO\n");
        printf("Inserido no inicio da lista com sucesso!\n");
    }
    else{
    // Pega o numero inserido pelo usuario para adicionar na lista:
    printf("Digite o numero que deseja adicionar: ");
    scanf("%f", &laux->dado);
    laux->prox = *lista; // adiciona o elemento ao resto da lista aux
    laux->ant = NULL; // tanto o elemento final quanto o inicial tem pelo menos um ponteiro para NULL
    (*lista)->ant = laux;
    printf("Inserido no inicio da lista com sucesso!\n");
}

    *lista = laux; // atualiza a lista com o novo primeiro elemento.

    return 1; // se a insercao ocorreu bem retorna 1.

}

/*--------------------------------------- INSERE NO FINAL DA LISTA ---------------------------------------*/
int insereFinal(float valor, struct caixa **lista){

    struct caixa *novo, *laux = *lista, *anterior; // novo elemento, lista aux

    // Aloca espaço para o novo elemento:
    novo = (struct caixa*)malloc(sizeof(struct caixa));
    if(!novo) return 0; // nao foi possivel alocar

    if(ehVazia(lista)){ // se nao tem nenhum elemento na lista
        insereInicio(valor, lista); // entao eh a mesma coisa de add no inicio ou fim
        return 1; // retorna 1 se add com sucesso
    }

    novo->dado = valor;
    laux->ant = 0;
    for(laux = *lista; laux->prox != 0; anterior = laux, laux = laux->prox); // vai até o ultimo elemento da lista
    laux->prox = novo; // adiciona um novo elemento ao final da lista
    laux->ant = anterior;
    novo->prox = 0; // e define o novo ponto final
    novo->ant = laux;

    return 1; // retorna 1 se add com sucesso

    }

/*---------------- INSERE DADOS NA LISTA DE FORMA ORDENADA, ISTO EH DO MENOR PARA O MAIOR ----------------*/
int insereOrdenado(float valor, struct caixa **lista){

    int i = 0; // contador
    struct caixa *nova, *busca = *lista, *anterior = NULL, *inicio = *lista, *aux; // listas auxiliares

    if(busca == NULL){ // se a lista for vazia
        insereInicio(valor, lista); // insere no inicio
        return 0;
     }

    nova = (struct caixa*)malloc(sizeof(struct caixa)); // malloc para o novo elemento da lista

    if(nova){ // verifica se o malloc foi bem sucessedido

        nova->dado = valor;  // atribui a struct
        /*
        for(busca = *lista; busca, busca->dado < valor; busca = busca->prox);

        // Insere meio
        nova->prox = busca;
        nova->ant = busca->ant;
        busca->ant = nova;
        nova->ant->prox = nova;  */

        if(busca->dado > valor){ // se o 1 valor da lista for maior, adiciona antes dele
            insereInicio(valor, lista);
            return 0;
        }
        /*procura posicao para insercao*/
        while(busca != NULL && busca->dado < valor)
        {
            aux = anterior;
            anterior = busca;     // atualiza o anterior
            busca = busca->prox; // atualiza ate encontrar a posicao ordenada
        }
        /*insere elemeto*/
        if(inicio->prox == NULL) /*insere no comeco*/
        {
            printf("Inserindo no comeco\n");
            nova->ant = inicio;     // define o anterior do novo elemento
            inicio->ant = 0;        // define o anterior do 1 elemento como NULL
            inicio->prox = nova;    // define o prox do 1 elemento
            nova->prox = NULL;      // define o prox do novo elemento
            return 0;
        }
        else /*insere no meio/fim*/
        {
            printf("Inserindo no meio e fim\n");

            anterior->prox = nova; // valor < busca->dado, define novo elemento p anterior
            anterior->ant = aux;   // elemento ant de anterior eh atualizado

            nova->prox = busca;    // valor > busca->dado, define nova como busca(busca==0 ou busca>valor)
            nova->ant = anterior;  // atualiza com o anterior
            return 0;
        }

    }

}


/*----------------------------------------- INVERTE A ORDEM DA LISTA -------------------------------------*/
int inverteLista(struct caixa **lista){

    struct caixa *busca = *lista, *aux; // listas auxiliares

    if(!busca){ //verifica a lista
        printf("Lista vazia\n");
        return 0;
    }

    busca->ant = 0;
    if(busca->prox == 0){ // no caso de ser 1 elemento
        return 0; // retorna ao menu
    }
    for(aux = *lista; aux->prox != 0; aux = aux->prox); // vai ate o ultimo elemento da lista
    *lista = aux;   // atualiza a lista com o ultimo elemento
    busca = *lista; // atualiza busca com a lista

    // Altera/inverte o inicio da lista, caso mais de 1 elemento
    aux = busca->ant; // variavel aux, guarda o elemento anterior do ultimo elemento
    busca->prox = busca->ant; // troca o prox com o anterior
    busca->ant = 0; // define o anterior do 1 elemento como NULL
    busca = aux; // define busca com o elemento anterior do ultimo elemento(guardado em aux)

    if(busca->ant == 0){ // no caso de ser 2 elementos
        // Altera/inverte final da lista
        busca->ant = busca->prox; // troca o ponteiros do elemento
        busca->prox = 0; // atualiza o final(ponteiro do ultimo elemento) como NULL
        return 1; // retorna ao menu
    }

    // Altera/inverte o meio e fim da lista
    do{ // no caso de mais de 2 elemento
        aux = busca->prox; // variavel aux, guarda o proximo elemento
        busca->prox = busca->ant; // troca o prox com o anterior
        busca->ant = aux; // usa o aux, variavel que guarda o proximo elemento
        busca = busca->prox; // atualiza a busca, com o proximo elemento
    }while(busca); // ate que chegue ao final(ponteiro do ultimo elemento)

}

/*-------------------------------- CONCATENA LISTAS -----------------------------*/
int contatenaLista(struct caixa **lista1, struct caixa **lista2){

    criaListaPContatenacao(lista1, lista2); // Adiociona elementos nas 2 listas de teste
    listar(lista1); // mostra o conteudo da primeira lista
    listar(lista2); // mostra o conteudo da segunda lista

    struct caixa *laux; // lista auxiliar

    while((*lista2) != 0){ // enquanto conteudo da segunda lista for diferente de NULL

    laux = *lista2; // atualiza lista auxiliar com o elemento que lista2 aponta
    printf("Removeu primeiro elemento: %f\n", laux->dado);
    *lista2 = laux->prox; // lista aponta para o proximo elemento

    insereOrdenado(laux->dado, lista1); // insere de forma ordenada na lista1
    free(laux); // libera o laux(conteudo da lista2)

    }

    listar(lista1); // mostra a lista concatenada na tela

}


/*-------------------------------- VALIDA A CONDICAO DE PARADA DO LOOP PRINCIPAL--------------------------*/
int validaEntrada(char novamente[2]){

    int x, flag; // contador e flag
    flag = 1;

    // inicialmente a entrada eh valida
    for(x = 0; x < strlen(novamente); x++){ // porem, se a entrada n for '0' nem '1'
        if(novamente[x] < '0' || novamente[x] > '9'){
            flag = 0; // entao a entrada eh invalida
            return flag; // retorna invalido, 0
        }
    }

    return flag; // retorna valido, 1

}

