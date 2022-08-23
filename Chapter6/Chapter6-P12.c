#include <stdio.h>

int main(void)
{
    //定义变量，e为输入的项
    int i = 1,demon = 1;
    float e, sum = 1.00f;

    printf("Enter the e: ");
    scanf("%f", &e);

    while((1.00f / demon) > e){
        demon *= i;
        sum = sum + 1.00f / demon;
        printf("%d of terms is %f\n", i+1, 1.00f / demon);
        //用来显示每一个项的值，与输入项做对比
        i++ ;
    }
    printf("e is %f \nsum is %f\n", e, sum);

    return 0;
}
