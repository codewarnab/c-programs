#include<stdio.h>
#include<string.h>

#define MAX 100 

char stack[MAX];
int top = -1;

void push(char ch ){
    if(top == MAX - 1){
        printf("Stack Overflow\n");
    }else{
        stack[++top] = ch;
    }
}

void pop(){
    if(top == -1){
        printf("Stack Underflow\n");
    }else{
        top--;
    }
}

int isMathhingPair(char left , char right ){
    if (left == '(' && right == ')'){
        return 1;
    }else if (left == '{' && right == '}'){
        return 1;
    }else if (left == '[' && right == ']'){
        return 1;
    }else{
        return 0;
    }

}

int areParenthesisBalanced(char exp[]){
    int i;
    for(i = 0; i < strlen(exp); i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(exp[i]);
        }else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(top == -1 || !isMathhingPair(stack[top], exp[i])){
                return 0;
            }else{
                pop();
            }
        }
    }
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    char exp[MAX];
    printf("Enter an expression: ");
    gets(exp);
    if(areParenthesisBalanced(exp)){
        printf("Balanced\n");
    }else{
        printf("Not Balanced\n");
    }
    return 0;
}