/**********************************************
  虽然程序执行没有问题,但是在用户输入一个
  既不是运算符也不是操作数的时候不能正常结束，
  二是停留在一个无限输入的状态，不能自动退出程序
  如果在return之前加上一个printf语句，即使是输入
  其他字符也不能显示这个printf语句
  不清楚为什么会这样？
 **********************************************/
#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100

/* external variable */
int contents[STACK_SIZE];
int top = 0;

/* function prototype */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
    char ch = 0;
    bool end = false;
    int temp;

    while (!end) {
        make_empty();

        printf("Enter an RPN expression: ");

        for ( ; ch != '='; ) {
            scanf(" %c", &ch);

            switch(ch) {
                case '0':   push(0);    break;
                case '1':   push(1);    break;
                case '2':   push(2);    break;
                case '3':   push(3);    break;
                case '4':   push(4);    break;
                case '5':   push(5);    break;
                case '6':   push(6);    break;
                case '7':   push(7);    break;
                case '8':   push(8);    break;
                case '9':   push(9);    break;
                case '-1':  push(-1);   break;    //负数主要为运算后的结果压入栈中
                case '-2':  push(-2);   break;
                case '-3':  push(-3);   break;
                case '-4':  push(-4);   break;
                case '-5':  push(-5);   break;
                case '-6':  push(-6);   break;
                case '-7':  push(-7);   break;
                case '-8':  push(-8);   break;
                case '-9':  push(-9);   break;
                case '+':   push(pop() + pop());
                            break;
                case '-':   temp = pop();
                            push(pop() - temp);    //注意减法和除法先弹出的是减数和除数
                            break;
                case '*':   push(pop() * pop());
                            break;
                case '/':   temp = pop();
                            push(pop() / temp);    //但是计算时是：被减数-减数，被除数/除数
                            break;
                case '=':   printf("Value of expression: %d\n", pop());
                            break;
                default:    end = true;  break;
            }
        }
        ch = 0;
    }

    return 0;
}

/************************************************
  Function: make_empty
  Description: make stack empty
  Calls: No
  Called by: main
  Input:
  Output:
  Return:
  Others:
 ***********************************************/
void make_empty(void)
{
    top = 0;
}

/**********************************************
  Function: is_empty
  Description: check stack whether is empty
  Calls: No
  Called by: push
  Input:
  Output:
  Return:
  Others:
 *********************************************/
bool is_empty(void)
{
    return top == 0;
}

/*********************************************
  Function: is_full
  Description: check stack whether is full
  Calls: No
  Called by: pop
  Input:
  Output:
  Return:
  Others:
 *********************************************/
bool is_full(void)
{
    return top == STACK_SIZE;
}

/*********************************************
  Function: push
  Description: push the i into the top
  Calls: is_full, stack_overflow
  Called by: main
  Input:
  Output:
  Return:
  Others:
 *********************************************/
void push(int i)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = i;
}

/********************************************
  Function: pop
  Description: pop the top from stack
  Calls: is_empty, stack_underflow()
  Called by: main
  Input:
  Output:
  Return:
  Others:
 ********************************************/
int pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}

/*********************************************
  Function: stack_overflow
  Description: print it when stack is overflow
  Calls:
  Called by: push
  Input:
  Output:
  Return:
  Others:
 *********************************************/
void stack_overflow(void)
{
    printf("Expression is too complex");
}

/**********************************************
  Function: stack_underflow
  Description: print it when stack is underflow
  Calls:pop
  Called by: pop
  Input:
  Output:
  Return:
  Others:
 *********************************************/
void stack_underflow(void)
{
    printf("Not enough operands in expression");
}
