package huffman;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 * O algoritmo de Huffman é um método de compressão que a partir da 
 * quantidade de ocorrências de um símbolo em um arquivo a ser comprimido 
 * determina uma codificação para cada símbolo.
 * @author Emmanuella Albuquerque.
 */
public class Huffman {

	/* Vetor de frequências: Representa as aparições de um nó. */
    private int[] frequencia;
    
    /* Arquivo para leitura. */
    private File file;
    
	/* Tabela de codificação: preenchida de acordo com a frequência. */
    private String[] vetorCodificacao;

    /**
     * Construtor dado um arquivo de entrada.
     * @param file, arquivo de entrada.
     */
    public Huffman(File file) {
    	
        this.file = file;
        
        /* [0...255] Caracterizando os 256 caracteres ASCII possíveis. 2^8 = 256. */
        this.frequencia = new int[256];
        this.vetorCodificacao = new String[256];
        
    }

    /**
     * Realiza a soma da quantidade de aparições de cada 
     * variável/símbolo lido pelo arquivo de entrada.
     */
    public void contarFrequencia() {
    	
    	/* Armazena a quantidade de elementos lidos. */
        this.frequencia[0] = 0;

        try {
        	
        	/* Auxiliares para leitura do arquivo. */
            FileReader leitor = new FileReader(this.file);
            BufferedReader buffer = new BufferedReader(leitor);

            // Lê valor da entrada e armazena convertido para inteiro.
            int entrada = buffer.read();
            
            // Quando o arquivo termina retorna -1, então: 
            while (entrada != -1) {
            	
            	/* Incrementa a frequência de aparição do valor lido(entrada).*/
                this.frequencia[entrada]++;
                
                /* Atualiza o valor da quantidade de elementos lidos. */
                this.frequencia[0]++;
                
                /* Continua. Lê o próximo elemento.*/
                entrada = buffer.read();
                
            }
            
            /* Fecha os auxiliares de leitura. */
            buffer.close();
            leitor.close();
            
        } catch (Exception e) {
        	
            e.printStackTrace();
            System.out.println("Não foi possível ler o arquivo.");
            
        }
        
    }

    /**
     * Cria a Fila de Prioridade para o algoritmo de huffman.
     * @return, heap binária.
     */
    public FilaDePrioridade criaFilaMinima() {
    	
        FilaDePrioridade heap = new FilaDePrioridade(256);

        /* Usa o vetor de inteiros da Frequência para criar a fila dos 256 caracteres: */
        for (int i = 1; i < this.frequencia.length; i++) {
        	
        	/* Se o caractere não tiver sido lido não conta. */
            if (this.frequencia[i] != 0) {
            	
            	// Cria o nó e insere na Fila de Prioridade.
                No no = new No((char) i, this.frequencia[i]);
                heap.heapInsert(no);
                
            }
            
        }

        // Retorna a fila de Prioridade.
        return heap;
    }

    /**
     * Cria a árvore de codificação de huffman.
     * Retornando a raiz da árvore.
     * @param heap, fila de prioridade.
     * @return, o nó raiz da árvore.
     */
    public No criaArvore(FilaDePrioridade heap) {

    	/* Enquanto não sobrar somente a raiz: */
        while (heap.getQuantidade() != 1) {
        	
        	/* 1. Extraí os 2 menores nós da árvore */
            No filhoEsquerdo = heap.heapExtractMin();
            No filhoDireito = heap.heapExtractMin();

            /* 2. Agrupa eles em um terceiro nó(pai) */ 
            No pai = new No(filhoEsquerdo, filhoDireito);

            /* 3. Insere a união dos 2 nós mínimos na árvore.*/
            heap.heapInsert(pai);
        }

        /*Retorna o nó pai, dado pelo união dos 2 últimos nós. */
        return heap.heapExtractMin();
        
    }

    /**
     * Gera o código da árvore de codificação de huffman.
     * @param raiz, root da árvore.
     * @param codigo, codificação do nó/símbolo.
     */
    public void geraCodificacao(No raiz, String codigo) {
    	
    	/* Executa recursivamente até chegar em um nó folha. */
		if (raiz.verificaSeFolha()) {
			
			// Usa o valor inteiro do símbolo.
			int id = raiz.getSimbolo();
			
			// Atribui o código gerado ao índice respectivo. 
			vetorCodificacao[id] = codigo;
			
		} 
		else {
			
			/* Enquanto não chegar a um nó folha: */
			geraCodificacao(raiz.getEsquerdo(), codigo + "0");
			geraCodificacao(raiz.getDireito(), codigo + "1");
			
		}

    }

    /**
     * Retorna a codificação do símbolo desejado.
     * @param simbolo, que se deseja saber o código.
     * @return, a codificação.
     */
    public String getCodigo(char simbolo) {
        return vetorCodificacao[simbolo];
    }
    
    /**
     * Realiza a visita(recursivamente) pelo percurso em Ordem na ávore. 
     * @param no, a raiz da árvore.
     */
    public void emOrdem(No no) {

    if(no != null){
    	
		/* Percorre na ordem Esquerda->Raiz->Direita */
	    emOrdem(no.getEsquerdo());
	    
	    if(no.getSimbolo() != '+') {
		    System.out.println("[ Símbolo: " + no.getSimbolo() + 
		    		", Código: " + getCodigo(no.getSimbolo()) + 
		    		", Frequência: " + no.getFrequencia() +
		    		" ]");		
	    }
	    
	    emOrdem(no.getDireito());  
    	}    
    }

