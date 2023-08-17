//Programação Imperativa e Funcional | 2023.1
//Lista de Exercicíos 1 - Questão 01
//Aluna: Cristina Matsunaga
//https://www.beecrowd.com.br/judge/pt/homeworks/view/34464

#include <stdio.h>
#include <math.h>

int main(){
    int g, a, m, c;
    int i, j , k;
    scanf("%d %d %d %d", &g, &a, &m, &c);

    int matriz01[g][a];
    for (int i=0; i < g; i++){
        for(int j=0; j < a; j++){
            scanf("%d", &matriz01[i][j]);
        }
    }

    int matriz02[a][m];

    for(i=0; i<a; i++){
        for(j=0; j<m; j++){
            scanf("%d", &matriz02[i][j]);
        }
    } 

    int matriz03[m][c];

    for(i=0; i<m; i++){
        for(j=0; j<c; j++){
            scanf("%d", &matriz03[i][j]);
        }
    }
   
    int matrizRes01[g][m]; 
    
    for (i=0; i<g; i++){
        for (j=0; j<m; j++){
            matrizRes01[i][j] = 0;
            for(k=0; k<a; k++){
                matrizRes01[i][j] += matriz01[i][k] * matriz02[k][j];
            }
        }
    }

    int matrizRes02[g][c];
    for (i=0; i<g; i++){
        for (j=0; j<c; j++){
            matrizRes02[i][j] = 0;
            for(k=0; k<m; k++){
                matrizRes02[i][j] += matrizRes01[i][k] * matriz03[k][j];
            }
        } 
    }

    int contador[c];

    for(j=0; j<c; j++){//coluna
        contador[j] = 0;
        for(i=0; i<g; i++){//linha
            if (log10(matrizRes02[i][j]) +1 > contador[j]){
                contador[j] = log10(matrizRes02[i][j]) + 1;
            }else{
                break;
            }
        }
    }

    for( i=0; i<g; i++){ //linha
        for(int j=0; j<c; j++){ //coluna
            if (j==0){
                printf("%*d", contador[j], matrizRes02[i][j]);
            }else{
                printf(" %*d",contador[j], matrizRes02[i][j]);
            }
        }
        printf("\n");
    }
    
    return 0;
}