#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float a, b, c, d, root1, root2, real, imaginary;

    printf("Enter the coefficients of a, b, and c: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a == 0) {
        printf("Invalid coefficients.");
        exit(0);
    }

    d = (pow(b, 2)) - (4 * a * c);

    if (d > 0) {
        root1 = (- b + (sqrt(d))) / (2 * a);
        root2 = (- b - (sqrt(d))) / (2 * a);
        printf("The roots are real and distinct.\n");
        printf("Root 1: %f\nRoot 2: %f", root1, root2);
    } 

    else if (d == 0) {
        root1 = root2 = - b / (2 * a);
        printf("The roots are real and equal.\n");
        printf("Both root 1 and root 2: %f", root1);
    }

    else {
        real = - b / (2 * a);
        imaginary = sqrt(fabs(d)) / (2 * a);
        printf("The roots are complex and imaginary.\n");
        printf("Root 1: %f + i%f\nRoot 2: %f - i%f", real, imaginary, real, imaginary);
    }
    return 0;
}