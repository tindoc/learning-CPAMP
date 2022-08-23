#include <stdio.h>

int main (void)
{
    int a, b, m, n, remainder;

    printf("Enter a fraction: ");
    scanf("%d/%d",&a, &b);

    //定义变量a,b为了保留原来输入数的数值
    m = a, n = b;

    //引用Euclid算法以及第二题中管方的做法
    while(n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    printf("In lowest terms: %d/%d\n", a/m, b/m);

    return 0;
}
