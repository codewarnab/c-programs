// Author = Arnab Mondal 
 // Date = 25 may in 2022 

 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <limits.h>
 #include <time.h>
 double inputarr[100];
 // This funtion for main input 
double *input(int n,double *inputarr)
 {  
    int i;
   printf("enter numbers :: ");
    for ( i = 0; i < n; i++) 
    {
       scanf(" %lf",&inputarr[i]);
       
    } 
    return inputarr;

 }
 // This funtion is for addition
void  add( )
 { 
 int n,i;
 double *addarr;
 
 double  sum=0.0;
    printf(" how many numbers you want to add ?");
    scanf(" %d",&n);
    addarr = input(n,inputarr);
    for (i = 0; i < n; i++) {
        
        sum+=*addarr;
        ++addarr;
        
    }
    printf(" sum of the enterd numbers is %lf ",sum);
 }
 // This funtion is for multiplication 
void multiply()
 {   double  result=1.0,*mul2;int n;
    printf(" how many numbers you want to multiply ?");
    scanf(" %d",&n);
    mul2=input(n,inputarr);
    // Doing multiplication 
    for (int i = 0 ; i < n ;i++ )
    {   result *=*mul2;
     ++mul2;
    }
    printf(" Multiplication of the entered number = %lf ",result);
 }

void substraction()
  {   double result =0.0 , *sub1; int n ;
      printf(" how many numbers you want to substraction ?");
      
      scanf(" %d",&n);
      printf("(Dont forget to add sign)")
      sub1=input(n,inputarr);
    
   for (int i = 0 ; i < n ;i++ )
    {   result -=*sub1;
     ++sub1;
    }
     printf(" Multiplication of the entered number = %lf ",result);
     
  }
int main ()

  {   double tick1,tick2,et;
       int op ;
       printf("which funtion you want to do ?\n");
       printf ("Additon (0)\tMultiplication (1)\t Substraction (2)");
       scanf("%d",&op);
      tick1= clock();
       switch (op)
       {
       case 0:
       add();
   
       case 1:
       multiply();
       
       case 2:
      substraction();
        
       //     case 0:
       //  add();
        
       //     case 0:
       //  add();
        
         default:
       break;
        }
       tick2 = clock();
       double e = tick2- tick1;
       et= (double)e/CLOCKS_PER_SEC;
       printf(" Time taken to calculate = %lf... second   ",et);
       return 0;
  }

