#include <stdio.h>

#define MESG_LEN 100

void reverse(char *message);

int main(void)
{
	char message[MESG_LEN];
	
	printf("Enter a message: ");
	gets(message);
	
	reverse(message);
	
	return 0;
}

void reverse(char *message)
{
	