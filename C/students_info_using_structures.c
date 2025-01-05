#include<stdio.h>

struct student_info {
    int roll_number;
    char name[20];
    float marks;
};

int main() {
    int number_of_students, i;
    struct student_info students_array[10];
    float sum = 0, average_marks;

    printf("Enter the number of students [max 10]: ");
    scanf("%d", &number_of_students);


    if (number_of_students < 1 || number_of_students > 10) {
        printf("Invalid number of students, please choose betweeen 1 - 10.");
        return 1;
    }

    for (i = 0; i < number_of_students; i++) {
        printf("Enter the details of student %d.\n", i + 1);

        printf("Enter the roll number: ");
        scanf("%d", &students_array[i].roll_number);

        printf("Enter the name: ");
        scanf("%s", &students_array[i].name);

        printf("Enter the marks: ");
        scanf("%f", &students_array[i].marks);
    }

    printf("Students details are:\n");
    printf("Roll No.\t\tName\t\tMarks\n");

    for (i = 0; i < number_of_students; i++) {
        printf("%d\t\t%s\t\t%.2f\n", students_array[i].roll_number, students_array[i].name, students_array[i].marks);
        sum += students_array[i].marks;
    }

    average_marks = sum / number_of_students;

    for (i = 0; i < number_of_students; i++) {
        if (students_array[i].marks >= average_marks) {
            printf("%s has scored above average marks.\n", students_array[i].name);
        }
        else {
            printf("%s has scored below average marks.\n", students_array[i].name);
        }
    }

    return 0;
}