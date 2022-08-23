#include <stdio.h>

int main(void)
{
    char ch[80], get_ch;
    int n, i, m = 0;

    printf("Enter message to be encrypted: ");
    for (i = 0; (get_ch = getchar()) != '\n'; i++) {
        ch[i] = get_ch;
        m++;
    }

    printf("Enter shift amount (1-25):");
    scanf("%d", &n);

    printf("Encrypted message: ");

    ch[0] = (((ch[0] - 'A') + n) % 26 + 'A') ;
    putchar(ch[0]);

    for (i = 1; i < m; i++) {
        if (ch[i] >= 97 && ch[i] <= 122) {    //'a'的值为97，'z'的值为122
            ch[i] = (((ch[i] - 'a') + n) % 26 + 'a');
            putchar(ch[i]);
        }
        else
            putchar(ch[i]);
    }

    return 0;
}
