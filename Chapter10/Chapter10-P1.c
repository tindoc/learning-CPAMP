#include <stdbool.h>
#include <stdio.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char ch);
int pop(void);
void stack_underflow(void);
void stack_overflow(void);

int main(void)
{
    char ch;

    make_empty();

    printf("Enter parenteses and/or braces: ");
    for ( ;(ch = getchar()) != '\n'; ) {
        switch(ch) {
            case '(':   push(ch);   break;
            case '{':   push(ch);   break;
            case ')':   pop();
                        if (contents[top] != '(') {
                                printf("Parenteses/braces aren't nested properly.\n");
                                goto stop;
                            }
                            break;
            case '}':   pop();
                        if (contents[top] != '{') {
                            printf("Parenteses/braces aren't nested properly.\n");
                            goto stop;
                        }
                            break;
        }
    }

    if (is_empty())
        printf("Prenteses/braces are nested properly.\n");
    else
        printf("prenteses/braces aren't nested properly.\n");

    stop:

    return 0;
}

/*************************************
 *Function:    make_empty
 *Description: initialize a empty stack
 *Calls:       No
 *Called by:   main
 *Input:
 *Output:
 *Return:
 *Others:
 *************************************/
 void make_empty(void)
 {
     top = 0;
 }

/************************************
 *Function:    is_empty
 *Description: judge the stack whether is empty
 *Calls:       No
 *Called by:   main, pop
 *Input:
 *Output:
 *Return:
 *Others:
 *************************************/
 bool is_empty(void)
 {
     return top == 0;
 }

/*************************************
 *Function:    is_full
 *Description: judge the stack whether is full
 *Calls:       No
 *Called by:   push
 *Input:
 *Output:
 *Return:
 *Others:
 **************************************/
 bool is_full(void)
 {
     return top == STACK_SIZE;
 }

/***************************************
 *Function:    push
 *Description: push the top in the stack
 *Calls:       is_full, stack_overflow
 *Called by:   main
 *Input:
 *Output:
 *Return:
 *Others:
 ****************************************/
 void push(char ch)
 {
     if (is_full())
        stack_overflow();
     else
        contents[top++] = ch;
 }

/***************************************
 *Function:    pop
 *Description: pop the top in the stack
 *Calls:       is_empty, stack_underflow
 *Called by:   main
 *Input:
 *Output:
 *Return:
 *Others:
 ****************************************/
 int pop(void)
 {
     if (is_empty())
        stack_underflow();
     else
        return contents [--top];
 }

/***************************************
 *Function:    stack_underflow
 *Description: stack underflow and print it
 *Calls:       No
 *Called by:   pop
 *Input:
 *Output:
 *Return:
 *Others:
 ****************************************/
 void stack_underflow(void)
 {
     printf("Parenteses/braces aren't nested properly.\n");
 }

/***************************************
 *Function:    overflow
 *Description: stack overflow and print it
 *Calls:       No
 *Called by:   push
 *Input:
 *Output:
 *Return:
 *Others:
 ****************************************/
 void stack_overflow(void)
 {
     printf("Stack Overflow.\n");
 }
