#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void)
{
    int num_cards, rank, suit, i, n;
    char *rank_code[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven",
                            "Eight", "Nine", "Ten", "Jack", "Queen ", "King", "Ace"};
    char *suit_code[] = {"clubs", "diamonds", "hearts", "spades"};    //见215

    srand((unsigned) time(NULL));

    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);
    char in_hand[num_cards][20];    //我在这里使用指向字符串的指针的数组使得程序不能运行

    printf("Your hand:\n");
    for (i = 0; i < num_cards; i++) {
        again:

        suit = rand() % NUM_SUITS;     /* picks a random suit */
        rank = rand() % NUM_RANKS;     /* picks a random rank */

        strcpy(&in_hand[i][0], &rank_code[rank][0]);
        strcat(&in_hand[i][0], " of ");
        strcat(&in_hand[i][0], &suit_code[suit][0]);

        for (n = 0; n < i; n++)
            if (strcmp(&in_hand[i][0], &in_hand[n][0]) == 0) {
                goto again;
            }

        puts(&in_hand[i][0]);
    }

    return 0;
}

