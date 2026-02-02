#include<stdio.h>
#include<stdlib.h>

typedef struct SLL {
    int usn;
    char name[20];
    char mode[20];
    struct SLL *next;
} node;

node* head = NULL;

node *create_node() {
    node *new_node = (node *)malloc(sizeof(node));
    printf("Enter USN: ");
    scanf("%d", &new_node->usn);   
    printf("Enter Name: ");
    scanf("%s", new_node->name);
    printf("Enter Mode(Regular/lateral): ");
    scanf("%s", new_node->mode);
    new_node->next = NULL;
    return new_node;
}

void insert_end() {
    node *new_node = create_node();

    if (head == NULL) {
        head = new_node;
        return;
    }

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

void display() {
    node *temp = head; int count = 0;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("USN\tName\tMode");
    while (temp != NULL) {
        printf("\n%d\t%s\t%s", temp->usn, temp->name, temp->mode);
        temp = temp->next;
        count++;
    }

    printf("\nThe total number of students is %d\n", count);
}

void delete_key() {
    int key;
    printf("Enter USN to delete: ");
    scanf("%d", &key);

    node *temp = head, *prev;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->usn == key) {
        head = head->next;
        printf("Student with USN %d deleted\n", temp->usn);
        free(temp); 
        return;
    }   

    if (temp != NULL && temp->usn != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("USN not found\n");
        return;
    }

    prev->next = temp->next;
    printf("Student with USN %d deleted\n", temp->usn);
    free(temp); 
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert Student\n2. Delete Student\n3. Display Students\n4. Delete students of lateral entry\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_end();
                break;
            case 2:
            case 4:
                delete_key();
                break;
            case 3:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}