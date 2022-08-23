#include <stdio.h>

#define N 1000

void selection_sort(int a[], int n)
{
    int i, max, tem;

    max = a[0];
    for (i = 0; i < n; i++) {
        if (max <= a[i]) {    //用<=就可以不提前声明tem=0，否则要提前声明tem=0，避免第一个数为最大的情况
            max = a[i];
            tem = i;
        }
    }

    n--;    //有n个元素但是数组的最后一个数的下标是n-1，而且恰好再次调用的时候需要n-1
    a[tem] = a[n];
    a[n] = max;

    if (n != 1)
        selection_sort(a, n);    //注意：a不能是a[n]
}

int main(void)
{
    int i, n, a[N];
    char ch;

    printf("Enter a series of integers: ");
    for (i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        if ((ch = getchar()) == '\n')
            break;
    }
    //这种做法恰好解决了我在第八章第四题的问题，这种更好
    //不过要注意，这时数组的元素个数是i+1，是break导致的

    n = i + 1;    //n为数组元素个数

    selection_sort(a, n);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
