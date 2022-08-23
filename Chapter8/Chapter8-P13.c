#include <stdio.h>

int main(void)
{
    int i = 0, n = 0;
    char last_name[20], first_name, ch;

    printf("Enter a first and last name: ");
    scanf(" %c", &first_name);

    while ((ch = getchar()) != ' ')
        ;

    while ((ch = getchar()) != '\n') {
        if (ch == ' ')
            break;
        else {
            last_name[i] = ch;
            n++;
            i++;
        }
    }

    printf("You entered the name: ");

    for (i = 0; i < n; i++)
        putchar(last_name[i]);

    printf(" %c\n", first_name);

    return 0;
}
