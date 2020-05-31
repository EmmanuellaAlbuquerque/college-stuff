/* Ler um nome e contar o número de vogais.
/* Aluna: Emmanuella Faustino Albuquerque
/***********************************************/

// Includes
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]){

    char nome[30];

    printf("Digite o nome desejado: ");
    // para receber uma string do usuário através da função scanf(),
    // não é necessário colocar o operador &, pois o nome da string
    // em si já é um endereço de memória.
    scanf("%s", nome); // referencia

    //strcpy("name", nome);
    //strcpy(nome, "manu");

    int i, contador = 0;

    printf("O nome digitado e: %s\n", nome); // cópia

    for(i = 0; i  < strlen(nome); i++){

    if(nome[i] == 'a' || nome[i] == 'e' || nome[i] == 'i' ||nome[i] == 'o' ||nome[i] == 'u'){

    contador++;

     }

    }

    printf("Quantidade de vogais no nome escolhido: %d vogais\n", contador);

}

void contadorDeVogais(char nome[30]){

    int i, contador = 0;

    for(i = 0; i  < strlen(nome); i++){

    if(nome[i] == 'a' || nome[i] == 'e' || nome[i] == 'i' ||nome[i] == 'o' ||nome[i] == 'u'){

    contador++;

} }
}
