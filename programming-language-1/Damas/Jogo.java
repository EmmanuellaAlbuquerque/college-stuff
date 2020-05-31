import javax.swing.JOptionPane;
/**
 * Armazena o tabuleiro e é responsável por posicionar/ mover as peças.
 * @author Alan Moraes alan@ci.ufpb.br;
 * @author Leonardo Villeth lvilleth@cc.ci.ufpb.br;
 * @author Emmanuella F. Albuquerque emmanuellaalbuquerque@cc.ci.ufpb.br;
 */
public class Jogo {
    public Peca pecaAtacante;
    private Tabuleiro tabuleiro;
    private Casa pecaAtual;
    private String jogador;

    public Jogo() {
        tabuleiro = new Tabuleiro();
        criarPecas();
        jogador = "jogador1";
    }

    /**
     * Posiciona peças no tabuleiro.
     * Utilizado na inicialização do jogo.
     */
    private void criarPecas() {
        for(int i = 0; i < 8; i++){            // preenche a parte do i/x de 0 a 7
            for(int j = 0; j < 3; j++){        // limitado pelo j/y de 0 a 3
                if(i % 2 == j % 2){            // se casa escura, o módulo sempre vai dar igual
                    Casa casa1 = tabuleiro.getCasa(i, j);
                    Peca peca1 = new Peca(casa1, Peca.PEDRA_BRANCA);
                }
            }
        }

        for(int i = 0; i < 8; i++){             // preenche a parte do i/x de 0 a 7
            for(int j = 5; j < 8; j++){         // limitado pelo j/y de 5 a 7
                if(i % 2 == j % 2){             // se casa escura, o módulo sempre vai dar igual
                    Casa casa2 = tabuleiro.getCasa(i, j);
                    Peca peca2 = new Peca(casa2, Peca.PEDRA_VERMELHA);
                }
            }
        }       
    }

    /**
     * Retorna o jogador de acordo com a peça encontrada.
     * @param casa, casa onde a peça foi encontrada.
     * @return String jogador, retorna o jogador dado o tipo de peça.
     */
    public String getJogador(Casa casa){
        if(casa.getPeca() != null){
            if (casa.getPeca().getTipoString().equals("branca")){     // jogador1 corresponde a peça branca.
                return "jogador1";
            }
            if (casa.getPeca().getTipoString().equals("vermelha")){  //jogador2 corresponde a peça vermelha.
                return "jogador2";
            }
        }
        return null; // retorna null se não tiver peça em casa.
    }

    /**
     * Verifica o jogador, faz a troca do jogador.
     */
    public void verificaJogador(){
        if(jogador.equals("jogador1")){  // faz a troca do jogador teórico/string
            jogador = "jogador2";
        }
        else
        if(jogador.equals("jogador2")){  // faz a troca do jogador teórico/string
            jogador = "jogador1";   
        }
    }

    /**
     * Retorna a cor da peça de acordo com o jogador encontrado.
     * @return String, retorna a cor.
     */
    public String pecaJogador(){
        if(jogador.equals("jogador1")){
            return "brancas";
        }
        else
        if(jogador.equals("jogador2")){
            return "vermelhas";   
        }
        return null;
    }

