#include <stdio.h>
#include <ctype.h>

#define N 100

int main(void)
{
    char msg[N] = {'0'}, *p, *p_r;
    int i;

    printf("Enter a message: ");
    for (p = &msg[0]; p < msg + N; p++) {
        *p = toupper(getchar());
        while (*p == ' ' || *p == ',' || *p == '\'' ||
               *p == '!' || *p == '.' || *p == '?')
            *p = toupper(getchar());

        if (*p == '\n')
            break;
    }

    p_r = &msg[0];
    for (p--; p >= &msg[0]; p--, p_r++) {
        if (*p_r != *p) {
            printf("Not a palindrome.\n");
            goto end;
        }
    }

    printf("palindrome.\n");

    end:

    return 0;
}
