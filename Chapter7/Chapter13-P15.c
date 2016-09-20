#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100
#define MAX 199

/* external variables */
int top = 0;
int contents[STACK_SIZE];

/* function prototype */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);
int evaluate_RPN_expression(const char *expression);

/* main function */
int main(void)
{
	char expression[MAX];

	for ( ; ; ) {
		printf("Enter an RPN expression: ");
		gets(expression);
		if (expression[0] < '0' || expression[0] > '9')
			break;

		printf("Value of expression: %d\n", evaluate_RPN_expression(expression));
	}

	return 0;
}

/* function */
void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(int i)
{
	if (is_full())
		stack_overflow();
	else
		contents[top++] = i;
}

int pop(void)
{
	if (is_empty())
		stack_underflow();
	else
		return contents[--top];
}

void stack_overflow(void)
{
	printf("Expression is too complex");
}

void stack_underflow(void)
{
	printf("Not enough operands in expression");
}

int evaluate_RPN_expression(const char *expression)
{
	int i, temp;

	make_empty();

	for (i = 0; expression[i] != '\0'; i++) {
		if (expression[i] >= '0' && expression[i] <= '9')
			push(expression[i] - '0');
        else
            switch (expression[i]) {
                case '+':
                    push(pop() + pop());
                    break;
                case '-':
                    temp = pop();
                    push(pop() - temp);
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    temp = pop();
                    push(pop() / temp);
                    break;
                case '=':
                    return pop();
                    break;
            }
	}
}
