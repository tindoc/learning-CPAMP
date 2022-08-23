#include <stdio.h>

#define M 5
#define N 5

int main(void)
{
    int a[M][N],m, n, sum_row = 0, sum_col = 0;

    //读取输入数
    for (m = 0; m < M; m++) {
        printf("Enter row %d: ", m + 1);
        for (n = 0; n < N; n++)
            scanf("%d", &a[m][n]);
    }

    //计算并输出每行的和
    printf("Row totals: ");
    for (m = 0; m < M; m++) {
        for (n = 0; n < N; n++) {
            sum_row += a[m][n];
        }
        printf("%d ", sum_row);
        sum_row = 0;
    }

    //计算并输出每列的和
    printf("\nColumn totals: ");
    for (n = 0; n < N; n++) {
        for (m = 0; m < M; m++) {
            sum_col += a[m][n];
        }
        printf("%d ", sum_col);
        sum_col = 0;
    }

    return 0;
}
