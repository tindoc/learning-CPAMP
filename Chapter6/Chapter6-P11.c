#include <stdio.h>

int main(void)
{
    //定义变量，在需要运算的时候要初始化值,demon是分母
    int n, demon = 1, i = 1;
    float sum = 1.00f;

    printf("Enter the n: ");
    scanf("%d", &n);

    while(i <= n){
        demon *= i;
        sum = sum + 1.00f / demon;    //这里用1.00f是为了避免整数相除截短的影响,P15
        i++ ;
    }
    printf("e is :%f", sum);

    return 0;
}

/*
这道题目涉及了自然对数e的一些问题，一开始有点萌B
（其实一开始很纠结那个！的，一开始我理解为（1/2）！，我好像没有学过分数的阶乘啊
  后来原来是1/（2！），哈哈~~~囧）
后来找了点有关e的资料看看，觉得数学好神奇
http://www.guokr.com/article/50264/
https://www.zhihu.com/question/27054780
*/
