#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROW 10
#define COL 10

int main(void)
{
    int m, n, move, i, t = 0;
    char a[ROW + 2][COL + 2];
    bool b[ROW + 2][COL + 2] = {false};
    //生成12*12的数组是为了将“判断是否到边界”也转换为“判断四周是否为可行”
    //因为“判断四周是否可行”是必须判断的，这样的话可以减少了一个判断条件
    //只是在生成字符为'.'和输出的时候注意一下

    //生成字符为'.'的数组
    for (m = 1; m < ROW + 1; m++) {
        for (n = 1; n < COL + 1; n++)
            a[m][n] = '.';
    }

    //使得（外加的）边界全为true
    for (m = 0; m < ROW + 2; m++) {
        for (n = 0; n < COL + 2; n++) {
            b[0][n] = true;
            b[ROW + 1][n] = true;
            b[m][0] = true;
            b[m][COL + 1] = true;
        }
    }

    //确定一个开始的位置，即A的位置
    srand((unsigned) time(NULL));
    m = rand() % ROW + 1;
    n = rand() % COL + 1;
    a[m][n] = 'A';
    b[m][n] = true;

    //移动
    for (i = 1; i < 26; i++) {
        //判断a[m][n]的四周有多少个可以走的位
        if (b[m - 1][n] == false) {    //得益于使用12*12的数组，这里不需要另外判断m-1>0
            t++;    //up can
        }
        if (b[m][n + 1] == false) {
            t++;    //right can
        }
        if (b[m + 1][n] == false) {
            t++;    //down can
        }
        if (b[m][n - 1] == false) {
            t++;    //left can
        }

        //如果四周都没有位置可走，则退出for循环
        if (t == 0)
            break;

        //移动（能执行到这里的都是至少有一个方向可以移动的，否则就执行了上面退出循环的语句）
        for (; t != 0; ) {
            move = rand() % 4;
            switch (move) {
                case 0: if (b[m - 1][n] == false) {    //与上面同理，无需另外判断m-1>0
                            m--;
                            a[m][n] = 'A' + i;
                            b[m][n] = true;
                            t = 0;    //确认是否移动过
                        }//up
                        break;
                case 1: if (b[m][n + 1] == false) {
                            n++;
                            a[m][n] = 'A' + i;
                            b[m][n] = true;
                            t = 0;
                        }//right
                        break;
                case 2: if (b[m + 1][n] == false) {
                            m++;
                            a[m][n] = 'A' + i;
                            b[m][n] = true;
                            t = 0;
                        }//down
                        break;
                case 3: if (b[m][n - 1] == false) {
                            n--;
                            a[m][n] = 'A' + i;
                            b[m][n] = true;
                            t = 0;
                        }//left
                        break;
            }
        }
    }


    //输出结果
    for (m = 1; m < ROW + 1; m++) {
        for (n = 1; n < COL + 1; n++)
            printf("%c ", a[m][n]);
        printf("\n");
    }

    return 0;
}


//说明一下12*12长度的使用
/*
   0  1  2  3  4  5  6  7  8  9  10 11
0  *  *  *  *  *  *  *  *  *  *  *  *
1  *  .  .  .  .  .  .  .  .  .  .  *
2  *  .  .  .  .  .  .  .  .  .  .  *
3  *  .  .  .  .  .  .  .  .  .  .  *
4  *  .  .  .  .  .  .  .  .  .  .  *
5  *  .  .  .  .  .  .  .  .  .  .  *
6  *  .  .  .  .  .  .  .  .  .  .  *
7  *  .  .  .  .  .  .  .  .  .  .  *
8  *  .  .  .  .  .  .  .  .  .  .  *
9  *  .  .  .  .  .  .  .  .  .  .  *
10 *  .  .  .  .  .  .  .  .  .  .  *
11 *  *  *  *  *  *  *  *  *  *  *  *
*/
//这里就用 * 表示true，用 . 表示false
//为了a[m][n]里面的m,n能和b[m][n]的一样，所以数组a也使用了12*12的长度
