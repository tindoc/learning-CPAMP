//#include <stdio.h>
//#include <string.h>
//
//#define LENGTH_WORD 20
//#define COUNT_WORDS 30
//
//int main(void)
//{
//    char sentence[COUNT_WORDS][LENGTH_WORDS + 1] = {0}, ch, punctuation;
//    int i, j;
//
//    printf("Enter a sentence: ");
//    for (i = 0; i < COUNT_WORDS; i++) {
//        for (j = 0; j < LENGTH_WORD; ) {
//            ch = getchar();
//            if (ch != ' ' && ch != '\n') {
//                sentence[i][j] = ch;
//                j++;
//            }
//            else {
//                sentence[i][j] = '\0';
//                break;
//            }
//        }
//        if (ch == '\n')
//            break;
//    }   //以上for循环取值任然有缺陷
//        //如果之前存在空隔，或者单词之间的空格不止一个的话，空格会单独占据一行
//
//    punctuation = sentence[i][j - 1];
//    sentence[i][j - 1] = '\0';  //靠将最后一个标点符号字符另外储存
//                                //再替换为空字符的做法也有缺陷
//                                //如果没有标点符号将无法正确显示
//    printf("Reversal of sentence:");
//    for ( ; i > 0; i--)
//        printf("%s ", &sentence[i]);
//    printf("%s%c", &sentence[i], punctuation);
//
//    return 0;
//}


//改进版本 动态分配字符串的数组（17章）+指针数组
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH_WORD 20
#define COUNT_WORDS 30


int main(void)
{
    char *sentence[COUNT_WORDS], ch, punctuation;
    //使用储存字符串的指针的数组可以解决不定数量空格的问题
    int i, len, j;

    printf("Enter a sentence: ");
    for (i = 0; i < COUNT_WORDS; i++) {
        sentence[i] = (char *)malloc(LENGTH_WORD * sizeof(char));
        //动态分配字符串长度的数组
        if (sentence[i] == NULL) {
            printf("allocation failed\n");
            exit(1);
        }
        //判断内存分配是否为空
        scanf(" %s", sentence[i]);
        ch = getchar();
        len = strlen(sentence[i]);
        sentence[i][len] = '\0';
        if (ch == '\n') {
            if (sentence[i][len - 1] == '.'     ||
                sentence[i][len - 1] == '\?'    ||
                sentence[i][len - 1] == '!'
                ) {
                punctuation = sentence[i][len - 1];
                sentence[i][len - 1] = '\0';
            }   //second-if
            break;
        }   //first-if
    }   //for

    for ( ; i > 0; i--)
        printf("%s ", sentence[i]);
    printf("%s%c", sentence[0], punctuation);

    return 0;
}
