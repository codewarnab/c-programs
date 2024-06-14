#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
 int data;
 struct node *next;
}nd;
nd *insertend(nd *h);
void view(nd *h);
int main()
{
 nd *head=NULL;
 int ch;
 while(1)
 {
  printf("\n1.for Insert at End");
  printf("\n2.for View");
  printf("\n3.for Exit");
  printf("\nEnter choice:");
  scanf("%d",&ch);
  fflush(stdin);
  switch(ch)
  {
   case 1:
        head=insertend(head);
        break;
   case 2:
        view(head);
        break;
   case 3:
        exit(0);
   default:
        printf("\nInvalid Choice...");
        
  }
 }
}
nd *insertend(nd *h)
{
 nd *temp,*temp1;  int x;
 temp=(nd *)malloc(sizeof(nd)) ;
 printf("enter data : ");
 scanf("%d",&x);
 fflush(stdin);
 temp->data=x;
 temp->next=NULL;
 if(h==NULL)
 {
   h=temp;
 }
 else
 {
   temp1=h;
  while(temp1->next!=NULL)
  {
   temp1=temp1->next;
  }
  temp1->next=temp;  
 }
 return(h);
}
void view(nd *head)
{
 nd *temp=head;
 while(temp!=NULL)
 {
  printf("%d->",temp->data);
  temp=temp->next;
 }
}