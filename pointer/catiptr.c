#include <stdio.h>
#include <string.h>

int main()  
{
  char str1[100] = "arnab ";
  char str2[100] = "mondal";
  char *ps1, *ps2;

  ps1 = str1;
  ps2 = str2;

  // Move ps1 to the end of the first string
  while (*ps1 != '\0')
  {
    ps1++;
  }

  // Concatenate str2 to the end of str1
  while (*ps2 != '\0')
  {
    *ps1 = *ps2;
    ps1++;
    ps2++;
  }

  // Null-terminate the resulting string
  *ps1 = '\0';

  // Output the concatenated string
  puts(str1);

  return 0;
}
