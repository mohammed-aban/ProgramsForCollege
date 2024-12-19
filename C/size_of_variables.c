#include <stdio.h>

int main() {
    int integerType;
    float floatType;
    double doubleType;
    char charType;

    printf("Size of int: %d bytes\n", sizeof(integerType));
    printf("Size of float: %d bytes\n", sizeof(floatType));
    printf("Size of double: %d bytes\n", sizeof(doubleType));
    printf("Size of char: %d bytes\n", sizeof(charType));
    return 0;
}