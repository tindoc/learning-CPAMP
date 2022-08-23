#include <stdio.h>

#define N 1000

int main(void)
{
    int start_of_work;
    char a[N], ch, stop_point, *p, *p_everywork;

    printf("Enter a sentence: ");
    ch = getchar();
    for (p = a; ch != '\n'; p++) {
        *p = ch;
        ch = getchar();
    }

    printf("Reversal of sentence: ");
    stop_point = *--p;
    for (p--; p >= a; p--) {
        if (*p == ' ') {
            for (p_everywork = p + 1; *p_everywork != ' ' && *p_everywork != '.' &&
                                      *p_everywork != '!' && *p_everywork != '?'; p_everywork++)
                putchar(*p_everywork);
            printf(" ");
        }
    }

    for (p = a; *p != ' '; p++) {
        putchar(*p);
    }

    putchar(stop_point);

    return 0;

}

