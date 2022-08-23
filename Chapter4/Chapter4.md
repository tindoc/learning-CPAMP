Chapter 4

Exercises

1.
(a)1 2
(b)0
(c)1
(d)0

2. 
在C89中不一样. 假设i为9，j为7，(-i)/j的值为–1或者–2, 与具体实现有关；-(i/j)的值为–1。在C99, 两个的值相等。

3.无法通过编程核对，可能会有错
(a)1
(b)-1,-2    /*向上取值为-1，向下取值为-2*/
(c)-1,-2    /*向上取值为-1，向下取值为-2*/
(d)1,2    /*向上取值为2，向下取值为1*/

4.
(a)1    
(b)-1    /*在第三题中，得出两种可能，为-1，-2，-1更为接近0（向零截取），下面同理*/
(c)-1
(d)1

5.无法通过编程核对，可能会有错
(a)3
(b)-3,2
(c)3,-2
(d)-3,2

6.
(a)3
(b)-3
(c)3
(d)-3

7.我的理解如下，不知正确与否（未曾学过%的拆解）
9 - (total - 1) % 10 = 9 - (total % 10 - 1 % 10) = 9 - (total % 10 - 1) = 9 - total % 10 + 1 = 10 - total % 10

8.
正确。
#include <stdio.h>

int main(void)
{
  int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5,
      first_sum, second_sum, total;

  printf("Enter the first (single) digit: ");
  scanf("%1d", &d);
  printf("Enter first group of five digits: ");
  scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
  printf("Enter second group of five digits: ");
  scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);

  first_sum = d + i2 + i4 + j1 + j3 + j5;
  second_sum = i1 + i3 + i5 + j2 + j4;
  total = 3 * first_sum + second_sum;

  printf("Check digit: %d\n", (10 - (total % 10 )) % 10);    /*好像不可通过拆解来等同*/

  return 0;
}

9. 
(a) 63 8 
(b) 3 2 1 
(c) 2 -1 3 
(d) 0 0 0

10.
(a)12 12
(b)3 4
(c)2 8    
/*我使用的是下面的代码来验算，在未输出之前，i应该等于2.5，j应该为8.5，但是在一开试定义了i，j为int型，在最后输出的时候就变成了int型的
#include <stdio.h>

int main(void)
{
  int i, j;

  i = 7;
  j = 6 + (i = 2.5); 

  printf ("%d %d",i, j);

  return 0;
}
*/
(d)6 9

11.
(a)0 2
(b)4 11 6
(c)0 8 7
(d)3 4 5 4

12.
(a)6 16
(b)6 -7
(c)6 23
(d)6 15

13. 
++i。两个表达式的值是i增加后执行。

14.
(a)  (((a * b) - (c * d)) + e)
(b)  (((a / b) % c) / d)
(c)  ((((-a) - b) + c) - (+d))
(d) (((a * (-b)) / c) - d)

15.
(a)i = 3,j = 2
(b)i = 0,j = 2
(c)i = 1,j = 2
(d)i = 1,j = 3

Projects
1.
#include <stdio.h>
int main (void)
{
	int n, digit1, digit2;

	printf ("Enter a two-digit number: ");
	scanf ("%d", &n);

	digit1 = n / 10;
	digit2 = n % 10;

	printf ("The reversal is: %d%d\n",digit2,digit1);

	return 0;
}

2. 
#include <stdio.h>

int main(void)
{
  int n;

  printf("Enter a three-digit number: ");
  scanf("%d", &n);
  printf("The reversal is: %d%d%d\n", n % 10, (n / 10) % 10, n / 100);    

/*
其中的（n / 10） % 10这里真的很妙，减少了很多代码的输入，一般的做法是去除前面的数，例如123提取2会用123-100得23再取余数，这里的做法是去除后面的数，123/10得12，再取余数 
*/

  return 0;
}

3.
#include <stdio.h>
int main (void)
{
	int digit1, digit2, digit3;

	printf ("Enter a three-digit number: ");
	scanf ("%1d%1d%1d", &digit1, &digit2, &digit3);

	printf ("The reversal is: %d%d%d\n",digit3,digit2,digit1);

	return 0;
}

4.
#include <stdio.h>
int main (void)
{
	int number, digit1, digit2, digit3, digit4, digit5;

	printf ("Enter a number between 0 and 32767:");
	scanf ("%d",&number);

	digit5 = number % 8;
	number /= 8;
	digit4 = number % 8;
	number /= 8;
	digit3 = number % 8;
	number /= 8;
	digit2 = number % 8;
	number /= 8;
	digit1 = number % 8;

	printf ("In cotal, your number is: %d%d%d%d%d\n",digit1,digit2,digit3,digit4,digit5);
	
	return 0;
}

5.
#include <stdio.h>
int main (void)
{
	int d, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, total;

	printf ("Enter the first 11 digits of a UPC: ");
	scanf ("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11);
	
	total = (n1 + n3 + n5 + n7 + n9 + n11) * 3 + (n2 + n4 + n6 + n8 + n10);

	printf ("Check digit: %d\n", 9 - ((total - 1) % 10));

	return 0;
}

6.
#include <stdio.h>
int main (void)
{
	int d, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, total;

	printf ("Enter the first 12 digits of an EAN: ");
	scanf ("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11, &n12);
	
	total = (n2 + n4 + n6 + n8 + n10 + n12) * 3 + (n1 + n3 + n5 + n7 + n9 + n11);

	printf ("Check digit: %d\n", 9 - ((total - 1) % 10));

	return 0;
}
