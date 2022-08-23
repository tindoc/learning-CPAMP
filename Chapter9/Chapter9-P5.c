#include <stdio.h>

void create_magic_square(int n, int magic_aquare[99][99]);
void print_magic_square(int n, int magic_aquare[99][99]);

int main(void)
{
    int size;
    int magic_square[99][99] = {0};

    printf("This program created a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &size);

    create_magic_square(size, magic_square);

    print_magic_square(size, magic_square);

    return 0;
}

void create_magic_square(int n, int magic_square[99][99])
{
    int x, y, i;

    x = 0;
    y = (n - 1) / 2;
    magic_square[x][y] = 1;

    for (i = 2; i <= n * n; i++) {
        if (x - 1 == -1) {
            if (y + 1 == n) {
                if (magic_square[n - 1][0] == 0) {      //up:N right:N repeat:N
                    x = n - 1;
                    y = 0;
                    magic_square[x][y] = i;
                }
                else {                                     //up:N right:N repeat:Y
                    x = x + 1;
                    y = y;
                    magic_square[x][y] = i;
                }
            }
            else {
                if (magic_square[n - 1][y + 1] == 0) {  //up:N right:Y repeat:N
                    x = n - 1;
                    y = y + 1;
                    magic_square[x][y] = i;
                }
                else {                                     //up:N right:Y repeat:Y
                    x = x + 1;
                    y = y;
                    magic_square[x][y] = i;
                }
            }
        }
        else {
            if (y + 1 == n) {
                if (magic_square[x - 1][0] == 0) {        //up:Y right:N repeat:N
                    x = x - 1;
                    y = 0;
                    magic_square[x][y] = i;
                }
                else {                                    //up:Y right:N repeat:Y
                    x = x + 1;
                    y = y;
                    magic_square[x][y] = i;
                }
            }
            else {
                if (magic_square[x - 1][y + 1] == 0) {    //up:Y right:Y repeat:N
                    x = x - 1;
                    y = y + 1;
                    magic_square[x][y] = i;
                }
                else {                                    //up:Y right:Y repeat:Y
                    x = x + 1;
                    y = y;
                    magic_square[x][y] = i;
                }
            }
        }
    }

}

void print_magic_square(int n, int magic_square[99][99])
{
    int x, y;

    for (x = 0; x < n; x++) {
        for (y = 0; y < n; y++)
            printf("%5d", magic_square[x][y]);
        printf("\n");
    }
}

