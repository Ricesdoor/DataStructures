#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data; //data field
    struct Node *next; //pointer to next node
} Node;

int main(){
    Node *first = (Node *)malloc(sizeof(Node)); //allocate storage that is the size of Node
    first->data = 10; //assingning data

    Node *second = (Node *)malloc(sizeof(Node));
    second->data = 20;

    Node *third = (Node *)malloc(sizeof(Node));
    third->data = 30;

    first->next = second;
    second->next = third;
    third->next = NULL;

    printf("Linked List: ");
    Node* temp = first;
    while(temp) {
        printf(" %d", temp->data);
        temp = temp->next;
    }

    Node *new = (Node *)malloc(sizeof(Node));
    new->data = 15;
    first->next = new;
    new->next = second;

    printf("\nNew Linked List: ");
    temp = first;
    while(temp) {
        printf(" %d", temp->data);
        temp = temp->next;
    }

    return 0;
}
