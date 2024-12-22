// Design and Develop a C program to perform binary search using user defined functions.

#include<stdio.h>

int main() {
    int a[10], key, n, i, low, high, mid, found = 0;

    printf("How many numbers are to be read?: ");
    scanf("%d", &n);

    printf("Enter the numbers in ascending order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the number to be searched: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        
        if (a[mid] == key) {
            found = 1;
            break;
        }
        
        else if (a[mid] < key) {
            low = mid + 1;
        }
        
        else {
            high = mid - 1;
        }
    }

    if (found == 1) {
        printf("%d found at position: %d", key, mid + 1);
    }
    
    else {
        printf("%d not found.", key);
    }
    
    return 0;
}
