#include <stdlib.h>

int main(){

    char *pc;
    pc = (char*)malloc(60*sizeof(char));

    while(1){
    if(pc!=0){
    pc = (char*)malloc(60*sizeof(char));
    }
    else{
    printf("Memoria indisponivel!");
    }
}

}