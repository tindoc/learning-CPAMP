#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int n, sum = 0;    /*注意这里只有sum的值为0，n的并没有被定义*/

    printf("Enter a word : ");

    ch = getchar();
    while (ch != '\n') {
        switch (toupper(ch)) {
    case 'A': case 'E': case 'I': case 'L': case 'N': case 'O': case 'R': case 'S': case 'T': case 'U':
        n = 1;
        break;
    case 'D': case 'G':
        n = 2;
        break;
    case 'B': case 'C': case 'M': case 'P':
        n = 3;
        break;
    case 'F': case 'H': case 'V': case 'W': case 'Y':
        n = 4;
        break;
    case 'K':
        n = 5;
        break;
    case 'J': case 'X':
        n = 6;
        break;
    case 'Q': case 'Z':
        n = 7;
        break;
        }
        sum = sum + n;
        ch = getchar();
    }
    printf("%d", sum);

    return 0;
}


/*官方答案*/
//#include <ctype.h>
//#include <stdio.h>
//
//int main(void)
//{
//  int sum = 0;
//  char ch;
//
//  printf("Enter a word: ");
//
//  while ((ch = getchar()) != '\n')
//    switch (toupper(ch)) {
//      case 'D': case 'G':
//        sum += 2; break;
//      case 'B': case 'C': case 'M': case 'P':
//        sum += 3; break;
//      case 'F': case 'H': case 'V': case 'W': case 'Y':
//        sum += 4; break;
//      case 'K':
//        sum += 5; break;
//      case 'J': case 'X':
//        sum += 8; break;
//      case 'Q': case 'Z':
//        sum += 10; break;
//      default:
//        sum++; break;  /*简略了1的计算*/
//    }
//
//  printf("Scrabble value: %d\n", sum);
//
//  return 0;
//}