    /**
     * Comanda uma Peça na posição (origemX, origemY) fazer um movimento 
     * para (destinoX, destinoY).
     * @param origemX, linha da Casa de origem.
     * @param origemY, coluna da Casa de origem.
     * @param destinoX, linha da Casa de destino.
     * @param destinoY, coluna da Casa de destino.
     */
    public void moverPeca(int origemX, int origemY, int destinoX, int destinoY) {
        Casa origem = tabuleiro.getCasa(origemX, origemY);
        Casa destino = tabuleiro.getCasa(destinoX, destinoY);
        Peca peca = origem.getPeca();
        pecaAtual = origem;
        // se peçaAtacante = peça da origem, está em movimento de ataque 
        if(pecaAtacante == null || origem.getPeca() == pecaAtacante){ // se peçaAtacante == null é o primeiro ataque ou a peça saiu do modo de ataque
            if(getJogador(origem) == jogador){                        // verifica se é a vez do jogador certo
                if(seCasaEscura(destinoX, destinoY) == true){        // Só move se a casa for COR_ESCURA.
                    if(peca.realizaMovimentoNormal(origem, destino, peca) == true){
                        origem = destino;
                        verificaSeVirouDama(destino);
                        verificaJogador();                          // se movimento normal foi realizado, troca de jogador. 
                    }
                    else{
                        realizaMovimentoDeAtaque(origem,destino,peca);
                    }
                }           
            }
            else{
                JOptionPane.showMessageDialog(null, "                 ERROR: \n  Vez das peças. " + pecaJogador());             
            }
            verificaVitoria();
        }
        else{
            JOptionPane.showMessageDialog(null, "Jogador " + pecaJogador().replace("as", "o") + " você deve comer todas as peças possíveis!");             
        }
    }

    /**
     * Realiza o movimento de ataque.
     * @param origem, casa em que se encontra a peça atualmente.
     * @param destino, casa pra onde a peça irá se deslocar.
     * @param peça, peça que ira se movimentar.
     */
    public void realizaMovimentoDeAtaque(Casa origem, Casa destino, Peca peca){
        if(pecaAtacante == null || origem.getPeca() == pecaAtacante){
            if(ModoDeAtaque(origem, destino) == true){
                if(verificaNSNS(origem, destino) == true){ // verifica nordeste, sudeste, noroeste e sudoeste
                    jogador = getJogador(origem);
                    if(MovimentoDeAtaque(origem, destino, peca) == true){
                        verificaJogador();  // se movimento de ataque foi realizado, troca de jogador. 
                        verificaSeVirouDama(destino);
                        peca.trocarSentido(origem);
                    }
                    origem = destino;
                    pecaAtacante = origem.getPeca(); // se movimento de ataque foi realizado, a peçaAtacante deixa de ser null.
                    pecaAtacante.setCasa(origem);
                }
                verificaSePodeSairDoModoDeAtaque(origem, destino, peca);
            }
        }
    }

    /**
     * Verifica modo de ataque.
     * @param origem, casa em que se encontra a peça atualmente.
     * @param destino, casa pra onde a peça irá se deslocar.
     * @return boolean, true se modo de ataque ativo.
     */
    public boolean ModoDeAtaque(Casa origem, Casa destino){
        if(jogador == getJogador(pecaAtual)){
            if(destino.getX() == origem.getX()+2 || destino.getX() == origem.getX()-2 &&    // verifica os pares de movimento de 2 possíveis
            destino.getY() == origem.getY()+2 || destino.getY() == origem.getY()-2){        // Ex: se (2,2) --> (4,4),(4,0),(0,0) e (0,4)
                return true;
            }
        }
        return false;
    }

    /**
     * Verifica se pode sair do movimento de ataque.
     * @param origem, casa em que se encontra a peça atualmente.
     * @param destino, casa pra onde a peça irá se deslocar.
     * @param peça, peça que ira se movimentar.
     */
    public void verificaSePodeSairDoModoDeAtaque(Casa origem, Casa destino, Peca peca){
        if(peca.realizaMovimentoNormal(origem, destino, peca) == false){
            verificaJogador();      //ajusta a vez do jogador.
        }
        if(destino.getX() < 8 && destino.getY() < 8 ){
            if(verificaSeTemPecaNordeste(origem, destino, tabuleiro) == false && 
            verificaSeTemPecaSudeste(origem, destino, tabuleiro) == false  &&        // se não tem peça em nenhum sentido
            verificaSeTemPecaSudoeste(origem, destino, tabuleiro) == false &&           
            verificaSeTemPecaNoroeste(origem, destino, tabuleiro) == false ){
                verificaJogador();    // se não tem peça em nenhum sentido, significa não terá mais movimento de ataque com a mesma peça
                pecaAtacante = null;  // Assim, peçaAtacante virá null.
            }
        }
    }

