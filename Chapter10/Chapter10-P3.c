/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* poker.c (Chapter 10, page 233) */
/* Classifies a poker hand */

#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* external variables */
char hand[NUM_CARDS][2];
bool straight, flush, four, three;
int pairs;   /* can be 0, 1, or 2 */

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);

/**********************************************************
 * main: Calls read_cards, analyze_hand, and print_result *
 *       repeatedly.                                      *
 **********************************************************/
int main(void)
{
  for (;;) {
    read_cards();
    analyze_hand();
    print_result();
  }
}

/**********************************************************
 * read_cards: Reads the cards into the external          *
 *             variables hand[NUM_CARDS][2];     *
 *             checks for bad cards and duplicate cards.  *
 **********************************************************/
void read_cards(void)
{
  char ch, rank_ch, suit_ch;
  bool bad_card, duplicate_card;
  int cards_read = 0;
  int i, temp;

  for (i = 0; i < NUM_CARDS; i++) {
    hand[i][0] = 0;
    hand[i][1] = 0;
  }

  while (cards_read < NUM_CARDS) {
    bad_card = false;

    printf("Enter a card: ");

    rank_ch = getchar();
    switch (rank_ch) {
      case '0':           exit(EXIT_SUCCESS);
      case '2':           rank_ch = '0'; break;
      case '3':           rank_ch = '1'; break;
      case '4':           rank_ch = '2'; break;
      case '5':           rank_ch = '3'; break;
      case '6':           rank_ch = '4'; break;
      case '7':           rank_ch = '5'; break;
      case '8':           rank_ch = '6'; break;
      case '9':           rank_ch = '7'; break;
      case 't': case 'T': rank_ch = '8'; break;
      case 'j': case 'J': rank_ch = '9'; break;
      case 'q': case 'Q': rank_ch = '10'; break;
      case 'k': case 'K': rank_ch = '11'; break;
      case 'a': case 'A': rank_ch = '12'; break;
      default:            bad_card = true;
    }

    suit_ch = getchar();
    switch (suit_ch) {
      case 'c': case 'C': suit_ch = 0; break;
      case 'd': case 'D': suit_ch = 1; break;
      case 'h': case 'H': suit_ch = 2; break;
      case 's': case 'S': suit_ch = 3; break;
      default:            bad_card = true;
    }

    while ((ch = getchar()) != '\n')
      if (ch != ' ') bad_card = true;

    duplicate_card = false;
    //下面的处理方法没有答案的好，continue和for循环的使用比这个要好很多
    if (bad_card)
      printf("Bad card; ignored.\n");
    else {
        temp = cards_read - 1;
        while (temp >= 0) {
            if (rank_ch == hand[temp][0] && suit_ch == hand[temp][1]) {
                printf("Duplicate card; ignored.\n");
                duplicate_card = true;
                break;
            }
            else
                temp--;
        }

        if (!duplicate_card) {
            hand[cards_read][0] = rank_ch;
            hand[cards_read][1] = suit_ch;
            cards_read++;
        }
    }
  }
}

/**********************************************************
 * analyze_hand: Determines whether the hand contains a   *
 *               straight, a flush, four-of-a-kind,       *
 *               and/or three-of-a-kind; determines the   *
 *               number of pairs; stores the results into *
 *               the external variables straight, flush,  *
 *               four, three, and pairs.                  *
 **********************************************************/
