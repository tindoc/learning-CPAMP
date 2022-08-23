#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int alphabet[26] = {0}, i;

    printf("Enter first word: ");
    while ((ch = getchar()) != '\n')
        alphabet[toupper(ch) - 65]++;

    printf("Enter second word: ");
    while ((ch = getchar()) != '\n')
        alphabet[toupper(ch) - 65]--;

    for (i = 0; i < 26; i++) {
        if (alphabet[i] != 0) {
            printf("The words are not anagrams.\n");
            goto stop;
        }
    }

    printf("The words are anagrams.\n");

    stop:

    return 0;
}


//另外的实现方法
//#include <stdio.h>
//
//int main(void)
//{
//    int m, n, x = 0, y = 0, i = 0;
//    char first_word[100], second_word[100], ch;
//
//    printf("Enter first word: ");
//    ch = getchar();
//    for (m = 0; ch != '\n'; m++, x++) {
//        first_word[m] = ch;
//        ch = getchar();
//    }
//
//    printf("Enter second word: ");
//    ch = getchar();
//    for (n = 0; ch != '\n'; n++, y++) {
//        second_word[n] = ch;
//        ch = getchar();
//    }
//
//    for (m = 0; m < x; m++) {
//        for (n = 0; n < y; n++) {
//            if (first_word[m] == second_word[n]) {
//                first_word[m] = second_word[n] = '0';    //相同相消
//            }
//        }
//    }
//
//    //判断first word和second word是否还有没有被消去的不是'0'的字符
//    for (m = 0; m < x; m++) {
//        if (first_word[m] != '0')
//            i = 1;
//    }
//    for (n = 0; n < y; n++) {
//        if (second_word[n] != '0')
//            i = 1;
//    }
//
//    if (i == 0)
//        printf("The words are anagrams.\n");
//    else
//        printf("The words are not anagrams.\n");
//
//    return 0;
//}
