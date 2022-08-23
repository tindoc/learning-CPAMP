#include <stdio.h>
#include <ctype.h>

#define N 1000    //最多能够储存1000个字符

int main(void)
{
    int  n = 0, i;
    char a[N], ch;

    printf("Enter message: ");
    while ((ch = getchar()) != '\n') {
        a[n] = ch;
        n++;
        }

    printf("In BIFF-speak: ");
    for (i = 0; i < n; i++) {
        switch (toupper(a[i])) {
            case 'A': printf("4"); break;
            case 'B': printf("8"); break;
            case 'E': printf("3"); break;
            case 'I': printf("1"); break;
            case 'O': printf("0"); break;
            case 'S': printf("5"); break;
            default: putchar((toupper(a[i]))); break;
        }
    }
    printf("!!!!!!!!!!\n");

    return 0;

}