void analyze_hand(void)
{
  int num_consec = 0;
  int i, temp, counts;
  char suit_ch, rank_min;

  straight = false;    //答案默认为true
  flush = false;    //答案默认为true
  four = false;
  three = false;
  pairs = 0;

  /* check for flush */
  counts = 0;
  suit_ch = hand[0][1];
  for (i = 1; i < NUM_CARDS; i++)
    if (hand[i][1] == suit_ch)
      counts++;
  if (counts == 4)
    flush = true;    //如果默认为true能够使代码简洁一些

  /* check for straight */
  rank_min = hand[0][0];
  for (i = 1; i < NUM_CARDS; i++)
    if (hand[i][0] < rank_min)
        rank_min = hand[i][0];

  counts = 0;
  for (temp = 0; temp < NUM_CARDS; temp++) {
    for (i = 0; i < NUM_CARDS; i++) {
        if (rank_min + temp == hand[i][0]) {
            counts++;
            break;
        }
    }
    if (counts != 1)
        break;
    else
        counts = 0;
  }

  if (temp == NUM_CARDS) {
    straight = true;
    return;
  }

  /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
  counts = 0;
  for (i = 0; i < NUM_CARDS; i++) {
    for (temp = 0; temp < NUM_CARDS && temp != i; temp++) {
        if (hand[i][0] == hand[temp][0])
            counts++;
    }
    if (counts == 3) four = true;
    if (counts == 2) three = true;
    if (counts == 1) pairs++;
    counts = 0;
  }
}

/**********************************************************
 * print_result: Prints the classification of the hand,   *
 *               based on the values of the external      *
 *               variables straight, flush, four, three,  *
 *               and pairs.                               *
 **********************************************************/
void print_result(void)
{
  if (straight && flush) printf("Straight flush");
  else if (four)         printf("Four of a kind");
  else if (three &&
           pairs == 1)   printf("Full house");
  else if (flush)        printf("Flush");
  else if (straight)     printf("Straight");
  else if (three)        printf("Three of a kind");
  else if (pairs == 2)   printf("Two pairs");
  else if (pairs == 1)   printf("Pair");
  else                   printf("High card");

  printf("\n\n");
}


