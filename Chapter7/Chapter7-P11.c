#include <stdio.h>

int main(void)
{
    char ch, first_name;

    printf("Enter a first and last name: ");
    scanf(" %c", &first_name);

    while ((ch = getchar()) != ' ')
        ;

    while ((ch = getchar()) != '\n') {
        if (ch == ' ')
            ;
        else
            putchar(ch);
    }

    printf(", %c", first_name);

    return 0;
}


/*这里需要注意ch = getchar()然后再加while和直接while(ch = getchar())的区别*/

//ch = getchar();
//while (ch != '\n') {
//    putchar(ch);
//    ch = getchar();
//}
//上面这个必须在循环内加上ch = getchar()才不会出现死循环（ch 直接为 '\n' 不会出现死循环）


//while ((ch = getchar()) != '\n')
//    putchar(ch);
//这种用法较为简单，也不容易出错