    /**
     * Gera a codificação do arquivo lido.
     * -> Conta a frequência, 
     * -> Cria a árvore, 
     * -> Gera o arquivo codificado.
     */
    public void codificacao() {

    	/* Conta a frequência de aparições de um símbolo no arquivo. */
    	contarFrequencia();

    	/* Cria a heap dado o vetor de frequências. */
        FilaDePrioridade heap = criaFilaMinima();

        /* Cria a árvore de codificação do algoritmo de huffman. */
        No rootTree = criaArvore(heap);
        
        /* Gera a codificação a partir da árvore. */
        geraCodificacao(rootTree, "");
        
        System.out.println("Valores da Entrada: ");
        
        /* Exibe o percurso em Ordem no Console. */
        emOrdem(rootTree);

        // Gera o arquivo codificado.
        escreveCodificacao();
 
    }
    
    /**
     * Gera o arquivo codificado.
     * 
     */
    public void escreveCodificacao() {
    	
    	try {
        	
    		// Auxiliares para escrita do arquivo de codificação.
			FileOutputStream saida = new FileOutputStream("codificacao.bin");
			DataOutputStream dataSaida = new DataOutputStream(saida);

            // Escrita do array de frequências no arquivo.
            for (int i = 0; i < frequencia.length; i++) {
            	dataSaida.writeInt(frequencia[i]);
            }
			
        	/* Auxiliares para leitura do arquivo de entrada(normal). */
            FileReader leitor = new FileReader(this.file);
            BufferedReader buffer = new BufferedReader(leitor);
            
            // Lê valor da entrada e armazena convertido para inteiro.
            int entrada = buffer.read();
            
            // Quando o arquivo termina retorna -1, então: 
            while (entrada != -1) {
            
            	// Dada a entrada, pega seu valor na tabela de codificação(vetor).
            	String codSimbolo = vetorCodificacao[entrada];
            	
            	// Converte a string de codificação em um array de bytes.
            	if(codSimbolo != null) {
            		
            		byte[] arrayBytes = codSimbolo.getBytes();
                	/* Escreve cada elemento da tabela de códigos no arquivo de codificação. */
                	saida.write(arrayBytes);
                
            	}
            	
            	// Lê o próximo elemento.
            	entrada = buffer.read();
            }
            
            // Fecha os recursos.
            dataSaida.close();
            buffer.close();
			
		} catch (FileNotFoundException e) {
			
			System.out.println("Arquivo não encontrado!");
			e.printStackTrace();
			
		} catch (IOException e) {
			
			System.out.println("Erro na entrada!");
			e.printStackTrace();
			
		}

    }

    /**
     * Dado um arquivo codificado, realiza o procedimento de
     * decodificação do mesmo.  
     * 
     */
    public void processDecodificacao() {
    	
    	System.out.println("A Entrada Decodificada se encontra no arquivo decodificacao.txt");
    	
    	try {
    		
    		// Auxiliares para leitura do arquivo de entrada.
			FileInputStream entrada = new FileInputStream("codificacao.bin");
            DataInputStream dataEntrada = new DataInputStream(entrada);
			
            // Arquivo onde será escrito a decodificação.
            File saida = new File("decodificacao.txt");
            
            // Auxiliares para escrita no arquivo de saída.
            FileWriter escritor = new FileWriter(saida);
            BufferedWriter bufferEscritor = new BufferedWriter(escritor);
            
            // Lê o arquivo codificado, para pegar as frequências.
            for (int i = 0; i < this.frequencia.length; i++) {
                this.frequencia[i] = dataEntrada.readInt();
            }
            
            // Reconstroe a Fila Mínima.
            FilaDePrioridade heap = criaFilaMinima();
            // Recria a árvore.
            No raiz = criaArvore(heap);
            
            // Continua o procedimento de leitura do arquivo codificado.
            int i;
            StringBuilder codificacao = new StringBuilder();
            
            // Enquanto não acabar o arquivo.
            while ((i = entrada.read()) != -1) {
            	
            	// Cria a string.
                codificacao.append((char)i);
            	
            }
            
            // Gera a decodificação.
            String decodificacao = decodificacao(codificacao, raiz);
            
            // Escreve o conteúdo no arquivo.
            bufferEscritor.write(decodificacao);
            
            // Fecha os recursos utulizados.
            bufferEscritor.close();
            escritor.close();
            dataEntrada.close();

		} catch (FileNotFoundException e) {
			
			System.out.println("Arquivo não encontrado!");
			e.printStackTrace();
			
		} catch (IOException e) {
			
			System.out.println("Erro na entrada!");
			e.printStackTrace();
		}	
    	
}
    /**
     * Gera a decodificação do arquivo.
     * @param data, o que será decodificado.
     * @param topo, a raiz/ topo da árvore.
     * @return, a decodificação.
     */
    public String decodificacao(StringBuilder data, No topo) {

    	// Raiz da árvore.
    	No no = topo;
    	
        StringBuilder saida = new StringBuilder();
        
        // Percorre a entrada.
        for (char ch : getCaracteres(data)) {
        	
        	// Caso entrada 0:
            if (ch == '0') { 	
            	no = no.getEsquerdo();
            } 
            
            // Caso entrada 1:
            else {
            	no = no.getDireito();	
            }

            // Verificação no percurso da arquivo.
            if (no.verificaSeFolha()) {
            	
            	// Cria a decodificação.
            	saida.append(no.getSimbolo());
            	// Retorna a raiz.
                no = topo;
            }
        }
        
        // Saída valor decodificado.
        return saida.toString();
    }
    
    /**
     * Retorna todos os caracteres da entrada.
     * @param texto, entrada do a ser codificada.
     * @return, vetor de caracteres.
     */
    private char[] getCaracteres(StringBuilder texto) {
    	
        char[] letras = new char[texto.length()];
        
        /* Pega os chars de uma String e coloca em um array de caracteres.*/
        texto.getChars(0, texto.length(), letras, 0);
        
        return letras;
        
    }
}
