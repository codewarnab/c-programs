#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
 void input();
 void print();
 void add();
 void sub();
 void tsp();
 void mul();
 int row,col;
int main ()
 {
     int op,s1,s2  ;
      printf("Enter row  number first array:");
      scanf(" %d",&row);
      int ** arr1= (int **)malloc (row * sizeof(int *));
      printf("Enter column number :");
      scanf(" %d",&col);
      for (int i = 0; i < row; i++) {
          arr1[i]=(int*)malloc(col*sizeof(int));
      }
      input(arr1);
      s1=row*col;
      printf("(!FOR ALL FUNTIONS MAKE SURE BOTH ARRAY ARE OF SAME SIZE!)\n");
      printf("Enter row  number second array:");
      scanf(" %d",&row);
      int ** arr2= (int **)malloc (row * sizeof(int *));
      
      printf("Enter column number :");
      scanf(" %d",&col);
      for (int i = 0; i < row; i++) {
          arr2[i]=(int*)malloc(col*sizeof(int));
      }
      input(arr2);
      s2=row*col;
      printf("enter which oporation you want to perform\n");
      if (s1==s2) {
          
      printf("Addition (0)\t Substraction(1)\nTranspose(2)\t Multiplicaton(3)  \n ");
      }
      else {   
      printf("Transpose (2) \n");    
      }
      scanf(" %d",&op);
      printf("Entered matrices are \n");
      printf(" First matrix \n");
      print(arr1);
      printf(" Second  matrix \n");
      print(arr2);
      switch (op)
      { 
           case 0: 
         printf("Additon of two matrices below \n");
          add(arr1,arr2);
          break;
         case 1:
          printf("substraction of two matrices below \n");
          sub(arr1,arr2);
          break;
          
         case 2:
          printf("transpose of first matrix  \n");
          tsp(arr1);
          printf("transpose of second  matrix  \n");
          tsp(arr2);
          break;
         case 3:
          printf("multiplication of two matrices below \n");
          mul(arr1,arr2);
          break;
          
         default:
          break;
      }
      printf("Do you wanna restart?");
      printf("Enter 'y' for yes 'n' for no ");
       char ch ;
       scanf(" %c",&ch);
       if (ch=='y')
       { 
         main();
       }
       else 
      return 0;
       
 }
void input(int arr[row][col])
 { 
      
      printf("Enter enter  elements  \n");
     int i,j;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j <col ; j++) {
           scanf(" %d",*(arr+i)+j);
        }

    }
  
  }
void print(int arr[row][col])

  { int i,j;
     for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t",*(*(arr+i)+j));
        }
        printf("\n");
    }
  
  }
void add(int arr1[row][col],int arr2[row][col])
  {
  
    int i,j,add[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          add[i][j]= arr1[i][j]+arr2[i][j];
        }
        
    }
   print(add);
  }
  
void sub(int arr1[row][col],int arr2[row][col])
  {
  
    int i,j,sub[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
          sub[i][j]= arr1[i][j]-arr2[i][j];
        }
        
    }
   print(sub);
  }
  
void tsp(int arr[row][col])
  {
  
    int i,j;
        for (int j = 0; j < col; j++) {
           for (int i = 0; i < row; i++) {
          printf(" %d  ",arr[i][j]);
        }
        printf("\n");
    }
   
  }
void mul(int arr1[row][col],int arr2[row][col])
  {
  
    int i,j,mul[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            mul[i][j]=0;
            for (int k = 0; k <col ; k++) {
          mul[i][j]+= arr1[i][k]*arr2[k][j];
            }
        }
        
    }
   print(mul);
  }
  