    /**
     * Verifica em todas as direções de ataques possíveis se tem peças para comer.
     * @param origem, casa em que se encontra a peça atualmente.
     * @param destino, casa pra onde a peça irá se deslocar.
     * @return boolean, true se tiver peças para comer.
     */
    public boolean verificaNSNS(Casa origem, Casa destino){
        if(verificaSeTemPecaNordeste(origem, destino, tabuleiro) == true || 
        verificaSeTemPecaSudeste(origem, destino, tabuleiro) == true  ||        // se tem pelo menos uma peça a ser comida em alguma direção
        verificaSeTemPecaSudoeste(origem, destino, tabuleiro) == true ||
        verificaSeTemPecaNoroeste(origem, destino, tabuleiro) == true ){
            return true;             
        }
        return false;
    }

    /**
     * Verifica se a casa pra onde vai mover é escura.
     * @param destinoX, valor da coordenada X da casa.
     * @param destinoY, valor da coordenada Y da casa.
     * @return boolean, true se casa escura.
     */
    public boolean seCasaEscura(int destinoX, int destinoY){    // só movimenta as peças na casa Marrom(escura) do tabuleiro.
        if(destinoX % 2 == destinoY % 2){                      // Ex: se (2,2) -> módulo entre de cada um irá dar 0
            return true;                                      // Ex: se (5,3) -> módulo entre de cada um irá dar 1
        }                                                    // Ex: se (5,2) -> módulo de um vai dar 1 e do outro 0
        else{                                               // Ex: se (3,2) -> módulo de um vai dar 1 e do outro 0
            JOptionPane.showMessageDialog(null, "Movimento inválido/CASA CLARA!"); 
            return false;
        }
    }

    /**
     * Realiza movimento de ataque e come a peça.
     * @param origem, casa em que se encontra a peça atualmente.
     * @param destino, casa pra onde a peça irá se deslocar.
     * @param peça, peça que irá comer a outra.
     * @return boolean, true se comeu a peça.
     */
    public boolean MovimentoDeAtaque(Casa origem, Casa destino, Peca peca){
        if(destino.getX() == origem.getX()+2 || destino.getX() == origem.getX()-2 ||  // dado o par de movimento de 2 possíveil
        destino.getY() == origem.getY()+2 || destino.getY() == origem.getY()-2){
            origem.removerPeca();
            if(destino.getPeca() == null){       // se no destino não tiver peça
                destino.colocarPeca(peca);
                if(destino.getX() < 8 && destino.getY() < 8 ){
                    comerPeca(origem, destino, tabuleiro);
                    return true;
                }
                origem = destino;
            }
        }
        return false;
    }

    /**
     * Verifica se a pedra virou dama
     * Se elas se moverem para as extremidades Y = 7 ou Y = 0.
     * @param destino, casa pra onde a peça irá se deslocar.
     */
    public void verificaSeVirouDama(Casa destino){
        if(destino.getPeca() != null){
            if(destino.getPeca().getTipoString() == "branca"){
                if(destino.getX() == 1 && destino.getY() == 7 || destino.getX() == 3 && destino.getY() == 7 || // ou destino.getY() == 7
                destino.getX() == 5 && destino.getY() == 7  || destino.getX() == 7 && destino.getY() == 7 ){
                    destino.removerPeca();
                    Peca pecaDamaBranca =  new Peca(destino, 1);    //troca pedra branca por dama branca
                }
            }

            if(destino.getPeca().getTipoString() == "vermelha"){
                if(destino.getX() == 0 && destino.getY() == 0 || destino.getX() == 2 && destino.getY() == 0 ||  // ou destino.getY() == 0
                destino.getX() == 4 && destino.getY() == 0  || destino.getX() == 6 && destino.getY() == 0 ){
                    destino.removerPeca();
                    Peca pecaDamaVermelha =  new Peca(destino, 3);  //troca pedra vermelha por dama vermelha
                }
            }
        }
    }

