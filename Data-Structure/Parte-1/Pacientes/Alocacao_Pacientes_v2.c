/* Alocacao dinamica de memoria com ponteiro para ponteiro,
/* de pacientes.
/* Aluna: Emmanuella Faustino Albuquerque
/***********************************************/

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tipos
struct ficha{

    char nome[30];
    int idade;
    char sexo[2];

};

// Prototipos
void adicionaPaciente(FILE *arq);
void displayArquivo(FILE *arq);
int validaEntrada(char novamente[2]);
void menu();
void consultorio(FILE *arq);
void apagarArquivo(FILE *arq);

/*############################################  MAIN ###################################### */
int main(){

    FILE *arq; // ponteiro do arquivo lido
    int opcao = 0; // opcao do menu escolhida pelo usuario
    char novamente[2]; // variavel de validacao para continuar no programa
    strcpy(novamente, "1"); // com a string = '1', continua no programa
    consultorio(arq); // acessos ao consultorio, escreve no arquivo

    while(validaEntrada(novamente)){ // se a funcao for verdadeira continua

    menu(); // apresenta o menu no console

    printf("  Digite a opcao desejada: "); // pede a escolha com base no menu
    scanf("  %d", &opcao); // opcao, pelos indices 1,2,3

    switch (opcao){ // analisa a opcao escolhida

    case 1:         // caso 1, adiciona os pacientes no arquivo
        adicionaPaciente(arq);
        break;

    case 2:         // caso 2, mostra o arquivo na tela
        displayArquivo(arq);
        break;

    case 3:         // caso 3, apaga o conteudo de 'arq'
        apagarArquivo(arq);
        break;

    case 4:         // caso 4, encerra o programa
        printf("  Programa Encerrado!\n");
        exit(0);    // return(exit(0);

}

    printf("  Deseja continuar? Type 1 para continuar, e 0 para sair: \n");
    scanf("  %s", novamente); // variavel de validacao para continuar no programa
    while(!validaEntrada(novamente)){ // se a funcao for falsa continua
        printf("  COMANDO INVALIDO TENTE NOVAMENTE!\n");
        printf("  Deseja continuar? Type 1 para continuar, e 0 para sair: \n");
        scanf("  %s", novamente); // variavel de validacao para continuar no programa
    }
    if(strcmp(novamente,"0") == 0){ // se novamente == '0', o programa termina
        exit(0); // encerra o programa
    }

}

}

/***
** Apresenta o menu do programa no console.
*/
void menu(){

    // MENU DO PROGRAMA
    printf("  ---------------------MENU---------------------\n\n");
    printf("  Digite a opcao desejada:\n");
    printf("  1. Adicionar pacientes\n");
    printf("  2. Ver arquivo com a lista de pacientes\n");
    printf("  3. Para apagar o conteudo do arquivo\n");
    printf("  4. Sair\n\n");
    printf("  ----------------------------------------------\n\n");

}

