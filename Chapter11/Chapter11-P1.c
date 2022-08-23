#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void)
{
    int dollars, counts_20 = 0, counts_10 = 0, counts_5 = 0, counts_1 = 0;

    printf("Enter a dollar amount: ");
    scanf("%d", &dollars);

    pay_amount(dollars, &counts_20, &counts_10, &counts_5, &counts_1);

    printf("$20 bills: %d\n$10 bills: %d\n $5 bills: %d\n $1 bills: %d", counts_20, counts_10,
           counts_5, counts_1);

    return 0;
}

/**************************************************
  Function: pay_amount
  Description:  counting how many $20, $10, $5, $1
                bills need in minimum
  Calls:    No
  Called by:    main
  Input:
  Output:
  Return:
  Others:
 **************************************************/
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
    *twenties = dollars / 20;
    *tens = (dollars - *twenties * 20) / 10;
    *fives = (dollars - *twenties * 20 - *tens * 10) / 5;
    *ones = dollars - *twenties * 20 - *tens * 10 - *fives * 5;
}

