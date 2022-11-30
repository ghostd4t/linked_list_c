#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
//push - input
//pop - take out

typedef struct Node
{
    int value;
    struct Node*next;
}Node;

void push(Node **head, int data){
    print("distance sub");
    Node*tmp = (Node*)malloc(sizeof(Node));
    tmp->value = data;
    tmp->next =(*head);
    (*head) = tmp;
}

/*
void print(const Node *head){
    int len = lenght(head);
    int *values = (int*) malloc(len*sizeof(int));
    while (head){
        values[--len] = head->value;
        head = head->next;
    }
    return values;
}*/

void print(const Node *head){
    while(head){
        printf("%d", head->value);
        head = head->next;
    }
    printf("/n");
}
/*
void pop(Node **head){
    Node *prev = NULL;
    int val;
    if (head == NULL){
        return -1;
    }
    prev = (*head);
    val = prev -> value;
    (*head) = (*head)->next;
    free(prev);
    return val;

}*/

int main(){
    //head list
    printf("distance 1\n");
    int data = 0;
    int tmp = 0;
    Node *head = NULL;
    printf("distance 2\n");
    push(head, data);
    printf("distance 3\n");
    print(head);
    printf("distance 4");
   
    /*
    Node*tmp = (Node*)malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
    */

    /*
    int data;
    for(int i = 0; i < 5; i++){
        scanf("%d", &data);
        push(NULL, data);
    }
    for(int i = 0; i < 5; i_++){
        printf("%d", Node[i]);
    }
    */
    return 0;
}