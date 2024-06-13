// This program defines a structure for storing Employee details and then uses this structure to manage an array of employees. Here’s a detailed breakdown of what the program does:
#include <stdio.h>
#include <string.h>

// Define the Employee structure
struct Employee
{
    int Id;
    char Name[100];
    float Salary;
};

int main()
{
    int n, i, index_of_highest_salary = 0;

    // Take the number of employees as input
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Create an array of Employee
    struct Employee employees[n];
    printf("%d",sizeof(employees));
    // Take input for each Employee
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for employee %d:\n", i + 1);

        printf("Enter Employee ID: ");
        scanf("%d", &employees[i].Id);
        getchar(); // To consume the newline character left by scanf

        printf("Enter Employee Name: ");
        fgets(employees[i].Name, sizeof(employees[i].Name), stdin);
        // Remove the newline character if present
        employees[i].Name[strcspn(employees[i].Name, "\n")] = '\0';

        printf("Enter Employee Salary: ");
        scanf("%f", &employees[i].Salary);
    }

    // Find the Employee with the highest salary
    for (i = 1; i < n; i++)
    {
        if (employees[i].Salary > employees[index_of_highest_salary].Salary)
        {
            index_of_highest_salary = i;
        }
    }

    // Display the details of the Employee with the highest salary
    printf("\nEmployee with the highest salary:\n");
    printf("ID: %d\n", employees[index_of_highest_salary].Id);
    printf("Name: %s\n", employees[index_of_highest_salary].Name);
    printf("Salary: %.2f\n", employees[index_of_highest_salary].Salary);

    return 0;
}
