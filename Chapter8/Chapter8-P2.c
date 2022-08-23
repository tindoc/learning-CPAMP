#include <stdio.h>

int main(void)
{
    int digit, times[10] = {0};
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        times[digit] += 1;
        n /= 10;
    }

    printf("Digit:        0  1  2  3  4  5  6  7  8  9\n");
    printf("occurrence: ");

    for (digit = 0; digit < 10; digit++) {
        printf("%3d",times[digit]);
    }

    return 0;
}


//官方答案
//#include <stdio.h>
//
//int main(void)
//{
//  int digit_count[10] = {0};
//  int digit;
//  long n;
//
//  printf("Enter a number: ");
//  scanf("%ld", &n);
//
//  while (n > 0) {
//    digit = n % 10;
//    digit_count[digit]++;
//    n /= 10;
//  }
//
//  printf ("Digit:      ");
//  for (digit = 0; digit <= 9; digit++)
//    printf("%3d", digit);
//  printf("\nOccurrences:");
//  for (digit = 0; digit <= 9; digit++)
//    printf("%3d", digit_count[digit]);
//  printf("\n");
//
//  return 0;
//}
