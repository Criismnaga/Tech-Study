//Programação Imperativa e Funcional | 2023.1
//Lista de Exercicíos 3 - Questão 03
//Aluna: Cristina Matsunaga
//https://www.beecrowd.com.br/judge/pt/problems/view/1581

#include <stdio.h>
#include <string.h>

int main(){
    int testes;
    int i, j, k;
    int tamanhoString = 20;
    int qtdLingua;
    int resultado;
    int cont =0;

    scanf("%d", &testes);
    getchar(); // limpa o buffer de memoria pq fica o \n sobrando

    for (i=0; i<testes; i++){
        scanf("%d", &qtdLingua);
        getchar();

        char texto[qtdLingua][tamanhoString];

        for (k=0; k<qtdLingua; k++){
            
            fgets(texto[k], tamanhoString, stdin);
            while (texto[k][strlen(texto[k])-1] == '\n') {
                texto[k][strlen(texto[k])-1] = '\0';
            }
        }

        if (qtdLingua == 1){            
            printf("%s\n", texto[qtdLingua-1]);
        }

        for ( j = 0; j<qtdLingua-1; j++){
          
            resultado = strcmp(texto[j],texto[j+1]);
                       
            if (resultado != 0){
                printf("ingles\n");
                cont = cont -1;
                break;
            }else{
                cont = cont +1;
            }

            if (cont == qtdLingua -1){
                
                printf("%s\n", texto[0]);

            }      
        }
    }
}