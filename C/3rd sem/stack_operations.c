#include<stdio.h>
#include<stdlib.h>

int *stack;
int max, top = -1;

void push(int element) {
    if (top == max - 1) {
        printf("Stack Overflow. Resizing stack and pushing element.\n");

        max *= 2;
        stack = realloc(stack, max * sizeof(int));
    }
    top++;
    stack[top] = element;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }

    else {
        int element = stack[top];
        top--;
        return element;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    }

    else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
    }
}

int main() {
    printf("Enter the max size of stack: ");
    scanf("%d", &max);
    stack = (int *)malloc(max * sizeof(int));
    int choice, element;

    

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                element = pop();
                if (element != -1) {
                    printf("Popped element: %d\n", element);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                free(stack);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}