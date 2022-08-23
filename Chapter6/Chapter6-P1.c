#include <stdio.h>
int main (void)
{
    //定义变量
    float num, num_max;
    num = 1;

    //读取第一个数，现为最大
    printf ("Enter a number: ");
    scanf ("%f", & num_max);

    //循环取数
    if (num_max > 0){
        while (num > 0){
            printf ("Enter a number:");
            scanf ("%f", & num);
            if (num > num_max){
                num_max = num;
            }
        }
        printf ("The largest number entered was %.2f\n", num_max);
    }
    else
        printf ("Error\n");

    return 0;

}

