//program to create file AND ENTER CHARECTER ARray
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 int main ()
 {
 FILE *fp=NULL; 
 char str[50];
 fp=fopen("strinoutput.txt","w"); 
 if (fp==NULL)
  {
     printf("error ");
      exit(1);
 }
printf (" enter string for file :: ");
 gets (str);
 fputs(str,fp)   ; /*this funtion used to put a string directly 
                      into a file */
// you can use any of this 
//  for (int i = 0; i < strlen(str); i++)
//  {
// fputc(str[i],fp);
//  }
fclose(fp);
return 0;
 }