//官方答案：
//#include <stdbool.h>   /* C99 only */
//#include <stdio.h>
//#include <stdlib.h>
//
//#define NUM_CARDS 5
//#define RANK 0
//#define SUIT 1
//
///* external variables */
//int hand[NUM_CARDS][2];
///*    0    1
//    ____ ____
// 0 |____|____|
// 1 |____|____|
// 2 |____|____|
// 3 |____|____|
// 4 |____|____|
//    rank suit
//*/
//
//bool straight, flush, four, three;
//int pairs;   /* can be 0, 1, or 2 */
//
///* prototypes */
//void read_cards(void);
//void analyze_hand(void);
//void print_result(void);
//
///**********************************************************
// * main: Calls read_cards, analyze_hand, and print_result *
// *       repeatedly.                                      *
// **********************************************************/
//int main(void)
//{
//  for (;;) {
//    read_cards();
//    analyze_hand();
//    print_result();
//  }
//}
//
///**********************************************************
// * read_cards: Reads the cards into the external variable *
// *             hand; checks for bad cards and duplicate   *
// *             cards.                                     *
// **********************************************************/
//void read_cards(void)
//{
//  char ch, rank_ch, suit_ch;
//  int i, rank, suit;
//  bool bad_card, duplicate_card;
//  int cards_read = 0;
//
//  while (cards_read < NUM_CARDS) {
//    bad_card = false;
//
//    printf("Enter a card: ");
//
//    rank_ch = getchar();
//    switch (rank_ch) {
//      case '0':           exit(EXIT_SUCCESS);
//      case '2':           rank = 0; break;
//      case '3':           rank = 1; break;
//      case '4':           rank = 2; break;
//      case '5':           rank = 3; break;
//      case '6':           rank = 4; break;
//      case '7':           rank = 5; break;
//      case '8':           rank = 6; break;
//      case '9':           rank = 7; break;
//      case 't': case 'T': rank = 8; break;
//      case 'j': case 'J': rank = 9; break;
//      case 'q': case 'Q': rank = 10; break;
//      case 'k': case 'K': rank = 11; break;
//      case 'a': case 'A': rank = 12; break;
//      default:            bad_card = true;
//    }
//
//    suit_ch = getchar();
//    switch (suit_ch) {
//      case 'c': case 'C': suit = 0; break;
//      case 'd': case 'D': suit = 1; break;
//      case 'h': case 'H': suit = 2; break;
//      case 's': case 'S': suit = 3; break;
//      default:            bad_card = true;
//    }
//
//    while ((ch = getchar()) != '\n')
//      if (ch != ' ') bad_card = true;
//
//    if (bad_card) {
//      printf("Bad card; ignored.\n");
//      continue;
//    }
//
//    duplicate_card = false;
//    for (i = 0; i < cards_read; i++)
//      if (hand[i][RANK] == rank && hand[i][SUIT] == suit) {
//        printf("Duplicate card; ignored.\n");
//        duplicate_card = true;
//        break;
//      }
//
//    if (!duplicate_card) {
//      hand[cards_read][RANK] = rank;
//      hand[cards_read][SUIT] = suit;
//      cards_read++;
//    }
//  }
//}
//
///**********************************************************
// * analyze_hand: Determines whether the hand contains a   *
// *               straight, a flush, four-of-a-kind,       *
// *               and/or three-of-a-kind; determines the   *
// *               number of pairs; stores the results into *
// *               the external variables straight, flush,  *
// *               four, three, and pairs.                  *
// **********************************************************/
//void analyze_hand(void)
//{
//  int rank, suit, card, pass, run;
//
//  straight = true;    //厉害之处
//  flush = true;    //厉害之处
//  four = false;
//  three = false;
//  pairs = 0;
//
//  /* sort cards by rank */
//  //按照等级“从小到大”的顺序重新排序数组hand，方便straight的检查
//  //这个循环也很厉害！应该也是排序法的一种。
//  for (pass = 1; pass < NUM_CARDS; pass++)
//    for (card = 0; card < NUM_CARDS - pass; card++) {
//      rank = hand[card][RANK];
//      suit = hand[card][SUIT];
//      if (hand[card+1][RANK] < rank) {
//        hand[card][RANK] = hand[card+1][RANK];
//        hand[card][SUIT] = hand[card+1][SUIT];
//        hand[card+1][RANK] = rank;
//        hand[card+1][SUIT] = suit;
//      }
//    }
//
//  /* check for flush */
//  suit = hand[0][SUIT];
//  for (card = 1; card < NUM_CARDS; card++)
//    if (hand[card][SUIT] != suit)
//      flush = false;
//
//  /* check for straight */
//  for (card = 0; card < NUM_CARDS - 1; card++)    //0-1-2-3-4.0-1, 1-2, 2-3, 3-4共四个，所以NUM_CARDS - 1
//    if (hand[card][RANK] + 1 != hand[card+1][RANK])    //上面有sort cards by rank的基础
//      straight = false;
//
//  /* check for 4-of-a-kind, 3-of-a-kind, and pairs by
//     looking for "runs" of cards with identical ranks */
//  card = 0;
//  while (card < NUM_CARDS) {    //这个循环也很厉害！
//    rank = hand[card][RANK];
//    run = 0;
//    do {
//      run++;
//      card++;
//    } while (card < NUM_CARDS && hand[card][RANK] == rank);
//    switch (run) {
//      case 2: pairs++;      break;
//      case 3: three = true; break;
//      case 4: four = true;  break;
//    }
//  }
//}
//
///**********************************************************
// * print_result: Prints the classification of the hand,   *
// *               based on the values of the external      *
// *               variables straight, flush, four, three,  *
// *               and pairs.                               *
// **********************************************************/
//void print_result(void)
//{
//  if (straight && flush) printf("Straight flush");
//  else if (four)         printf("Four of a kind");
//  else if (three &&
//           pairs == 1)   printf("Full house");
//  else if (flush)        printf("Flush");
//  else if (straight)     printf("Straight");
//  else if (three)        printf("Three of a kind");
//  else if (pairs == 2)   printf("Two pairs");
//  else if (pairs == 1)   printf("Pair");
//  else                   printf("High card");
//
//  printf("\n\n");
//}
