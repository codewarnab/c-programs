// Define a structure named Employee that contains fields for ID, name, and salary.
// Take input from the user for the number of employees.
// Create an array of Employee structures based on the user-provided number.
// Prompt the user to input details for each employee, including ID, name, and salary.
// Find the employee with the highest salary among the entered details.
// Display the details of the employee with the highest salary.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Employee
{
    int id;
    char name[100];
    float salary;
} Employee;

int main()
{
    int n, i, index_highest_salary = 0;
    printf("Enter the number of employee");
    scanf("%d", &n);

    Employee *Employees = (Employee *)malloc(n * sizeof(Employee));

    if (Employees == NULL)
    {
        printf("Memory allocation error occured ");
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for employee %d:\n", i + 1);

        printf("Enter Employee ID: ");
        scanf("%d", &(Employees + i)->id);
        getchar(); // To consume the newline character left by scanf

        printf("enter the name of the employee ");
        fgets((Employees + i)->name, sizeof((Employees + i)->name), stdin);
        // Remove newline character from the end of the string
        (Employees + i)->name[strcspn((Employees + i)->name, "\n")] = '\0';

        printf("Enter employee Salary :");
        scanf("%f", &(Employees + i)->salary);
    }

    for (int i = 1; i < n; i++)
    {
        if ((Employees + i)->salary > (Employees + index_highest_salary)->salary)
        {
            index_highest_salary = i;
        }
    }

    printf("Employee with Highest salary :\n");
    printf("ID: %d\n", Employees[index_highest_salary].id);
    printf("Name: %s\n", Employees[index_highest_salary].name);
    printf("Salary: %.2f\n", Employees[index_highest_salary].salary);

    return 0;
}
