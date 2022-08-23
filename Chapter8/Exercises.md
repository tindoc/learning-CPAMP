Chapter 8

Exercises

1.
这在阅读程序的时候不容易检查正确性。（阅读者需要看有关a的声明来确定类型t）
The problem with sizeof(a) / sizeof(t) is that it can't easily be checked for correctness by someone reading the program. (The reader would have to locate the declaration of a and make sure that its elements have type t.)

2.
使用数字 d (以字符形式)作为数组的下标,我们会写 a[d - '0']。这假设数字在底层字符集连续编码,这是真正的ASCII和其他流行的字符集。
To use a digit d (in character form) as a subscript into the array a, we would write a[d-'0']. This assumes that digits have consecutive codes in the underlying character set, which is true of ASCII and other popular character sets.

3.
#include <stdbool.h>
#include <stdio.h>

#define n 7

int main(void)
{
    bool weekend[n] = {true, [6] = true};    //注意这里是[6]，不是[7]
    int m;

    for (m = 0;m < n;m++)
    printf("%d", weekend[m]);

return 0;
}

4.
与第三题一样

5.
#include <stdio.h>
#define N 40

int main(void)
{
    int fit_number[N] = {0, 1};
    int n;

    printf("0,1");
    for (n = 2;n < N;n++) {
        fit_number[n] = fit_number[n - 1] + fit_number[n - 2];
        printf(",%d", fit_number[n]);
    }
    return 0;
}

6.
( 1){1, 1, 1, 1, 1, 1, 0}
( 2){0, 1, 1, 0, 0, 0, 0}
( 3){1, 1, 0, 1, 1, 0, 1}
( 4){1, 1, 1, 1, 0, 0, 1}
( 5){0, 1, 1, 0, 0, 1, 1}
( 6){1, 0, 1, 1, 0, 1, 1}
( 7){1, 0, 1, 1, 1, 1, 1}
( 8){1, 1, 1, 0, 0, 0, 0}
( 9){1, 1, 1, 1, 1, 1, 1}
(10){1, 1, 1, ,1 0, 1, 1}

7.
( 1){1, 1, 1, 1, 1, 1}
( 2){0, 1, 1}
( 3){1, 1, 0, 1, 1, 0, 1}
( 4){1, 1, 1, 1, 0, 0, 1}
( 5){0, 1, 1, 0, 0, 1, 1}
( 6){1, 0, 1, 1, 0, 1, 1}
( 7){1, 0, 1, 1, 1, 1, 1}
( 8){1, 1, 1}
( 9){1, 1, 1, 1, 1, 1, 1}
(10){1, 1, 1, 1, 0, 1, 1}

8.
看第9题

9.
#include <stdio.h>

#define Day 30
#define Hour 24

int main(void)
{
    float temperature_readings[Day][Hour], sum_Day = 0.0, sum_Hour = 0.0;
    int x, y;

    //取数
    printf("Please enter the temperature:");
    for (x = 0;x < Day;x++) {
        for (y = 0; y < Hour;y++) {
            scanf(" %f", &temperature_readings[x][y]);
            sum_Day += temperature_readings[x][y];
        }
    }

    //计算并显示一月中每一天的平均值
    printf("The average temperature in Month is %f\n", sum_Day / (float)Day);

    //计算并显示一天中每个小时的平均值
    for (x = 0;x < Day;x++) {
        printf("The average temperature in Day%d is:", x + 1);
        for (y = 0; y < Hour;y++) {
            sum_Hour += temperature_readings[x][y];
        }
        printf("%f\n",sum_Hour / (float)Hour);
        sum_Hour = 0.0;    //计算完一次之后要清零，否则第一天的结果会计算到第二天的平均值中
    }
    return 0;
}

10.
const char chess_board[8][8] = {{'r' 'n' 'b' 'q' 'k' 'b' 'n' 'r'}
                                {'p' 'p' 'p' 'p' 'p' 'p' 'p' 'p'}
                                {' ' '.' ' ' '.' ' ' '.' ' ' '.'}
                                {'.' ' ' '.' ' ' '.' ' ' '.' ' '}
                                {' ' '.' ' ' '.' ' ' '.' ' ' '.'}
                                {'.' ' ' '.' ' ' '.' ' ' '.' ' '}
                                {'p' 'p' 'p' 'p' 'p' 'p' 'p' 'p'}
                                {'r' 'n' 'b' 'q' 'k' 'b' 'n' 'r'}
                                                                 }
11.
#include <stdio.h>

int main(void)
{
    const char checker_board[8][8];
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0)
                putchar('B');
            else
                putchar('R');
        }
        printf("\n");
    }
    return 0;
}