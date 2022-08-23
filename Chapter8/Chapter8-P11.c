#include <stdio.h>

int main(void)
{
    char a[15];
    int i;

    printf("Enter number: ");
    for (i = 0; i < 15; i++) {
        a[i] = getchar();
    }

    for (i = 0; i < 15; i++) {
        switch (a[i]) {
            case 'A': case 'B': case 'C':
                putchar('2');
                break;
            case 'D': case 'E': case 'F':
                putchar('3');
                break;
            case 'G': case 'H': case 'I':
                putchar('4');
                break;
            case 'J': case 'k': case 'L':
                putchar('5');
                break;
            case 'M': case 'N': case 'O':
                putchar('6');
                break;
            case 'P': case 'Q': case 'R': case 'S':
                putchar('7');
                break;
            case 'T': case 'U': case 'V':
                putchar('8');
                break;
            case 'W': case 'x': case 'Y': case 'Z':
                putchar('9');
                break;
            default:
                putchar(a[i]);
                break;
        }
    }

    return 0;
}
