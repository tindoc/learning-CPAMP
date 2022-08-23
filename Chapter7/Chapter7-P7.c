//#include <stdio.h>
//
//int main(void)
//{
//    int num1, denom1, num2, denom2, result_num, result_denom;
//    char ch;
//
//    printf("Enter two fractions separated: ");
//    scanf("%d/%d", &num1, &denom1);
//
//    ch = getchar();
//
//    scanf("%d/%d", &num2, &denom2);
//
//    switch (ch) {
//        case '+':
//            result_num = num1 * denom2 + num2 * denom1;
//            result_denom = denom1 * denom2;
//            printf("The result is: %d/%d", result_num, result_denom);
//            break;
//        case '-':
//            result_num = num1 * denom2 - num2 * denom1;
//            result_denom = denom1 * denom2;
//            printf("The result is: %d/%d", result_num, result_denom);
//            break;
//        case '*':
//            result_num = num1 * num2;
//            result_denom = denom1 * denom2;
//            printf("The result is %d/%d", result_num, result_denom);
//            break;
//        case '/':
//            result_num = num1 * denom2;
//            result_denom = denom1 * num2;
//            printf("The result is %d/%d", result_num, result_denom);
//            break;
//    }
//    return 0;
//}


/*2.0版本*/
//简化每个case后面的语句
//#include <stdio.h>
//
//int main(void)
//{
//    int num1, denom1, num2, denom2, result_num, result_denom;
//    char ch;
//
//    printf("Enter two fractions separated: ");
//    scanf("%d/%d", &num1, &denom1);
//    ch = getchar();
//    scanf("%d/%d", &num2, &denom2);
//
//    switch (ch) {
//        case '+':
//            result_num = num1 * denom2 + num2 * denom1;
//            result_denom = denom1 * denom2;
//            break;
//        case '-':
//            result_num = num1 * denom2 - num2 * denom1;
//            result_denom = denom1 * denom2;
//            break;
//        case '*':
//            result_num = num1 * num2;
//            result_denom = denom1 * denom2;
//            break;
//        case '/':
//            result_num = num1 * denom2;
//            result_denom = denom1 * num2;
//            break;
//    }
//    printf("The result is %d/%d", result_num, result_denom);
//    return 0;
//}


/*3.0版本*/
//最后结果取最简
#include <stdio.h>

int main(void)
{
    int num1, denom1, num2, denom2, result_num, result_denom, m, n, remainder;  //GCD为最大公约数
    char ch;

    printf("Enter two fractions separated: ");
    scanf("%d/%d", &num1, &denom1);
    ch = getchar();
    scanf("%d/%d", &num2, &denom2);

    switch (ch) {
        case '+':
            result_num = num1 * denom2 + num2 * denom1;
            result_denom = denom1 * denom2;
            break;
        case '-':
            result_num = num1 * denom2 - num2 * denom1;
            result_denom = denom1 * denom2;
            break;
        case '*':
            result_num = num1 * num2;
            result_denom = denom1 * denom2;
            break;
        case '/':
            result_num = num1 * denom2;
            result_denom = denom1 * num2;
            break;
    }
    m = result_num; n = result_denom;

    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }
    //详情见第六章编程题第3题

    printf("The result is %d/%d", result_num/m, result_denom/m);

    return 0;
}
