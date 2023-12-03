#include <stdio.h>
#include <stdlib.h>
 typedef struct  
{
    char *firstName;
    char *lastName ;
    int salary ;
}employee ;
typedef struct  
{
    char *firstName;
    char *lastName ;
    int salary ;
}swap  ;
int main ( ) 
{  swap s1;
    int employeen;
    printf("Enter number of employees : ");
    scanf("%d",&employeen);
    employee* employees = malloc(employeen*sizeof *employees); 
    for (int i = 0; i <employeen ; i++)
    {  employees[i].firstName=(char*)malloc(sizeof(char*));
        printf("Enter first name :");
        scanf("%s",employees[i].firstName);
        employees[i].lastName=(char*)malloc(sizeof(char*));
        printf("Enter last name :");
        scanf("%s",employees[i].lastName);
        printf("Enter the salary of %s ",employees[i].firstName);
        scanf("%d",&employees[i].salary);
    }



 for (int i = 0; i < employeen ; i++)
 {
printf("First Name: %s, Last Name: %s,salary: %d \n",employees[i].firstName,employees[i].lastName,employees[i].salary );
 }

     return 0;
}
