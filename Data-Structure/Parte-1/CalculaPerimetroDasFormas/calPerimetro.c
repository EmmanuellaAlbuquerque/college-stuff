/* Programa que calcula o perímetro das formas:
/* Círculo,
/* Quadrado,
/* Triângulo.
/* Aluna: Emmanuella Faustino Albuquerque
/* versão: 1.0 (console, personalizado com ASCII)
/***********************************************/

// Includes
#include <stdio.h>
#include<stdlib.h>
#include <conio2.h>
#include <string.h>
#define MAXBUF  (100)
#define STRTAM 60

// Prototipos
float calculaPCirculo(float raio);
float calculaPQuadrado(float lado);
float calculaPTringulo(float lado1, float lado2, float lado3);
void criaMenuLinhaSuperior();
void criaMenuLinhaRodape();
void criaMenuItem();
void montaMenu();
char tipoDaEscolha(int escolha);
char *obter_msg(int i);

// Variáveis globais
// #define PI 3.1415

int main(int argc, const char * argv[]){

    int escolha;
    char novamente[2], s[2]; // letra + enter + /nulo
    float raio, ladoQuadrado, ladoTriangulo1, ladoTriangulo2, ladoTriangulo3;

    strcpy(s, "s"); // Realiza a cópia do conteúdo de uma variável a outra.
    strcpy(novamente, "n");
    montaMenu();

    while(strcmp("s", novamente) != 0){

    textcolor(LIGHTGRAY);
    printf("  Digite o numero correspondente ao que deseja realizar: ");
    scanf("%d", &escolha);
    printf("  OPCAO ESCOLHIDA: %d -> %s\n", escolha, obter_msg(escolha));

    switch (escolha){

    case 1:
        printf("  Digite o raio: ");
        scanf("%f", &raio);
        printf("  O perimetro e igual a %.2f cm", calculaPCirculo(raio));
        break;

    case 2:
        printf("  Digite o lado: ");
        scanf("%f", &ladoQuadrado);
        printf("  O perimetro e igual a %.2f cm", calculaPQuadrado(ladoQuadrado));
        break;

    case 3:
        printf("  Digite o primeiro lado: ");
        scanf("%f", &ladoTriangulo1);
        printf("  Digite o segundo lado: ");
        scanf("%f", &ladoTriangulo2);
        printf("  Digite o terceiro lado: ");
        scanf("%f", &ladoTriangulo3);
        printf("  O perimetro e igual a %.2f cm", calculaPTringulo(ladoTriangulo1, ladoTriangulo2, ladoTriangulo3));
        break;

    default:
    //Acentos em ASCII: letra 'E' agudo (é):130  letra 'E' com circumflexo(ê):136  letra 'A' com til (ã):198
        printf("  Opc%co Indisponivel", 198);
        break;
    }

    printf("\n  Deseja sair?\n  Digite s para sair e n para continuar: ");
    // para receber uma string do usuário através da função scanf(),
    // não é necessário colocar o operador &, pois o nome da string
    // em si já é um endereço de memória.
    scanf("%s", novamente);

    }

    return 0;
}

// A função possui um buffer estático interno e sempre retorna seu ponteiro para o cliente:
 char *obter_msg(int escolha)
{
    static char msg[MAXBUF + 1] = {0};

    if(escolha == 1){
        strncpy(msg, "circulo", MAXBUF);
        return msg;
    }
    if(escolha == 2){
        strncpy(msg, "quadrado", MAXBUF);
        return msg;
    }
    if(escolha == 3){
        strncpy(msg, "triangulo", MAXBUF);
        return msg;
    }

    strncpy(msg, "Error", MAXBUF);
    return msg;
}

/**
    Retorna o valor do perímetro da circunfência dado o valor do raio.
*/
float calculaPCirculo(float raio)
{
    // Constante
    const float PI = 3.1415;

	float perimetro;
	perimetro = 2*PI*raio;
	return perimetro;

}

/**
    Retorna o valor do perímetro do quadrado dado o valor do lado.
*/
float calculaPQuadrado(float lado)
{
	float perimetro;
	perimetro = 4*lado;
	return perimetro;

}

/**
    Retorna o valor do perímetro do Triângulo dado o valor do lado.
*/
float calculaPTringulo(float lado1, float lado2, float lado3)
{
	float perimetro;
	perimetro = lado1+lado2+lado3;
	return perimetro;

}

void criaMenuLinhaSuperior(){

    textcolor(LIGHTGREEN);
    int i;
    printf("%c", 201);
    for(i = 0; i < STRTAM; i++){
        printf("%c", 205);
    }
    printf("%c\n", 187);

}

void criaMenuLinhaRodape(){

    int i;
    printf("%c", 200);
    for(i = 0; i < STRTAM; i++){
        printf("%c", 205);
    }
    printf("%c\n", 188);

}

/**

*/
void criaMenuItem(int tamX, char str[]){

    printf("%c", 186);
    textcolor(LIGHTGRAY);
    printf("%-*s", tamX, str); // Fomatação do printf(Alinhamento)
    textcolor(LIGHTGREEN);
    printf("%c\n", 186);

}

void criaMenuLinhaHorizontal(int tamX){

    int i;
    printf("%c", 204);
    for(i = 0; i < tamX; i++){
    printf("%c", 205);
    }
    printf("%c\n", 185);

}

void montaMenu(){

    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "                        MENU PRINCIPAL");
    criaMenuLinhaHorizontal(STRTAM);
    criaMenuItem(STRTAM, "             1 - Calcula perimetro do circulo");
    criaMenuItem(STRTAM, "             2 - Calcula perimetro do quadrado");
    criaMenuItem(STRTAM, "             3 - Calcula perimetro do triangulo");
    criaMenuLinhaRodape();

}

/** * Cores para usar na sua aplicação: */
/* Cores{
    BLACK,  textcolor(0) ou textcolor(BLACK)
    BLUE,  textcolor(1)
    GREEN,  textcolor(2)
    CYAN,  ...
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE;  textcolor(15)

    } */
