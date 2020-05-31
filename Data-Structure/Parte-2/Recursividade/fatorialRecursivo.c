/* Função que cálcula o fatorial de um número n, de forma recursiva.*/

// Includes
# include <stdio.h>
# include <stdlib.h>


// Prototipos
int fatorial(int n);

int main(){

	int n;

	printf("Digite o numero que deseja saber o fatorial: ");
	scanf("%d", &n);
	printf("O fatorial de %d eh: %d", n, fatorial(n));

}

int fatorial(int n){

	if(n != 1){
		return (n*fatorial(n-1));
	}
	else{
		return 1;
	}

}