#include <stdio.h>
#include <string.h>

#define MESG_LEN 80

void encrypt(char *message, int shift);

int main(void)
{
    int shift_count, i;
    char message[MESG_LEN + 1], ch;

    printf("Enter message to be encrypted: ");
    gets(message);
    if (strlen(message) > MESG_LEN)
        message[MESG_LEN + 1] = '\0';

    printf("Enter shift amount (1-25):");
    scanf("%d", &shift_count);

    printf("Encrypted message: ");
    encrypt(message, shift_count);

    return 0;
}

void encrypt(char *message, int shift)
{
    int i;

    for (i = 0; i < MESG_LEN; i++) {
        if (message[i] != '\0')
            if (message[i] <= 'Z' && message[i] >= 'A')
                message[i] = ((message[i] - 'A') + shift) % 26 + 'A';
            else if (message[i] <= 'z' && message[i] >= 'a')
                message[i] = ((message[i] - 'a') + shift) % 26 + 'a';
    }

    puts(message);
}
