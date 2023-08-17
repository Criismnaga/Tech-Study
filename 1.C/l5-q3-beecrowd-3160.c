//Programação Imperativa e Funcional | 2023.1
//Lista de Exercicíos 5 - Questão 03
//Aluna: Cristina Matsunaga
//https://www.beecrowd.com.br/judge/pt/problems/view/3160

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *listaAtual = malloc(1000 * sizeof(char));
    char *novaLista = malloc(1000 * sizeof(char));
    char *novaIndicacao = malloc(100 * sizeof(char));

   
    fgets(listaAtual, 1000, stdin);
    listaAtual[strcspn(listaAtual, "\n")] = 0; 
    fgets(novaLista, 1000, stdin);
    novaLista[strcspn(novaLista, "\n")] = 0;
    fgets(novaIndicacao, 100, stdin);
    novaIndicacao[strcspn(novaIndicacao, "\n")] = 0;

    
    if (strcmp(novaIndicacao, "nao") == 0) {
        char *output = malloc(2000 * sizeof(char));
        strcpy(output, listaAtual);
        strcat(output, " ");
        strcat(output, novaLista);
        printf("%s", output);
        free(output);
    } else {
        char *token;
        char *current_friend_split[100];
        int friend_index = 0;
        int split_index = 0;

        token = strtok(listaAtual, " ");
        while (token != NULL) {
            current_friend_split[friend_index++] = token;
            token = strtok(NULL, " ");
        }

        for (int i = 0; i < friend_index; i++) {
            if (strcmp(current_friend_split[i], novaIndicacao) == 0) {
                split_index = i - 1;
                break;
            }
        }

        char *output = malloc(1000 * sizeof(char));
    
        for (int i = 0; i <= split_index; i++) {
            strcat(output, current_friend_split[i]);
            strcat(output, " ");
        }
        strcat(output, novaLista);
        strcat(output, " ");

        for (int i = split_index + 1; i < friend_index; i++) {
            strcat(output, current_friend_split[i]);
            strcat(output, " ");
        }
        printf("%s", output);
        free(output);
    }

    free(listaAtual);
    free(novaLista);
    free(novaIndicacao);

    return 0;
}