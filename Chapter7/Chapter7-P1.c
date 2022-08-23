//#include <stdio.h>
//
//int main(void)
//{
//    int i, n;
//
//    printf("This program prints a table of squares.\n");
//    printf("Enter number of entries in table: ");
//    scanf("%d",&n);
//
//    for (i = 1; i <= n; i++)
//        printf("%10d%10d\n", i, i * i);
//
//    return 0;
//
//}


//#include <stdio.h>
//
//int main(void)
//{
//    int n;
//    short i;
//
//    printf("This program prints a table of squares.\n");
//    printf("Enter number of entries in table: ");
//    scanf("%d",&n);
//
//    for (i = 1; i <= n; i++)
//        printf("%10hd%10hd\n", i, i * i);
//
//    return 0;
//
//}


#include <stdio.h>

int main(void)
{
    long n, i;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%ld",&n);

    for (i = 1; i <= n; i++)
        printf("%20ld%20ld\n", i, i * i);

    return 0;

}


/*
我的电脑是64位的
所以当 i 为int时，导致失败的 n 的最小值是46341
    当 i 为short时，导致失败的 n 的最小值是182
    当 i 为long时，导致失败的 n 的最小值是     (不知道为什么没有结果)
*/
