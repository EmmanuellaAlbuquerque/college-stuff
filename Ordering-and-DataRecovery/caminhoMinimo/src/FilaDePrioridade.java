/**
 * Fila de prioridade, heap binária mínima.
 * Os elementos da árvore, ficam do menor
 * (índice 0) para o maior(índice n).
 * @author Emmanuella Albuquerque e Vanessa Pessoa.
 */
public class FilaDePrioridade {

    /* Guarda a posição/índices dos vértices na heap. */
    private int[] ids;
    /* Vetor usado para criar a heap mínima. */
    private Vertice[] elementos;
    /* Tamanho da heap mínima. */
    private int quantidade;

    /**
     * Construtor da classe recebe os vértices para adicionar na fila de prioridade.
     * @param vetorVertices, os vértices da fila de prioridade.
     */
    public FilaDePrioridade(Vertice[] vetorVertices) {
    	
    	// A fila apresentará os vértices.
        this.elementos = new Vertice[vetorVertices.length];

        // Define os vértices inseridos como elementos da fila de prioridade.
        for (int i = 0; i < vetorVertices.length; i++) {
            this.elementos[i] = vetorVertices[i];
        }

        // Define a quantidade de vértices.
        this.quantidade = vetorVertices.length;
        
        // Define os índices dos elementos/vértices.
        this.ids = new int[vetorVertices.length];

        // Define os índices de cada vértice. 0, 1, 2...
        for (int i = 0; i < ids.length; i++) {
            ids[i] = i;
        }
    }

    /**
     * Retorna o tamanho da heap binária.
     * @return, quantidade de nós da heap. [0, N].
     */
    public int getQuantidade() {
        return quantidade;
    }

    /**
     * Retorna o nó pai de um índice qualquer. 
     * @param i, o índice do filho que se deseja saber o pai. 
     * @return, o índice do pai.
     */
    public int pai(int i) {
        return (i - 1) / 2;
    }

    /**
     * Retorna o nó a esquerda de um índice. 
     * @param i, o índice do nó pai.
     * @return, o índice do nó a esquerda.
     */
    public int esquerda(int i) {
        return 2 * i + 1;
    }

    /**
     * Retorna o nó a direita de um índice. 
     * @param i, o índice do nó pai.
     * @return, o índice do nó a direita.
     */
    public int direita(int i) {
        return 2 * i + 2;
    }

    /**
     * Se a fila de prioridade estiver vazia retorna 
     * false, caso contrário retorna true.
     * @return, false or true.
     */
    public boolean isEmpty() {
        return quantidade == 0;
    }

    /**
     * Realiza o procedimento min-heapify.
     * @param i, o índice no qual se deseja 
     * realiza o procedimento.
     */
    public void minHeapfy(int i) {

    	// Armazena o INDICE a esquerda do índice escolhido da árvore
        int left = esquerda(i);
        
        // Armazena o INDICE a direita do índice escolhido da árvore
        int right = direita(i);
        
        int menor;
        
    	// Se estiver dentro do limite dos INDICES da árvore E o VALOR a esquerda(filho) for menor que o pai.
        if (left <= (quantidade - 1) && elementos[left].getDistancia() < elementos[i].getDistancia()) {
            menor = left;
        } else { // Senão, o PAI eh definido como o menor.
            menor = i;
        }

        // Se estiver dentro do limite dos INDICES da árvore E o VALOR a direita(filho) for menor que o pai.
        if (right <= (quantidade - 1) && elementos[right].getDistancia() < elementos[menor].getDistancia()) {
            menor = right;
        }

        // Se for o caso, realiza a troca.
        if (menor != i) {

        	// Realiza a troca dos índices 
            int aux = ids[elementos[i].getId()];
            ids[elementos[i].getId()] = ids[elementos[menor].getId()];
            ids[elementos[menor].getId()] = aux;

            // Realiza a troca dos vértices.
            Vertice v = elementos[i];
            elementos[i] = elementos[menor];
            elementos[menor] = v;

            // Realiza o procedimento novamente ate que o indice do menor == indice inicial.
            minHeapfy(menor);
        }
    }

    /**
     * Realiza o procedimento build min heap, 
     * isto eh o min_Heapify em todos os índices.
     */
    public void buildMinHeap() {
    	
    	/* Realiza o procedimento de min heapify até que o índice do menor == índice pai */
        for (int i = elementos.length / 2; i >= 0; i--) {
        
            minHeapfy(i);
        }
    }

    /**
     * Realiza o procedimento de extração do menor valor da heap.
     * @return, o menor elemento da fila de prioridade.
     */
    public Vertice heapExtractMin() {

    	// Se a quantidade for menor que zero não tem mais elementos para extrair.
        if (quantidade < 0) {
            return null;
        }

        // Min recebe o menor elemento da heap mínima.
        Vertice min = elementos[0];
        
        // Faz o último elemento(vértice) ser o primeiro. 
        elementos[0] = elementos[quantidade - 1];
        
        //  Define um id inválido para o vértice a ser extraído.
        ids[min.getId()] = -1;
        
        // Redefine o id do que antes era o último elemento da heap.
        ids[elementos[0].getId()] = 0;

        // Decrementa a fila de prioridade
        quantidade--;
        
        // Realiza o procedimento min-heapify para ajustar os valores.
        minHeapfy(0);
        
        // Retorna o vértice mínimo.
        return min;
    }

    /**
     * Procedimento de decreaseKey. Dado um valor 'key', ele é colocado no índice
     * atualizando assim o seu valor antigo e sua posição.
     * @param i, o índice que se deseja dar decrease.
     * @param key, a chave(valor) que será colocado na modificação.
     */
    public void decreaseKey(int i, int key) {
    	
    	// Atualização da key(valor).
        elementos[ids[i]].setDistancia(key);

        // Guarda o índice desejado.
        int indice = ids[i];
        
        // Calcula o índice do pai.
        int pai = pai(indice);
        int filho = indice;
        
        // Guarda as posições do pai e filho.
        int pai_pos = elementos[pai].getId();
        int filho_pos = elementos[filho].getId();

        // Enquanto o índice for maior que o nó superior(zero) e o valor do pai for maior que o do filho. 
        while (i > 0 && elementos[pai].getDistancia() > elementos[filho].getDistancia()) {

        	// Vértice auxiliar com o elemento pai.
            Vertice aux = elementos[pai];
            
            // Troca o vértice do pai com o do filho.
            elementos[pai] = elementos[filho];
            elementos[filho] = aux;

            // Posição auxiliar do vértice pai.
            int temp = ids[pai_pos];
            
            // Troca o índice do pai com o do filho.
            ids[pai_pos] = ids[filho_pos];
            ids[filho_pos] = temp;

            /* Para ir subindo na árvore atualiza os valores do pai e filho para continuar. */
            filho = pai;
            pai = pai(pai);
            // Atualiza as posições/ íncides.
            pai_pos = elementos[pai].getId();
            filho_pos = elementos[filho].getId();
            
        }
    }
}
