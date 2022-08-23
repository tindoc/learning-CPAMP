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
    char *suit_code[] = {"clubs", "diamonds", "hearts", "spades"};
