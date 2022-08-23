#include <stdio.h>

int main(void)
{
    float a, b, c, sum;
    char ch1, ch2;

    printf("Enter an expression: ");
    scanf("%f", &a);

    ch1 = getchar();

    scanf("%f", &b);
    switch (ch1) {
        case '+':
            sum = a + b;
            break;
        case '-':
            sum = a - b;
            break;
        case '*':
            sum = a * b;
            break;
        case '/':
            sum = a / b;
            break;
    }

    ch2 = getchar();

    scanf("%f", &c);
    switch (ch2) {
        case '+':
            sum = sum + c;
            break;
        case '-':
            sum = sum - c;
            break;
        case '*':
            sum = sum * c;
            break;
        case '/':
            sum = sum / c;
            break;
    }
    printf("Value of expression: %.1f\n", sum);

    return 0;
}
