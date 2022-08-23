#include <stdio.h>
#include <ctype.h>

int main (void)
{
	int h, min, time;
	char ch;

	printf ("Enter a 12-hour time with A, P, AM or PM in the end:");
    scanf("%d:%d ", &h, &min);    //这里"%d:%d "后面的空格十分重要
    ch = getchar();

    switch (toupper(ch) != '/n') {
        case 'A': case 'AM':    //这里有个问题，如果是首字母相同的话，用getchar就区分不出是上午还是下午，因为只能读取一个数
            time = h * 60 + min; break;
        default:
            time = (h + 12) * 60 + min; break;
    }

    putchar(ch);
    printf("\n");    //用来显示getchar读取的数，与本题实现无关

	printf ("Closest departure time is ");

	if (time < 531.5f && time >= 172.5f)
		printf ("8:00 a.m., arriving at 10:16 a.m.\n");
	else if (time < 634.5f && time >= 531.5f)
		printf ("9:43 a.m., arriving at 11:52 a.m.\n");
	else if (time < 723.0f && time >= 634.5f)
		printf ("11:19 a.m., arriving at 1:31 p.m.\n");
	else if (time < 803.5f && time >= 723.0f)
		printf ("12:47 p.m., arriving at 3:00 p.m.\n");
	else if (time < 892.5f && time >= 803.5f)
		printf ("2:00 p.m., arriving at 4:08 p.m.\n");
	else if (time < 1042.5f && time >= 892.5)
		printf ("3:45 p.m., arriving at 5:55 p.m.\n");
	else if (time < 1222.5 && time >= 1042.5f)
		printf ("7:00 p.m., arriving at 9:20 p.m.\n");
	else
		printf ("9:45 p.m., arriving at 11:58 p.m.\n");

	return 0;
}

