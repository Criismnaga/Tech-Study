//PIF 2023.1 -lista 06 - q3
//Aluna: Cristina
//https://www.beecrowd.com.br/judge/pt/problems/view/1068

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char expressao[1001];
    struct no *prox;
} No;

No *topo = NULL;

void push(char *expressao);
char conta_parentese(char *expressao);
void pop();

int main() {
    char expressao[1001];

    while (scanf("%s", expressao) != EOF) {
        push(expressao);
        printf("%s\n", conta_parentese(expressao) ? "correct" : "incorrect");
        pop();
    }

    return 0;
}

void push(char *expressao) {
    No *novoNo = (No*) malloc(sizeof(No));

    strcpy(novoNo->expressao, expressao);
    novoNo->prox = topo;
    topo = novoNo;
}

void pop() {
    if (topo == NULL) {
        return;
    }

    No *temp = topo;
    topo = topo->prox;
    free(temp);
}

char conta_parentese(char *expressao) {
    int tam, i, cont_aberto = 0, cont_fechado = 0;
    tam = strlen(expressao);

    for (i = 0; i < tam; i++) {
        if (cont_fechado <= cont_aberto) {
            if (expressao[i] == '(') {
                cont_aberto++;
            }

            if (expressao[i] == ')') {
                cont_fechado++;
            }
        } else {
            return 0;
            break;
        }
    }

    if ((cont_aberto - cont_fechado) == 0) {
        return 1;
    } else {
        return 0;
    }
}