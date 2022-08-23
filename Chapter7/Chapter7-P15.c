#include <stdio.h>

int main(void)
{
    typedef float TYE;
    int n, m = 1, x = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    TYE sum = 1;
    while (m <= n) {
        sum *= m;
        printf("m:%.5d sum:%f\n", m, sum);
        m++;
    }

    printf("Factorial of %d: %f\n", n, sum);

    return 0;
}


//答案如下,32位（这个答案不是很确定）
//short--7
//int--12
//long--12
//long long--不支持
//float--34
//double--170
//long double--

//我是参照这个的结果，这里有1~100的阶乘结果
//http://zhidao.baidu.com/link?url=Td6H6cFubk3rKmG0kTJpV45mAFQJnzScJfPMg94EiUz9VPb1K3IY3-sRuwonCauwKysFbsa8FEQEizHKM3rZNq
