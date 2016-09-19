#include <stdio.h>

int main(void)
{
    //因为用到了两个for语句，所以定义了变量i_days和i_starting_day
    int days, starting_day, i_days, i_starting_day;

    //输入
    printf("Enter number of days in month: ");
    scanf("%d", &days);
    printf("Enter starting day of the week:(1=Sun, 7=Sat): ");
    scanf("%d", &starting_day);

    for(i_starting_day = 1; i_starting_day != starting_day; i_starting_day++)
        printf("   ");
    //用这个for语句输出起始日不是Sun所占用的空格
    //如果起始日是第三天，最后i_starting_day=3
    //由于以上i_starting_day=3,实际占的是两个位置
    //所以在下面(i_days + i_starting_day - 1)中要减1

    for(i_days = 1; i_days <= days; i_days++){
        printf("%3d", i_days);
        if((i_days + i_starting_day - 1) % 7 == 0)    //在一个星期的最后一日用这个if实现转行
            printf("\n");
    }

    /*
    printf("\n\n%d %d",i_starting_day, i_days );    //这个主要用来查看两个i的值
    */

    return 0;
}


/*官方答案
#include <stdio.h>

int main(void)
{
  int i, n, start_day;

  printf("Enter number of days in month: ");
  scanf("%d", &n);
  printf("Enter starting day of the week (1=Sun, 7=Sat): ");
  scanf("%d", &start_day);

  // print any leading "blank dates" 打印开始的”空白日期“
  for (i = 1; i < start_day; i++)
    printf("   ");

  // now print the calendar 现在打印日历
  for (i = 1; i <= n; i++) {
    printf("%3d", i);
    if ((start_day + i - 1) % 7 == 0)
      printf("\n");
  }

  return 0;
}
  //这次觉得和答案不相上下，答案的高明之处在于重新初始化了i的值

*/
