package huffman;

import java.io.File;
import java.io.IOException;

public class Main {
    
    public static void main(String[] args) throws IOException {
    	
    	File file = new File("/home/manu/eclipse-workspace/Huffman/src/huffman/file.txt");
    	
        Huffman huff = new Huffman(file);
        
        huff.codificacao();
        huff.processDecodificacao();
        
    }
}
