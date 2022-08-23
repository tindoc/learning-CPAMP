#include <stdio.h>

int main (void)
{
    //定义变量
    int n, i = 1;
    //根据书中P15中关于未初始化变量的解释
    //在这里中给i一个初始值1，便于下面循环语句的执行

    //取值
    printf("Enter the number n: ");
    scanf("%d", &n);

    while(i * i <= n){
        if (i * i % 2 == 0)
            printf("%d\n", i * i);
        i += 1;
    }

    return 0;

}
