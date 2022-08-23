#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROW 10
#define COL 10

void generate_random_walk(char walk[ROW + 2][COL + 2])
{
    int m, n;

    for (m = 1; m < ROW + 1; m++) {
        for (n = 1; n < COL + 1; n++)
            walk[m][n] = '.';
    }
}

void print_array(char walk[ROW + 2][COL + 2])
{
    int m, n;

    for (m = 1; m < ROW + 1; m++) {
        for (n = 1; n < COL + 1; n++)
            printf("%c ", walk[m][n]);
        printf("\n");
    }
}

int main(void)
{
    int m, n, move, i, t = 0;
    char walk[ROW + 2][COL + 2];
    bool b[ROW + 2][COL + 2] = {false};

    generate_random_walk(walk);

    for (m = 0; m < ROW + 2; m++) {
        for (n = 0; n < COL + 2; n++) {
            b[0][n] = true;
            b[ROW + 1][n] = true;
            b[m][0] = true;
            b[m][COL + 1] = true;
        }
    }

    srand((unsigned) time(NULL));
    m = rand() % ROW + 1;
    n = rand() % COL + 1;
    walk[m][n] = 'A';
    b[m][n] = true;

    for (i = 1; i < 26; i++) {
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

        if (t == 0)
            break;

        for (; t != 0; ) {
            move = rand() % 4;
            switch (move) {
                case 0: if (b[m - 1][n] == false) {    //与上面同理，无需另外判断m-1>0
                            m--;
                            walk[m][n] = 'A' + i;
                            b[m][n] = true;
                            t = 0;    //确认是否移动过
                        }//up
                        break;
                case 1: if (b[m][n + 1] == false) {
                            n++;
                            walk[m][n] = 'A' + i;
                            b[m][n] = true;
                            t = 0;
                        }//right
                        break;
                case 2: if (b[m + 1][n] == false) {
                            m++;
                            walk[m][n] = 'A' + i;
                            b[m][n] = true;
                            t = 0;
                        }//down
                        break;
                case 3: if (b[m][n - 1] == false) {
                            n--;
                            walk[m][n] = 'A' + i;
                            b[m][n] = true;
                            t = 0;
                        }//left
                        break;
            }
        }
    }

    print_array(walk);

    return 0;
}
//详细的解析请看第第8章编程题16
