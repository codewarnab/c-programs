#include<stdio.h>
#include<stdlib.h>
int main(int argc, char** argv)
{
    typedef struct
    {
        char* firstName;
        char* lastName;
        int rollNumber;

    } STUDENT;

    int numStudents=1;
    int x;
    STUDENT* students = malloc(numStudents * sizeof (*students));
   
    for (x = 0; x < numStudents; x++)
    {
        students[x].firstName=(char*)malloc(sizeof(char*));
       
        printf("Enter first name :");
        scanf("%s",students[x].firstName);
        students[x].lastName=(char*)malloc(sizeof(char*));
        printf("Enter last name :");
        scanf("%s",students[x].lastName);
        printf("Enter roll number  :");
        scanf("%d",students[x].rollNumber);

    }
}