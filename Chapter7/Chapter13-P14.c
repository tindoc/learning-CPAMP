#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 50

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
	char first_word[MAX_LEN + 1], second_word[MAX_LEN + 1];

	printf("Enter first word: ");
	gets(first_word);
	printf("Enter second word: ");
	gets(second_word);

	if (are_anagrams(first_word, second_word))
		printf("The words are anagrams");
	else
		printf("The words are not anagrams");

	return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
	int len1, len2, alphabet[26]={0}, i, site1, site2;

	len1 = strlen(word1);
	len2 = strlen(word2);

	if (len1 != len2)
		return false;

	for (i = 0; i < len1; i++) {
        site1 = word1[i] - 'a';
        alphabet[site1]++;
	}
    for (i = 0; i < len2; i++) {
        site2 = word2[i] - 'a';
        alphabet[site2]--;
    }

    for (i = 0; i < len1; i++)
        if (alphabet[i] != 0)
            return false;

	return true;
}
