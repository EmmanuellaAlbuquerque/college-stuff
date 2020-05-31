import java.util.ArrayList;
import java.util.Stack;

/**
 * Representa um grafo ponderado. Na qual a matriz de adjacência possui os pesos,
 * isto é, o valor das distâncias entre os vertices do mesmo. 
 * @author Emmanuella Albuquerque e Vanessa Pessoa.
 */
public class Grafo {

	// A matriz de adjacência do grafo ponderado.
    int[][] matrizAdj;
    // Os vertices do grafo.
    public Vertice[] vertices;

    /**
     * Construtor da classe recebe uma matriz de adjacência com as distâncias entre os vértices.
     * @param matrizAdj, contém os pesos entre os vértices.
     */
    public Grafo(int[][] matrizAdj) {
    	
        this.matrizAdj = matrizAdj;
        // Vertices da matriz, ex.: em 10x10: 10 vertices
        this.vertices = new Vertice[matrizAdj.length];

        // Constroe cada vertice
        for (int i = 0; i < vertices.length; i++) {
            vertices[i] = new Vertice(i);
        }
    }

    /**
     * Retorna a distância entre 2 vertices v1 e v2.
     * @param v1, vertice 1.
     * @param v2, vertice 2;
     * @return peso/distância dos vertices.
     */
    public int getPeso(int v1, int v2) {
        return matrizAdj[v1][v2];
    }

    /**
     * Algoritmo de Dijkstra, realiza o procedimento para achar o
     * caminho mínimo de um vértice para outro.
     * @param s, source id do vertice.
     */
    public void dijkstra(int src) {
    	
    	// Array que apresentará as distâncias mínimas entre os vértices.
        int[] distancias = new int[matrizAdj.length];
        // Array que define se um vertice foi visitado ou não.
        boolean[] visitados = new boolean[vertices.length];

        // INITIALIZE_SINGLE_SOURCE
        for (int i = 0; i < vertices.length; i++) {
        	// Seta as distâncias entre os vértices como a maior possível.
            vertices[i].setDistancia(Integer.MAX_VALUE);
            // Define como visitado.
            visitados[i] = true;
        }

        // Seta o anterior de 0.
        vertices[src].setAnterior(-1);
        // Seta a distância da fonte, 0 para 0.
        vertices[src].setDistancia(0);

        // Define a fila de prioridade com os vértices do grafo.
        FilaDePrioridade fila = new FilaDePrioridade(this.vertices);
        // Redefine como min heap.
        fila.buildMinHeap();

        // Enquanto a fila de prioridade não estiver vazia.
        while (!fila.isEmpty()) {
        	
        	// Extraí o menor elemento da mesma.
            Vertice u = fila.heapExtractMin();

            // Apresenta os vértices adjacentes.
            ArrayList<Vertice> adjacentes = new ArrayList<Vertice>();
            
            // Redefine os elementos adjacêntes.
            for (int i = 0; i < matrizAdj.length; i++) {
            	
                if (matrizAdj[u.getId()][i] != 0) {
                    
                	// Adiciona os vértices da linha na lista de adjacência 
                	adjacentes.add(vertices[i]);
                	
                }
                
            }

            // Define a distância dado o id(vértice)
            distancias[u.getId()] = u.getDistancia();

            // Para todo vértice v da lista de adjacência
            for (Vertice v : adjacentes) {
            	
            	/* Se o vértice tiver sido visitado e se a distância do vértice(destination, v) for maior que
            	 * a distância do vértice(adj, u) + (distância do (destination, v) - distância do (adj, u))*/
            	if (!(v == null) && visitados[v.getId()] 
            			&& v.getDistancia() > u.getDistancia() + getPeso(u.getId(), v.getId())) {
            		
            		// Refine o anterior como o id do vértice u.
	                v.setAnterior(u.getId());
	                // Atualiza os valores com a nova menor distância.
	                fila.decreaseKey(v.getId(), u.getDistancia() + getPeso(u.getId(), v.getId()));
                        
                    }
                
            }
            
        }
        
        //mostraMatrizAdj(matrizAdj);

        // Mostra o menor caminho da src até o último nó no console.
       System.out.print("Caminho Mínimo de " + src + " : " + (vertices.length - 1) 
    		   + " = " + vertices[(vertices.length - 1)].getDistancia() + ", ");
        
       // Mostra o percurso de 0 até o último elemento(nó) do grafo.
        percurso(vertices.length - 1);
        
    }

    /**
     * Apresenta o percurso entre o elemento principal 0 e a source que
     * se deseja saber o caminho.
     * @param source, ex.: elemento de 0 até source.
     */
    public void percurso(int source) {
    	
    	// Pilha que guardará os ids para chegar ao último vértice.
        Stack<Integer> pilha = new Stack<>();

        // Guarda o elemento final(desejado), que é o próprio source.
        pilha.push(source);
        // Atualiza i com o id do último vértice.
        int i = source;

        // Enquanto não chegar ao vértice zero.
        while (i != 0) {
        	
        	/* Atualiza o i, com o vértice anterior utilizado para chegar ao caminho mínimo. */
            i = vertices[i].getAnterior();
            // Coloca o i, na pilha.
            pilha.push(i);
            
        }

        System.out.print("Percurso " + 0 + " : " + source + " = ");
        
        // Desempinha os índices(ids dos vértices).
        while (!pilha.isEmpty()) {
            System.out.print(pilha.pop() + " ");
        }

        System.out.println();
    }

    /**
     * Mostra os elementos de uma matriz no console.
     * @param matriz, a matriz de Adjacência.
     */
    public void mostraMatrizAdj(int[][] matriz) {
    	
    	// Linha:
        for (int i = 0; i < matriz.length; i++) {
        	// Coluna:
        	for(int j = 0; j < matriz.length; j++) {
        		
        		System.out.print(matriz[i][j] + " ");
        	}
        	
        	System.out.println();
        }
        
    }
    
}
