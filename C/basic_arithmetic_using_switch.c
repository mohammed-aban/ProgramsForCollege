#include <stdio.h>
#include <stdlib.h>

int main() {
    int first_num, second_num, result;
    char operation;

    printf("Enter a simple arithmetic operation: ");
    scanf("%d %c %d", &first_num, &operation, &second_num);

    switch (operation) {
    case '+':
        result = first_num + second_num;
        break;
    
    case '-':
        result = first_num - second_num;
        break;

    case '*':
        result = first_num * second_num;
        break;

    case '/':
        if (second_num != 0) {
            result = first_num / second_num;
        }
        else {
            printf("Division by 0 isn't possible.");
            exit(0);
        }
        break;
    
    case '%':
        result = first_num % second_num;
        break;

    default:
        printf("Invalid operation.");
        break;
    }

    printf("%d %c %d = %d", first_num, operation, second_num, result);
    return 0;
}