#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    struct student { 
        char name[20];
        int marks;
        int roll;
        char grade;
    };

    int m, i;
    printf("Enter number of students: ");
    scanf("%d", &m);

    // Dynamic memory allocation
    struct student *ptr = malloc(m * sizeof(*ptr));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exiting program due to memory allocation failure
    }

    // Input block 
    for (i = 0; i < m; i++) {
        printf("Enter details for student [%d]\n", i + 1);
        printf("Enter roll number: ");
        scanf("%d", &ptr[i].roll);

        getchar(); // Consume newline character
        printf("Enter name of the student: ");
        fgets(ptr[i].name, sizeof(ptr[i].name), stdin);
        strtok(ptr[i].name, "\n"); // Remove newline character from the name

        printf("Enter student's marks: ");
        scanf("%d", &ptr[i].marks);
    }

    // Output block 
    printf("\n Name\tRoll\tMarks\tGrade");
    for (i = 0; i < m; i++) {
        if (ptr[i].marks < 30) {
            ptr[i].grade = 'F';
        } else if (ptr[i].marks >= 30 && ptr[i].marks < 60) {
            ptr[i].grade = 'C';
        } else if (ptr[i].marks >= 60 && ptr[i].marks < 80) {
            ptr[i].grade = 'B';
        } else {
            ptr[i].grade = 'A';
        }
        printf("\n%-20s\t%d\t%d\t%c", ptr[i].name, ptr[i].roll, ptr[i].marks, ptr[i].grade);
    }

    // Free dynamically allocated memory
    free(ptr);
    
    return 0;
}
