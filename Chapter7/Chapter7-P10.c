#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int n = 0;

    printf("Enter a sentence: ");

    ch = getchar();
    while (ch != '\n') {
        switch (toupper(ch)) {
            case 'A':case 'E':case 'I':case 'O':case 'U':
                n ++;
                break;
        }
        ch = getchar();
    }
    printf("Your sentence contains %d vowels.\n", n);

    return 0;
}
