import javax.swing.JOptionPane;
/**
 * Representa uma Peça do jogo.
 * Possui uma casa e um tipo associado.
 * 
 * @author Alan Moraes alan@ci.ufpb.br;
 * @author Leonardo Villeth lvilleth@cc.ci.ufpb.br;
 * @author Emmanuella F. Albuquerque emmanuellaalbuquerque@cc.ci.ufpb.br;
 */
public class Peca {

    public static final int PEDRA_BRANCA = 0;
    public static final int DAMA_BRANCA = 1;
    public static final int PEDRA_VERMELHA = 2;
    public static final int DAMA_VERMELHA = 3;

    private Casa casa;
    private int tipo;
    private String sentido;

    public Peca(Casa casa, int tipo) {
        this.casa = casa;
        this.tipo = tipo;
        casa.colocarPeca(this);
        direcoesIniciais(this);
    }

    /**
     * Determina uma nova casa para a peça.
     * @param casa, é a nova casa.
     */
    public Casa setCasa(Casa casa){
        return this.casa = casa;
    }

    /**
     * Movimenta a peca para uma nova casa.
     * @param origem, casa que contém a peça.
     * @param destino, nova casa que ira conter esta peca.
     * @param peca, é a peça que irá mover.
     * @return retorna true se movimento normal aconteceu ou false se não aconteceu.
     */
    public boolean realizaMovimentoNormal(Casa origem, Casa destino, Peca peca) { 
        if( getDirecao() == "positivo"){ // Se pedra branca ou o sentido dá peça for positivo.
            if(MovimentoNormalBranca(origem, destino) == true){ // Verifica se o movimento está correto.
                origem.removerPeca();
                return moverNormal(origem, destino); // realiza o movimento e retorna true ou não realiza e retorna false.
            }
        }

        if( getDirecao() == "negativo"){ // Se pedra vermelha ou o sentido dá peça for negativo.
            if(MovimentoNormalVermelha(origem, destino) == true){ // Verifica se o movimento está correto.
                origem.removerPeca();
                return moverNormal(origem, destino); // realiza o movimento e retorna true ou não realiza e retorna false.
            }
        }
        return false;
    }

    /**
     * Move para uma casa vazia.
     * @param origem, casa que contém a peça.
     * @param destino, nova casa que ira conter esta peca.
     * @return retorna true se movimento possível ou false se movimento inválido.
     */
    public boolean moverNormal(Casa origem, Casa destino){
        if(destino.getPeca() == null){
            destino.colocarPeca(this);
            origem = destino;
            return true;
        }
        else{ // Indica movimento inválido se existir uma peça na casa destino.
            origem.colocarPeca(this);
            JOptionPane.showMessageDialog(null, "Movimento inválido");
            return false;
        }
    }

    /**
     * Verifica se o movimento da pedra branca está correto, ou seja, o movimento positivo/para cima.
     * @param origem, casa que contém a peça.
     * @param destino, nova casa que ira conter esta peca.
     * @return retorna true se movimento certo.
     */
    public boolean MovimentoNormalBranca(Casa origem, Casa destino){                    // nordeste (X+1, Y+1) ou noroeste(X-1, Y+1)
        if((destino.getX() == origem.getX()+1 && destino.getY() == origem.getY()+1) || //verifica movimento nordeste ou noroeste
        (destino.getX() == origem.getX()-1 && destino.getY() == origem.getY()+1)){     // (movimento das pedras brancas)
            return true;
        }
        else{ 
            return false;
        }
    }

    /**
     * Verifica se o movimento da pedra vermelha está correto, ou seja, o movimento negativo/para baixo.
     * @param origem, casa que contém a peça.
     * @param destino, nova casa que ira conter esta peca.
     * @return retorna true se movimento certo.
     */
    public boolean MovimentoNormalVermelha(Casa origem, Casa destino){                    //sudoeste(X-1, Y-1) ou sudeste (X+1, Y-1) 
        if((destino.getX() == origem.getX()-1 && destino.getY() == origem.getY()-1) ||   //verifica movimento sudoeste ou sudeste
        (destino.getX() == origem.getX()+1 && destino.getY() == origem.getY()-1)){      // (movimento das pedras vermelhas)
            return true;
        }
        else{ 
            return false;
        }
    }

    /**
     * Valor    Tipo
     *   0   Branca (Pedra)
     *   1   Branca (Dama)
     *   2   Vermelha (Pedra)
     *   3   Vermelha (Dama)
     * @return o tipo da peca.
     */
    public int getTipo() {
        return tipo;
    }

    /**
     * Retorna a cor de uma peça em uma string.
     * @return String (tipo), retorna a cor da peça.
     */
    public String getTipoString() {
        String tipo = " ";
        if(getTipo() == 0 || getTipo() == 1){  // pedra e dama brancas
            tipo = "branca";
        }
        if(getTipo() == 2 || getTipo() == 3){  // pedra e dama vermelhas
            tipo = "vermelha";
        }
        return tipo;
    }

    /**
     * Determina as direções iniciais de cada peça. 
     * @return String (sentido), retorna o sentido inicial da peça.
     */
    public String direcoesIniciais(Peca peca){
        if(peca != null){
            if(peca.getTipo() == 0 ||  peca.getTipo() == 3 ){ // sentidos iniciais da pedra branca e dama vermelha são positivos 
                return sentido = "positivo";
            }
            if(peca.getTipo() == 2 || peca.getTipo() == 1 ){  // // sentidos iniciais da pedra vermelha e dama branca são negativos 
                return sentido = "negativo";
            }
        }
        return null; // se peça nula, retorna nulo
    }

    /**
     * Determina as direções atuais da peça. 
     * @return String (sentido), retorna o sentido atual da peça.
     */
    public String getDirecao(){
        return sentido;
    }

    /**
     * Troca o sentido da peça.
     * @param destino, destino que se encontra a peça.
     */
    public void trocarSentido(Casa destino){
        if(destino.getPeca() != null){
            if(destino.getY() == 7){ // se peça está na extremidade Y = 7, movimento é de cima pra baixo(negativo)
                sentido = "negativo";
            }
            if(destino.getY() == 0){ // se peça está na extremidade Y = 0, movimento é de baixo pra cima(positivo)
                sentido = "positivo";
            }
        }
    }
}
