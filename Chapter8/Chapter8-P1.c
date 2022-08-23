#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool digit_seen[10] = {false};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit]){
            printf("Repeated digit(s): %d\n", digit);
            //结果与书本的不太一样，我没有较为简单的其他的解决办法
            //缺点是：1.每次都会显示Repeated这段；2.重复2次以上的会再次打印
        }
        digit_seen[digit] = true;
        n /= 10;
    }

    return 0;
}

//repdigit.c
//#include <stdio.h>
//#include <stdbool.h>
//
//int main(void)
//{
//    bool digit_seen[10] = {false};
//    int digit;
//    long n;
//
//    printf("Enter a number: ");
//    scanf("%ld", &n);
//
//    while (n > 0) {
//        digit = n % 10;
//        if (digit_seen[digit]){
//            break;
//            //使用break使得只要出现一个重复的数字即可，无需顾虑后面是否出现重复
//        }
//        digit_seen[digit] = true;
//        n /= 10;
//    }
//
//    if (n > 0)
//        printf("Repeated digit\n");
//    else
//        printf("No repeated digit\n");
//
//    return 0;
//}
