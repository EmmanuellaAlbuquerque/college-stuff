package huffman;

/**
 * Representa um nó de uma árvore adaptada para
 * o algoritmo de huffman. 
 * @author Emmanuella Albuquerque.
 */
public class No {
    
	/* O nó pai. */
    private No pai;
    
    /* O nó a esquerda do pai */
    private No filhoEsquerdo;
    
    /* O nó a direita do pai. */
    private No filhoDireito;
    
    /* Número de repetições do símbolo. */
    private int frequencia;
    
    /* Símbolo que representa o nó. */
    private Character simbolo;

    /**
     * Construtor da Classe para um nó filho.
     * @param símbolo, caractere que representa o nó.
     * @param frequência de aparições.
     */
    public No(char simbolo, int frequencia) {
    	
    	/* A frequência. */
        this.frequencia = frequencia;
        
        /* O símbolo que representa o nó. */
        this.simbolo = simbolo;
        
    }
    
    /**
     * Construtor da Classe para um nó pai.
     * @param no1, nó filho esquerdo.
     * @param no2, nó filho direito.
     */
    public No(No no1, No no2) {
    	
    	/*A frequência é a união das frequências dos nós filhos. */
        this.frequencia = no1.getFrequencia() + no2.getFrequencia();
        this.simbolo = '+';
        
        /* Seta os nós como filhos. */
        setEsquerdo(no1);
        setDireito(no2);

        /* Seta o pai dos nós filhos. */
        no1.setPai(this);
        no2.setPai(this);
        
    }

    /**
     * Retorna o nó pai.
     * @return, um nó.
     */
    public No getPai() {
        return pai;
    }

    /**
     * Seta um nó pai.
     * @param pai, um nó.
     */
    public void setPai(No pai) {
        this.pai = pai;
    }

    /**
     * Retorna o nó a esquerda.
     * @return, nó a esquerda.
     */
    public No getEsquerdo() {
        return filhoEsquerdo;
    }

    /**
     * Seta um nó a esquerda.
     * @param esquerdo, um nó.
     */
    public void setEsquerdo(No esquerdo) {
        this.filhoEsquerdo = esquerdo;
    }

    /**
     * Retorna o nó a direita.
     * @return, nó a direita.
     */
    public No getDireito() {
        return filhoDireito;
    }

    /**
     * Seta um nó a esquerda.
     * @param direito, um nó.
     */
    public void setDireito(No direito) {
        this.filhoDireito = direito;
    }

    /**
     * Retorna a frequência de um nó. Isto é,
     * quantas vezes tal símbolo aparece.
     * @return, valor da frequencia.
     */
    public int getFrequencia() {
        return frequencia;
    }

    /**
     * Incrementa o valor da frequência, isto é da quantidade
     * de aparições de um determinado símbolo.
     */
    public void incrementaFrequencia() {
        this.frequencia++;
    }

    /**
     * Retorna o símbolo que representa o nó na árvore.
     * @return, o símbolo do nó.
     */
    public char getSimbolo() {
        return simbolo;
    }

    /**
     * Verifica se determinado nó é folha.
     * @return, o resultado da verificação.
     */
    public boolean verificaSeFolha() {
    	
    	/* Caso ele não tenha nenhum filho, ele é folha. */
        return filhoEsquerdo == null && filhoDireito == null;
        
    }
}