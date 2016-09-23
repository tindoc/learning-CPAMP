#include <stdio.h>
#include <string.h>

int main(void)
{
    int num1, num2;
    char *second_num[] = {"ten", "eleven", "twelve", "thirteen", "fourteen",\
                         "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",\
                         "twenty", "thirty", "forty", "fifty",\
                         "sixty", "seventy", "eighty", "ninety"};
    char *first_num[] = {"first", "second", "third", "fourth", "fifth",\
                          "sixth", "seventh", "eighth", "ninth"};

    printf("Enter a two-digit number: ");
    scanf("%1d%1d", &num1, &num2);

    printf("You entered the number ");
    if (num1 < 2)
        puts(second_num[num2]);
    else {
        printf("%s-%s", second_num[num1 + 8], first_num[num2 - 1]);
    }

    return 0;
}

//这种做法比用switch能够节省大量的时间
