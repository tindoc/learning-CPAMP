#include <stdio.h>

int result(int n)
{
    return 3 * n * n * n * n * n + 2 * n * n * n * n - 5 * n * n * n - n * n + 7 * n - 6;
}

int main(void)
{
    int n;

    printf("Enter the x: ");
    scanf("%d", &n);

    printf("The result is: %d", result(n));

    return 0;
}
