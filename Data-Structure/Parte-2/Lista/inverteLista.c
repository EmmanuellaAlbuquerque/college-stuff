/******************************************************************************
INVERTER LISTA
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
void criaLista(struct caixa **lista);
int listar(struct caixa **lista);
int insereInicio(struct caixa **lista);
int insereFinal(struct caixa **lista);
struct caixa *inverte(struct caixa **lista);
int somaLista(struct caixa **lista);
void insereOrdenado(struct caixa **lista, int valor);

/*---------------------------------------- Main -------------------------------------------*/
int main(){

    struct caixa *lista; // lista principal e lista2
    criaLista(&lista); // cria a lista principal
    insereFinal(&lista);
    insereFinal(&lista);
    insereFinal(&lista);
    lista = inverte(&lista);
    //insereOrdenado(&lista, 15);
    //insereOrdenado(&lista, 11);
    //insereOrdenado(&lista, 10);

    listar(&lista);
    //printf("%d", somaLista(&lista));

    return 0;
}

struct caixa *inverte(struct caixa **lista){
  struct caixa *aux, *laux, *nova=NULL, *ant=NULL;

  while((*lista) != NULL){
    ant=NULL;
    for(aux = *lista; aux->prox != NULL; ant = aux, aux = aux->prox);
    if(nova == NULL)
      nova = aux;
    else{
      for(laux=nova; laux->prox != 0; laux=laux->prox);
      laux->prox = aux;
    }
    
    if(ant)
      ant->prox = NULL;
    else{
      (*lista) = NULL;
    }
    
  }

  return nova;
}

int somaLista(struct caixa **lista){
  struct caixa *aux;
  int soma = 0;
  for(aux = *lista; aux!=NULL; aux = aux->prox){
    soma += aux->dado;
  }
  return soma;
}

void insereOrdenado(struct caixa **lista, int valor){
  struct caixa *aux = *lista, *nova, *ant=NULL;
  nova = (struct caixa*) malloc(sizeof(struct caixa));
  if(!nova) return;
  nova->dado = valor;
  
  if(aux == NULL){ // lista vazia
    (*lista) = nova;
    nova->prox = NULL;
  }
  else{
  for(aux = *lista; aux != NULL; ant = aux, aux = aux->prox){
    if(aux->dado > valor){ // achou valor maior
      break;
    }
    }
    
    if(aux == (*lista)){ // comeco
      nova->prox = (*lista);
      (*lista) = nova;
      return;
    }

    if(aux == NULL){ // fim
      ant->prox = nova;
      nova->prox = NULL;
      return;
    }

    if(ant != NULL){ // meio
      ant->prox = nova;
      nova->prox = aux;
      return;
    }
    
  }
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
    laux = *lista;

    if(laux == NULL){ // Se a lista estiver vazia. Então, não tem como lista-la.
        printf("LISTA VAZIA!\n");
        return 0;
        }

    // Apresenta o conteudo da lista no console:
    printf("------------------- Lista ---------------------\n");

    // Enquando existir elementos na lista:
    for(laux = *lista; laux!=0; laux = laux->prox){
            printf("%d\n", laux->dado); // mostra o elemento e o contador
    }
    printf("-----------------------------------------------\n\n");
    return 1;

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

    if((*lista) == NULL){ // se nao tem nenhum elemento na lista
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

