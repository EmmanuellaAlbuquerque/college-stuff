import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

	/** A Classe reconhece padrões através de expressões regulares.
	 * 	Os padrões que podem ser verificados são: CPF, número telefônico,
	 *  endereço de e-mail e URL.
	 *  @author Emmanuella Faustino Albuquerque
	 *  @author Maria Raquel
	 */
		public class ReconhecedorDePadroes {

			// Campos:
			Pattern pattern;
			Matcher matcher;
			Scanner scan;
			String input, CPF, numero, email, url;
			
	/* Construtor da classe ReconhecedorDePadroes();
	 * Esta configura inicialmente a instância recebendo do teclado
	 * a cadeia a ser reconhecida pela expressão regular escolhida pelo usuário. 
	 */
		public ReconhecedorDePadroes(){
			scan = new Scanner(System.in);
			String palavra = scan.nextLine();
			input = palavra;		
		}

	/** Verifica se a String recebida pelo teclado equivale 
	 * ao formato da expressão regular do CPF.
	 * @return boolean, true se forem equivalentes. 
	 */
		public boolean verificaCPF(){
			// Validação do CPF: 
	        CPF = "\\d{3}\\.\\d{3}\\.\\d{3}-\\d{2}";
	        boolean valida = input.matches(CPF);
	        return valida;
		}
		
		/** Verifica se a String recebida pelo teclado equivale 
		 *	ao formato da expressão regular do número telefônico.
		 * @return boolean, true se forem equivalentes.
		 */
		private boolean verificaNumero(){
			// Validação do número telefônico: 
	        numero = "\\d{4,5}-\\d{4}";
	        boolean valida = input.matches(numero);
	        return valida;
		}
		
		/** Verifica se a String recebida pelo teclado equivale 
		*	ao formato da expressão regular do endereço de e-mail.
		* @return boolean, true se forem equivalentes.
		*/
		private boolean verificarEmail() {
			// Validação do endereço de e-mail
			email = "^[_A-Za-z0-9-\\+]+(\\.[_A-Za-z0-9-]+)*@"
			        + "[A-Za-z0-9-]+(\\.[A-Za-z0-9]+)*(\\.com$|\\.org$|\\.br$)";
			boolean valida = input.matches(email);
			return valida;
		}
		
		/** Verifica se a String recebida pelo teclado equivale 
		*	ao formato da expressão regular da URL do endereço web.
		* @return boolean, true se forem equivalentes.
		*/
		private boolean verificarURL() {
			// Validação do endereço URL; 
			url = "^www\\.([a-zA-Z0-9]+)(\\.com$|\\.org$|\\.br$)";
			boolean valida = input.matches(url);
			return valida;
		}

		/** Realiza a verificação dos 2 dígitos finais do CPF,
		 *  encontrados após o "-".
		 * 	Verificação realizada através do cálculo do CNPJ.
		 * @return boolean, true se os cálculos forem equivalentes
		 *  aos dígitos de verificação.
		 */
 		public boolean digitoVerificador(){
			
			int num1,num2, soma1 = 0, soma2 = 0;
			int digitoverificador1 = Integer.parseInt(input.substring(12, 13));
			int digitoverificador2 = Integer.parseInt(input.substring(13, 14));
			
			for(int i = 0, j = 10; i < 11; j--){
				if(i == 3 || i == 7 || i == 11){
					i++;
				}
				num1 = Integer.parseInt(input.substring(i++, i));
				soma1 = soma1 + (num1*j);
			}
				
			int resto1 = soma1%11;
			int sub1 = 11 - resto1;
			int digito1, digito2;
			
			if(sub1 > 9){
				digito1 = 0;
			}
			else{
				digito1 = sub1;
			}
			
			for(int i = 0, j = 11; i < 11; j--){
				
				if(i == 3 || i == 7 || i == 11){
					i++;
				}
				
				num2 = Integer.parseInt(input.substring(i++, i));
				soma2 = soma2 + (num2*j);
			}
			
			soma2 = soma2 + (digitoverificador1*2);
			
			int rest2 = soma2%11;
			int sub2 = 11 - rest2;
			
			if(sub2 > 9){
				digito2 = 0;
			}
			else{
				digito2 = sub2;
			}
			
			if(digito1 == digitoverificador1 && digito2 == digitoverificador2){
				return true;
			}
			else{
				return false;
			}
		}
		
		/** Inicia o processo de verificação da String digitada pelo usuário,
		 *  de acordo com a expressão regular que ele deseja comparar.
		 * 
		 */
		private static void iniciaReconhecimento(){
			
			int opcao = 0;
	    	ReconhecedorDePadroes validar;
	    	Scanner scan = new Scanner(System.in);
	    	
	    	while(opcao!=5){
	    		
	    	menu();	
	    	
	    	try{
	            opcao = scan.nextInt();
	        }catch(Exception e){
	        	opcao = 0;
	        }finally{
	            scan.nextLine();
	        }
	    	
	    	while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 ){
	    		System.out.println("Digite um inteiro válido! Tente novamente.");
		    	
		    	try{
		            opcao = scan.nextInt();
		        }catch(Exception e){
		             opcao = 0;
		        }finally{
		            scan.nextLine();
		        }
		    		
	    	}
	    	
	    	
	    	switch (opcao) {
	    	
			case 1:
			{
				System.out.println("Digite o número do CPF: ");
				validar = new ReconhecedorDePadroes();
				reconheceCPF(validar);
				break;
			}
				
			case 2:
			{
				System.out.println("Digíte o número do celular: ");
				validar = new ReconhecedorDePadroes();
				ReconheceNumero(validar);
				break;
			}
				
			case 3:
			{
				System.out.println("Digite seu endereço de e-mail: ");
				validar = new ReconhecedorDePadroes();
				ReconheceEmail(validar);
				break;
			}
				
			case 4:
			{
				System.out.println("Digite seu endereço url: ");
				validar = new ReconhecedorDePadroes();
				ReconheceURL(validar);
				break;
			}
			
			case 5:
				scan.close();
				break;
			
			}
	    	}
	    	// Quando o while é encerrado:
	    	System.out.println("Programa encerrado!");
	    	
		}
		
		/** Para ser um CPF válido o formato da expressão regular deve ser 
		 * equivalente e os dígitos verificadores devem ser iguais.
		 * @param validar, instância que gera o input do usuário.
		 */
		private static void reconheceCPF(ReconhecedorDePadroes validar){
			
			if(validar.verificaCPF() && validar.digitoVerificador()){
				System.out.println("O CPF é válido!");
			}
			else{
				System.out.println("O CPF não é válido!");
			}
		}
		
		/** Para ser um número telefônico válido o input deve ter o
		 *  formato da expressão regular.
		 * @param validar, instância que gera o input do usuário.
		 */
		private static void ReconheceNumero(ReconhecedorDePadroes validar){
			if(validar.verificaNumero()== true){
				System.out.println("O número é válido!");
			}
			else{
				System.out.println("O número não é válido!");
			}
			
		}
		
		/** Para ser um e-mail válido o input deve ter o
		*  formato da expressão regular.
		* @param validar, instância que gera o input do usuário.
		*/
		private static void ReconheceEmail(ReconhecedorDePadroes validar) {
			if(validar.verificarEmail()==true) {
				System.out.println("O e-mail é válido!");
			}
			else {
				System.out.println("O e-mail não é válido!");
			}
		}
		
		/** Para ser uma URL válida o input deve ter o
		*  formato da expressão regular.
		* @param validar, instância que gera o input do usuário.
		*/
		private static void ReconheceURL(ReconhecedorDePadroes validar) {
			if(validar.verificarURL()== true) {
				System.out.println("A URL é válida!");
			}
			else {
				System.out.println("A URL não é válida!");
			}
		}
		
		/** Gera o Menu do programa. Apresentando qual número 
		 *  você deve digitar, dependendo da sua necessidade.
		 */
		private static void menu(){
			System.out.println(" ");
			System.out.println("         MENU         ");
			System.out.println("Digite a opção desejada: ");
			System.out.println("1. Para verificar o CPF: ");
			System.out.println("2. Para verificar o número: ");
			System.out.println("3. Para verificar o e-mail: ");
			System.out.println("4. Para verificar a URL: ");
			System.out.println("5. Para sair: ");
		}
		
		/** Thread principal main
		 *  Inicia o procedimento.
		 * @param args
		 */
	    public static void main(String[] args) {
	    	
	    	iniciaReconhecimento();
	        
	    }
	}

