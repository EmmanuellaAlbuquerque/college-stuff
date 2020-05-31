//---------------------------------------------------------------------  
// Arquivo modificado da gramática cmm.g disponibilizada pelo professor.  
  
grammar cmm;  
  
//---------------------------------------------------------------------  
// Início da regra: começa por um programa:  
start_rule  
    :    programa;  
  
//---------------------------------------------------------------------  
// Programa: deve conter pelo menos uma função  
programa:   funcao+;  
  
//---------------------------------------------------------------------  
// Tipos:  
tipo    :   'int'  
    |   'void'  
    ;  
  
//---------------------------------------------------------------------   
//  Parâmetros  
param   :   tipo ID;  
      
params  :   param (',' param)*;  
  
  
//---------------------------------------------------------------------  
// Função:    
funcao  :   tipo ID '(' params? ')' '{' comando* '}';  
  
  
//---------------------------------------------------------------------  
// Função sem tipo, de retorno:   
funcaoRetZero  
    :   ID '(' ('"')?  ID? ('"')? ')' ';';  
      
//---------------------------------------------------------------------  
// Comando:   
comando :   ID '=' exp  ';'       // atribuicao  
    |   'return' exp ';'     // return  
    |   '{' comando+ '}'    // bloco de comandos  
    |   funcao         // função dentro de função  
    |       funcaoRetZero     // função sem retorno  
    |   'if' '(' exp ')' comando ELSE? comando* // condicional  
    ;  
      
ELSE    :   'else'  ;  
  
//---------------------------------------------------------------------  
// Expressão Lógica:   
expLog  :   expRel(( OU | E ) expRel)*;  
  
//---------------------------------------------------------------------  
// Expressão:   
exp :   expLog;  
  
//---------------------------------------------------------------------  
// Expressão Regular:     
expRel    
    :   termoTerceiraPrecedencia(( MAIOR_QUE | MENOR_QUE | COMPARACAO ) termoTerceiraPrecedencia)*;   
   
//---------------------------------------------------------------------  
// Expressões da soma e subtração:        
termoTerceiraPrecedencia  
    :   termoSegundaPrecedencia(( SOMA | SUBTRACAO ) termoSegundaPrecedencia)*;  
   
//---------------------------------------------------------------------  
// Expressões da multiplicação e divisão:         
 termoSegundaPrecedencia  
    : termoPrimeiraPrecedencia(( MULTIPLICACAO | DIVISAO ) termoPrimeiraPrecedencia)*;  
   
 //---------------------------------------------------------------------  
// Expressão da exponenciação :       
 termoPrimeiraPrecedencia  
    : fator((EXPONENCIACAO) fator)*;  
   
//---------------------------------------------------------------------  
// Nome da produção, derivação, especificação da derivação: Tokens   
SOMA  
    :    '+';  
SUBTRACAO  
    :    '-';  
MULTIPLICACAO  
    :    '*';  
DIVISAO  
    :    '/';     
EXPONENCIACAO  
    :    '^';     
MENOR_QUE  
    :   '<';  
MAIOR_QUE  
    :   '>';  
COMPARACAO  
    :   '==';  
OU    
    :   '||';  
E     
    :   '&&';     
      
//expMul    :   fator ('*' fator)*;  
  
//---------------------------------------------------------------------  
// Fator:     
fator   :   ID                // variável [a-z ou 0-9]  
    |   INT               // literal inteiro [0-9]  
    |   ID '(' args? ')'  // chamada de funcao  
    ;  
  
//---------------------------------------------------------------------  
// Argumentos p/ função:  
args    :   exp (',' exp)*  
;  
  
//---------------------------------------------------------------------  
// Tokens  
ID  :   ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*  
    ;  
  
INT :   '0'..'9'+  
    ;  
  
COMMENT  
    :   '//' ~('\n'|'\r')* '\r'? '\n' {$channel=HIDDEN;}  
    |   '/*' ( options {greedy=false;} : . )* '*/' {$channel=HIDDEN;}  
    ;  
  
WS  :   ( ' '  
        | '\t'  
        | '\r'  
        | '\n'  
        ) {$channel=HIDDEN;}  
    ;  
