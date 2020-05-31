/**
 * Representa uma Casa do tabuleiro.
 * Possui uma posiçao (i,j) e pode conter uma Peça.
 * 
 * @author Alan Moraes alan@ci.ufpb.br;
 * @author Leonardo Villeth lvilleth@cc.ci.ufpb.br;
 * @author Emmanuella F. Albuquerque emmanuellaalbuquerque@cc.ci.ufpb.br;
 */
public class Casa {
    private int x;
    private int y;
    private Peca peca;
    
    public Casa( int x, int y) {
        this.x = x;
        this.y = y;
        this.peca = null;
    }

    /**
     * @param peca a Peça a ser posicionada nesta Casa.
     */
    public void colocarPeca(Peca peca) {
        this.peca = peca;
    }

    /**
     * Remove a peca posicionada nesta casa, se houver.
     */
    public void removerPeca() {
        peca = null;
    }

    /**
     * @return a Peca posicionada nesta Casa, ou Null se a casa estiver livre.
     */
    public Peca getPeca() {
        return peca;
    }

    /**
     * @return true se existe uma peça nesta casa, caso contrario false.
     */
    public boolean possuiPeca() {
        return peca != null;
    }

    /**
     * @return retorna o valor da coordenada X.
     */
    public int getX() {
        return x;
    }

    /**
     * @return retorna o valor da coordenada Y.
     */
    public int getY() {
        return y;
    }
}
