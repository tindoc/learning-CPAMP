#include <stdio.h>
#include <ctype.h>

#define N 100

int main(void)
{
    char msg[N];
    int i;

    printf("Enter a message: ");
    for (i = 0; i < N; i++) {
        msg[i] = toupper(getchar());
        while (msg[i] == ' ' || msg[i] == ',' || msg[i] == '\'' ||
               msg[i] == '!' || msg[i] == '.' || msg[i] == '?')
            msg[i] = toupper(getchar());

        if (msg[i] == '\n')
            break;
    }

    int n = 0;
    for (i--; i >= 0; i--, n++) {
        if (msg[i] != msg[n]) {
            printf("Not a palindrome.\n");
            break;
        }
    }

    if (i == -1)
        printf("Palindrome.\n");

    return 0;
}
