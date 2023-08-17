//Programação Imperativa e Funcional | 2023.1
//Lista de Exercicíos 6 - Questão 02
//Aluna: Cristina Matsunaga
//https://www.beecrowd.com.br/judge/pt/problems/view/3163

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h> 

typedef struct Node{
    char *value;
    struct Node *next;
} Node;

typedef struct Queue{
    Node *head;
    Node *tail;
    int size;
} Queue;

Queue *create_queue();
bool is_empty(Queue *queue);
void enqueue(Queue *queue,  char *value);
char* dequeue(Queue *queue, bool *status);
void freeQueue(Queue *queue);

int main(){
    Queue *queue_oeste = create_queue(); // -1
    Queue *queue_norte = create_queue(); //-3
    Queue *queue_sul = create_queue(); // -2
    Queue *queue_leste = create_queue(); // -4

    int p=1, sair_loop;
    char id[5], *idOrde;
    scanf("%d", &p);
    do{
        if (p == -1){
            sair_loop = 0; 
            do{ 
                scanf("%s",id);
                if (!strcmp(id, "-4") || !strcmp(id, "-2") || !strcmp(id, "-3") || !strcmp(id, "-1")|| !strcmp(id, "0")){
                    p = atoi(id); 
                    sair_loop = 1;
                }else{
                    enqueue(queue_oeste, id);
                    sair_loop = 0;
                }

            }while (sair_loop == 0);

        }else if(p == -3){ 
            sair_loop = 0; 
            do{ 
                scanf("%s",id);
                if (!strcmp(id, "-4") || !strcmp(id, "-2") || !strcmp(id, "-3") || !strcmp(id, "-1")|| !strcmp(id, "0")){
                    p = atoi(id); 
                    sair_loop = 1;
                }else{
                    enqueue(queue_norte, id);
                    sair_loop = 0;
                }

            }while (sair_loop == 0);

        }else if(p == -2){
            sair_loop = 0; 
            do{ 
                scanf("%s",id);
                if (!strcmp(id, "-4") || !strcmp(id, "-2") || !strcmp(id, "-3") || !strcmp(id, "-1")|| !strcmp(id, "0")){
                    p = atoi(id); 
                    sair_loop = 1;
                }else{
                    enqueue(queue_sul, id);
                    sair_loop = 0;
                }

            }while (sair_loop == 0);

        }else if(p == -4){ 
            sair_loop = 0; 
            do{ 
                scanf("%s",id);
                if (!strcmp(id, "-4") || !strcmp(id, "-2") || !strcmp(id, "-3") || !strcmp(id, "-1") || !strcmp(id, "0")){
                    p = atoi(id); 
                    sair_loop = 1;
                }else{
                    enqueue(queue_leste, id);
                    sair_loop = 0;
                }

            }while (sair_loop == 0);
        }
    } while(p != 0);

    //printar em ordem
    sair_loop = 0;
    bool status = false; 
    do {
        if (!is_empty(queue_oeste)) {
            idOrde = dequeue(queue_oeste, &status);
            printf("%s", idOrde);
            if (!is_empty(queue_norte) || !is_empty(queue_sul) || !is_empty(queue_leste) || !is_empty(queue_oeste)) {
                printf(" "); 
            }
        }

        if (!is_empty(queue_norte)) {
            idOrde = dequeue(queue_norte, &status);
            printf("%s", idOrde);
            if (!is_empty(queue_norte) || !is_empty(queue_sul) || !is_empty(queue_leste) || !is_empty(queue_oeste)) {
                printf(" "); 
            }
        }

        if (!is_empty(queue_sul)) {
            idOrde = dequeue(queue_sul, &status);
            printf("%s", idOrde);
            if (!is_empty(queue_norte) || !is_empty(queue_sul) || !is_empty(queue_leste) || !is_empty(queue_oeste)) {
                printf(" "); 
            }
        }

        if (!is_empty(queue_leste)) {
            idOrde = dequeue(queue_leste, &status);
            printf("%s", idOrde);
            if (!is_empty(queue_norte) || !is_empty(queue_sul) || !is_empty(queue_leste) || !is_empty(queue_oeste)) {
                printf(" "); 
            }
        }

        if (is_empty(queue_oeste) && is_empty(queue_norte) && is_empty(queue_sul) && is_empty(queue_leste)) {
            sair_loop = 1;
        }

    } while (sair_loop != 1);

    printf("\n");

    freeQueue(queue_sul);
    freeQueue(queue_norte);
    freeQueue(queue_leste);
    freeQueue(queue_oeste);

}

Queue *create_queue(){
    Queue *queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

bool is_empty(Queue *queue){
    return (queue->size == 0);
}

void enqueue(Queue *queue, char *value){

    Node *newNode = malloc(sizeof(Node));
    newNode->value = malloc((strlen(value) + 1) * sizeof(char));
    strcpy(newNode->value, value);
    newNode->next = NULL;

    if (is_empty(queue)){
        queue->head = newNode;
        queue->tail = newNode;
    }else{
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->size++;
}

char* dequeue(Queue *queue, bool *status){

    if (is_empty(queue)){
        *status = false;
        return NULL;
    }
    *status = true;
    char* value = queue->head->value;
    Node *temp = queue->head;

    if (queue->size == 1){
        queue->head = NULL;
        queue->tail = NULL;
    }else{
        queue->head = queue->head->next;
    }

    free(temp);
    queue->size--;

    return value;
    }

void freeQueue(Queue *queue){

    Node *currentNode = queue->head;

    while (currentNode != NULL){
        Node *temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
    free(queue);
}