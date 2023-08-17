//Programação Imperativa e Funcional | 2023.1
//Lista de Exercicíos 6 - Questão 03
//Aluna: Cristina Matsunaga
//https://www.beecrowd.com.br/judge/pt/problems/view/1340

#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {

        int pilha = 1, fila = 1, fila_prioritaria = 1;
        int operacao, valor, i, j;
        int pilha_a[1001], fila_a[1001], fila_prio_a[1001], topo_pilha = -1, frente_fila = 0, fim_fila = -1; 
        
        for (i = 0; i < n; i++) {
            scanf("%d", &operacao); // quantas linha vai ter a interação
            if (operacao == 1) { // que adiciona (tipo 1)

                scanf("%d", &valor); 
                topo_pilha++;
                pilha_a[topo_pilha] = valor;
                fim_fila++;
                fila_a[fim_fila] = valor;
                j = fim_fila; // ultimo valor da fila (-1)

                while (j > frente_fila && fila_prio_a[j-1] < valor) {
                    fila_prio_a[j] = fila_prio_a[j-1];
                    j--;
                }
                fila_prio_a[j] = valor;

            }else if (operacao == 2) {// que retira (tipo 2)
                scanf("%d", &valor);
                
                if (topo_pilha < 0 || pilha_a[topo_pilha] != valor) { // vazio ou pode ser pilha
                    pilha = 0;
                }
                
                if (frente_fila > fim_fila || fila_a[frente_fila] != valor) {  
                    fila = 0;
                }
            
                if (fim_fila < 0 || fila_prio_a[frente_fila] != valor) {
                    fila_prioritaria = 0;
                }

                if (frente_fila <= fim_fila) { // anda com a lista 
                    frente_fila++;
                }

                if (topo_pilha >= 0) { // anda com a pilha tipo pop()
                    topo_pilha--;
                }
            }
        }
        
        if (pilha + fila + fila_prioritaria == 0) {
            printf("impossible\n");
        }else if (pilha + fila + fila_prioritaria > 1) {
            printf("not sure\n");
        }else if (pilha == 1) {
            printf("stack\n");
        }else if (fila == 1) {
            printf("queue\n");
        }else if (fila_prioritaria == 1) {
            printf("priority queue\n");
        }
    }
}