// Implementacao da Heap Binaria em C
// gcc heapBinario.c -o heapBinario -lm
// ./heapBinario

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include<string.h> 
#define MAX 101000

// Tipos
struct heapBinario
{
	/*Representa a estrutura de dados heap binaria(estatica)*/
	int arvore[MAX]; // info
    int quantidade; // controle de ocupacao
	
};
typedef struct heapBinario HeapBinario;

/** Retorna o no pai de um indice qualquer. 
 * @param i, o indice do filho que se deseja saber o pai. 
 * @return , o indice do pai.
 */
int pai(int i){
	return (i - 1) / 2;
}

/** Retorna o no a esquerda de um indice. 
 * @param i, o indice.
 * @return , o indice do no a esquerda.
 */
int esquerda(int i){
	return 2 * i + 1;
}

/** Retorna o no a direita de um indice. 
 * @param i, o indice.
 * @return , o indice do no a direita.
 */
int direita(int i){
	return 2 * i + 2;
}

/** Troca por referência os valores de 2 variaveis.
 * @param x, primeira variavel.
 * @param y, segunda variavel.
 */
void swap(int *x, int *y){ 

	// variavel temporaria para realizar a troca.
	int temp; 
	temp = *x;
	*x = *y;
	*y = temp;

}

/** Realiza o procedimento max-heapify.
 * @param heap, a heap binaria.
 * @param i, o indice no qual se deseja 
 * realiza o procedimento.
 * @return , a heap binaria modificada.
 */
HeapBinario max_Heapify(HeapBinario heap, int i){

	int maior;
	// Armazena o INDICE a esquerda do indice escolhido da arvore
	int left = esquerda(i); 
	// Armazena o INDICE a direita do indice escolhido da arvore
	int right = direita(i);

	// Se estiver dentro do limite dos INDICES da arvore E o VALOR a esquerda(filho) for maior que o pai.
	if(left <= heap.quantidade && heap.arvore[left] > heap.arvore[i]){
		maior = left;
	}
	else{ // Senão, o PAI eh definido como o maior.
		maior = i;
	}

	// Se estiver dentro do limite dos INDICES da arvore E o VALOR a direita(filho) for maior que o pai.
	if(right <= heap.quantidade && heap.arvore[right] > heap.arvore[maior]){
		maior = right;
	}

	// Se for o caso, realiza a troca.
	if(maior != i){
		swap(&heap.arvore[i], &heap.arvore[maior]);
		// Realiza o procedimento novamente ate que o indice do maior == indice pai
		heap = max_Heapify(heap, maior);
	}

	return heap;

}


/** Retorna o tamanho da heap binaria.
 * @return , quantidade de nos da heap. [0, N]
 */
int tamanho(HeapBinario heap){
	return heap.quantidade;
}

/** Realiza o calculo do comprimento da heap.
 * @param n, o numero de nos.
 * @return , o comprimento da heap.
 */
int comprimento(int n){

	if (n == 0) return 0; // heap sem nos

	double result;
	int comprimento, niveis;
	// lg(n) representa o numero de niveis da arvore
	result = log2(n); 
	niveis = result + 1;
	// C = (2^(niveis+1) - 1) 
	comprimento =  pow(2, niveis) - 1;

	return comprimento;

}

/** Realiza o procedimento build max heap, 
 * isto eh o max_Heapify em todos os indices.
 * @param heap, a heap binaria.
 * @return , a heap modificada.
 */
HeapBinario build_Max_Heap(HeapBinario heap){

	HeapBinario heapModificado = heap;
	int i;

	// Realiza o procedimento de max heapify de baixo para cima.
	for(i = (comprimento(tamanho(heapModificado)+1)/2); i >= 0; i--){
		heapModificado = max_Heapify(heapModificado, i);
	}

	return heapModificado;
}

/** Realiza o procedimento de ordenacao.(sort)
 * @param heap, a heap binaria.
 * @return , a heap modificada.(em ordem crescente)
 */
HeapBinario heap_Sort(HeapBinario heap){

	HeapBinario heapModificado;
	int i, m;
	// Armazena o tamanho da arvore heap binaria
	m = tamanho(heap);

	// Modifica a heap original, trocando os indices pais com os maiores valores dos indices filhos
	heapModificado = build_Max_Heap(heap);

	// Realiza o procedimento de ordenacao
	for(i = tamanho(heapModificado); i > 0; --i){

		// Troca o primeiro(valor) com o ultimo da arvore.
		swap(&heapModificado.arvore[0], &heapModificado.arvore[i]);

		// Retina um no da arvore(modifica o controle de ocupacao).
		heapModificado.quantidade -= 1;

		// Realiza o maxHeapipy do no PAI principal com seus filhos.
		heapModificado = max_Heapify(heapModificado, 0);

	}

	// Restaura o controle de ocupacao. 
	heapModificado.quantidade = m;
	return heapModificado;

}

/** Apresenta os valores da heap no console.
 * @param heap, a heap binaria.
 */
void shown_Heap(HeapBinario heap){

	int i;
	printf("<");
	for(i = 0; i < tamanho(heap) + 1; i++){
		printf(" %d, ", heap.arvore[i]);
	}
	printf(">\n");

}

/* ------------------------------------------------------- MAIN ---------------------------------------------------*/
int main(){

	/************************ TESTES ************************/

	int i;

	// Criando heap e setando quantidade.
	HeapBinario heap, heapModificado;
	heap.quantidade = 0;

	/***** LEITURA DE ARQUIVO TXT *****/
	i = 0;
    int numPalavras = 0;
    char* palavras[110000];
    char line[110000];

    FILE *arquivo;
    arquivo = fopen("couting.txt", "r");

    // ERRO ao abrir arquivo
    if (arquivo == NULL) 
        return EXIT_FAILURE;

    while(fgets(line, sizeof line, arquivo) != NULL)
    {
        // Adiciona cada palavra
        palavras[i] = strdup(line);

        i++;

        // Conta a quantidade de palavras
        numPalavras++;
    }

	printf("\n");

	//heap.arvore[0] = 16;
	//heap.arvore[1] = 14;
	//heap.arvore[2] = 10;
	//heap.arvore[3] = 8;
	//heap.arvore[4] = 7;
	//heap.arvore[5] = 9;
	//heap.quantidade = 5;

	// Converte as (cadeia de caracteres)strings para inteiros
	for (int i = 0; i < 20; i++)
	{
		heap.arvore[i] = atoi(palavras[i]);
	}
	heap.quantidade = 19;

	heapModificado = heap;

	//heapModificado = max_Heapify(heap, 1);
	//heapModificado = max_Heapify(heapModificado, 3);
	//heapModificado = max_Heapify(heapModificado, 8);

	//heapModificado = build_Max_Heap(heapModificado);

	printf("TAM: %d\n", tamanho(heapModificado) + 1);
	printf("COMP: %d\n", comprimento(heapModificado.quantidade + 1));

	heapModificado = heap_Sort(heapModificado);

	shown_Heap(heapModificado);

	return 0;
}
