//square3在P77，程序说明在P71

#include <stdio.h>

int main(void)
{
  int i, n, odd, square;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);

  odd = 3;
  for (i = 1, square = 1; i <= n; ++i, odd += 2) {
    printf("%10d%10d\n", i, square);
    square += odd;
  }
  //不知道题目的意思是不是这个

  return 0;
}
