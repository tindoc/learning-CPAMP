#include <stdio.h>

int main(void)
{
    int num, reverse_num;    //用int的话在2147483647之前显示没有问题，当超过之后会显示没有意义的数
                             //用2147483648试会显示-8-4-6-3-8-4-7-4-1-2,不知道是什么原因

    printf("Enter a any-digit number: ");
    scanf("%d", &num);

    printf("The reverse is: ");

    do {
        reverse_num = num % 10;
        num = num / 10;
        printf("%d", reverse_num);
    }while(num != 0);

    return 0;
}
