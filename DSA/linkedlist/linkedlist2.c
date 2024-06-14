#include<stdio.h>
#include <stdlib.h>
typedef struct node 
{
   int data ;
   struct node *next;	
}nd ;
int data ;
nd *head = NULL ;
void insertbeg();
void insertend();
void appened();
void printnode();
int main (){
int ch ;
while(1){
	printf("enter choice : \n");
	printf("1.insert at end  \n2.exit\n 3.printlist \n4.Add node begining \n5.Add node at end  \n");
	scanf("%d",&ch);
	switch (ch)
	{  case 1:
	 appened();
	 break;
	 case 2 :
 exit(0);
 break;
 case 3 :
 printnode();
 break ;
 case 4 :
 insertbeg();
 break;
 case 5 :
// insertatend();
 break;
	default:
	printf("invalid choice !\n");
		break;
	}
}}

void appened( )
{  nd * temp , * curr ;
	 temp =(struct node * )malloc(sizeof(struct node  *)); 
	printf("Enter data :");
	scanf("%d",&data);
	temp->data=data;
	temp->next=NULL;
	if (head == NULL)	
	head = temp ;
	else 
	{
		curr = head ;
		while (curr->next!=NULL) {
			curr = curr->next;
		} 
		curr->next= temp  ;
		}
	}

void printnode()
{ nd *curr = head ;int count= 0 ;
 printf("printing the list:\n ");
 while (curr != NULL ) {
	 printf("%d.%d \n",++count , curr->data );
	 curr = curr->next; 
 }
}

void insertbeg(){
	nd *newnode;
	newnode = (struct node *)malloc(sizeof(struct node *));
	printf("enter data :");
	scanf("%d",&data);
	newnode->data=data  ;
	newnode->next= head ;
	head = newnode  ;
}
// void insertend(){
// 	nd *newnode;
// 	newnode = (struct node *)malloc(sizeof(struct node *));
// 	printf("enter data :");
// 	scanf("%d",&data);
// 	newnode->data=data  ;
// 	while (curr->next!=NULL) {
// 			curr = curr->next;
// 		} 
	
// }
