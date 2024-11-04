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
// Traverse the expression; push any opening brackets onto the stack.
// For each closing bracket, check if it matches the top stack element.
// If there's no match or stack is empty, return 0 (not balanced).
// At the end, return 1 if stack is empty (balanced), else 0.

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