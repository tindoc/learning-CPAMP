#include <stdio.h>
#include <string.h>

#define LARGEST 100

void computer_average_word_length(const char *sentence);

int main(void)
{
    char sentence[LARGEST + 1];

    printf("Enter a sentence: ");
    gets(sentence);

    computer_average_word_length(sentence);

    return 0;
}

void computer_average_word_length(const char *sentence)
{
    int count = 0, count_space = 0, i = 0;
    float average;

    for (i = 0; sentence[i]; i++)
        if (sentence[i] == '\'' || sentence[i] == '.' ||
            sentence[i] == '\?' || sentence[i] == '!')
            count++;
        else if (sentence[i] == ' ')
            count_space++;

    average = (strlen(sentence) - count_space) / (float)(count + count_space);    //ÀàĞÍ×ª»»
    printf("Average word length: %.1f", average);
}
