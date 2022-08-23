//#include <stdio.h>
//
//int main(void)
//{
//    int i, n;
//
//    printf("This program prints a table of squares.\n");
//    printf("Enter number of entries in table: ");
//    scanf("%d", &n);
//
//    for (i = 1; i <= n; i++) {
//        printf("%10d%10d\n", i, i * i);
//        if (i % 24 == 0) {
//            printf("Press Enter to continue...");
//        while (getchar() == '\n')
//            ;
//        }
//    }
//
//    return 0;
//}

/*如果程序如上，在暂停之后不能直接输入“Enter”来继续程序，必须还要输入一个任意字符，再输入"Enter"才能继续程序*/

#include <stdio.h>

int main(void)
{
  int i, n;
  char ch;

  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);
  ch = getchar();
    /* dispose of new-line character following number of entries */
    /* could simply be getchar(); */

  for (i = 1; i <= n; i++) {
    printf("%10d%10d\n", i, i * i);
    if (i % 24 == 0) {
      printf("Press Enter to continue...");
      ch = getchar();   /* or simply getchar(); */
    }
  }

  return 0;
}
