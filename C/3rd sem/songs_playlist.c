#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[30];
    char artist[25];
    char genre[20];
    int duration;
    struct Song *next;
};

struct Song *head = NULL;
struct Song *current = NULL;

void addSong() {
    struct Song *newNode = (struct Song *)malloc(sizeof(struct Song));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter title: ");
    scanf(" %[^\n]", newNode->title);
    printf("Enter artist: ");
    scanf(" %[^\n]", newNode->artist);
    printf("Enter genre: ");
    scanf(" %[^\n]", newNode->genre);
    printf("Enter duration (seconds): ");
    scanf("%d", &newNode->duration);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        current = newNode;
    } else {
        struct Song *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Song added successfully!\n");
}

void playNext() {
    if (current == NULL) {
        printf("Playlist is empty\n");
        return;
    }
    if (current->next != NULL) {
        current = current->next;
        printf("Now playing: %s\n", current->title);
    } else {
        printf("No next song\n");
    }
}

void playPrevious() {
    if (current == NULL || current == head) {
        printf("No previous song\n");
        return;
    }

    struct Song *temp = head;
    while (temp->next != current)
        temp = temp->next;

    current = temp;
    printf("Now playing: %s\n", current->title);
}

void displayByGenre() {
    if (head == NULL) {
        printf("Playlist is empty\n");
        return;
    }

    char g[20];
    int found = 0;
    printf("Enter genre: ");
    scanf(" %[^\n]", g);

    struct Song *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->genre, g) == 0) {
            printf("%s by %s\n", temp->title, temp->artist);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found)
        printf("No songs found in genre '%s'\n", g);
}

int main() {
    int choice;
    do {
        printf("\n1. Add Song\n2. Play Next\n3. Play Previous\n4. Display by Genre\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addSong(); break;
            case 2: playNext(); break;
            case 3: playPrevious(); break;
            case 4: displayByGenre(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
