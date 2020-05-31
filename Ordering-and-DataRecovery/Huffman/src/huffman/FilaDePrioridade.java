package huffman;

/**
 * Fila de prioridade, heap binária mínima.
 * @author Emmanuella Albuquerque.
 */
public class FilaDePrioridade {

    /* Vetor usado para criar a heap mínima. */
    private No[] elementos;
    
    /* Tamanho da heap mínima. */
    private int quantidade;

    /**
     * Construtor da Fila de Prioridade.
     * @param size, o tamanho da heap.
     */
    public FilaDePrioridade(int tamanho) {
    	
    	/* Tamanho da heap mínima. */
        this.quantidade = 0;
        
        /* Inicializa vetor. */
        this.elementos = new No[tamanho];
    }
    
    /**
     * Retorna os nós da Fila de Prioridade.
     * @return, os nós da heap.
     */
    public No[] getArray() {
    	return elementos;
    }
    
    /**
     * Seta os elementos da Fila de Prioridade.
     * @param elementos, os nós.
     */
    public void setElementos(No[] elementos) {
    	this.elementos = elementos;
    }

    /**
     * Realiza o procedimento build min heap, 
     * isto eh o min_Heapify em todos os índices.
     */
    public void buildMinHeap() {
    	
        int metade = quantidade / 2;

        /* Realiza o procedimento de min heapify até que o índice do menor == índice pai */
        for (int i = metade - 1; i >= 0; i--) {
            minHeapify(i);
        }
    }

    /**
     * Realiza o procedimento min-heapify.
     * @param i, o índice no qual se deseja 
     * realiza o procedimento.
     */
    public void minHeapify(int indice) {
    	
    	// Armazena o INDICE a esquerda do índice escolhido da árvore
        int left = esquerdo(indice);
        
        // Armazena o INDICE a direita do índice escolhido da árvore
        int right = direito(indice);
        
        int menor = indice;

    	// Se estiver dentro do limite dos INDICES da árvore E o VALOR a esquerda(filho) for menor que o pai.
        if (left < quantidade && elementos[left].getFrequencia() < elementos[menor].getFrequencia()) {
        	menor = left;
        }
        
        // Se estiver dentro do limite dos INDICES da árvore E o VALOR a direita(filho) for menor que o pai.
        if (right < quantidade && elementos[right].getFrequencia() < elementos[menor].getFrequencia()) {
        	menor = right;
        }

        // Se for o caso, realiza a troca.
        if (menor != indice) {
        	
        	// Realiza a troca dos nós. SWAP.
            No aux;
            aux = elementos[indice];
            elementos[indice] = elementos[menor];
            elementos[menor] = aux;
            
            // Realiza o procedimento novamente.
            minHeapify(menor);
            
        }
    }

    /**
     * Realiza o procedimento de extração do menor valor da heap.
     * @return, o menor elemento da fila de prioridade.
     */
    public No heapExtractMin() {
    	
    	// Se a quantidade for menor que zero não tem mais elementos para extrair.
        if (quantidade < 1) {
            return null; 
        }
        
        // Min recebe o menor elemento da heap mínima.
        No min = elementos[0];
        
        // Faz o último elemento(dos nós) ser o primeiro. 
        elementos[0] = elementos[quantidade - 1];
        
        // Decrementa a fila de prioridade
        quantidade--;
        
        // Realiza o procedimento min-heapify para ajustar os valores.
        minHeapify(0);
        
        // Retorna o nó mínimo.
        return min;
        
    }

    /**
     * Insere um nó na fila de prioridade.
     * @param no, o nó que será inserido.
     */
    public void heapInsert(No no) {
    	
    	// Seta i como o último elemento da fila
        int i = quantidade;
        
        // Reajusta a prioridade da fila: Enquanto o pai for maior que o filho.
        while(i > 1 && elementos[pai(i)].getFrequencia() > no.getFrequencia()){
        	
        	/* Realiza o swap dos elementos. */
        	elementos[i] = elementos[pai(i)];
        	
        	// Atualiza o novo i com o superior.
            i = pai(i);
            
        }
        
        /* Realiza o swap dos elementos. */
        elementos[i] = no;
        
        // Incrementa a quantidade de elementos da Fila de Prioridade.
        quantidade++;
    }

    /**
     * Retorna a posição/índice de um nó pai dado um índice.
     * @param indice, o índice do filho.
     * @return, índice pai.
     */
    private int pai(int indice) {
        return (indice - 1) / 2;
    }

    /**
     * Retorna a posição/índice de um nó filho dado um índice.
     * @param indice, o índice do pai.
     * @return, índice filho esquerdo.
     */
    public int esquerdo(int indice) {
        return (indice * 2) + 1;
    }

    /**
     * Retorna a posição/índice de um nó filho dado um índice.
     * @param indice, o índice do pai.
     * @return, índice filho direito.
     */
    public int direito(int indice) {
        return (indice * 2) + 2;
    }

    /**
     * Retorna o tamanho da Fila de Prioridade.
     * @return, tamanho da heap.
     */
    public int getQuantidade() {
        return quantidade;
    }
}