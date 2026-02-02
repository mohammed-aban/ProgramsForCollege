#include<stdio.h>

int main() {
    FILE *sourceFile, *targetFile;
    char sourcePath[100], targetPath[100];
    char letter;

    // Entering the source file path
    printf("Enter the source file path: ");
    scanf("%s", sourcePath);

    // Entering the target file path
    printf("Enter the target file path: ");
    scanf("%s", targetPath);

    // Open the source file in read mode
    sourceFile = fopen(sourcePath, "r");

    if (sourceFile == NULL) {
        printf("No source file detected.");
        return 1;
    }

    // Create the target file
    targetFile = fopen(targetPath, "w");

    if (targetFile == NULL) {
        printf("No target file has been created.");
        fclose(sourceFile);
        return 1;
    }

    // Copy contents from source file to target file
    while ((letter = fgetc(sourceFile)) != EOF) {
        fputc(letter, targetFile);
    }

    fclose(sourceFile);
    fclose(targetFile);

    printf("File opened successfully.");

    return 0;
}