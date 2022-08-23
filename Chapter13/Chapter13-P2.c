#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

int read_line(char str[], int n);
bool check_day(int month, int day);


int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN+18];    //date_str占据17个字符
    char month_str[3], day_str[3], hour_str[3], minute_str[3],
            date_str[18], msg_str[MSG_LEN+1];
    int month, day, hour, minute, i, j, num_remind = 0;

    printf("Attention:day(include month and day, separate with ""/"")\n");
    printf("          time(in 24hour and separate with "":"")\n");
    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

    printf("Enter day, time and reminder: ");
    fflush(stdin);    //清除缓冲区，否则函数check_day为false时无限循环
    scanf("%2d/%2d %2d:%2d", &month, &day, &hour, &minute);
    if (month == 0)
        break;
    if (!check_day(month, day)) {
        printf("-- Error in day--\n");
        continue;
    }
    sprintf(month_str, "%2d", month);
    sprintf(day_str, "%2d", day);
    sprintf(hour_str, "%2d", hour);
    sprintf(minute_str, "%2d", minute);
    read_line(msg_str, MSG_LEN);

    strcpy(date_str, month_str);    //此处用strcpy函数可以重新初始化date_str
    strcat(date_str, "/");
    strcat(date_str, day_str);
    strcat(date_str, " ");
    strcat(date_str, hour_str);
    strcat(date_str, ":");
    strcat(date_str, minute_str);

    for (i = 0; i < num_remind; i++)
        if (strcmp(date_str, reminders[i]) < 0)
            break;
    for (j = num_remind; j > i; j--)
        strcpy(reminders[j], reminders[j-1]);

    strcpy(reminders[i], date_str);
    strcat(reminders[i], msg_str);

    num_remind++;
  }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]);

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
    if (i < n)
        str[i++] = ch;
    str[i] = '\0';
    return i;
}

bool check_day(int month, int day)
{
    switch (month) {
        case  1:
        case  3:
        case  5:
        case  7:
        case  8:
        case 10:
        case 12:    if (day > 31)
                        return false;
                    else
                        return true;
                    break;
        case  2:    if (day > 29)
                        return false;
                    else
                        return true;
                    break;
        default :   if (day > 30)
                        return false;
                    else
                        return true;
                    break;
    }
}

