#include <stdio.h>

int main(void)
{
    float m = 0.0, n = 0.0;
    char ch;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n') {
        if ((ch) == ' ')
            n ++;
        else
        m ++;
    }

    printf("Average word length: %.1f", m / (n + 1.0f));

    return 0;
}
