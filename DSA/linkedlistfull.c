//inserting a node after a specific node 
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
void insertsp();
void appened();
void printnode();
void deletebeg();
void deleteend();
int getlenth();

int main (){
  int ch ;
  while(1){
      
   printf("\nEnter choice : \n");
   printf("1.insert at end \n2.exit\n3.printlist \n4.Add node  begining\n"  
    "6.insertafter a specific node \n7.Delete from begining\n"
    "8.Deleting last node\n");
   
   scanf("%d",&ch);
   switch (ch)
     {case 1:
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
      break;
      case 6 :
          if (head ==NULL)
          printf("list is empty ");
          else 
          insertsp();
          break ;
      case 7:
       if (head ==NULL)
          printf("list is empty ");
          else 
          deletebeg();
          break;
     case 8:
         if (head ==NULL)
         printf("list is empty ");
      else 
        deleteend();  
		break;
     default:
       printf("invalid choice !\n");
        break;
   }
  }}

//   Funtiuon for deleting the frist  node 
void deletebeg()
{  
    nd*temp = head ;
    if(head==NULL)
 {
  printf("list is empty");
  return;
 }
 head = temp->next;
 free(temp); 
 printf("First node is deleted ");
}
//   Funtiuon for deleting the last node 
void deleteend(){
 
 nd * temp ,*prev=NULL ;
 if(head==NULL)
 {
  printf("list is empty");
  return;
 }
 temp=head;
 while (temp->next!=NULL)
 { prev = temp ;
 temp= temp->next ; }
 if(prev==NULL)
  head=NULL;
 else
 {
 
 prev->next = NULL ;
 free(temp);
 printf("last node is deleted ");
 }
}
// funtion for creating nodes of the list 
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
//   funtion for printing the list 

void printnode()
{   nd *curr = head ;int count= 0 ;
   printf("printing the list:\n\n");
   while (curr != NULL ) {
    printf("%d.%d \n",++count , curr->data );
    curr = curr->next; 
 }
 printf("Length of the list = %d \n",count);
}

// funtion for adding new node at the begining  of the list 
void insertbeg( )
{
   nd *newnode;
   newnode = (struct node *)malloc(sizeof(struct node *));
   printf("enter data :");
   scanf("%d",&data);
   newnode->data=data  ;
   newnode->next= head ;
   head = newnode  ;
}
// for adding node after a specific position 
void insertsp(){
    int l,pos,i=1;
    printf("Enter postion after which you want to insert node  :\n");
    scanf("%d",&pos);
    nd * temp,*newnode;
     l = getlenth();
    if(pos>l)
    {
        printf(" invalid position! \n");
    }
    else {
        newnode= (struct node *)malloc(sizeof(struct node *));
        printf("Enter data :");
        scanf("%d",&newnode->data);
        temp = head ;
        while (i<pos)
        {
            temp = temp ->next ;
            i++;
        }
        newnode->next= temp->next;
        temp->next=newnode;
    }
}
int getlenth(){
    int l=0 ; nd *temp ;
temp = head ;
while(temp!=NULL){
    l++;
    temp = temp->next;
}
return l ;

}