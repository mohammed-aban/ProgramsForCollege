#include <stdio.h>

int ascendingOrder(int arr[], int number_of_elements) {
    int i, j, temp;
    for (i = 0; i < number_of_elements - 1; i++) {
        for (j = 0; j < number_of_elements - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("The elements are: ");
    for (i = 0; i < number_of_elements; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

int descendingOrder(int arr[], int number_of_elements) {
    int i, j, temp;
    for (i = 0; i < number_of_elements - 1; i++) {
        for (j = 0; j < number_of_elements - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("The elements are: ");
    for (i = 0; i < number_of_elements; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

int main() {
    int number_of_elements, i, arr[10], choice;

    printf("Enter the number of elements: ");
    scanf("%d", &number_of_elements);

    printf("Enter the elements: ");
    for (i = 0; i < number_of_elements; i++) {
        scanf("%d", &arr[i]);
    }   

    printf("Do you want it in:\n1. Ascending order?\n2. Descending order?: ");
    scanf("%d", &choice);

    if (choice == 1) {
        ascendingOrder(arr, number_of_elements);
    }
    else if (choice == 2) {
        descendingOrder(arr, number_of_elements);
    }
    return 0;
} 