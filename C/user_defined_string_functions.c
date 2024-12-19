// Making user-defined string-handling functions.

#include <stdio.h>

int strlength(char s1[50]);
void strconcat(char s1[50], char s2[50]);
void strcomp(char s1[10], char s2[10]);

int main() {
    char s1[50], s2[50];
    int length1, length2;

    printf("Enter the source string 1: ");
    scanf("%s", &s1);
    printf("Enter the source string 2: ");
    scanf("%s", &s2);

    length1 = strlength(s1);
    length2 = strlength(s2);

    printf("String length of string 1 is: %d\n", length1);
    printf("String length of string 2 is: %d\n", length2);

    strconcat(s1, s2);
    strcomp(s1, s2);

    return 0;
}

int strlength(char s1[50]) {
    int i = 0;
    while (s1[i] != '\0') {
        i++;
    }
    return i;
}

void strconcat(char s1[50], char s2[50]) {
    char s3[50];
    int i = 0, j = 0;

    while (s1[i] != '\0') {
        s3[i] = s1[i];
        i++;
    }

    while (s2[j] != '\0') {
        s3[i + j] = s2[j];
        j++;
    }

    s3[i + j] = '\0';
    printf("String concatenated: %s\n", s3);
}

void strcomp(char s1[10], char s2[10]) {
    int i = 0;
    while (s1[i] == s2[i] && s1 != '\0' && s2[i] != '\0') {
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0') {
        printf("Both the strings are same.");
    }
    else {
        printf("The strings are different.");
    }
}
