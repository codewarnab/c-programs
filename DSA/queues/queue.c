// implementation of Queue using array 

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void enqueue();
void dequeue();
void show();
int items[100],front=-1,rear= -1,size ;

int main ( ) 
{      
 int choice ;
 printf("Enter the number of elements for the store :");
 scanf("%d",&size);
 while(1){
 printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
 scanf("%d",&choice);
 switch (choice )
 {
     case 1:
     enqueue();
     break;
     case 2 :
     dequeue();
     break;
     case 3:
     show();
     break;
     case 4:
     printf("Exiting.....\n");
     exit(0);
     break;
 default:
 printf("Please enter a valid choice\n");
     break;
 }                                                          
 }
    return 0;
}
// inserts an element at the end of the queue i.e the rear end 
void enqueue()
{ int value ;
    if (rear==size-1)
    {
        printf("Queue is full !\n ");
    }
else {
    printf("Enter the value to enter :\n");
    scanf("%d",&value);
     if (front== -1 )
     front=0 ;
     rear++;
     items[rear]=  value ;
    printf("Insertd %d",value);
    }
}
// this funtion removes and returns the element that is at the front end of queque 
void dequeue()
{
    if(front==-1)
    printf("\n Queue is empty !");
    else 
    {
        printf("\n Deleted : %d \n", items[front]);
front++;
if(front>rear)
front=rear=-1;
    }
}
void show()
{
    if(rear==-1)
    printf("\n Queue is empty ");
    else {
        printf("Queue elements are :\n");
        for (int i = front ; i <=rear ; i++) {
            printf(" %d \t ",items[i]);
        }
    }
    printf("\n");
    
}







