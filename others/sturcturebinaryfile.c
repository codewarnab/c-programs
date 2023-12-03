//write a program  that stores a structure in a binary file and read the structure from binary file 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct emp {
 int eid ;
 char *name;
} ;
int main ()
{  struct emp e2;
 int i ; 
 printf("Enter how many employes data you want to store :");
 int n ;
 scanf("%d",&n);
 struct emp *e = (struct emp*)calloc(n,sizeof(struct emp) );
 
 for(i=0;i<n;i++)
 { 
     e[i].name=(char*)malloc(sizeof(char*));
  printf("Enter the name of the employee ");
  fflush(stdin);
  scanf("%s",e[i].name);
  
  printf("Enter employee id ");
  
  fflush(stdin);
  scanf("%d",&e[i].eid);
  
 }
 FILE *fp,*fp1;
 fp=fopen("abc.bin","wb");
 
for(i=0;i<n;i++)
 {
    fwrite(&e[i],sizeof(struct emp ),1,fp );
 }
 fclose(fp);
 fp1=fopen("abc.bin","rb");
 for(i=0;i<n;i++)
 {
    fread(&e2,sizeof(struct emp ),1,fp );
    printf("%s",e2.name\n);
    printf("%d",e2.eid);
 }
 fclose(fp1);
 return 0;
}