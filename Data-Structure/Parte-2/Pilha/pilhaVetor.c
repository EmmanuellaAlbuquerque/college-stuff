/******************************************************************************
* Estrutura de dados: Implementacao de uma pilha estática.
* Aluna: Emmanuella Faustino Albuquerque
*******************************************************************************/

// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

// Tipos
struct pilha{

    /* VARIAVEIS PARA REPRESENTACAO DA LISTA*/
    int pilhaDados[MAX]; // info
    int lp; // controle de ocupacao

};

// Prototipos
void menu();
void criarPilha(struct pilha *p);
int ehVazia(struct pilha *p);
void esvaziar(struct pilha *p);
void listar(struct pilha *p);
int push(int entradaUsuario, struct pilha *p);
int pop(struct pilha *p);
int tamanhoPilha(struct pilha *p);
void consulta_Ultimo(struct pilha *p);
int validaEntrada(char novamente[2]);

/*################################################ MAIN ##################################################*/
int main(){

    struct pilha p;
    int entradaUsuario; // variaveis do usuario
    char opcao[2]; // variavel de validacao para continuar no programa

    criarPilha(&p);

    menu(); // apresenta o menu no console
    printf("Digite a opcao desejada: "); // pede a escolha com base no menu
    scanf("%s", opcao); // opcao, pelos indices

    while(validaEntrada(opcao)){ // se a funcao for verdadeira continua

    switch (opcao[0]){ // analisa a opcao escolhida

        case '1':
        printf("Digite o numero que deseja guardar na pilha: ");
        scanf("%d", &entradaUsuario);
        if(push(entradaUsuario, &p)) printf("Inserido com sucesso!\n");
        break;

        case '2':
        if(pop(&p)) printf("Removido com sucesso!\n");
        else printf("Pilha vazia!\n");
        break;

        case '3':
        if(ehVazia(&p)) printf("A pilha esta vazia!\n");
        else printf("O tamanho da pilha eh: %d\n", tamanhoPilha(&p));
        break;

        case '4':
        esvaziar(&p);
        printf("Pilha esvaziada com sucesso!\n");
        break;

        case '5':
        consulta_Ultimo(&p);
        printf("Pilha consultada com sucesso!\n");
        break;

        case '6':         // caso 4, encerra o programa
        printf("Programa Encerrado!\n");
        exit(0);    // return(exit(0);

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
    printf("------------------- MENU ------------------\n");
    printf("1. Push - Inserir no fim da pilha\n");
    printf("2. Pop - Remover do fim da pilha\n");
    printf("3. Tamanho da pilha\n");
    printf("4. Esvaziar pilha\n");
    printf("5. Cunsulta - Ultimo\n");
    printf("6. Sair\n");
    printf("-------------------------------------------\n\n");

}

/**
* Cria a pilha.
**/
void criarPilha(struct pilha *p){
    p->lp = 0; // define/cria a pilha, como vazia.
}

/**
* Verifica se a pilha eh vazia.
**/
int ehVazia(struct pilha *p){
    // se a variavel de controle de ocupacao for 0, a pilha esta vazia.
    if(p->lp == 0){
        return 1; // retorna 1, se for vazia
    }
    return 0; // retorna 0, se nao for vazia
}

/**
* Esvazia a pilha.
**/
void esvaziar(struct pilha *p){
    p->lp = 0; // define que a pilha tem 0 elementos.
}

/**
* Mostra o conteudo da pilha.
**/
void listar(struct pilha *p){

    int i; // contador
    printf("Elementos da pilha\n");

    // Se a pilha nao for vazia (ou seja, 0), !0 = true
    if(!ehVazia(p)){
        // percorre dado o controle de ocupacao
        for(i = 0; i < tamanhoPilha(p); i++){
            printf("%d - %d\n", i, p->pilhaDados[i]);
        }
    }
    else{
            printf("Pilha vazia!\n");
        }
}

/**
* Insere conteudo no final da pilha.
**/
int push(int entradaUsuario, struct pilha *p){ // Insere no final da pilha

    /* Dado o tamanho de lp(variavel de controle de ocupacao),
    eh inserido no final da pilha*/
    p->pilhaDados[tamanhoPilha(p)] = entradaUsuario;
    p->lp = p->lp + 1; // incrementa o tamanho da pilha
    return 1; // retorna 1, se foi inserido com sucesso

}

/**
* Remove conteudo do final da pilha.
**/
int pop(struct pilha *p){ // remover do final da pilha
    // Se a pilha nao for vazia (ou seja, 0), !0 = true
    if(!ehVazia(p)){
    p->lp = p->lp - 1; // decrementa o indice de ocupacao
    return 1; // retorna 1, se removido com sucesso
    }
    return 0; // retorn 0, se nao for removida
}

/**
* Retorna o tamanho da pilha. Dada a variavel de controle de ocupacao.
**/
int tamanhoPilha(struct pilha *p){
    return p->lp; // tamanho pilha
}

void consulta_Ultimo(struct pilha *p){

    if(!ehVazia(p)){
        printf("Topo -> %d\n", p->pilhaDados[0]);
    }
    else{
        printf("Pilha vazia!\n");
    }
}

/***
** Valida a condicao de parado do loop principal.
*/
int validaEntrada(char novamente[2]){

    int x, flag; // contador e flag
    flag = 1;    // inicialmente a entrada eh valida
    for(x = 0; x < strlen(novamente); x++){ // porem, se a entrada n for '0' nem '1'
    if(novamente[x] < '0' || novamente[x] > '9'){
        flag = 0; // entao a entrada eh invalida
        return flag; // retorna invalido, 0
    }

}
    return flag; // retorna valido, 1
}
