Chapter 12

Exercises

1.****************************************
(a)14
(b)34
(c)1
(d)true    //在这里要注意一个问题，在数学中p<q可以转换为p-q<0,但是在这里比较指针不可以这样转换，因为p-q的运算结果只有0或者1（在这里为0），0<0是false的，指针的比较依赖于数组中两个元素的相对位置
(e)false

2.****************************************
指针算术运算中没有两个指针相加的运算
改：
*middle = (*low + *high) / 2;
官方答案：
The statement is illegal because pointers cannot be added. Here's a legal statement that has the desired effect:（语句是不合法的因为指针不能相加。下面是具有一样作用的合法语句：）
middle = low + (high - low) / 2;
The value of (high - low) / 2 is an integer, not a pointer, so it can legally be added to low.（(high - low) / 2的值是一个int类型值，不是指针，所以加给low是合法的）

3.****************************************
a[N] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}

4.****************************************
void make_empty(void）
{
    top_ptr = &contents[0];
}

bool is_empty(void)
{
    return top_ptr == &contents[0];
}

bool is_full(void)
{
    return top_ptr == &contents[STACK_SIZE];
}
官方答案：
int *top_ptr;

void make_empty(void)
{
  top_ptr = &contents[0];
}

bool is_empty(void)
{
  return top_ptr == &contents[0];
}

bool is_full(void)
{
  return top_ptr == &contents[STACK_SIZE];
}

5.****************************************
不合法：a, d
为真：b，c

6.****************************************
int sum_array(const int a[], int n)
{
    int *p, sum;
    
    sum = 0;
    for (p = a; p < a + n; p++)
        sum += *p;
    return sum;
}
官方答案：
int sum_array(const int a[], int n)
{
  int *p, sum;

  sum = 0;
  for (p = a; p < a + n; p++)
    sum += *p;
  return sum;
}

7.****************************************
bool search(const int a[], int n, int key)
{
    int *p;

    for (p = a; p < a + n; p++)
        if (*p == key)
	    return true;

    return false;
}

8.****************************************
void store_zeros(int a[], int n)
{
    int *p;

    for (p = a; p < n; p++)
    	*p = 0;
}

9.****************************************
double inner_product(const int *a, const int *b, int n)
{
    double result = 0.0f;
    int i = 0;

    while (i++ < n)
        result += ((*a++) * (*b++));

    return result;
}

10.****************************************
int *find_middle(int a[], int n)
{
    return a + n / 2;
}

11.****************************************
int find_largest(int a[], int n)
{
    int i, max;

    max = a[0];
    for (i = 1; i < n; i++)
        if (*(a + i) > max)
        max = *(a + i);

    return max;
}

12.****************************************
void find_two_largest(const int *a, int n, int *largest, int *second_largest)
{
    int i;

    if (a[0] < a[1]) {
        *largest = *(a + 1);
        *second_largest = *a;
    }

    for (i = 2; i < n; i++) {
        if (*(a + i) > *largest) {
            *second_largest = *largest;
            *largest = *(a + i);
        }
        else if (*(a + i) > *second_largest)
            *second_largest = *(a + i);
    }
}

13.****************************************
#define N 10

double ident[N][N], *p = &ident[0][0];
int i, n = 0;

ident[0][0] = 1.0;
for (i = 1; i < N * N; i++) {
    if  (n == 10) {
        *(p + i) = 1.0;
        n = 0;
    }
    else {
        *(p + i) = 0.0;
        n++;
    }
}
官方答案：
#define N 10

double ident[N][N], *p;
int num_zeros = N;

for (p = &ident[0][0]; p <= &ident[N-1][N-1]; p++)
  if (num_zeros == N) {
    *p = 1.0;
    num_zeros = 0;
  } else {
    *p = 0.0;
    num_zeros++;
  }

14.****************************************
search(temperatures, 7 * 24, 32);

15.****************************************
int *p;

for (p = temperatures[i]; p < temperatures[i] + 24; p++)
    printf("%d ", *p);
官方答案：
int *p;

for (p = temperatures[i]; p < temperatures[i] + 24; p++)
  printf("%d ", *p);

16.****************************************
int i = 0, (*p)[24];    //这里声明的p是指向长度为24的整型数组的指针，见P192

for (p = temperatures[0]; p < &temperatures[7]; p++)
    printf("Largest is: %d\n", find_largest(p, 24));

17.****************************************
int sum_two_dimensional_array(const int a[][LEN], int n)
{
    int *p, sum = 0;

    for (p = a[0]; p < &a[n][LEN]; p++)
	sum += *p;
    
    return sum;
}

18.****************************************
int evaluate_position(char board[8][8])
{
    int sum_black = 0, sum_white = 0;
    char *p;

    for (p = board[0]; p < &board[8][8]; p++) {
        switch(*p) {
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

    return sum_white - sum_black;
}