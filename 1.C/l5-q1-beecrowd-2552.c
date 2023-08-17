//Programação Imperativa e Funcional | 2023.1
//Lista de Exercicíos 5 - Questão 01
//Aluna: Cristina Matsunaga
//https://www.beecrowd.com.br/judge/pt/problems/view/2552


#include <stdio.h>
#include <stdlib.h>

int** PrintaMatriz (int n, int m, int** matriz);

int main(){

    int n, m, i, j; 
    int** tabela;

    //tamanho matriz
    while (scanf("%d %d", &n, &m) != EOF) {

        int** matriz = (int**)calloc(n,sizeof(int*));

        for(i=0; i<n; i++){
            matriz[i]= (int*)calloc(m, sizeof(int));
        }

        for(i=0; i<n; i++){
            for(j=0; j<m; j ++){
                scanf("%d", &matriz[i][j]);
            }
        }
        // troca 1 por 9 
        for(int i=0; i<n; i++){ 
            for(int j=0; j<m; j++){
                if(matriz[i][j] == 1){
                    matriz[i][j] = 9;
                }
            }
        }

        for(int i=0; i<n; i++){ 
            for(int j=0; j<m; j++){
                //if ((i+1 <= n)&& (j+1 <= m) && (i-1 >=0) && (j-1 >=0)){
                if (matriz[i][j] == 0){
                    //verifica em cima
                    if (i-1 >=0){ 
                        if(matriz[i-1][j] == 9){
                            matriz[i][j] = matriz[i][j] +1;
                        }
                    }
                    //verifica a esquerda
                    if(j-1 >=0){
                        if(matriz[i][j-1] == 9){
                            matriz[i][j] = matriz[i][j] +1;
                        }
                    }
                    // verifica a direita
                    if(j+1 < m){
                        if(matriz[i][j+1] == 9){
                            matriz[i][j] = matriz[i][j] +1; 
                        }
                    }
                    //verifica embaixo
                    if (i+1 < n) {
                        if(matriz[i+1][j] == 9){
                            matriz[i][j] ++; 
                        }
                    }
                }
            }
        }

        tabela = PrintaMatriz(n,m,matriz);

        for(i=0; i<n; i++){
            free(matriz[i]);
        }
        free(matriz);
    }

}

int** PrintaMatriz (int n, int m, int** matriz){

    for(int i=0; i<n; i++){ 
        for(int j=0; j<m; j++){ 
            if (j==0){
                printf("%d", matriz[i][j]);
            }else{
                printf("%d", matriz[i][j]);
            }
        }
        printf("\n");
    }

    return matriz;

}