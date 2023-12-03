#include <stdio.h>
// #include <conio.h>
// #include <string.h>
// #include <stdlib.h>
void dayname(int n);
int main ()
{int n;
     printf("enter the  day number ");
scanf("%d",&n);
dayname(n);

}
void dayname (int n)
{  switch (n) {
      case 1:
      printf("Monday\n");
      break;
      case 2:
      printf("TUESDAY\n");
      break;
      case 3:
      printf("WEDNESDAY\n");
      break;
      case 4:
      printf("THURSDAY\n");
      break;
      case 5:
      printf("FRIDAY\n");
      break;
      case 6:
      printf("SATURDAY\n");
      break;
      case 7:
      printf("SUNDAY\n");
       break;
    default:
        break;
    }
    
}











