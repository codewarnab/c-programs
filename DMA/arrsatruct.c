#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* firstName;
    char* lastName;
    int rollNumber;
} STUDENT;

int main() {
    int numStudents ;
    printf("Enter number of students: ");
    scanf("%d", &numStudents);
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

       
    }

    // Print student details
    for (x = 0; x < numStudents; x++) {
        printf("Student %d\n", x + 1);
        printf("First name: %s\n", students[x].firstName);
        printf("Last name: %s\n", students[x].lastName);
        printf("Roll number: %d\n", students[x].rollNumber);
    }

    // Free allocated memory
    for (x = 0; x < numStudents; x++) {
        free(students[x].firstName);
        free(students[x].lastName);
    }
    free(students);

    return 0;
}
