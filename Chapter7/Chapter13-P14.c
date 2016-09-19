#include <stdio.h>
#include <string.h>

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
	int len1, len2;
	int i;
	
	len1 = strlen(word1);
	len2 = strlen(word2);
	
	if (len1 != len2)
		return false;
	
	for (i = 0; i < len1; i++)
		if (word1[i] != word2[len1 - i])
			return false;
	
	return true;
}	