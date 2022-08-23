#include <stdio.h>

int main (void)
{
    //定义变量，l为转换量，用来确定m，n的大小
    int a, b, m, n, mod, GCD;

    //取值
    printf ("Enter two integers: ");
    scanf ("%d %d",&a, &b);

    //判断m,n大小
    if (a > b)
        m = a, n = b;
    else
        m = b, n = a;

    //循环
    if (a != 0 && b != 0){
        while (mod != 0) {
            mod = m % n;
            m = n;
            n = mod;
        }
        printf ("Greatest common divisor: %d",m);
    }
    else if (m == 0)
        printf ("Greatest common divisor: %d",n);
    else if (n == 0)
        printf ("Greatest common divisor: %d",m);

    return 0;
}

/***********
  官方答案
 ***********/

//#include <stdio.h>
//
//int main(void)
//{
//  int m, n, remainder;
//
//  printf("Enter two integers: ");
//  scanf("%d%d", &m, &n);
//
//  while (n != 0) {
//    remainder = m % n;
//    m = n;
//    n = remainder;
//  }
//
//  //由上得
//  //1. n != 0的存在不是为了排除m或者n为0的问题，而是为了避免除数为0
//  //2. 取余函数符合“0除以任何不为0的数都得0”的数学知识
//  //3. 这里取余函数为什么不用考虑前面数小于后面数的原因是下面的语句能够自动转换顺序，运行一下下面的“代码3”就可以知道了
//  //虽然是考虑得周全了，但是在简洁性上还是败给了官方答案（原因是没有深入理解以及没有联系），哈哈，我服了
//
//  printf("Greatest common divisor: %d\n", m);
//
//  return 0;
//}


/**********
 * 代码3  *
 **********/
//#include <stdio.h>
//
//int main(void)
//{
//  int m, n, remainder;
//
//  printf("Enter two integers: ");
//  scanf("%d%d", &m, &n);
//
//  while (n != 0) {
//    remainder = m % n;
//    m = n;
//    n = remainder;
//    printf("remainder = %d;m = %d;n = %d\n", remainder, m, n);    //可以看到每一步的操作
//  }
//
//  printf("Greatest common divisor: %d\n", m);
//
//  return 0;
//}
