#include <stdio.h>

#define NUM_RATES ((int)(sizeof(value) / sizeof(value[0])))
#define INITIAL_BLANCE 100.00

int main(void)
{
    int i, low_rate, num_years, year, month;
    double value[5];

    //读取利率和年数
    printf("Enter interest rate: ");
    scanf("%d", &low_rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    //显示表格第一行
    printf("\nYears");
    for (i = 0; i < NUM_RATES; i++) {
        printf("%6d%", low_rate + i);
        value[i] = INITIAL_BLANCE;
    }
    printf("\n");

    //计算并输出表格的数据
    for (year = 1; year <= num_years; year++) {
        printf("%3d   ", year);
        for (i = 0; i < NUM_RATES; i++) {
            for (month = 0; month < 12; month++)
                value[i] += ((low_rate + i) / 12) / 100.00 * value[i];
                //年利率除以12为月利率，答案在这里用了double类型的强制转换
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }

    return 0;
}


//官方答案
//#include <stdio.h>
//
//#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
//#define INITIAL_BALANCE 100.00
//
//int main(void)
//{
//  int i, low_rate, month, num_years, year;
//  double value[5];
//
//  printf("Enter interest rate: ");
//  scanf("%d", &low_rate);
//  printf("Enter number of years: ");
//  scanf("%d", &num_years);
//
//  printf("\nYears");
//  for (i = 0; i < NUM_RATES; i++) {
//    printf("%6d%%", low_rate + i);
//    value[i] = INITIAL_BALANCE;
//  }
//  printf("\n");
//
//  for (year = 1; year <= num_years; year++) {
//    printf("%3d    ", year);
//    for (i = 0; i < NUM_RATES; i++) {
//      for (month = 1; month <= 12; month++)
//        value[i] += ((double) (low_rate + i) / 12) / 100.0 * value[i];
//      printf("%7.2f", value[i]);
//    }
//    printf("\n");
//  }
//
//  return 0;
//}
