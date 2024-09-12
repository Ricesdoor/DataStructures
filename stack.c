#include <stdio.h>
#include <stdbool.h>

//define the maximum capacity of the stack
#define MAX_SIZE 100 

typedef struct{
    int arr[MAX_SIZE]; //array to store stack elements
    int top; //index of the top elements in the stack
} Stack;


//by passing a Stack as a pointer "*stack", it allows the function to modify the original stack without creating a copy of the stack structure.
//"Stack" is the custom defined data structure and "*stack" is a pointer that allows the function to access and modify the actual stack

//funcion to initiate stack
void initialize(Stack *stack) { 
    stack->top = -1; //set top index to -1 to indicate an empty stack
}

bool isEmpty(Stack *stack){
    return stack->top == -1; //if the top is -1, the stack is empty
}

bool isFull(Stack *stack){
    return stack->top == MAX_SIZE - 1; // if the top is MAX_SIZE -1, the stack is full
}

void push(Stack *stack, int value){
    //check for stack overflow
    if(isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    //Increment top and add the value to the top of the stack
    stack->arr[++stack->top] = value;
    printf ("Pushed %d onto the stack\n", value);
}

int pop(Stack *stack) {
    //check for stakc underfow
    if(isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    int popped = stack = stack->arr[stack->top]; //getting the top element
    stack->top--; //decrement top pointer
    printf("Popped %d from the stack\n", popped);
    return popped; //return popped element
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top]; //return the top element without removing it
}

int main() {
    Stack stack;
    initialize(&stack);
    // Push elements onto the stack and print the stack after each push
    push(&stack, 3);
    printf("Top element: %d\n", peek(&stack));

    push(&stack, 5);
    printf("Top element: %d\n", peek(&stack));

    push(&stack, 2);
    printf("Top element: %d\n", peek(&stack));

    push(&stack, 8);
    printf("Top element: %d\n", peek(&stack));

    // Pop elements from the stack and print the stack after each pop
    while (!isEmpty(&stack)) {
        printf("Top element: %d\n", peek(&stack));
        printf("Popped element: %d\n", pop(&stack));
    }

    return 0;
}