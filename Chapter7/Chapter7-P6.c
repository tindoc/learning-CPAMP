#include <stdio.h>

int main(void)
{
    printf("Size of int: %lu\n", (unsigned long) sizeof(int));

    printf("Size of short: %lu\n", (unsigned long) sizeof(short));

    printf("Size of long: %lu\n", (unsigned long) sizeof(long));

    printf("Size of float: %lu\n", (unsigned long) sizeof(float));

    printf("Size of double: %lu\n", (unsigned long) sizeof(double));

    printf("Size of long double: %lu\n", (unsigned long) sizeof(long double));

    return 0;
}


/*官方答案*/
//#include <stdio.h>
//
//int main(void)
//{
//  printf("Size of int: %d\n", (int) sizeof(int));
//  printf("Size of short: %d\n", (int) sizeof(short));
//  printf("Size of long: %d\n", (int) sizeof(long));
//  printf("Size of float: %d\n", (int) sizeof(float));
//  printf("Size of double: %d\n", (int) sizeof(double));
//  printf("Size of long double: %d\n", (int) sizeof(long double));
//
//  return 0;
//}
/*
sizeof表达式的类型在转换中可能会不一样，
所以在C89中要在打印sizeof表达式之前把它转换成已知的类型。例如，%lu\n, (int)sizeof(int)
基本类型的大小只是一些很小的数字，所以转化为int类型没有问题。
（然而，最好把sizeof转换为unsigned long类型以及打印时用%lu）
在C99，在我们使用%zu说明符之后可以不用在打印之前使用转换。例如，%zu\n, sizeof(int)
*/
