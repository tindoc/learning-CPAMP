#include <stdio.h>
#include <string.h>

/* external variables */
#define MSG_LEN 100

/* function prototype */
void reverse(char *message);

int main(void)
{
    char message[MSG_LEN + 1];

    printf("Enter a message: ");
    gets(message);

    printf("Reversal is: ");
    reverse(message);

    return 0;
}

void reverse(char *message)
{
    char *start, *stop, temp;

    start = &message[0];
    stop = &message[strlen(message) - 1];   //attention: remember "-1"

    while (start != stop && start + 1 != stop) {    //attention: use "&&" no "||"
        temp = *start;
        *start = *stop;
        *stop = temp;
        start++;
        stop--;
    }

    puts(message);
}

