#include <stdio.h>

int main(void)
{
    int h, min, time;
	char ch;

	printf ("Enter a 12-hour time:");
    scanf("%d:%d ", &h, &min);
    ch = getchar();

    printf("Equivalent 24-hour time: ");

    switch (toupper(ch)) {
        case 'A': case 'AM':
            printf("%d:%d\n", h, min); break;
        case 'P': case 'PM':
            printf("%d:%d\n", h + 12, min); break;
    }
    return 0;
}
