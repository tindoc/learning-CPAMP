#include <stdio.h>

#define LARGEST 50

void reverse_name(char *name);

int main(void)
{
    char name[LARGEST + 1];    //+1是良好的编程习惯，为最后的空字符预留位置

    printf("Enter a first and last name: ");
    gets(name);

    reverse_name(name);

    return 0;
}

void reverse_name(char *name)
{
    int i = 0, n = 0;
    char first_word;

    while (name[i] == ' ')    //清除名之前的0
        i++;
    first_word = name[i];

    while (name[i] != ' ')    //清除名
        i++;
    while (name[i] == ' ')    //清除名和姓之间的0
        i++;
    for ( ; name[i] != ' '; i++)
        printf("%c", name[i]);

    printf(", %c.", first_word);
}
