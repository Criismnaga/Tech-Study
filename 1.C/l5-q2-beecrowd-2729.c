//Programação Imperativa e Funcional | 2023.1
//Lista de Exercicíos 5 - Questão 02
//Aluna: Cristina Matsunaga
//https://www.beecrowd.com.br/judge/pt/problems/view/2729

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char item[21];
    struct node *next;
};

void insereOrdenado(struct node **head, char *valor);
void imprimeLista(struct node *head);
void liberaLista(struct node **head);

int main() {
    int n, i, j;
    char coisa[21];

    struct node *head = NULL;

    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++) {
        j = 0;
        while (scanf("%s", coisa) != EOF) {
            insereOrdenado(&head, coisa);
            j++;
            if (getchar() == '\n') {
                break;
            }
        }
        imprimeLista(head);
        liberaLista(&head);
    }

    return 0;
}

void insereOrdenado(struct node **head, char *valor) {
    struct node *n = *head;
    struct node *novo = (struct node *)malloc(sizeof(struct node));
    strcpy(novo->item, valor);
    novo->next = NULL;

    if (*head == NULL) {
        *head = novo; //pode alocar aqui e fazer copia também
        return;
    }

    if (strcmp(n->item, valor) > 0) { // indica que que a head vem antes de tempo 
        novo->next = *head;
        *head = novo;
        return;
    }

    while (n->next != NULL && strcmp(n->next->item, valor) < 0) 
    // n é váriavel temporaria se for utilizar hed a gente perderia a info dele. 
    {
        n = n->next; 
    }

    if (n->next != NULL && strcmp(n->next->item, valor) == 0) {
        free(novo);
        return;
    }

    if (strcmp(n->item, valor) == 0) {
        free(novo);
        return;
    }

    novo->next = n->next;
    n->next = novo;
}

void imprimeLista(struct node *head) {
    struct node *n = head;
    while (n != NULL) {
        printf("%s", n->item);
        if (n->next != NULL) {
            printf(" ");
        }
        n = n->next;
    }
    printf("\n");
}

void liberaLista(struct node **head) {
    struct node *n = *head;
    while (n != NULL) {
        struct node *temp = n;
        n = n->next;
        free(temp);
    }
    *head = NULL;
}