/***
** Adiciona um paciente no arquivo de texto.
*/
void adicionaPaciente(FILE *arq){

    struct ficha **pacientes;  // ponteiro para ponteiro do tipo struct ficha
    int indice, quantidade;    // contador e o numero de pacientes a serem adicionados

    /* Cria um arquivo texto para leitura e gravacao. Se o arquivo existir, o conteudo
    anterior sera destruido. Se não existir, será criado. */
    arq = fopen("pacientes.txt", "a+"); // r,w ou a
	if(!arq){ // arq == 0, se nao existe ou nao foi encontrado
	printf("  Arquivo nao encontrado!");
	exit(0); // terminou com sucesso
	}

    // Pergunta a quantidade de pacienes a serem alocados:
	printf("  Digite a quantidade de pacientes que deseja adicionar: ");
	scanf("  %d", &quantidade); // numero de pacientes a serem adicionados

    // Aqui você aloca a 'quantidade' de ponteiros de ficha, ou seja, 'quantidade' de fichas **vazias**, ainda **não alocadas**.
    pacientes = malloc(sizeof(struct ficha*)*quantidade);

    // Verifica se o alocamento anterior foi bem sucedido
	if(!pacientes){ // Nao alocou o vetor
	printf("  Memoria Indisponivel");
	exit(0); // terminou com sucesso
	}

    /* Loop para percorrer todos os indices do seu "vetor" de fichas/pacientes
    [ponteiros que apontaram para structs ficha] */
    for(indice = 0; indice < quantidade; indice++){ // dada a quantidade digitada pelo usuario

	// eh alocado espaço de uma ficha para um paciente
    pacientes[indice] = malloc(sizeof(struct ficha)); // paciente[0] tem uma ficha, etc...

    // Verifica se o alocamento anterior foi bem sucedido
    if(!pacientes[indice]){ // nao alocou a ficha
	printf("  Struct nao alocada!");
	exit(0); // terminou com sucesso
	}

	printf("  Digite o nome do paciente: ");
	scanf("  %s", pacientes[indice]->nome);     // armazena o nome ao paciente[indice]

	printf("  Digite a idade: ");
	scanf("  %d", &pacientes[indice]->idade);   // armazena a idade ao paciente[indice]

	printf("  Digite o sexo: ");
	scanf("  %s", pacientes[indice]->sexo);     // armazena o sexo ao paciente[indice]

	//if(strcmp(pacientes[indice]->sexo, "f") == 0    // se os caracteres do sexo forem inseridos
    //|| strcmp(pacientes[indice]->sexo, "m") == 0 ){  // corretamente. continua:
	 //  printf("  Paciente inserido com sucesso!\n");
	//}
	//else{
	 //   printf("  Sexo inserido invalido! Use f p/ feminino e m p/ masculino!\n");
	    //exit(0); // terminou com sucesso
	//}

	while(strcmp(pacientes[indice]->sexo, "f") != 0  // se os caracteres do sexo forem inseridos
    && strcmp(pacientes[indice]->sexo, "m") != 0 ){  // corretamente. continua:

        printf("  Sexo inserido invalido! Use f p/ feminino e m p/ masculino!\n");
        printf("  Digite o sexo: ");
        scanf("  %s", pacientes[indice]->sexo);     // armazena o sexo ao paciente[indice]

    }

    printf("  Paciente inserido com sucesso!\n");

    }

    for(indice = 0; indice < quantidade; indice++){ //Percorre o "Vetor" de struct/fichas

    //printf(" -----------  %d° PACIENTE -----------\n", indice+1);
    //printf(" Nome: %s\n", pacientes[indice]->nome);
    //printf(" Idade: %d\n", pacientes[indice]->idade);
    //printf(" Sexo: %s\n", pacientes[indice]->sexo);
    //printf(" -------------------------------------\n", quantidade);

    // Escreve os dados digitados pelo usuario no arquivo-texto
    fprintf(arq, " -----------  %d° PACIENTE -----------\n", indice + 1);
    fprintf(arq, " Nome: %s\n", pacientes[indice]->nome);
    fprintf(arq, " Idade: %d\n", pacientes[indice]->idade);
    fprintf(arq, " Sexo: %s\n", pacientes[indice]->sexo);
    fprintf(arq, " -------------------------------------\n", quantidade);

    free(pacientes[indice]); //Libera uma struct/ficha ao decorrer do loop


}

    free(pacientes); //No término do Loop, libera o "Vetor" de structs
    fclose(arq); // fecha o arquivo

}

/***
** Valida a condicao de parado do loop principal.
*/
int validaEntrada(char novamente[2]){

    int x, flag; // contador e flag
    flag = 1;    // inicialmente a entrada eh valida
    for(x = 0; x < strlen(novamente); x++){ // porem, se a entrada n for '0' nem '1'
    if(novamente[x] < '0' || novamente[x] > '1'){
        flag = 0; // entao a entrada eh invalida
        return flag; // retorna invalido, 0
    }

    return flag; // retorna valido, 1
}
}

/***
** Apresenta o conteudo do arquivo de texto no console.
*/
void displayArquivo(FILE *arq){

    char ch; // caractere

    // Cria um arquivo texto para leitura e gravacao. Se o arquivo existir, o conteudo anterior sera destruido. Se não existir, será criado.
    arq = fopen("pacientes.txt", "a+"); // r,w ou a
	if(!arq){ // arq == 0, se nao existe ou nao foi encontrado
	printf("  Arquivo nao encontrado!");
	exit(0); // terminou com sucesso
	}

	/* Enquanto nao for o final do arquivo, pega os caracteres do mesmo e mostra no console */
    while((ch = fgetc(arq))!= EOF){ // ch, recebe caractere por caractere do arquivo

        //fscanf(arq, "%s\n", nome);
        //printf(" Nome: %s\n", nome);

        putchar(ch);                // e mostra na tela

	}

	fclose(arq); // fecha o arquivo
}

/***
** Conteudo inserido no arquivo-texto para cada inicio do programa. Para dessa forma,
** toda vez que o programa eh aberto mostra-se uma string de acesso.
*/
void consultorio(FILE *arq){

    arq = fopen("pacientes.txt", "a+"); // r,w ou a
	if(!arq){ // arq == 0, se nao existe ou nao foi encontrado
	printf("  Arquivo nao encontrado!");
	exit(0); // terminou com sucesso
	}

	/* Caso o programa seja acessado, porem nao seja adicionado novos pacientes,
	apenas essa string irá aparecer no arquivo-texto */
    fprintf(arq, " -------------------------- ACESSOS CONSULTORIO ------------------------\n\n");

    fclose(arq); // fecha o arquivo

}

/***
** Apaga o conteudo do arquivo-texto.
*/
void apagarArquivo(FILE *arq){

    /* Ao abrir se ja tiver conteudo no arquivo-texto, o mesmo eh apagado e reescrito,
    Nesse caso, como nada sera escrito ele so apaga o conteudo anterior*/
    arq = fopen("pacientes.txt", "w"); // write, sobrescreve
	if(!arq){ // arq == 0, se nao existe ou nao foi encontrado
	printf("  Arquivo nao encontrado!");
	exit(0); // terminou com sucesso
	}

	printf("  ARQUIVO APAGADO COM SUCESSO!\n");
    fclose(arq); // fecha o arquivo

}

