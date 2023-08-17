//Programação Imperativa e Funcional | 2023.1
//Lista de Exercicíos 2 - Questão 02
//Aluna: Cristina Matsunaga
//https://www.beecrowd.com.br/judge/pt/problems/view/1214

#include <stdio.h>

float funcaoMedia(int notaTotal, int n);

int main(){
    int c=0, n = 0; 
    int i, j, k;
    int nota, notaTotal = 0;
    
    float maior =0.0, cont=0.0, notaMedia=0.0;

    scanf("%d", &c); 
    
    for (i=0; i<c; i++){
    scanf("%d", &n);
    notaTotal = 0;
    cont = 0;
    int vetor[n];
        for(j=0; j<n; j++){
            scanf("%d", &vetor[j]);
            //printf("vetor[j]: %d\n", vetor[j]);
            notaTotal = notaTotal + vetor[j];
            //printf("Nota total é: %d\n", notaTotal);
        }
        notaMedia = funcaoMedia(notaTotal,n);
        //printf("Valor n é: %d\n", n);
        //printf("Nota Total é: %d\n", notaTotal);
        //printf("Nota média é: %f\n", notaMedia);
        for (k=0; k<n; k++){
            if (vetor[k] > notaMedia){
                //printf("Contador antes: %f\n", cont);
                cont = cont +1;
            } 
        }
        //printf("Contador depois: %f\n", cont);
        //printf("Valor n é: %d\n", n);
        maior = (100*cont)/n;
        printf("%.3f%%\n", maior);   
    }
}

float funcaoMedia(int notaTotal, int n){
    return notaTotal/n;
}