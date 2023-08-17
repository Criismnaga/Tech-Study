#include <stdio.h>
#include <string.h>

int main(){
    int testes;
    int i, k, l, m, n;
    int tamanhoString = 1000;
    int tamanhoFrase =0;
    int resultado = 0;
    

    scanf("%d", &testes);
    getchar(); // limpa o buffer de memoria pq fica o \n sobrando

    char texto[testes][tamanhoString];

    for (i=0; i<testes; i++){
        fgets(texto[i], tamanhoString, stdin);
        while (texto[i][strlen(texto[i])-1] == '\n') {
            texto[i][strlen(texto[i])-1] = '\0';
        }

        tamanhoFrase = strlen(texto[i]);

        //printf("%d\n", tamanhoFrase);
        for(k=0; k<tamanhoFrase; k++){
            if (texto[i][k] > 64 && texto[i][k] < 123){
                texto[i][k] = texto[i][k] + 3;
            }
        }

        /*for (n=0; n<testes; n++){
            printf("%s\n", texto[n]);
        }
        */

        k=0;
        l = tamanhoFrase - 1;
        while (k < l) {
            char temp = texto[i][k];
            texto[i][k] = texto[i][l];
            texto[i][l] = temp;
            k++;
            l--;
    
        }

       
        /*if (tamanhoFrase % 2 != 0) {
            resultado = tamanhoFrase / 2 + 1;
            } else {
            resultado = tamanhoFrase / 2;
            }   

        printf("resultado divisao truncada é %d\n", resultado);
*/ 
        resultado = tamanhoFrase/2;

        for (m=0; m<tamanhoFrase; m ++){
            if( m >= resultado){
                texto[i][m] = texto[i][m] -1;
            }
        }
    
    }

    //Verifica se o input ta correto
    for (i=0; i<testes; i++){
        printf("%s\n", texto[i]);
    }

}