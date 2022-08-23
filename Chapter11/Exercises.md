Chapter 11

Exercises

1.****************************************
(a), (c), (g)是i的别名。(c)主要是因为是指向指针的指针，再返回到原始变量还是i。（P173）

2.****************************************
(e), (f), (i)是合法的。(e)也是因为是指向指针的指针。
官方答案：
(e), (f), and (i) are legal. (a) is illegal because p is a pointer to an integer and i is an integer. (b) is illegal because *p is an integer and &i is a pointer to an integer. (c) is illegal because &p is a pointer to a pointer to an integer and q is a pointer to an integer. (d) is illegal for reasons similar to (c). (g) is illegal because p is a pointer to an integer and *q is an integer. (h) is illegal because *p is an integer and q is a pointer to an integer.
(e), (f) 和 (i)是合法的。
(a)是不合法的，因为p是一个指向int类型对象的指针但i是一个整型。
(b)是不合法的，因为*p是一个整型但&i是一个指向int类型对象的指针。
(c)是不合法的，因为&p是一个指向（指向int类型对象的指针）的指针但q是一个指向int类型对象的指针。
(d)与c一样的原因。
(g)是不合法的，因为p是一个指向int类型对象的指针但*q是一个整型。
(h)是不合法的，因为*p是一个整型但q是一个指向int类型对象的指针。

3.****************************************
主要错误是函数体内的sum和avg都没有加*
void avg_sum(double a[], int n, double *avg, double *sum)
{
    int i;

    *sum = 0.0;
    for (i = 0; i < n; i++)
      *sum += a[i];
    *avg = *sum / n;
}

4.****************************************
void swap(int *p, int *q)
{
    int temp;
    
    temp = *p;
    *p = *q;
    *q = temp;
}
官方答案：
void swap(int *p, int *q)
{
  int temp;

  temp = *p;
  *p = *q;
  *q = temp;
}

5.****************************************
void split_time(long total_sec, int *hr, int *min, int *sec)
{
    *hr = total_sec / (60 * 60);
    *min = (total_sec - *hr * 60 * 60) / 60;
    *sec = total_sec - *hr * 60 * 60 - *min * 60;
}
下面是测试用的main函数
int main(void)
{
    long total_sec;
    int hr, min, sec;    //注意这里是int变量，不需要指针变量

    printf("Enter: ");
    scanf("%ld", &total_sec);

    split_time(total_sec, &hr, &min, &sec);

    printf("%d, %d, %d\n", hr, min, sec);

    return 0;
}

6.****************************************
void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
    int i;

    if (a[0] > a[1]) {
        *largest = a[0];
        *second_largest = a[1];
    }
    else {
        *largest = a[1];
        *second_largest = a[0];
    }

    for (i = 2; i < n; i++)
        if (a[i] > *largest) {
            *second_largest = *largest;
            *largest = a[i];
        }
        else if (a[i] > *second_largest)
            *second_largest = a[i];
}
官方答案：
void find_two_largest(int a[], int n, int *largest,
                      int *second_largest)
{
  int i;

  if (a[0] > a[1]) {
    *largest = a[0];
    *second_largest = a[1];
  } else {
    *largest = a[1];
    *second_largest = a[0];
  }

  for (i = 2; i < n; i++)
    if (a[i] > *largest) {
      *second_largest = *largest;
      *largest = a[i];
    } else if (a[i] > *second_largest)
      *second_largest = a[i];
}

7.****************************************
void split_data(int day_of_year, int year, int *month, int *day)
{
    int day_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i;

    *day = day_of_year;
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))    //第八章练习题第四题
        day_of_month[1] = 29;

    for (i = 0; day_of_year >= 28; i++)
        day_of_year -= day_of_month[i];

    if (day_of_year > 0)
        *month = i + 1;
    else
        *month = i;

    for (i = 0; i < *month - 1; i++)
        *day -= day_of_month[i];

    *day++;
}
下面是测试用的main函数int main(void)
{
    int day_of_year, year, month, day;

    printf("Enter the year: ");
    scanf("%d", &year);

    printf("Enter the day_of_year: ");
    scanf("%d", &day_of_year);

    while (day_of_year <= 366) {
        split_data(day_of_year, year, &month, &day);
        printf("%d, %d\n", month, day);

        printf("Enter the day_of_year: ");
        scanf("%d", &day_of_year);
    }

    return 0;
}

8.****************************************
//来自第10章编程题第3题中的sort cards by rank
int *find_largest(int a[], int n)
{
    int i, temp, pass = n;

    for (; pass > 1; pass--)
        for (i = 0; i < n - 1; i++)
            if (a[i + 1] < a[i]) {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }

    return &a[n - 1];
}
下面是测试用的main函数int main(void)
int main(void)
{
    int a[5] = {23, 54, 67, 2, 42};

    printf("%d", *find_largest(a, 5));    //注意这里的表达式

    return 0;
}