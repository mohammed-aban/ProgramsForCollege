#include<stdio.h>
#include<math.h>

int main() {
    float myArr[10], *pMyarr, mean, sum = 0, stdSum = 0, stdDev;
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &myArr[i]);
    }

    // Point to the start of the array
    pMyarr = myArr;

    // Calculating the sum
    for (i = 0; i < n; i++) {
        sum += *pMyarr;
        pMyarr++;
    }

    // Calculating the mean
    mean = sum / n;

    // Reset pointer to the start of the array
    pMyarr = myArr;

    // Calculating standard sum
    for (i = 0; i < n; i++) {
        stdSum += pow((*pMyarr - mean), 2);
        pMyarr++;
    }

    // Calculating standard sum
    stdDev = sqrt(stdSum / n);

    printf("Sum: %f\n", sum);
    printf("Mean: %f\n", mean);
    printf("Standard Deviation: %f", stdDev);

    return 0;
}