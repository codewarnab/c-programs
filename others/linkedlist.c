// this is a simple program t create linkedlist 

#include <conio.h>
#include <stdlib.h>
#include<stdio.h>
typedef struct node {
    int data ;
    struct node *next ;
} nd ;
nd *head = NULL ;
void append (int data );
void display ( );
void printnode(nd *head);
int main (int argc, char *argv[]) {
    int ch ,data;
printf(" enter choice :");
    while (1) {
    printf("<1>create node\n ");
    printf("<0> for exit \n");
    printf("<2>call print funtion \n");
    
    scanf("%d",&ch);
        switch (ch )
    {
        case 1:
        printf("enter data ");
        scanf("%d",&data);
        append (data);
        display();
        break;
        case 0:
         exit(0);
         break;
         case 2:;
         void printnode(nd *head);
         break;
    default:
        break;
    }
        
    }
    return 0;
}
//this funtion is creating node and linking them eg
void append (int data )
{
    nd *temp ,*curr ;
    temp =(struct node* )malloc(sizeof(struct node ));
    temp->data=data ;
    temp->next = NULL ;
    if (head == NULL)
 head = temp ;

 else {
     curr = head ;// the address of first node is copied to curr 
     while(curr->next!=NULL) // in case of the last node not reached 
     { curr = curr->next; }//move curr to next link part of curr  
         curr->next= temp ; // to connect new node at end of the list 
     
 }
}

void display() {

    int count = 0 ;
    nd * curr = head ;
    printf("\n current list : ");
    while (curr!= NULL )
    {printf("\ndata %d = %d \n",++count,curr->data);
    curr=curr->next;
    }
    
}

void printhnode(nd *head)
{
    while (head->next != NULL)
    {
        head = head->next; //Because there is a head node,
        //  but the head node does not store data, 
        //  it starts traversal from the next node of the head node
        printf("%d\n", head->data);
    }
}




