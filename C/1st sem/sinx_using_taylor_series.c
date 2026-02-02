// Finding sinx using Taylor Series
// sin(x) = x/1! - x^3! + x^5/5!-.....

#include <stdio.h>
#include <math.h>
#define PI 3.142

int main() {
    // Declare all the possible variables
    int degrees, factorial_number;
    float radians, sum = 0, term, numerator, denominator;

    printf("Enter the value of degrees: ");
    scanf("%d", &degrees);
    
    radians = degrees * (PI / 180);
    numerator = radians;
    denominator = 1;
    factorial_number = 2;

    do {
        term = numerator / denominator;
        numerator = -numerator * radians * radians;
        denominator = denominator * factorial_number * (factorial_number + 1);
        sum += term;
        factorial_number += 2;
    }
    while (fabs(term) >= 0.000001);

    printf("The summation of sine of %d is %f\n", degrees, sum);
    printf("The value of sin(%d) using library functions is %f", degrees, sin(radians));
    return 0;
}
