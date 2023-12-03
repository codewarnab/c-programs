// this program is to charecter by charecter and print the output

#include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 int main ()
 { FILE *fp=NULL;
 char ch ;
 fp = fopen ("strinoutput.txt","r"); // here r represents the read  mode 
//here file must be created alr4eADY FOR reading if file 
// checking if not there fp = NULL 
if (fp==NULL ) {
    printf ("error");
    exit(1); 
}
while (!feof(fp)) // location + kore check if it is eof  or not 
 {
  ch =fgetc(fp);   // basically funtion ta jeta read korche ota amra 
                  // ch a store kore print korbo 
  printf("%c",ch);
    /* code here */ 
 }
    /*feof funtion indicate end of file and this return true or false value 
    at the end of file a giye true hobe jekane loop stop hobe so oi true spot \
    take ! diye false korte hobe */
    /* for reading the first charecter use just fgetc and not the ;loop */
    /* fgetc() is used to obtain input from a file single character 
     at a time. This function returns the ASCII code of the character read
      by the function. It returns the character present at position 
      indicated by file pointer. Afterreading the character, the file 
  pointer is advanced to next character.*/
fclose(fp);

 }