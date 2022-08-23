#include <stdio.h>
#include <ctype.h>

#define LARGEST 200

int compute_vowel_count(const char *sentence);

int main(void)
{
    char sentence[LARGEST];

    printf("Enter a sentence: ");
    gets(sentence);

    printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));

    return 0;
}

int compute_vowel_count(const char *sentence)
{
    int i, count = 0;

    for (i = 0; sentence[i] != '\0'; i++) {
        switch(toupper(sentence[i])) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':   count++; break;
        }
    }

    return count;
}
