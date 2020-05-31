/* Árvores Binária Encadeada: Usadas para estruturas hierarquicas
*  Ex.: Diretorios do Computador
*/

// Includes
#include <stdio.h>
#include <stdlib.h>

// Tipos
struct no{
    int info; // dado que representa o no
    struct no *sae, *sad; // sub-area esquerda e direita
};

// Prototipos
void menu();
struct no *criaArvore();
void libera_arvore(struct no **raiz);
void libera_no(struct no *no);
int estaVazia(struct no **raiz);
int altura(struct no **raiz);
int totalDeNos(struct no **raiz);
void preOrdem(struct no **raiz);
void emOrdem(struct no **raiz);
void posOrdem(struct no **raiz);
int insere(struct no **raiz, int valor);
struct no* removeAtual(struct no *atual);
int removeBin(struct no **raiz, int valor);

    /*
    struct no *arvoreBinaria;
    arvoreBinaria = criaArvore();
    libera_arvore(&arvoreBinaria);
    printf("A altura da Arvore eh: %d\n", altura(&arvoreBinaria));
    printf("O total de nos eh: %d\n", totalDeNos(&arvoreBinaria));
    preOrdem(&arvoreBinaria);
    emOrdem(&arvoreBinaria);
    posOrdem(&arvoreBinaria);
    if(estaVazia(&arvoreBinaria)){
        printf("Arvore esta vazia!\n");
    }
    insere(&arvoreBinaria, 10);
    insere(&arvoreBinaria, 11);
    insere(&arvoreBinaria, 12);
    posOrdem(&arvoreBinaria);
    removeBin(&arvoreBinaria, 10);
    posOrdem(&arvoreBinaria);
    */

/***************************************************************** MAIN *******************************************************************************/
int main()
{
    struct no *arvoreBinaria;
    arvoreBinaria = criaArvore();
    int opcao, valor;
    menu();
    printf(">>> Digite a opcao escolhida: [0 para sair] ");
    scanf("%d", &opcao);
    while(opcao != 0){
        switch (opcao){
            case 1:
                printf(">>> Digite o valor que deseja inserir: ");
                scanf("%d", &valor);
                insere(&arvoreBinaria, valor);
                printf("\n");
                break;
            case 2:
                printf("Pre-Ordem/Prefix: ");
                preOrdem(&arvoreBinaria);
                printf("\n\n");
                break;
            case 3:
                printf("Em-Ordem/Infix: ");
                emOrdem(&arvoreBinaria);
                printf("\n\n");
                break;
            case 4:
                printf("Pos-Ordem/Posfix: ");
                posOrdem(&arvoreBinaria);
                printf("\n\n");
                break;
            case 5:
                printf("Processando...\n");
                libera_arvore(&arvoreBinaria);
                printf("Limpando Conteudo da Arvore.\nConteudo da arvore LIMPO com sucesso!\n");

    }
    menu();
    printf(">>> Digite a opcao escolhida: [0 para sair] ");
    scanf("%d", &opcao);
    }

}

/*
* Cria a arvore.
*/
struct no *criaArvore(){
    return 0;
}

/*
* Mostra o MENU no console.
*/
void menu(){

    printf("----------------- MENU ------------------\n");
    printf("1. INSERE na Arvore\n");
    printf("2. Mostrar percurso PREFIX\n");
    printf("3. Mostrar percurso INFIX\n");
    printf("4. Mostrar percurso POSFIX\n");
    printf("5. LIBERA arvore\n");
    printf("-----------------------------------------\n");
}

/*
* Libera NO.
*/
void libera_no(struct no *no){
    if(no == NULL) // se no for 0
        return; // retorna
    libera_no(no->sae); // libera todo o lado esquerdo, POSFIX
    libera_no(no->sad); // libera todo o lado direito, POSFIX
    free(no); // libera o no
    no = NULL; // seta final
}

/*
* Libera arvore.
*/
void libera_arvore(struct no **raiz){
    if(raiz == NULL){ // verifica se a arvore esta vazia
        printf("ARVORE VAZIA!");
        return; // se estiver retorna
    }
    libera_no(*raiz); // libera os nos abaixo da raiz, um por um
    // free(raiz); // libera raiz
}

/*
* Verifica se a arvore esta vazia.
*/
int estaVazia(struct no **raiz){
    if(raiz == NULL) // se ela for vazia, retorna 1
        return 1;
    if(*raiz == NULL) // se o conteudo da arvore for vazio, retorna 1
        return 1;
    return 0; // senao, tem algo dentro da arvore
}

int altura(struct no **raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int altEsq = altura(&((*raiz)->sae));
    int altDir = altura(&((*raiz)->sad));
    if (altEsq > altDir)
        return (altEsq + 1);
    else
        return (altDir + 1);

}

