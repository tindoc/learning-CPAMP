#include <stdio.h>
#include <math.h>

int main(void)
{
    double x, y = 1.0;

    printf("Enter a positive number: ");
    scanf("%lf", &x);    //读取double类型时要在e,f,g前面放置l

    while (fabs((1.0 / 2.0 * (y + x / y)) - y) >= 0.00001)
        y = (1.0 / 2.0 * (y + x / y));

    printf("Square root: %f", y);    //这里不能使用l

    return 0;
}


//关于这道题目更加详细的解析请看下面
//http://www.nowamagic.net/librarys/veda/detail/2268
