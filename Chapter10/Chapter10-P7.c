#include <stdio.h>

#define MAX_DIGITS 10

/* external variable */
const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},    //0
                             {0, 1, 1, 0, 0, 0, 0},
                             {1, 1, 0, 1, 1, 0, 1},
                             {1, 1, 1, 1, 0, 0, 1},
                             {0, 1, 1, 0, 0, 1, 1},
                             {1, 0, 1, 1, 0, 1, 1},
                             {1, 0, 1, 1, 1, 1, 1},
                             {1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 0, 1, 1}};    //9
char digits[3][MAX_DIGITS * 4];
/*为什么使用[3][4]来显示一个数字，看下图
  0123|4567|891011|.....
0  _
1 |_|
2 |_|
*/

/* function prototype */
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
    int i, digit;
    char ch;

    clear_digits_array();

    printf("Enter a number: ");
    for (i = 0; i < MAX_DIGITS; i++) {
        ch = getchar();
        if (ch >= 48 && ch <= 57 && ch != '\n') {    //字符'0'在ASCII中的值是48
            process_digit(ch - 48, i);               //不过要注意书P95的内容
        }
        else if (ch == '\n')
            break;
        else
            i--;    //因为非数字字符也会使i自增，所以要减回
    }

    print_digits_array();

    return 0;
}

/**********************************************
  Function:     clear_digits_array
  Description:  all elements in the array become
                space
  Calls:        No
  Called by:    main
  Input:
  Output:
  Return:
  Others:
 ***********************************************/
void clear_digits_array(void)
{
    char digits[3][MAX_DIGITS * 4] = {0};
}

/***********************************************
  Function:     process_digit
  Description:  把digit的七段表示储存到digits数组
                的指定位置
  Calls:        No
  Called by:    main
  Input:
  Output:
  Return:
  Others:
 ************************************************/
void process_digit(int digit, int position)
{
    int i;

    for (i = 0; i < 7; i++) {
        if (segments[digit][i] == 1) {
            switch (i) {
            case 0: digits[0][1 + position * 4] = '_'; break;    //position * 4，每四个位置循环一次
            case 1: digits[1][2 + position * 4] = '|'; break;
            case 2: digits[2][2 + position * 4] = '|'; break;
            case 3: digits[2][1 + position * 4] = '_'; break;
            case 4: digits[2][0 + position * 4] = '|'; break;
            case 5: digits[1][0 + position * 4] = '|'; break;
            case 6: digits[1][1 + position * 4] = '_'; break;
            }
        }
    }
}

/**************************************************
  Function: print_digits_array
  Description:  print array digit
  Calls:        No
  Called by:    main
  Input:
  Output:
  Return:
  Others:
 **************************************************/
void print_digits_array(void)
{
    int row, col;

    for (row = 0; row < 3; row++) {
        for (col = 0; col < MAX_DIGITS * 4; col++)
            printf("%c", digits[row][col]);
        printf("\n");
    }

}
