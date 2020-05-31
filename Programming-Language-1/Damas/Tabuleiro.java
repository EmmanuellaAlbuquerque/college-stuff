/**
 * O Tabuleiro do jogo. 
 * Responsçvel por armazenar as 64 casas.
 * 
 * @author Alan Moraes alan@ci.ufpb.br;
 * @author Leonardo Villeth lvilleth@cc.ci.ufpb.br;
 * @author Emmanuella F. Albuquerque emmanuellaalbuquerque@cc.ci.ufpb.br;
 */
public class Tabuleiro {
    private Casa[][] casas;
    
    public Tabuleiro() {
        casas = new Casa[8][8];
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                Casa casa = new Casa(x, y);
                casas[x][y] = casa;
            }
        }
    }

    /**
     * @param x linha
     * @param y coluna
     * @return Casa na posicao (x,y)
     */
    public Casa getCasa(int x, int y) {
        if(x >= 0 && x < 8 && y >= 0 && y < 8) // se casa estiver dentro dos limites de 0 a 7 
            return casas[x][y];
        else
            return null;                      // senão retorne null
    }
}