Chapter 9

Exercises

1.
double triangle_area(double base, double height)
{
    double product;
    product = base * height;
    return product / 2;
}

2.
int check(int x, int y, int n)
{
    if (x >= o && x <= n && y > = 0 && y <= n)
	return 1;
    else
	return 0;
}
官方答案：
int check(int x, int y, int n)
{
    return (x >= 0 && x <= n - 1 && y >= 0 && y <= n - 1);
}


3.
int gcd(int m, int n)
{
    int mod;

    while (n != 0) {
	mod = m % n;
	m = n;
	n = mod;
    }

    return m;
}

4.
int day_of_year(int month, int day, int year)
{
    int i, days = 0, mon_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (year % 100 == 0) {
        if (year % 400 == 0)
            mon_days[1]++;
    }
    else {
        if (year % 4 == 0)
            mon_days[1]++;
    }

    for (i = 0; i < month - 1; i++)
        days += mon_days[i];

    return days + day;
}
官方答案：
int day_of_year(int month, int day, int year)
{
  int num_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int day_count = 0, i;

  for (i = 1; i < month; i++)
    day_count += num_days[i-1];

  /* adjust for leap years(闰年), assuming they are divisible by 4 */
  if (year % 4 == 0 && month > 2)
    day_count++;

  return day_count + day;
}

Using the expression year % 4 == 0 to test for leap years is not completely correct. Centuries are special cases: if a year is a multiple of 100, then it must also be a multiple of 400 in order to be a leap year. The correct test is（使用表达式 year % 4 == 0 来检验闰年是不完全正确的。世纪年是特殊的例子:如果该年能够整除100，这还需要能够整除400才是闰年，正确的检验是：）

year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)

5.
int num_digits(int n)
{
    int i;

    for (i = 0; n != 0; i++)
	n /= 10;

    return i;
}

6.
int digit(int n, int k)
{
    int i, digit;

    for (i = 0; i < k; i++) {
	if (n == 0)
	    return 0;
	digit = n % 10;
	n /= 10;
    }

    return digit;
}
官方答案：
int digit(int n, int k)
{
  int i;

  for (i = 1; i < k; i++)    //答案在这里用i=1开头是因为答案中先除以10，再取余数
    n /= 10;

  return n % 10;
}


7.
都是合法的。但是b, c, d得不到理想的结果。

8.
有效的是a, b。
c没有说明形式参数的类型，d没有说明返回类型，C89会假定为int，C99认定为不合法。

9.
经检验，输出的是i = 1, j = 2.
主要还是因为void函数输出的是“空”


10.
(1)
int max(int n, a[n])
{
    int i, max;

    max = a[0];
    for (i = 1; i < n; i++) {
	if (a[i] > max)
	    max = a[i];
    }
    
    return max;
}
(2)
int average(int n, a[n])
{
    int sum = 0, i;

    for (i = 0; i < n; i++)
	sum += a[i];

    return sum / n;
}
(3)
int positive_num(int n, a[n])
{
    int i, num = 0;

    for (i = 0; i < n; i++) {
	if (a[n] > 0)
	    num++;
    }
    return num;
}
官方答案：
(a)
int largest(int a[], int n)
{
  int i, max = a[0];

  for (i = 1; i < n; i++)
    if (a[i] > max)
      max = a[i];

  return max;
}
(b)
int average(int a[], int n)
{
  int i, avg = 0;

  for (i = 0; i < n; i++)
    avg += a[i];

  return avg / n;
}
(c)
int num_positive(int a[], int n)
{
  int i, count = 0;

  for (i = 0; i < n; i++)
    if (a[i] > 0)
      count++;

  return count;
}

