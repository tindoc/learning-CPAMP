#include <stdio.h>

#define N 100

int main(void)
{
    char a[N], ch;
    int i;

    printf("Enter a message: ");
    for (i = 0; (ch = getchar()) != '\n' && i != 100; i++)
        a[i] = ch;

    printf("Reversal is: ");
    for (i--; i >= 0; i--)
        putchar(a[i]);

    return 0;
}


//官方答案：
//#include <stdio.h>
//
//#define MSG_LEN 80     /* maximum length of message */
//
//int main(void)
//{
//  char msg[MSG_LEN];
//  int i;
//
//  printf("Enter a message: ");
//  for (i = 0; i < MSG_LEN; i++) {
//    msg[i] = getchar();
//    if (msg[i] == '\n')
//      break;
//  }
//
//  printf("Reversal is: ");
//  for (i--; i >= 0; i--)
//    putchar(msg[i]);
//  putchar('\n');
//
//  return 0;
//}
