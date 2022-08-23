Chapter 5

Exercises

1.
(a) 1 
(b) 1 
(c) 1 
(d) 0    /*(3 % 4)得3*/

2. 
(a) 1 
(b) 1    /*(!!i)得1，因为(!i)得0,(!0)得1*/ 
(c) 1
(d) 1

3.
(a) 1 3 4 5    /*见书中52页中的&&和||的短路特性导致的操作数的副作用不发生的，下面同样*/  
(b) 0 7 8 9 
(c) 1 8 8 9
(d) 1 2 1 1

4.
(i > j) - (i < j)

5.
合法，但是结果不对。当n=0时，先计算（n >= 1）得0，接着（0 <= 10）得1,接着输出"n is between 1 and 10\n"。但是0不在1到10之间。

6.
合法。当n=5时，什么也不做，因为5不等于（-9）。    /*合法与有没有结果还是不同的，没有结果不代表不合法*/

7.
i = 17时，17
i = -17时，17

8.
if (age >=13 && age <=19)
   teenager = true;
else
   teenager = false;
/*画个x轴就很好理解了*/

9.
等价吧。    /*没有办法验证，应该没有错*/

10. 
onetwo     /*因为没有break*/

11.
#include <stdio.h>
int main (void)
{
	int area_code;

	printf ("Enter the area_code: ");
	scanf ("%d",& area_code);

	switch (area_code) {
	case 229: printf ("Albany\n"); break;
	case 404:
        case 470:
	case 678:
	case 770: printf ("Atlanta\n"); break;
	case 478: printf ("Macon\n"); break;
	case 706:
	case 762:
	case 912: printf ("Savannah\n"); break;
	default: printf ("Area code not recognized.\n"); break;
	}
}


Programming Projects

1.
#include <stdio.h>
int main (void)
{
	int num;

	printf ("Enter a number: ");
	scanf ("%d",&num);

	printf ("The number %d has ", num);

	if (num <= 9)
		printf ("1");
	else if (num <= 99)
		printf ("2");
	else if (num <= 999)
		printf ("3");
	else if (num <= 9999)
		printf ("4");
	
	printf (" digits\n");

	return 0;
}

2.
#include <stdio.h>

int main(void)
{
  int hours, minutes;

  printf("Enter a 24-hour time: ");
  scanf("%d:%d", &hours, &minutes);

  printf("Equivalent 12-hour time: ");
  if (hours == 0)
    printf("12:%.2d AM\n", minutes);    /*其实不是很理解这种表示方式也，莫非这是我的个人常识问题*/
  else if (hours < 12)
    printf("%d:%.2d AM\n", hours, minutes);
  else if (hours == 12)
    printf("%d:%.2d PM\n", hours, minutes);
  else
    printf("%d:%.2d PM\n", hours - 12, minutes);

  return 0;
}

3.
#include <stdio.h>
int main (void)
{
	float n, price, commission_1, commission_2, value;

	printf ("Enter the price of every strade and commount: ");
	scanf ("%f %f",&price, &n);

        value = n * price;
        /*计算原有经纪人的佣金*/
	if (value < 2500.00f)
		commission_1 = 30.00f + .017f * value;
	else if (value < 6250.00f)
		commission_1 = 56.00f + .0066f * value;
	else if (value < 20000.00f)
		commission_1 = 76.00f + .0034f * value;
	else if (value < 50000.00f)
		commission_1 = 100.00f + .0022f * value;
	else if (value < 500000.00f)
		commission_1 = 155.00f + .0011f * value;
	else
		commission_1 = 255.00f + .0009f * value;

	if (commission_1 < 39.0f)
		commission_1 = 39.00f;
        /*计算竞争经纪人的佣金*/
	if (n < 2000)
		commission_2 = 33.30f * n;    /*我觉得这里有歧义，不知道是（33*n+0.3）还是（（33+0.3）*n）*/
	else
		commission_2 = 33.20f * n;
        /*输出*/
	printf ("First:%.2f\nScend:%.2f\n",commission_1,commission_2);

	return 0;
}

4.
#include <stdio.h>

int main(void)
{
  int speed;

  printf("Enter a wind speed in knots: ");
  scanf("%d", &speed);

  if (speed < 1)
    printf("Calm\n");
  else if (speed <= 3)
    printf("Light air\n");
  else if (speed <= 27)
    printf("Breeze\n");
  else if (speed <= 47)
    printf("Gale\n");
  else if (speed <= 63)
    printf("Storm\n");
  else
    printf("Hurricane\n");

  return 0;
}

