/* Implementação recursiva da sequência de Fibonacci.*/

#include <stdio.h>
#include <stdlib.h>

// Prototipos
int fibo(int n);

int main(){

	int numeroDeTermos, i;
   	printf("Digite a quantidade de termos da sequência de Fibonacci: ");
   	scanf("%d", &numeroDeTermos);

   	printf("\nA sequência de Fibonacci e: \n");
   	for(i = 0; i < numeroDeTermos; i++) // realiza a operação um por um. Começando do 1.
       printf("%d ", fibo(i+1)); // 1, 2, 3, 4, 5...
}

int fibo(int n){

	if(n <= 2){
		return 1; // retorna 1, caso n == 1 ou n == 2.
	}
	else{
		return (fibo(n-1) + fibo(n-2)); // entra em recursividade
	}
}