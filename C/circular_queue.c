#include<stdio.h>
#include<stdlib.h>

int *queue;
int max, rear, front, count = 0;

void enqueue(int element) {
    if (count == max) {
        printf("Queue Overflow.\n");
    }

    else {
        rear = (rear + 1) % max;
        queue[rear] = element;
        count++;
    }
}

int dequeue() {
    if (count == 0) {
        printf("Queue Underflow\n");
        return -1;
    }
    else {
        front = (front + 1) % max;
        count--;
        return queue[front];
    }
}

void display() {
    int i, k;

    if (count == 0) {
        printf("Queue is empty\n");
    }

    else {
        k = (front + 1) % max;
        printf("Queue elements: ");
        for (i = 0; i < count; i++) {
            printf("%d ", queue[k]);
            k = (k + 1) % max;
        }
    }
}

int main() {
    printf("Enter the max size of queue: ");
    scanf("%d", &max);
    queue = (int *)malloc(max * sizeof(int));
    rear = max - 1;
    front = max - 1;

    int choice, element;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;

            case 2:
                element = dequeue();
                if (element != -1) {
                    printf("Dequeued element: %d\n", element);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}