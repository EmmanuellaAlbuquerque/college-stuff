// Includes
#include <stdio.h>
#include <stdlib.h>

// Prototipos
int insereCirculo(float raio, int x, int y);
int insereQuadrado(int x[4], int y[4]);
int insereTriangulo();
int exibe();

// Tipos
struct ponto{
    int x, y;
};

struct circulo{
    float raio;
    struct ponto p;
} *c;

struct quadrado{
    struct ponto p[4];
} *q;

struct triangulo{
    struct ponto p[3];
} *t;

struct figura{
    int tipo;
    void *f;
    struct figura *prox;
} *lista = 0;
//--------------------------------------------------------------- MAIN ---------------------------------------------------------------------------------------
int main(){

    int x[4], y[4], i;
    for(i = 0; i < 4; i++){
        x[i] = 3;
        y[i] = 10;
    }

    insereCirculo(3.22, 3, 5);
    insereQuadrado(x, y);

        for(i = 0; i < 4; i++){
        x[i] = 20;
        y[i] = 50;
    }

    //insereTriangulo(x, y);
    exibe();

}

int insereCirculo(float raio, int x, int y){

    struct figura *novoCirculo, *novoQuadrado, *novoTriangulo; // Aux para criar novo elemento
    novoCirculo = (struct figura*)malloc(sizeof(struct figura)); // Aloca espaco

    if(!novoCirculo){ // Verifica se a alocacao foi bem sucedida.
        printf("Não foi possível alocar!");
        return 0;
    }

    /* Caso seja uma Circuferencia: */
    c = (struct circulo*)malloc(sizeof(struct circulo));

    if(!c){ // Verifica se a alocacao do circulo foi bem sucedida.
        printf("Não foi possível alocar!");
        return 0;
    }

    c->raio = raio; // define de raio para NOVO
    c->p.x = x; // define ponto X pra NOVO
    c->p.y = y; // define ponto Y para NOVO
    novoCirculo->tipo = 1; // define o tipo no NOVO
    novoCirculo->f = c; //
    novoCirculo->prox = NULL;
    lista = novoCirculo;

}

int insereQuadrado(int x[4], int y[4]){

    struct figura *novoQuadrado; // Aux para criar novo elemento
    novoQuadrado = (struct figura*)malloc(sizeof(struct figura)); // Aloca espaco

    if(!novoQuadrado){ // Verifica se a alocacao foi bem sucedida.
      printf("Não foi possível alocar!");
      return 0;
    }

    /* Caso seja um quadrado: */
    q = (struct quadrado*)malloc(sizeof(struct quadrado));

    if(!q){ // Verifica se a alocacao do circulo foi bem sucedida.
        printf("Não foi possível alocar!");
        return 0;
    }

    int i;
    for(i = 0; i < 4; i++){
        q->p[i].x = x[i];
        q->p[i].y = y[i];
    }

    novoQuadrado->tipo = 2; // define o tipo no NOVO
    novoQuadrado->f = q; //
    novoQuadrado->prox = NULL;
    lista->prox = novoQuadrado;

}

int insereTriangulo(int x[3], int y[3]){

    struct figura *novoTriangulo; // Aux para criar novo elemento
    novoTriangulo = (struct figura*)malloc(sizeof(struct figura)); // Aloca espaco

    if(!novoTriangulo){ // Verifica se a alocacao foi bem sucedida.
      printf("Não foi possível alocar!");
      return 0;
    }

    /* Caso seja um Triangulo: */
    t = (struct triangulo*)malloc(sizeof(struct triangulo));

    if(!t){ // Verifica se a alocacao do circulo foi bem sucedida.
        printf("Não foi possível alocar!");
        return 0;
    }

    int i;
    for(i = 0; i < 3; i++){
        t->p[i].x = x[i];
        t->p[i].y = y[i];
    }
    novoTriangulo->tipo = 3; // define o tipo no NOVO
    novoTriangulo->f = t; //
    novoTriangulo->prox = NULL;
    //lista = novoTriangulo;

}

int exibe(){
    //struct circulo *laux; // lista auxiliar
    //laux = c;
    //printf("%f\n",c->raio); // mostra o elemento e o contador


    // while (lista->prox != NULL)
    if (lista->tipo == 1){
        c = lista->f;
        printf("O tipo da figura eh um CIRCULO com RAIO: %.2f \n"
               "E pontos X = %d e Y = %d\n\n"
               ,c->raio, c->p.x, c->p.y);
    }

    lista = lista->prox;

        if (lista->tipo == 2){
        q = lista->f;
        printf("O tipo da figura eh um QUADRADO com pontos:\n"
               "Linha 1: X = %d, Y = %d\n"
               "Linha 2: X = %d, Y = %d\n"
               "Linha 3: X = %d, Y = %d\n"
               "Linha 4: X = %d, Y = %d\n"
                , q->p[0].x, q->p[0].y
                , q->p[1].x, q->p[1].y
                , q->p[2].x, q->p[2].y
                , q->p[3].x, q->p[3].y
               );
    }

    /*
    lista = lista->prox;

        if (lista->tipo == 3){
    q = lista->f;
    printf("O tipo da figura eh um TRIANGULO com pontos:\n"
           "Linha 1: X = %d, Y = %d\n"
           "Linha 2: X = %d, Y = %d\n"
           "Linha 3: X = %d, Y = %d\n"
            , q->p[0].x, q->p[0].y
            , q->p[1].x, q->p[1].y
            , q->p[2].x, q->p[2].y
           );
} */

}

