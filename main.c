#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
//push - input
//pop - take out

typedef int Data;
typedef struct Node {
    Data data;
    struct Node *next;
} Node;

void print(Node * list){
    for(Node * p = list; p != NULL; p = p -> next){
        printf("%d ", p -> data);
    }
    printf("\n");
}

void push(Node ** plist, Data d){
    Node * p = malloc(sizeof(Node));
    p -> data = d;
    p -> next = *plist;
    *plist = p;
}

int is_empty(Node * list){
    return list == NULL;
}

Data pop(Node ** plist){
    Node * p = *plist;
    Data res = p -> data;
    *plist = p -> next;
    free(p);
    return res;
}


int main(){

    Node*list = NULL;
    Node*max = NULL;
    Node*min = NULL;
    int amount;
    Data var;

    printf("[+] Input amount of elements: ");
    scanf("%d", &amount);
    for(int i = 0; i < amount; i++){
        printf("[+] Element %d: ", i + 1);
        scanf("%d", &var);
        if(var > 0){
            push(&list, var);
            push(&max, var);
        }
        else if(var < 0){
            push(&list, var);
            push(&min, var);
        }else{
            push(&list, var);
        }
        
    }
    printf("[+] All elements:\n ");
    print(list);
    printf("[+] Elements \"> 0\":\n");
    print(max);
    printf("[+] Elements \"< 0\":\n");
    print(min);
    return 0;
}