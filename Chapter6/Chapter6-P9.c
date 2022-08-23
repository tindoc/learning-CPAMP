#include <stdio.h>

int main(void)
{
    //定义变量，n为输入的是还贷的次数
    float loan, rate, monthly_pay;
    int n, i = 1;

    //输入
    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_pay);
    printf("Enter the tomes you pay: ");
    scanf("%d", &n);

    //循环
    while(i <= n){
        loan = loan - monthly_pay + loan * rate / 100.00f / 12.00f;    //这样可以减少变量的定义
        printf("Balance remaining after %d payment: $%.2f\n", i, loan);
        i++;
    }
    return 0;

}
