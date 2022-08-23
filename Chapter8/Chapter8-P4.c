#include <stdio.h>

#define N 10

int main(void)
{
  int a[N], i, n;

  printf("Enter %d numbers: ", N);
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);

  printf("In reverse order:");
  for (i = N - 1; i >= 0; i--)
    printf(" %d", a[i]);
  printf("\n");

  n = (int)(sizeof(a) / sizeof(a[0]));
  printf("The long is %d", n);

  return 0;
}


//reverse.c
//#include <stdio.h>
//
//#define N 10
//
//int main(void)
//{
//  int a[N], i;
//
//  printf("Enter %d numbers: ", N);
//  for (i = 0; i < N; i++)
//    scanf("%d", &a[i]);
//
//  printf("In reverse order:");
//  for (i = N - 1; i >= 0; i--)
//    printf(" %d", a[i]);
//  printf("\n");
//
//  return 0;
//}


//不是很清楚题目的意思是不是这个
//下面是一种比较符合题目结果但是又不太符合题目要求的做法
//#include <stdio.h>
//
//#define N 1000    //说明这里最多只能储存1000个数
//
//int main(void)
//{
//    int a[N], i = 0, m = 0, n;
//    char ch;
//
//    printf("Enter the numbers(with the space in the first): ");
//    //在输入之前加上一个空格是为了给getchar读取，否则第一个数会少一个位
//
//    while ((ch = getchar()) != '\n') {
//        scanf("%d", &n);    //这里无需加空格，正常输入下每次getchar读取空格，scanf读取数字
//        a[i] = n;
//        i++;
//        m++;
//        }
//
//    printf("In reverse order:");
//    for (i = m - 1; i >= 0; i--)
//        printf(" %d", a[i]);
//    printf("\n");
//
//    return 0;
//}
