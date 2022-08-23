#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    int counts_win = 0, counts_lose = 0;
    char ch;

    srand((unsigned)time(NULL));

    do {
        if (play_game() == true) {
            counts_win++;
            printf("You win!\n");
        }
        else {
            counts_lose++;
            printf("You lose!\n");
        }

        printf("Play again?");
        scanf("%c", &ch);
        getchar();    //根据键盘缓冲区的影响，用来消除'\n'的影响，详细见最后的几个链接

        printf("\n");
    } while(toupper(ch) != 'N');

    printf("Wins: %d   Losses: %d", counts_win, counts_lose);

    return 0;
}

int roll_dice(void)
{
    int counts_first, counts_second;

    counts_first = rand() % 6 + 1;
    counts_second = rand() % 6 + 1;

    return counts_first + counts_second;
}

bool play_game(void)
{
    int roll, point;

    roll = roll_dice();
    printf("You rolled: %d\n", roll);

    if (roll == 2 || roll == 3 || roll == 12 || roll == 7 || roll == 11) {    //注意！
        if (roll == 7 || roll == 11)
            return true;
        else
            return false;
    }
    else {
        point = roll;
        printf("You point is %d\n", point);

        for (roll = 0; roll != point && roll != 7; ) {
            roll = roll_dice();
            printf("You rolled: %d\n", roll);
        }

        if (roll == point)
            return true;
        else
            return false;
    }
}


//在scanf("%c", &ch)之前使用fflush(stdin)也可以达到效果，但是这种用法不利于移植，看下面链接
//http://bbs.csdn.net/topics/330219044

//详细解析：getchar、scanf以及缓冲区的概念
//http://blog.csdn.net/hackbuteer1/article/details/6704779
