/**
 * Representa um vértice. Um nó de um grafo ponderado, que
 * apresenta um id(índice na fila), uma distância(peso) e o
 * vértice anterior(que apresenta a menor distância do atual).
 * @author Emmanuella Albuquerque e Vanessa Pessoa.
 *
 */
public class Vertice {
    
	// Id, índice, posição do vértice na fila. 
    private int id;
    // A distância, o peso do vértice.
    private int distancia;
    // Id, posição do vértice anterior.
    private int anterior;
    
    /**
     * Construtor da classe recebe um índice que representará
     * a posição do vértice na fila de prioridade.
     * @param id, índice do vértice.
     */
    public Vertice(int id) {
    	
    	// Define a posição dada a entrada.
        this.id = id;
        
        // Define a distância default
        this.distancia = 0;
        
        // Define um anterior default
        this.anterior = -1;
    }

    /**
     * Retorna o índice do vértice anterior.
     * @return, id do anterior.
     */
    public int getAnterior() {
        return anterior;
    }

    /**
     * Seta um valor para a posição de um vértice.
     * @param anterior, um id.
     */
    public void setAnterior(int anterior) {
        this.anterior = anterior;
    }
    
    /**
     * Retorna o índice/posição do vértice.
     * @return, o índice.
     */
    public int getId() {
        return this.id;
    }
    
    /**
     * Retorna a distância atual do vértice principal até ele.
     * @return, a distância.
     */
    public int getDistancia() {
        return distancia;
    }
    
    /**
     * Seta uma nova distância para o vértice.
     * @param distancia, a distância.
     */
    public void setDistancia(int distancia) {
        this.distancia = distancia;
    }
    
}
