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
    struct Node *prev;
    
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

int pop(Node ** head) {
    int retval = -1;
    Node * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->data;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_by_index(Node ** head, int n) {
    int i = 0;
    int retval = -1;
    Node * current = *head;
    Node * temp_node = NULL;

    if (n == 0) {
        return pop(head);
    }

    for (i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    if (current->next == NULL) {
        return -1;
    }

    temp_node = current->next;
    retval = temp_node->data;
    current->next = temp_node->next;
    free(temp_node);
    print(*head);
    return retval;

}

int main(){

    Node*list = NULL;
    Node*max = NULL;
    Node*min = NULL;
    int amount;
    Data var;
    int max_element = -9999999;

    printf("[+] Task 1:\n");
    printf("[+] Input amount of elements: ");
    scanf("%d", &amount);
    for(int i = 0; i < amount; i++){
        printf("[+] Element %d: ", i + 1);
        scanf("%d", &var);
        push(&list, var);
    }
    
    for(Node * p = list; p != NULL; p = p -> next){
        if(p -> data > 0){
            push(&max, p -> data);
        }else if(p -> data <0){
            push(&min, p -> data);
        }
    }

    printf("[+] All elements:\n ");
    print(list);
    printf("[+] Elements \"> 0\":\n");
    print(max);
    printf("[+] Elements \"< 0\":\n");
    print(min);

    for(Node * p = list; p != NULL; p = p -> next){
        if (p -> data > max_element){
            max_element = p -> data;
        }
    }

   
    printf("[+] Task 2:\n");
    printf("[+] Max element: %d\n", max_element);
    printf("[!] Erasing max elements...\n");
    
    remove_by_index(&list, max_element);
    /*   
    for(Node * p = list; p != NULL; p = p -> next){
        if(is_empty(list)){
            return 0;
        }else{
            if (p -> data == max_element){
            Data d = pop(&list);
            print(list);
            }
        }
        
    }
    */
    print(list);
    

    
    return 0;
}