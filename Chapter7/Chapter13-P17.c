#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/* external variable */
#define MSG_LEN 100

/* function prototype */
bool is_palindrome(const char *message);

int main(void)
{
    char message[MSG_LEN + 1];
    int i;

    printf("Enter a message: ");
    for (i = 0; i < MSG_LEN + 1; i++) {
        message[i] = toupper(getchar());
        while (message[i] == ' ' || message[i] == '.' || message[i] == '!' ||
               message[i] == '?' || message[i] == ',' || message[i] == '\'')
            message[i] = toupper(getchar());

        if (message[i] == '\n')
            break;
    }
    message[i] = '\0';

    if (is_palindrome(message))
        printf("Palindrome.\n");
    else
        printf("Not a palindrome.\n");

    return 0;
}

bool is_palindrome(const char *message)
{
    int len = strlen(message);
    char *start, *stop;

    start = &message[0];
    stop = &message[len - 1];

    for ( ; start != stop && start + 2 != stop; start++, stop--) {
        if (*start != *stop)
            return false;
    }

    return true;
}
