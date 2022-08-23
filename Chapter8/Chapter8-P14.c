#include <stdio.h>

int main(void)
{
    int i = 0, n = 0, start_of_work;
    char a[1000], stop_point, ch;

    printf("Enter a sentence: ");
    ch = getchar();
    while ((ch != '.') && (ch != '!') && (ch != '?')) {
        a[i] = ch;
        i++;
        n++;
        ch = getchar();
    }
    stop_point = ch;    //这里不能用stop_point = getchar()，这样会取不到最后的符号

    //以空格为间隔，输出倒序的单词
    printf("Reversal of sentence: ");
    for (i = n - 1; i >= 0; i--) {
        if (a[i] == ' ') {
            start_of_work = i + 1;
            for ( ; (start_of_work < n) && (a[start_of_work] != ' ') ; start_of_work++)
                putchar(a[start_of_work]);
            printf(" ");
        }
    }

    //输出第一个单词
    //因为第一个单词之前没有空格，所以在上面的循环中不能输出第一个单词
    for (i = 0; a[i] != ' '; i++) {
        putchar(a[i]);
    }

    putchar(stop_point);

    return 0;

}
