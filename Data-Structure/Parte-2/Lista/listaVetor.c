/******************************************************************************
* Estrutura de dados: Implementacao de uma lista estática.
* Aluna: Emmanuella Faustino Albuquerque
*******************************************************************************/

// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

// Tipos
struct lista{
    
    /* VARIAVEIS PARA REPRESENTACAO DA LISTA*/
    int listaDados[MAX]; // info
    int lp; // controle de ocupacao
    
};

// Prototipos
void menu();
void criarLista(struct lista *l);
int ehVazia(struct lista *l);
void esvaziar(struct lista *l);
void listar(struct lista *l);
int insereFinal(int entradaUsuario, struct lista *l);
int removeInicio(struct lista *l);
int removeFinal(struct lista *l);
int tamanhoLista(struct lista *l);
int validaEntrada(char novamente[2]);
int removeDado(int entradaUsuario, struct lista *l);
int insereOrdenado(int entradaUsuario, struct lista *l);
int insereInicio(int entradaUsuario, struct lista *l);

/*################################################ MAIN ##################################################*/
int main(){

    struct lista l;
    int entradaUsuario; // variaveis do usuario
    char opcao[2]; // variavel de validacao para continuar no programa

    criarLista(&l);

    menu(); // apresenta o menu no console
    printf("Digite a opcao desejada: "); // pede a escolha com base no menu
    scanf("%s", opcao); // opcao, pelos indices

    while(validaEntrada(opcao)){ // se a funcao for verdadeira continua

    switch (opcao[0]){ // analisa a opcao escolhida

        case '0':
            printf("Digite o numero que deseja guardar na lista: ");
            scanf("%d", &entradaUsuario);
            //insereInicio(entradaUsuario);
            if(insereInicio(entradaUsuario, &l)) printf("Inserido com sucesso!\n");
            break;

        case '1':
        printf("Digite o numero que deseja guardar na lista: ");
        scanf("%d", &entradaUsuario);
        if(insereFinal(entradaUsuario, &l)) printf("Inserido com sucesso!\n");
        break;

        case '2':
            if(removeInicio(&l)) printf("Removido com sucesso!\n");
        else printf("Lista vazia!\n");
        break;

        case '3':
        if(removeFinal(&l)) printf("Removido com sucesso!\n");
        else printf("Lista vazia!\n");
        break;

        case '4':
        if(ehVazia(&l)) printf("A lista esta vazia!\n");
        else printf("O tamanho da lista eh: %d\n", tamanhoLista(&l));
        break;

        case '5':
        esvaziar(&l);
        printf("Lista esvaziada com sucesso!\n");
        break;

        case '6':
        printf("-----------------------------------------------\n");
        listar(&l);
        printf("-----------------------------------------------\n");
        break;

        case '7':
            printf("Digite o numero que deseja guardar ordenado na lista: ");
            scanf("%d", &entradaUsuario);
            if(insereOrdenado(entradaUsuario, &l)) printf("Inserido com sucesso!\n");
            break;
            
        case '8':
            printf("Digite o numero que deseja remover da lista: ");
            scanf("%d", &entradaUsuario);
            if(removeDado(entradaUsuario, &l)) printf("Removido com sucesso!\n");
            break;
            
        case '9':         // caso 4, encerra o programa
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
    printf("0. Inserir no inicio da lista\n");
    printf("1. Inserir no fim da lista\n");
    printf("2. Remover do inicio da lista\n");
    printf("3. Remover do fim da lista\n");
    printf("4. Tamanho da lista\n");
    printf("5. Esvaziar lista\n");
    printf("6. Ver conteudo da lista\n");
    printf("7. Inserir de forma ordenada\n");
    printf("8. Remove dado desejado da lista\n");
    printf("9. Sair\n");
    printf("-------------------------------------------\n\n");

}

/**
* Cria a lista.
**/
void criarLista(struct lista *l){
    l->lp = 0; // define/cria a lista, como vazia.
}

/**
* Verifica se a lista eh vazia.
**/
int ehVazia(struct lista *l){
    // se a variavel de controle de ocupacao for 0, a lista esta vazia.
    if(l->lp == 0){
        return 1; // retorna 1, se for vazia
    }
    return 0; // retorna 0, se nao for vazia
}

/**
* Esvazia a lista.
**/
void esvaziar(struct lista *l){
    l->lp = 0; // define que a lista tem 0 elementos.
}

/**
* Mostra o conteudo da lista.
**/
void listar(struct lista *l){

    int i; // contador
    printf("Elementos da lista\n");

    // Se a lista nao for vazia (ou seja, 0), !0 = true
    if(!ehVazia(l)){
        // percorre dado o controle de ocupacao
        for(i = 0; i < tamanhoLista(l); i++){
            printf("%d - %d\n", i, l->listaDados[i]);
        }
    }
    else{
            printf("Lista vazia!\n");
        }
}

/**
* Insere conteudo no final da lista.
**/
int insereFinal(int entradaUsuario, struct lista *l){ // Insere no final da lista

    /* Dado o tamanho de lp(variavel de controle de ocupacao),
    eh inserido no final da lista*/
    l->listaDados[tamanhoLista(l)] = entradaUsuario;
    l->lp = l->lp + 1; // incrementa o tamanho da lista
    return 1; // retorna 1, se foi inserido com sucesso

}

/**
* Insere conteudo no inicio da lista.
**/
int insereInicio(int entradaUsuario, struct lista *l){ // Insere no inicio da lista

    /* Dado o tamanho de lp(variavel de controle de ocupacao),
    eh inserido no inicio da lista*/

    int aux;

   // if(!ehVazia()){
        
        for(aux = l->lp; aux <= 0; aux--){
            l->listaDados[aux+1] = l->listaDados[aux];
    
    //}

    l->listaDados[0] = entradaUsuario;
    l->lp++;

    return 1; // retorna 1, se foi inserido com sucesso
    
    }
    
    //else{
        
       // listaDados[0] = entradaUsuario;
       // lp++;
       // return 1;
        
  //  }



}

/**
* Insere conteudo de forma ordenada na lista, isto eh do menor para o maior.
**/
int insereOrdenado(int entradaUsuario, struct lista *l){ 

    // Primeiro iremos verificar se a lista esta vazia 
    // caso esteja adionaremos o 1 elemento

    if(l->lp >= MAX){
        printf("Lista Cheia\n");
        return 0;
    }
    else{

        int posicao;
        for(posicao = l->lp; posicao > 0, l->listaDados[posicao-1] > entradaUsuario; posicao--){
            l->listaDados[posicao] = l->listaDados[posicao-1];
        }

        l->listaDados[posicao] = entradaUsuario;
        l->lp++;

    }

}

/**
* Remove conteudo de acordo com o dado passado pelo usuario.
**/
int removeDado(int entradaUsuario, struct lista *l){
    
    if(ehVazia(l)){
        printf("Lista vazia!\n");
        return 0;
    }
    
    int posicao;
    for(posicao = 0; posicao >= 0, posicao < l->lp, l->listaDados[posicao] != entradaUsuario; posicao++){
        if(posicao == l->lp && l->listaDados[posicao] != entradaUsuario){
            printf("Dado nao encontrado!\n");
            return 0;
        }
    }

    if(posicao == 0){
        printf("Removendo Inicio\n");
        removeInicio(l);
        return 1;
    } 
    if(posicao == l->lp){
        printf("Removendo Final\n");
        removeFinal(l);
        return 1;
    }

    printf("Removendo Meio\n");
    l->listaDados[posicao] = l->listaDados[posicao+1];
    l->lp--;
    
}


/**
* Remove conteudo do final da lista.
**/
int removeFinal(struct lista *l){ // remover do final da lista
    // Se a lista nao for vazia (ou seja, 0), !0 = true
    if(!ehVazia(l)){
    l->lp = l->lp - 1; // decrementa o indice de ocupacao
    return 1; // retorna 1, se removido com sucesso
    }
    return 0; // retorn 0, se nao for removida
}


/**
* Remove conteudo do inicio da lista.
**/
int removeInicio(struct lista *l){ // remover do inicio da lista
    // Se a lista nao for vazia (ou seja, 0), !0 = true

    if(ehVazia(l)){
        printf("Lista vazia!\n");
        return 0;
    } 

    int posicao;

    for(posicao = 0; posicao < l->lp; posicao++){
        l->listaDados[posicao] = l->listaDados[posicao+1];
    }
    l->lp--;
}

/**
* Retorna o tamanho da lista. Dada a variavel de controle de ocupacao.
**/
int tamanhoLista(struct lista *l){
    return l->lp; // tamanho lista
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