11.
float inner_GPA(char grades[], int n）
{
    int i;
    float sum = 0.00;

    for (i = 0; i < n; i++) {
	switch(toupper(grades[i]))
	    case 'A': sum += 4; break;
	    case 'B': sum += 3; break;
	    case 'C': sum += 2; break;
	    case 'D': sum += 1; break;
	    case 'F': sum += 0; break;
	}

    return sum / n;
}

12.
double inner_product(double a[], doouble b[], int n)
{
    int i;
    double sum = 0.00;

    for (i = 0; i < n; i++)
	sum += a[i] * b[i];

    return sum;
}

13.
int evaluate_position(char board[8][8])
{
    int row, col, sum_black = 0, sum_white = 0;

    for (row = 0; row < 8; row++) {
        for (col = 0; col < 8; col++) {
            switch(board[row][col]) {
                case 'K': sum_white += 11; break;    //书中没有给出k或者K的值，我自己假定为11
                case 'Q': sum_white += 9; break;
                case 'R': sum_white += 5; break;
                case 'B':
                case 'N': sum_white += 3; break;
                case 'P': sum_white += 1; break;
                case 'k': sum_black += 11; break;
                case 'q': sum_black += 9; break;
                case 'r': sum_black += 5; break;
                case 'b':
                case 'n': sum_black += 3; break;
                case 'p': sum_black += 1; break;
                default: break;
            }
        }
    }

    return sum_white - sum_black;
}

14.
bool has_zero(int a[], int n)
{
    int i, count_true = 0, count_false = 0;
    
    for (i = 0; i < n; i++) {
        if (a[i] == 0)
            count_true++;
        else
            count_false++;
    }
    
    if (count_true == n)
        return true;
    
    if (count_false == n)
        return false;
}

15.

double median(double x, double y, double z)
{
    double median;
    
    if (x <= y)
        if (y <= z) median = y;
        else if (x <= z) median = z;
        else median = x;
    else {
        if (z <= y) median = y;
        else if (x <= z) median = x;
        else median = z;
  }
        
    return median;
}
官方答案：
double median(double x, double y, double z)
{
  double result;

  if (x <= y)
    if (y <= z) result = y;
    else if (x <= z) result = z;
    else result = x;
  else {
    if (z <= y) result = y;
    else if (x <= z) result = x;
    else result = z;
  }

  return result;
}

16.
int fact(int n)
{
    return n <= 1 ? 1 : n * fact(n - 1);
}

17.
int factorial(int n)
{
    int sum = 1;

    for ( ; n >= 1; n--)
	sum *= n;

    return sum;
}
官方答案：
int fact(int n)
{
  int i, result = 1;

  for (i = 2; i <= n; i++)
    result *= i;

  return result;
}

18.
int gcd(int m, int n)
{
    return n != 0 ? m : gcd(n, m % n);
}

19.
把输入的数 n 以二进制输出
#include <stdio.h>

void pb(int n)
{
    if (n != 0) {
        pb(n / 2);
        putchar('0' + n % 2);
    }
}

int main(void)
{
    int n;

    printf("Enter:");
    scanf("%d", &n);

    pb(n);

    return 0;
}
官方答案：
#include <stdio.h>

void pb(int n);

int main(void)
{
  int n;

  printf("Enter a number: ");
  scanf("%d", &n);

  printf("Output of pb: ");
  pb(n);
  printf("\n");

  return 0;
}

void pb(int n)
{
  if (n != 0) {
    pb(n / 2);
    putchar('0' + n % 2);
  }
}
pb prints the binary representation of the argument n, assuming that n is greater than 0. (We also assume that digits have consecutive codes in the underlying character set.) For example:
（函数pb以二进制打印参数n，在这里假设n是大于0。（我们还假设底层字符集是连续编码的）例如：）

Enter a number: 53
Output of pb: 110101
A trace of pb's execution would look like this:

  pb(53) finds that 53 is not equal to 0, so it calls 
    pb(26), which finds that 26 is not equal to 0, so it calls 
      pb(13), which finds that 13 is not equal to 0, so it calls 
        pb(6), which finds that 6 is not equal to 0, so it calls 
          pb(3), which finds that 3 is not equal to 0, so it calls 
            pb(1), which finds that 1 is not equal to 0, so it calls 
              pb(0), which finds that 0 is equal to 0, so it returns, causing
            pb(1) to print 1 and return, causing
          pb(3) to print 1 and return, causing
        pb(6) to print 0 and return, causing
      pb(13) to print 1 and return, causing
    pb(26) to print 0 and return, causing 
  pb(53) to print 1 and return.