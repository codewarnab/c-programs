#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main ()
{
 struct student 
{ 
char name[20];
int marks;
int roll ;
char grade ;
} ;
char n[20];
struct student std;
    int m,i;
printf("Enter number of student ");
scanf("%d",&m);
struct student  *ptr=malloc(m*sizeof(*ptr));
  //input block 
  for(i=0;i<m;i++)
  { printf("enter details for student [%d]\n",i+1);
   printf("Enter roll number ");
  scanf("%d",ptr[i].roll);
   printf("Enter name of the student ");
   gets(n);
    strcpy(ptr[i].name,n);
   printf("Enter studens  marks ");
   scanf("%d",ptr[i].marks);
   
  }

 //output block 
 printf("\n Name\tRoll\tMarks\tgrade");
  for(i=0;i<m;i++)
 {
  if (ptr[i].marks<30)
  {
   ptr[i].grade='F';
  }
    else if (ptr[i].marks>=30 && ptr[i].marks<60)
    {
     
 
   ptr[i].grade='B';
  }
  else if (ptr[i].marks>=60 && ptr[i].marks<80)
  {
   ptr[i].grade='A';
  }
  else  
  {
   ptr[i].grade='A';
  }
  
  printf("\n%20s\t%d\t%d\t%c",ptr[i].name,ptr[i].roll,ptr[i].marks,ptr[i].grade);
  
 }
}