5.
#include <stdio.h>
int main (void)
{
	float income, taxes;
	
	printf ("Enter the income:");
	scanf ("%f", &income);

	if (income < 750)
		taxes = 750 * .01f;
	else if (income < 2250)
		taxes = 7.50f + (income - 750) * .02f;
	else if (income < 3750)
		taxes = 37.50f + (income - 2250) * .03f;
	else if (income < 5250)
		taxes = 82.50f + (income - 3750) * .04f;
	else if (income < 7000)
		taxes = 142.50f + (income - 5250) * .05f;
	else 
		taxes = 230.000f + (income - 7000) * .06f;

	printf ("The taxes you should pay is %.2f\n",taxes);

	return 0;
}

6.
#include <stdio.h>

int main(void)
{
  int check_digit, d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5,
      first_sum, second_sum, total;

  printf("Enter the first (single) digit: ");
  scanf("%1d", &d);
  printf("Enter first group of five digits: ");
  scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
  printf("Enter second group of five digits: ");
  scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
  printf("Enter the last (single) digit: ");
  scanf("%1d", &check_digit);

  first_sum = d + i2 + i4 + j1 + j3 + j5;
  second_sum = i1 + i3 + i5 + j2 + j4;
  total = 3 * first_sum + second_sum;

  if (check_digit == 9 - ((total - 1) % 10))
    printf("VALID\n");
  else
    printf("NOT VALID\n");

  return 0;
}

7.
#include <stdio.h>
int main (void)
{
	int num_1, num_2, num_3, num_4, max_1, max_2, mim_1, mim_2, max, mim;

	printf ("Enter four intergers: ");
	scanf ("%d %d %d %d", &num_1, &num_2, &num_3, &num_4);
	/*计算第一二个数的大小,注意if语句模板中的“语句”是一条语句，复合语句要用花括号*/
	if (num_1 <= num_2) 
	{
		max_1 = num_2;
	    mim_1 = num_1;
	}
	    else
	{
		max_1 = num_1;
	    mim_1 = num_2;
	}
    /*计算第三四个数的大小*/
	if (num_3 <= num_4)
	{
		max_2 = num_4;
	    mim_2 = num_3;
    }
	else
	{
		max_2 = num_3;
	    mim_2 = num_4;
	}
    /*计算四个数中的最大和最小*/
	if (max_1 <= max_2)
		max = max_2;
	else
		max = max_1;
	if (mim_1 <= mim_2)
		mim = mim_1;
	else
		mim = mim_2;

	printf ("Largest:%d\nSmallest:%d\n", max, mim);

	return 0;
}