    /**
     * Realiza o ato de comer a peça.
     * @param origem, casa em que se encontra a peça atualmente.
     * @param destino, casa pra onde a peça irá se deslocar.
     * @param tabuleiro, tabuleiro do jogo.
     * @return boolean, true se comeu a peça.
     */
    public boolean comerPeca(Casa origem, Casa destino, Tabuleiro tabuleiro){
        Casa destinoPulado = tabuleiro.getCasa((origem.getX() + destino.getX())/2, (origem.getY() + destino.getY())/2 ); // se encontra no meio
        if(destino.getPeca().getTipoString() != destinoPulado.getPeca().getTipoString()){
            if(destinoPulado.getPeca() != null){        // onde a peça que irá ser comida se encontra
                destinoPulado.removerPeca();
                return true;
            }
            else
                return false;
        }
        return false;
    }

    /**
     * Verifica se tem peça ao nordeste pra comer.
     * @param origem, casa em que se encontra a peça atualmente.
     * @param destino, casa pra onde a peça irá se deslocar.
     * @param tabuleiro, tabuleiro do jogo.
     * @return boolean, true se tem peça no nordeste.
     */
    public boolean verificaSeTemPecaNordeste(Casa origem, Casa destino, Tabuleiro tabuleiro){
        Casa origemDaPecaASerComida = tabuleiro.getCasa(origem.getX() + 1, origem.getY() +1); // peça do meio
        Casa maisAFrente = tabuleiro.getCasa(origem.getX() + 2, origem.getY() + 2);            
        if(maisAFrente == null){    // Significa que não tem casa a frente para verificar, logo não tem peça pra comer
            return false;
        }
        if(origemDaPecaASerComida.getPeca() != null){
            if(maisAFrente.getPeca() == null){ // destino da peça tem que ser vazio
                if(maisAFrente != null){       // casa deve existir
                    if(origem.getPeca().getTipoString() != origemDaPecaASerComida.getPeca().getTipoString()){ // se as peças forem de tipos diferentes
                        return true;                                         // desse modo se a peça for da mesma cor não é considerada na verificação
                    }
                }
            }
        }
        else
            return false;
        return false;
    }

    /**
     * Verifica se tem peça a sudoeste pra comer.
     * @param origem, casa em que se encontra a peça atualmente.
     * @param destino, casa pra onde a peça irá se deslocar.
     * @param tabuleiro, tabuleiro do jogo.
     * @return boolean, true se tem peça no sudoeste.
     */
    public boolean verificaSeTemPecaSudoeste(Casa origem, Casa destino, Tabuleiro tabuleiro){
        Casa origemDaPecaASerComida = tabuleiro.getCasa(origem.getX() - 1, origem.getY() - 1);  // peça do meio   
        Casa maisAFrente = tabuleiro.getCasa(origem.getX() - 2, origem.getY() - 2);
        if(maisAFrente == null){   // Significa que não tem casa a frente para verificar, logo não tem peça pra comer
            return false;
        }
        if(origemDaPecaASerComida.getPeca() != null){
            if(maisAFrente.getPeca() == null){  // destino da peça tem que ser vazio
                if(maisAFrente != null){        // casa deve existir       
                    if(origem.getPeca().getTipoString() != origemDaPecaASerComida.getPeca().getTipoString()){  // se as peças forem de tipos diferentes
                        return true;                                          // desse modo se a peça for da mesma cor não é considerada na verificação
                    }
                }
            }
        }
        else
            return false;
        return false;
    }

