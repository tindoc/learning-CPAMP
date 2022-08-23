#include <stdio.h>

int main(void)
{
    int magic_square[99][99] = {0}, size, i, m, n;

    printf("This program created a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &size);

    m = 0;
    n = (size - 1) / 2;
    magic_square[m][n] = 1;

    //根据题目，这里有三个要求，每个要求又有两种选择
    //所以共有 2*2*2=8 种可能
    //下面程序右边的 up:N right:N repeat:N 的意思是
    //up:N     --->  表示下一行在-1行的情况，所以是"不能"简单向上
    //right:N  --->  表示下一列在size列的情况，所以是"不能"简单向右
    //repeat:N --->  表示移动后的位置"没有"字符，只要重复了，移动的位置就会变成[m+1][n]
    for (i = 2; i <= size * size; i++) {
        if (m - 1 == -1) {
            if (n + 1 == size) {
                if (magic_square[size - 1][0] == 0) {      //up:N right:N repeat:N
                    m = size - 1;
                    n = 0;
                    magic_square[m][n] = i;
                }
                else {                                     //up:N right:N repeat:Y
                    m = m + 1;
                    n = n;
                    magic_square[m][n] = i;
                }
            }
            else {
                if (magic_square[size - 1][n + 1] == 0) {  //up:N right:Y repeat:N
                    m = size - 1;
                    n = n + 1;
                    magic_square[m][n] = i;
                }
                else {                                     //up:N right:Y repeat:Y
                    m = m + 1;
                    n = n;
                    magic_square[m][n] = i;
                }
            }
        }
        else {
            if (n + 1 == size) {
                if (magic_square[m - 1][0] == 0) {        //up:Y right:N repeat:N
                    m = m - 1;
                    n = 0;
                    magic_square[m][n] = i;
                }
                else {                                    //up:Y right:N repeat:Y
                    m = m + 1;
                    n = n;
                    magic_square[m][n] = i;
                }
            }
            else {
                if (magic_square[m - 1][n + 1] == 0) {    //up:Y right:Y repeat:N
                    m = m - 1;
                    n = n + 1;
                    magic_square[m][n] = i;
                }
                else {                                    //up:Y right:Y repeat:Y
                    m = m + 1;
                    n = n;
                    magic_square[m][n] = i;
                }
            }
        }
    }

    for (m = 0; m < size; m++) {
        for (n = 0; n < size; n++)
            printf("%5d", magic_square[m][n]);
        printf("\n");
    }

    return 0;
}
