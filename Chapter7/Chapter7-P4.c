#include <stdio.h>

int main(void)
{
    char ch;

    printf("Enter number: ");

    ch = getchar();
    while (ch != '\n')
        {
        switch (ch) {
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
                putchar(ch);
                break;
        }
        ch = getchar();    /*注意的地方，否则无法跳出循环*/
    }
    return 0;
}


/*case接的是”常量表达式“，必须是整数，字符也可以*/