    /**
     * Verifica se tem peça a noroeste pra comer.
     * @param origem, casa em que se encontra a peça atualmente.
     * @param destino, casa pra onde a peça irá se deslocar.
     * @param tabuleiro, tabuleiro do jogo.
     * @return boolean, true se tem peça a noroeste.
     */
    public boolean verificaSeTemPecaNoroeste(Casa origem, Casa destino, Tabuleiro tabuleiro){
        Casa origemDaPecaASerComida = tabuleiro.getCasa(origem.getX() - 1, origem.getY() + 1);  // peça do meio
        Casa maisAFrente = tabuleiro.getCasa(origem.getX() - 2, origem.getY() + 2);
        if(maisAFrente == null){  // Significa que não tem casa a frente para verificar, logo não tem peça pra comer
            return false;
        }
        if(origemDaPecaASerComida.getPeca() != null){
            if(maisAFrente.getPeca() == null){  // destino da peça tem que ser vazio
                if(maisAFrente != null){        // casa deve existir  
                    if(origem.getPeca().getTipoString() != origemDaPecaASerComida.getPeca().getTipoString()){   // se as peças forem de tipos diferentes
                        return true;                                           // desse modo se a peça for da mesma cor não é considerada na verificação
                    }
                }
            }
        }
        else
            return false;
        return false;
    }

    /**
     * Verifica se tem peça a sudeste pra comer.
     * @param origem, casa em que se encontra a peça atualmente.
     * @param destino, casa pra onde a peça irá se deslocar.
     * @param tabuleiro, tabuleiro do jogo.
     * @return boolean, true se tem peça a sudeste.
     */
    public boolean verificaSeTemPecaSudeste(Casa origem, Casa destino, Tabuleiro tabuleiro){
        Casa origemDaPecaASerComida = tabuleiro.getCasa(origem.getX() + 1, origem.getY() - 1);  // peça do meio
        Casa maisAFrente = tabuleiro.getCasa(origem.getX() + 2, origem.getY() - 2);
        if(maisAFrente == null){  // Significa que não tem casa a frente para verificar, logo não tem peça pra comer
            return false;
        }
        if(origemDaPecaASerComida.getPeca() != null){
            if(maisAFrente.getPeca() == null){  // destino da peça tem que ser vazio
                if(maisAFrente != null){        // casa deve existir       
                    if(origem.getPeca().getTipoString() != origemDaPecaASerComida.getPeca().getTipoString()){   // se as peças forem de tipos diferentes
                        return true;                                           // desse modo se a peça for da mesma cor não é considerada na verificação
                    }
                }
            }
        }
        else
            return false;
        return false;
    }

    /**
     * Pega o tabuleiro.
     * @return o Tabuleiro em jogo.
     */
    public Tabuleiro getTabuleiro() {
        return tabuleiro;
    }

    /**
     * Retorna a quantidade de peças.
     * @return tamanho, valor da quantidade de peças.
     */
    public int QuantidadeDePecas(){
        int tamanho = 0;
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                if(tabuleiro.getCasa(x, y).possuiPeca()){
                    tamanho = tamanho + 1;
                }
            }
        }
        return tamanho;
    }

    /**
     * Retorna a quantidade de peças brancas.
     * @return tamanho, valor da quantidade de peças brancas.
     */
    public int QuantidadeDePecasBrancas(){
        int tamanho = 0;
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                if(tabuleiro.getCasa(x,y).getPeca() != null){
                    if(tabuleiro.getCasa(x, y).getPeca().getTipoString() == "branca"){
                        tamanho = tamanho + 1;
                    }
                }
            }
        }
        return tamanho;
    }

    /**
     * Retorna a quantidade de peças vermelhas.
     * @return tamanho, valor da quantidade de peças vermelhas.
     */
    public int QuantidadeDePecasVermelhas(){
        int tamanho = 0;
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                if(tabuleiro.getCasa(x,y).getPeca() != null){
                    if(tabuleiro.getCasa(x, y).getPeca().getTipoString() == "vermelha"){
                        tamanho = tamanho + 1;
                    }
                }
            }
        }
        return tamanho;
    }

    /**
     * Retorna uma string se for o fim do jogo.
     * @return String, retorna uma string descrevendo quem venceu.
     */
    public String verificaVitoria(){
        if(QuantidadeDePecasVermelhas() == 0){
            return "            Game over \n   Time branco ganhou!";
        }
        if(QuantidadeDePecasBrancas() == 0){
            return "            Game over \n   Time vermelho ganhou!";
        }
        return " ";
    }
}

