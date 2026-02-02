#include <stdio.h>
#include <string.h>

#define MAX_TABLES 5

struct Table {
    int tableNo;
    int reserved;
    char name[30];
};

void displayTables(struct Table t[]) {
    for (int i = 0; i < MAX_TABLES; i++) {
        if (t[i].reserved)
            printf("Table %d : Reserved by %s\n", t[i].tableNo, t[i].name);
        else
            printf("Table %d : Available\n", t[i].tableNo);
    }
}

void reserveTable(struct Table t[]) {
    int num;
    printf("Enter table number: ");
    scanf("%d", &num);

    if (t[num - 1].reserved) {
        printf("Table already reserved\n");
    } else {
        printf("Enter name: ");
        scanf("%s", t[num - 1].name);
        t[num - 1].reserved = 1;
        printf("Table reserved\n");
    }
}

void cancelReservation(struct Table t[]) {
    int num;
    printf("Enter table number: ");
    scanf("%d", &num);

    if (t[num - 1].reserved) {
        t[num - 1].reserved = 0;
        printf("Reservation cancelled\n");
    } else {
        printf("Table not reserved\n");
    }
}

int main() {
    struct Table t[MAX_TABLES];

    for (int i = 0; i < MAX_TABLES; i++) {
        t[i].tableNo = i + 1;
        t[i].reserved = 0;
    }

    int choice;
    do {
        printf("\n1.Display Tables\n2.Reserve Table\n3.Cancel Reservation\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: displayTables(t); break;
            case 2: reserveTable(t); break;
            case 3: cancelReservation(t); break;
        }
    } while (choice != 4);

    return 0;
}