8.
#include <stdio.h>
int main (void)
{
	int h, min, time;

	printf ("Enter a 24-hour time:");
	scanf ("%d:%d", &h, &min);

	time = h * 60 + min;

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
/*
就现在而言，这道题难点主要在于编程前的数据处理
  1.先将“起飞时间”全部换成24小时制，计算出所有“起飞时间”从午夜开始的分钟数，分别是：480, 583, 679, 767, 840, 945, 1140, 1305（在这里定义为x1~x8）
  2.将每两个相邻的分钟数相减得出相差的时间，例如，8:00a.m.至9:43a.m.相差（583-480=103）分钟，除以2得（103/2得51.5），注意，9:45p.m.至8:00a.m.中间经过了24:00，计算时是（24*60-1305+480=615），除以2得（615/2的307.5），所以，分别是：51.5, 48, 44, 36.5, 52.5, 97.5, 82.5， 307.5（在这里定义为y1~y8）
  3.假设输入时间在(a1,b1)时间段内与起飞时间为8:00a.m.的飞机最为接近，（a1=x1-y8），（b1=x1+y1），即在（172.5 ，531.5）之间选择8:00a.m.的飞机最为合适，所以得
8:00a.m.（172.5 ，531.5）
9:43a.m.（531.5 ，634.5）
11:19a.m.（634.5 ， 723）
12:47p.m.（723 ， 803.5）
2:00p.m.（803.5 ， 892.5）
3:45p.m.（892.5 ， 1042.5）
7:00p.m.（1042.5 ， 1222.5）
9:45p.m.（1222.5 ，1440）||(0 , 172.5)
  4.其实这个编程不能很好地解决用户的需求，如果我需要在8:40a.m.的飞机，根据计算程序会推荐8:00a.m.起飞的飞机，但是我只需要在我起飞时间在我需求时间之后的航班，这里就显示不出来了，也就是用户不太友好。
*/

9.
#include <stdio.h>
int main (void)
{
	int f_m, f_d, f_y, s_m, s_d, s_y;    /*这里f，s分别表示first和second，m，d，y分别表示mouth，day，year*/

	printf ("Enter first date (mm/dd/yy):");
	scanf ("%d/%d/%d", &f_m, &f_d, &f_y);
	printf ("Enter second date (mm/dd/yy):");
	scanf ("%d/%d/%d", &s_m, &s_d, &s_y);

	if (f_y == s_y) {    /*注意这里用的是判等运算符，很容易错用赋值运算符“=”*/
		if (f_m == s_m) {
			if (f_d == s_d) {
				printf ("%d/%d/%.2d is the same as %d/%d/%.2d\n", f_m, f_d, f_y, s_m, s_d, s_y);
			} else {
				if (f_d < s_d) {
					printf ("%d/%d/%.2d is earlier than %d/%d/%.2d\n", f_m, f_d, f_y, s_m, s_d, s_y);
				} else {
                    printf ("%d/%d/%.2d is earlier than %d/%d/%.2d\n", s_m, s_d, s_y, f_m, f_d, f_y);
				}
			}
		} else {
			if (f_m < s_m) {
				printf ("%d/%d/%.2d is earlier than %d/%d/%.2d\n", f_m, f_d, f_y, s_m, s_d, s_y);
			} else {
				printf ("%d/%d/%.2d is earlier than %d/%d/%.2d\n", s_m, s_d, s_y, f_m, f_d, f_y);
			}
		}
	} else {
		if (f_y < s_y) {
			printf ("%d/%d/%.2d is earlier than %d/%d/%.2d\n", f_m, f_d, f_y, s_m, s_d, s_y);
		} else {
			printf ("%d/%d/%.2d is earlier than %d/%d/%.2d\n", s_m, s_d, s_y, f_m, f_d, f_y);
			}
	}

	return 0;
}

10.
#include <stdio.h>

int main(void)
{
  int grade;

  printf("Enter numerical grade: ");
  scanf("%d", &grade);

  if (grade < 0 || grade > 100) {    /*这里可以直接在switch语句中用default中表示*/
    printf("Illegal grade\n");
    return 0;
  }

  switch (grade / 10) {
    case 10:
    case 9:  printf("Letter grade: A\n");
             break;
    case 8:  printf("Letter grade: B\n");
             break;
    case 7:  printf("Letter grade: C\n");
             break;
    case 6:  printf("Letter grade: D\n");
             break;
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
    case 0:  printf("Letter grade: F\n");
             break;
  }

  return 0;
}

11.
#include <stdio.h>
int main (void)
{
	int num1, num2;

	printf ("Enter a two-digit number:");
	scanf ("%1d%1d", &num1, &num2);

	printf ("You entered the number ");

	if ((num1 * 10 +num2) >= 11 && (num1 * 10 +num2) <= 19) {
		switch (num1 *10 + num2) {
		case 11: printf ("eleven\n"); break;
		case 12: printf ("twelve\n"); break;
		case 13: printf ("thirteen\n"); break;
		case 14: printf ("fourteen\n"); break;
		case 15: printf ("fifteen\n"); break;
		case 16: printf ("sixteen\n"); break;
		case 17: printf ("seventeen\n"); break;
		case 18: printf ("righteen\n"); break;
		case 19: printf ("nineteen\n"); break;
		}
	} else {
		switch (num1) {
		case 1: printf ("ten"); break;
		case 2: printf ("twenty"); break;
		case 3: printf ("thirty"); break;
		case 4: printf ("forty"); break;
		case 5: printf ("fifty"); break;
		case 6: printf ("sixty"); break;
		case 7: printf ("seventy"); break;
		case 8: printf ("eighty"); break;
		case 9: printf ("ninety"); break;
		}
		
		printf ("-");    /*这里其实会出现10的整数倍时会有“-”在结尾，会有点奇怪，不过只要再用多一个if语句就可以解决了*/

		switch (num2) {
		case 1: printf ("first\n"); break;
		case 2: printf ("second\n"); break;
		case 3: printf ("third\n"); break;
		case 4: printf ("fourth\n"); break;
		case 5: printf ("fifth\n"); break;
		case 6: printf ("sixth\n"); break;
		case 7: printf ("seventh\n"); break;
		case 8: printf ("eighth\n"); break;
		case 9: printf ("ninth\n"); break;
		}
	}
	return 0;
}