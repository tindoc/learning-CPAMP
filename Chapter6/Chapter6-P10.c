//这道题目属于一种类型为“循环中判断语句（表达式）也是语句”的问题
//其中我觉得比较重要的是两次取值的位置
//在循环外面取一次值，在循环最后取一次值
//还有一个比较重要的就是比较大小的思路，关乎定义变量的数量以及循环判断语句的选择
//
//根据我尝试的几种方法，暂时觉得这种对功能实现得最好
//
//最后还有一个简化比较大小的方法


#include <stdio.h>

int main(void)
{
    //定义变量
    int m, d, y, earliest_m, earliest_d, earliest_y;

    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &m, &d, &y);

    //定义earliest的初始值，否则有可能遇到自动初始化的问题,即自动赋值给earliest变量
    earliest_d = d;
    earliest_m = m;
    earliest_y = y;

    if(m != 0 && d != 0 && y != 0){    //使用if语句当第一次输入为0/0/0终止程序
        while(m != 0 && d != 0 && y != 0){    //这算是逻辑运算符的嵌套使用，相当于(m!=0 && d!=0) && y!=0
            if(y= earliest_y){
                if(m = earliest_m){
                    if(d < earliest_d){
                        earliest_d = d;
                        earliest_m = m;
                        earliest_y = y;
                    }
                }else if(m < earliest_m){
                    earliest_d = d;
                    earliest_m = m;
                    earliest_y = y;
                }
            }else if(y < earliest_y){
                earliest_d = d;
                earliest_m = m;
                earliest_y = y;
            }

            printf("Enter a date (mm/dd/yy): ");
            scanf("%d/%d/%d", &m, &d, &y);

        }

        printf("%d/%d/%.2d is the earliest date\n", earliest_m, earliest_d, earliest_y);

    }

    return 0;
}


/***********
 *简化要求*
 **********/
////1.无限输入直到输入到某个数退出循环
//#include <stdio.h>
//
//int main(void)
//{
//    int i;
//
//    do{
//
//        printf("Enter a number(0 will stop): ");
//        scanf("%d", &i);
//
//    }while(i != 0);
//
//    return 0;
//}

////2.比较输入数的大小，输出最大的
//#include <stdio.h>
//
//int main(void)
//{
//    int n_1, n_2, n_max;
//
//    printf("Enter the number: ");
//    scanf("%d", &n_1);
//    printf("Enter the number: ");
//    scanf("%d", &n_2);
//
//    if(n_1 > n_2)
//        n_max = n_1;
//    else
//        n_max = n_2;
//
//    printf("The biggest number is: %d\n", n_max);
//
//    return 0;
//
//}

//3.无限输入数，比较输入数的大小，保留最大或者最小的，当输入数为某个数时停止（本题的一般形式）
//#include <stdio.h>
//
//int main(void)
//{
//    int n_max, n;
//
//    printf("Enter a number(if '0' will stop): ");
//    scanf("%d", &n);
//
//    n_max = n;
//
//    if(n != 0){
//        while(n != 0){
//            if(n > n_max)
//                n_max = n;
//            printf("Enter a number(if 0 will stop): ");
//            scanf("%d", &n);
//        }
//    printf("The biggest number is %d", n_max);
//    }
//
//    return 0;
//}


/*******************
 *  简化比较大小  *
 *******************/
//#include <stdio.h>
//
//int main(void)
//{
//    int m, d, y, date, earliest_date;
//
//    printf("Enter a date(mm/dd/yy): ");
//    scanf("%d/%d/%d", &m, &d, &y);
//
//    date = y * 10000 + m * 100 + d;
//
//    earliest_date = date;
//
//    while (date != 0){
//        if(date < earliest_date)
//            earliest_date = date;
//
//        printf("Enter a date(mm/dd/yy): ");
//        scanf("%d/%d/%d", &m, &d, &y);
//        date = y * 10000 + m * 100 + d;
//    }
//    printf("%d/%d/%.2d is the earliest date\n", (earliest_date - earliest_date / 10000 * 10000)/100, earliest_date % 100, earliest_date / 10000);
//
//    return 0;
//}