int totalDeNos(struct no **raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int altEsq = totalDeNos(&((*raiz)->sae));
    int altDir = totalDeNos(&((*raiz)->sad));
    return(altEsq + altDir + 1);

}

/* Forma de Percorrer: Pre-Ordem:
*  raiz -> esquerda -> direita
*/
void preOrdem(struct no **raiz){
    if(raiz == NULL) // se a arvore for vazia, retorna
        return;
    if(*raiz != NULL){ // se a arvore tiver conteudo
        printf("%d ", (*raiz)->info); // percurso: raiz
        preOrdem(&((*raiz)->sae)); // lado esquerdo da arvore
        preOrdem(&((*raiz)->sad)); // lado direito da arvore
    }
}

/* Forma de Percorrer: Em-Ordem:
*  esquerda -> raiz -> direita
*/
void emOrdem(struct no **raiz){
    if(raiz == NULL) // se a arvore for vazia, retorna
        return;
    if(*raiz != NULL){ // se a arvore tiver conteudo
        emOrdem(&((*raiz)->sae)); // percurso: lado esquerdo
        printf("%d ", (*raiz)->info); // raiz
        emOrdem(&((*raiz)->sad)); // lado direito
    }
}

/* Forma de Percorrer: Pos-Ordem:
*  esquerda -> direita -> raiz
*/
void posOrdem(struct no **raiz){
    if(raiz == NULL) // se a arvore for vazia, retorna
        return;
    if(*raiz != NULL){ // se a arvore tiver conteudo
        posOrdem(&((*raiz)->sae)); // percurso: lado esquerdo
        posOrdem(&((*raiz)->sad)); // lado direito
        printf("%d ", (*raiz)->info); // raiz
    }
}

/*
* Insere na Arvore.
*/
int insere(struct no **raiz, int valor){
    struct no *novo; // cria novo no
    novo = (struct no*)malloc(sizeof(struct no)); // aloca espaco para o novo no
    if(novo == NULL) // se nao foi possivel realizar a alocacao
        return 0; // retorna

    // difine o conteudo inicial do novo no
    novo->info = valor; // adiciona o valor inserido pelo usuario
    novo->sad = NULL; // add NULL inicialmente para o lado direito
    novo->sae = NULL; // e para o lado esquerdo

    // procurar onde inserir
    if(*raiz == NULL){ // se for o primeiro elemento
        *raiz = novo; // add na raiz o 1° elemento
        }
    else{ // se for o 2° elemento em diante
        struct no *atual = *raiz; // auxiliar para o no atual
        struct no *ant = NULL; // auxiliar para o no anterior
        while(atual != NULL){ // enquanto o no atual nao for NULO
            ant = atual; // anterior eh igual ao atual
            if(valor == atual->info){ // se valor do usuario for igual ao do no atual
                free(novo); // libera no, pois
                return 0; // elemento ja existe
            }
            if(valor > atual->info) // se valor do usuario for maior que o no atual
                atual = atual->sad; // no atual VIRA no direito(atualiza NO atual)
            else // se valor menor
                atual = atual->sae; // no atual VIRA no direito(atualiza NO atual)
        }
        if(valor > ant->info) // se valor for maior que o no anterior
            ant->sad = novo; // o no anterior direito = novo
        else // se for menor
            ant->sae = novo; // o no anterior esquerdo = novo
    }
    return 1; // insercao bem sucedida
}

int removeBin(struct no **raiz, int valor){
    /*
    FUNCAO RESPONSAVEL PELA BUSCA
    DO NO A SER REMOVIDO.
    */
    if(raiz == NULL)
        return 0;
    struct no *ant = NULL;
    struct no *atual = *raiz;
    while(atual != NULL){
        // Trata da remocao ao achar o no a ser removido
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = removeAtual(atual);
            else{
                if(ant->sad == atual)
                    ant->sad = removeAtual(atual);
                else
                    ant->sae = removeAtual(atual);
            }
            return 1;
    }
    // Continua andando na arvore
    ant = atual;
    if(valor > atual->info)
        atual = atual->sad;
    else
        atual = atual->sae;
}

}

struct no* removeAtual(struct no *atual){
    /*
    FUNCAO RESPONSAVEL POR TRATAR
    OS 3 TIPOS DE REMOCAO.
    */
    // Sem filho a esquerda
    struct no *no1, *no2;
    if(atual->sae == NULL){
        no2 = atual->sad;
        free(atual);
        return no2;
    }
    // Procura filho mais a direita na sub-arvore esquerda
    no1 = atual;
    no2 = atual->sae;
    while(no2->sad != NULL){
        no1 = no2;
        no2 = no2->sad;
    }
    // Copia o filho mais a direita na sub-arvore esquerda para o lugar do no removido.
    if(no1 != atual){
        no1->sad = no2->sad;
        no2->sae = atual->sae;
    }
    no2->sad = atual->sad;
    free(atual);
    return no2;
}







