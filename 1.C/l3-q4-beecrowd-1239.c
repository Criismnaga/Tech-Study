#include <stdio.h>
#include <string.h>


int main(){
    int i, k;
    int tamanhoString = 51, tamanhoFrase, contUnder=0, contAste=0;
    char ch;
    char texto[tamanhoString];

    while((ch = getchar()) != EOF){
        i = 0;
        while(ch != '\n'){
            texto[i] = ch;
            i++;
            ch = getchar();
            }         
        texto[i] = '\0';
    
    tamanhoFrase = strlen(texto);

        for (k=0; k<tamanhoFrase; k++){
            if (texto[k] == '_' && contUnder%2 !=0){
                printf("</i>");
                contUnder ++;
            }else if(texto[k] == '_' && contUnder%2 ==0){
                printf("<i>");
                contUnder ++;
            }else if(texto[k] == '*' && contAste%2 !=0){
                printf("</b>");
                contAste ++;
            }else if(texto[k] == '*' && contAste%2 ==0){
                printf("<b>");
                contAste ++;
            }else{
                putchar(texto[k]);
            }
        }
        printf("\n");
    }
}