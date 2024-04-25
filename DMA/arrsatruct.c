#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* firstName;
    char* lastName;
    int rollNumber;
} STUDENT;

int main() {
    int numStudents = 1;
    int x;

    STUDENT* students = malloc(numStudents * sizeof(STUDENT));

    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (x = 0; x < numStudents; x++) {
        char input[100]; // Assuming max length of input string is 100 characters

        printf("Enter first name: ");
        scanf("%s", input);
        students[x].firstName = malloc(strlen(input) + 1); // Allocate memory for string and null terminator
        strcpy(students[x].firstName, input);

        printf("Enter last name: ");
        scanf("%s", input);
        students[x].lastName = malloc(strlen(input) + 1); // Allocate memory for string and null terminator
        strcpy(students[x].lastName, input);

        printf("Enter roll number: ");
        scanf("%d", &students[x].rollNumber);

        printf("Student details: %s %s %d\n", students[x].firstName, students[x].lastName, students[x].rollNumber);
    }

    // Free allocated memory
    for (x = 0; x < numStudents; x++) {
        free(students[x].firstName);
        free(students[x].lastName);
    }
    free(students);

    return 0;
}
