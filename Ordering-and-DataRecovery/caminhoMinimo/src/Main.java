import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;

/**
 * Main: Instância os elementos: Leitura de arquivo;
 * Criação da matriz a partir da leitura; Utilização dos 
 * métodos do algoritmo do caminho mínimo.
 * @author Emmanuella Albuquerque e Vanessa Pessoa.
 */
public class Main {

    public static void main(String[] args) {
    	
    	// Define as 4 matrizes para os 4 arquivos.
        int[][] matriz1 = null;
        int[][] matriz2 = null;
        int[][] matriz3 = null;
        int[][] matriz4 = null;

        // Tenta abrir os arquivos, case dê erro vai para o catch.
        try {
        	
        	// Lê o arquivo dado o endereço.
            FileReader file1 = new FileReader("/home/manu/eclipse-workspace/caminhoMinimo/src/dij10.txt");
            BufferedReader readFile1 = new BufferedReader(file1);
            
            // Lê o arquivo dado o endereço.
            FileReader file2 = new FileReader("/home/manu/eclipse-workspace/caminhoMinimo/src/dij20.txt");
            BufferedReader readFile2 = new BufferedReader(file2);
            
            // Lê o arquivo dado o endereço.
            FileReader file3 = new FileReader("/home/manu/eclipse-workspace/caminhoMinimo/src/dij40.txt");
            BufferedReader readFile3 = new BufferedReader(file3);
            
            // Lê o arquivo dado o endereço.
            FileReader file4 = new FileReader("/home/manu/eclipse-workspace/caminhoMinimo/src/dij50.txt");
            BufferedReader readFile4 = new BufferedReader(file4);

            // Cria as 4 matrizes.
            matriz1 = criaMatriz(readFile1);
            matriz2 = criaMatriz(readFile2);
            matriz3 = criaMatriz(readFile3);
            matriz4 = criaMatriz(readFile4);
            
            // Fecha os leitores.
            readFile1.close();
            readFile2.close();
            readFile3.close();
            readFile4.close();

            
        } catch (IOException ex) {
        	
            ex.printStackTrace();
            
        }

        // Mostra no console o resultado do método de dijkstra.
        System.out.println("Matriz 1:");
        Grafo graph1 = new Grafo(matriz1);
        graph1.dijkstra(0);
        System.out.println("----------------------------------------------------------------");
        
        System.out.println("Matriz 2:");
        Grafo graph2 = new Grafo(matriz2);
        graph2.dijkstra(0);
        System.out.println("----------------------------------------------------------------");
        
        System.out.println("Matriz 3:");
        Grafo graph3 = new Grafo(matriz3);
        graph3.dijkstra(0);
        System.out.println("----------------------------------------------------------------");
        
        System.out.println("Matriz 4:");
        Grafo graph4 = new Grafo(matriz4);
        graph4.dijkstra(0);
        System.out.println("----------------------------------------------------------------");
        

    }
    
    /**
     * @param readFile, leitor de arquivo BufferedReader.
     * @return, a matriz de adjacência criada.
     * @throws IOException, exceção caso ocorra problema com a entrada de dados.
     */
    public static int[][] criaMatriz(BufferedReader readFile) throws IOException {
    	
    	// Divide(Split) no espaço em branco encontrado.
        String[] line = (readFile.readLine()).split("\\s");
        
        // Primeira linha contém a quantidade de elementos NxN.
        int n = Integer.parseInt(line[0]);
        
        // Cria a matriz com base no dado.
        int[][] matriz = new int[n][n];

        for (int i = 0; i < n - 1 && line != null; i++) {

        	// Divide(Split) no espaço em branco encontrado.
            line = (readFile.readLine()).split("\\s");

            for (int j = i + 1, k = 0; j < n; j++) {

            	/* Diagonal principal da matriz de adjacência é sempre zero. */
                if (i == j) {
                	
                    matriz[i][j] = 0;
                    
                } 
                
                else {
                	
                	// Lê do arquivo e adiciona na matriz.
                    matriz[i][j] = Integer.parseInt(line[k]);
                    // Espelha o valor do índice i,j com j, i.
                    matriz[j][i] = matriz[i][j];
                    k++;
                }
            }
        }
        
        // Retorna a matriz de adjacência criada a partir do arquivo.
        return matriz;
    }
}
