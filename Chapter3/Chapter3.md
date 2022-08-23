Chapter 3

Exercises
1.
(a)····64，1040    /*这里用·表示空格*/
(b)3.02530e+001    /*其实我原来的答案是0.30253e+002，考虑到m可以自动扩展，看来m的自动扩展是在迫不得已的情况下才成立的，又或者指数来说，个位一般不为单独的0*/
(c)83.1620
(d)1e-006    /*这道题不是很理解，但是vc6.0出来的结果就是这个*/

2.
(a) printf("%-8.1e", x);
(b) printf("%10.6e", x);
(c) printf("%-8.3f", x);
(d) printf("%6.0f", x);

3.
(a)Y.
(b)N.
输入1·-2·-3可以检验结果（这里用·表示空格），”%d-%d-%d”输出不了正确的数字，主要是因为”%d-%d-%d”在遇到1·-2·-3时是这样处理的，%d可以成功取到1的值，但是接下来的减号和空格两个字符不匹配，就异常退出了，详见31页“格式串的普通字符”-“其他字符”。
#include <stdio.h>
int main (void)
{
int x,y,z;

	printf ("Input: ");
	scanf ("%d -%d -%d",&x,&y,&z);    /* or scanf(“%d-%d-%d”,&x,&y,&z); */

	printf ("%d%d%d\n",x,y,z);

	return 0;
}
(c)Y.
(d)Y.
如果是遇到0.1,·0.2这种情况下，电脑是如何处理的，先用”%f,%f”来说明，主要是逗号后面的解释，这里就像是(a)的情况了，在寻找第二个小数的时候，会自动跳过空格，也就匹配到了0.2，就像31页格式串的普通字符”-“其他字符”下面的那个例子；再来说说”%f, %f”的处理，也是从逗号后面开始说，格式串中有一个空白字符（空格），那么就会在输入中读取空白字符直到遇到非空白字符放回原处，现在读取到的是0.2里面的0是非空白字符，所以0.2就放回原处了，接下来的%f就会匹配0.2，所以这个空格也就不影响到取值，如果在输入中没有空格呢，就会按照“格式串中的一个空白字符可以与输入中任意数量的空白字符相匹配，包括零个”来处理。

4.
I = 10; x = 0.300000; j = 5

5.
The values of x, i, and y will be 12.3, 45, and .6, respectively.

6.
#include <stdio.h>

int main(void)
{
int num1, denom1, num2, denom2, result_num, result_denom;

printf("Enter first fraction: ");
scanf("%d / %d", &num1, &denom1);    /*只要在/前后加上空格就可以了*/

printf("Enter second fraction: ");
scanf("%d / %d", &num2, &denom2);    /*只要在/前后加上空格就可以了*/

result_num = num1 * denom2 + num2 * denom1;
result_denom = denom1 * denom2;
printf("The sum is %d/%d\n", result_num, result_denom);

return 0;
}

Programming Projects
1.
#include <stdio.h>

int main(void)
{
int month, day, year;

printf("Enter a date (mm/dd/yyyy): ");
scanf("%d/%d/%d", &month, &day, &year);
printf("You entered the date %d%.2d%.2d\n", year, month, day);

return 0;
}

2.
#include <stdio.h>

int main(void)
{
int item, month, day, year;
float price;

printf ("Enter item number: ");
scanf ("%d",&item);

printf ("Enter unit price: ");
scanf ("%f",&price);

printf ("Enter purchase date (mm/dd/yyyy): ");
scanf ("%d/%d/%d",&month,&day,&year);

printf ("Item\tUnit\tPurchase\n\tPrice\tDate\n%-d\t$%7.2f%d/%d/%d\n",item,price,month,day,year);    /*这里有两个问题要注意，一是Price的输出用的是%7.2f，因为题目中指出价格的最大取值为9999.99，共七个字符宽度和两个小数，第二是为什么不是"Item\tUnit\tPurchase\n\tPrice\tDate\n%-d\t$%7.2f/t%d/%d/%d\n",注意%7.2f后面\t，为什么不要呢，在这里发现了一个问题，这里的\t无法识别出前面的字符，可能是因为前面既有普通字符$又有引用字符%7.2f ，所以最终的结果是\t默认了前面没有字符，空留了8个空格，将代码换进去就会知道了，所以对制表符的了解还不是很清楚，不过不要\t就可以达到题目的要求*/

return 0;
}

3.
#include <stdio.h>

int main(void)
{
int prefix, group, publisher, item, check_digit;

printf("Enter ISBN: ");
scanf("%d-%d-%d-%d-%d", &prefix, &group, &publisher, &item, &check_digit);    /*要达到题目中所说的每组中的数字的个数是可变的，只要不在d前面限定字符宽度m就可以了*/

printf("GS1 prefix: %d\n", prefix);
printf("Group identifier: %d\n", group);
printf("Publisher code: %d\n", publisher);
printf("Item number: %d\n", item);
printf("Check digit: %d\n", check_digit);

/* The five printf calls can be combined as follows:

     printf("GS1 prefix: %d\nGroup identifier: %d\nPublisher code: %d\nItem number: %d\nCheck digit: %d\n",
            prefix, group, publisher, item, check_digit);
*/

return 0;
}

4.
#include <stdio.h>
int main (void)
{
int x, y, z;

	printf ("Enter phone number [(xxx) xxx-xxxx]: ");
	scanf ("(%d) %d-%d",&x,&y,&z);

	printf ("You entered %d.%d.%d\n",x,y,z);
	
	return 0;
}

5.超级讨厌的第五题，声明了16个变量，暂时还没有更为简单的方法
#include <stdio.h>
int main (void)
{
int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12, num13, num14, num15, num16;
int row1, row2, row3, row4, column1, column2, column3, column4, diagonal1, diagonal2;

	printf ("Enter the numbers from 1 to 16 in any order: ");
	scanf ("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&num1,&num2,&num3,&num4,&num5,&num6,&num7,&num8,&num9,&num10,&num11,&num12,&num13,&num14,&num15,&num16);
    /*计算每行的结果*/
	row1 = num1 + num2 + num3 + num4;
	row2 = num5 + num6 + num7 + num8;
	row3 = num9 + num10 + num11 + num12;
	row4 = num13 + num14 + num15 + num16;
    /*计算每列的结果*/
	column1 = num1 + num5 + num9 + num13;
	column2 = num2 + num6 + num10 + num14;
	column3 = num3 + num7 + num11 + num15;
	column4 = num4 + num8 + num12 + num16;
    /*计算对角线的结果*/
	diagonal1 = num1 + num6 + num11 + num16;
	diagonal2 = num4 + num7 + num10 + num13;

	printf ("%2d %2d %2d %2d\n%2d %2d %2d %2d\n%2d %2d %2d %2d\n%2d %2d %2d %2d\n",num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12, num13, num14, num15, num16);
	printf ("Row sums: %d %d %d %d\nColumn sums: %d %d %d %d\nDiaginal sums: %d %d\n",row1, row2, row3, row4, column1, column2, column3, column4, diagonal1, diagonal2);

	return 0;
}

6.
#include <stdio.h>

int main(void)
{
int num1, denom1, num2, denom2, result_num, result_denom;

printf (“Enter two fractions separated by a plus sign: “);
scanf (“%d/%d+%d/%d”,&num1,&denom1,&num2,&denom2);

result_num = num1 * denom2 + num2 * denom1;
result_denom = denom1 * denom2;
printf("The sum is %d/%d\n", result_num, result_denom);

return 0;
}
