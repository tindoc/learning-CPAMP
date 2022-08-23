Chapter 13

Exercises

1.****************************************
(a)true
(b)false  输出了"\"(输出内容为""内内容，不包括"",下同)
(c)false  程序无法运行
(d)true
(e)false  程序无法运行
(f)true
(g)true
(h)false  输出了"\"
(i)false  程序无法运行
(j)false  输出了两个换行符
(k)true
解释：
这道题目需要了解字符常量与字符串字面量的区别，putchar、puts输出的内容是什么
(b)转换字符%c是将后面表达式转换为一个字符输出，由于'\n'就是一个表示换行的字符常量，而"\n"是一个字符串字面量，由两个字符常量（"\","n")组成，所以在输出的时候就只是输出了"\"（注意，如果输出了\n还是具有换行的效果，见(d),决定换行的是\n，与外面的''或者""无关）
(c)因为'\n'是字符常量，%s是“把字符串读入字符数组”，格式不对
(e)是因为如果没有按照printf的格式，格式串需要使用""括起来，如果为"'\n'"就是正确的，不过会在原行末输出一个',新行头输出一个'
(h)putchar函数的格式为 putchar(字符)，所以输出的是一个字符，因为"\n"有两个字符组成，所以就只输出了\
(i)puts函数的格式为 puts(字符串) ，因为'\n'是字符常量，不是字符串
(j)因为puts函数在写完字符串后会额外添加一个换行符，所以在这里出现了两个（P203）

2.****************************************
(a)不合法，putchar函数的格式为 putchar(字符)，但是p为指针变量（ps：printf函数的格式为printf(const char *,...)
(b)合法，输出结果为a
(c)合法，输出结果为abc
(d)不合法，put函数的格式为 puts(const char*),但是*p是常量
官方答案：
(a) Illegal; p is not a character.
(b) Legal; output is a.
(c) Legal; output is abc.
(d) Illegal; *p is not a pointer.

3.****************************************
i = 12; s = abc34; j = 空;
i = 56; s = def78; j = 空;  
这道题我使用以下程序无法运行，所以上面结果不是很确定
#include <stdio.h>

int main(void)
{
    int i, j;
    char *s;

    scanf("%d%s%d", &i, s, &j);
    printf("%d\n%s\n%d", i, s, j);

    return 0;
}

4.****************************************
(a)
int read_line_a(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != ' ');
        break;

    while (ch != '\n') {
        if (i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';

    return i;
}
(b)
int read_line_b(char str[], int n)
{
    int ch, i = 0;

    while (!isspace(ch = getchar()))
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';

    return i;
}
(c)
int read_line_c(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\n';
    str[i + 1] = '\0';

    return i;
}
(d)
见答案，感觉上题目的意思不是很清晰，(c)和(d)是一样。
官方答案：
(a)
int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i == 0 && isspace(ch))
      ;   /* ignore */
    else if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
(b)
int read_line(char str[], int n)
{
  int ch, i = 0;

  while (!isspace(ch = getchar()))
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
(c)
int read_line(char str[], int n)
{
  int ch, i = 0;

  do {
    ch = getchar();
    if (i < n)
      str[i++] = ch;
  } while (ch != '\n');
  str[i] = '\0';
  return i;
}
(d)
int read_line(char str[], int n)
{
  int ch, i;

  for (i = 0; i < n; i++) {
    ch = getchar();
    if (ch == '\n')
      break;
    str[i] = ch;
  }
  str[i] = '\0';
  return i;
}

5.****************************************
(a)
char *capitalize(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
        s[i] = toupper(s[i]);

    return s;
}
(b)
char *capitalize(char s[])
{
    char *p;
    int i = 0;

    for (p = s; *s != '\0'; i++, s++)
        *(p + i) = toupper(*s);

    return p;
}

6.****************************************
char *censor(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
    if (s[i] == 'f' && s[i + 1] == 'o' && s[i + 2] =='o')
        s[i] = s[i + 1] = s[i + 2] = 'x';

    return s;
}
官方答案：
void censor(char s[])
{
  int i;

  for (i = 0; s[i] != '\0'; i++)
    if (s[i] == 'f' && s[i+1] == 'o' && s[i+2] =='o')
      s[i] = s[i+1] = s[i+2] = 'x';
}
Note that the short-circuit evaluation of && prevents the if statement from testing characters that follow the null character.（注意&&的短路效应阻止if语句测试遵循null字符的字符）
不知道上面这是什么意思。

7.****************************************
(c)与其他三条语句不等价。
其他三条语句都是输出一个换行符，(c)是因为strcpy函数把后面的字符复制到前面直到遇到'\0',因为后面的字符中没有，所以无法运行，而strcat函数会自动将后面的字符以及其中的'\0'复制到前面的字符中

8.****************************************
tire-bouchon
tired-or-wi
tired-or-wired?
官方答案：
tired-or-wired?
解释：因为strcpy函数把后面的字符复制到前面直到遇到'\0'，在这里还会将这个'\0'也复制上去，所以后面的n就被抛弃了

9.****************************************
computers
因为经过if判断之后，s1为"computerscience"，strlen(s1)=15，s1[9] = '\0',又因为s1[9]为"c"，所以"c"后面的以及"c"本身就被抛弃了

10.****************************************
没有初始化q，将会导致strcpy函数无法执行，因为找不到'\0'
官方答案：
The value of q is undefined, so the call of strcpy attempts to copy the string pointed to by p into some unknown area of memory. Exercise 2 in Chapter 17 discusses how to write this function correctly.（q是未定义的值,所以strcpy函数会试图复制字符串到一些未知区域的内存。第十七章中的练习题2讨论了如何正确地编写这个函数。）

11.****************************************
int strcmp_2(char *s, char *t)
{
    int i;

    for (i = 0; *(s + i) == *(t + i); i++)
        if (*(s + i) == '\0')
            return 0;
    return *(s + i) - *(t + i);
}

12.***************************************
void get_extension(const char *file_name, char *extension)
{
    // get extension after "." //
    int i = 0;
    while (file_name[i] != '.') {
        if (file_name[i] != '\0')
            i++;
        else {
            i = strlen(file_name);
            break;
        }
    }

    strcpy(extension, &file_name[i + 1]);
}
另一种实现：
void get_extension(const char *file_name,char *extension)  
{  
    int i=0,length;  
    length=strlen(file_name);  
        while(file_name[i])  
    {  
        if(file_name[i]=='.')  
        break;  
        i++;  
    }  
    if(i<length)  
    strcpy(extension,file_name+i+1);  
    else  
    strcpy(extension,"\0");  
}  
来自：http://blog.csdn.net/wuweiweinanjing/article/details/6978758

13.****************************************
void build_index_url(const char *domain, char *index_url)
{
    char url[100] = "http://www.";

    strcat(url, domain);
    strcat(url, "/index.html");

    strcpy(index_url, url);
}
要时刻注意domain的const属性

14.****************************************
Grinch
见P187

15.****************************************
(a)3  f函数return的是"d" - "abcd"（注意一件事，如果单单是printf("%d", "d" - "abcd")得到的结果不一定是3）
(b)0  f函数return的是"abcd" - "abcd"
(c)The length of the longest prefix of the string s that consists entirely of characters from the string t. Or, equivalently, the position of the first character in s that is not also in t.(字符串s包含字符串t中的字符数目。或者,同样,s的第一个字符不在t字符串中。)

16.**************************************** 
int count_spaces(const char *s)
{
  int count = 0;

  while (*s)
    if (*s++ == ' ')    //++不可以放在while后面的*s
      count++;
  return count;
}

17.****************************************
bool test_extension(const char *file_name, const char *extension)
{
    while (*file_name != '.')
        if (*file_name)
            file_name++;
        else
            return false;

    while (*file_name) {
        if (toupper(*(file_name + 1)) != toupper(*extension))
            return false;
        file_name++;
        extension++;
    }

    return true;
}
记得#include <stdbool.h>

18.****************************************
void remove_filename(char *url)
{
    int i, len = strlen(url);

    for (i = 0; i <= len; i++)
        if (url[len - i] == '/') {
            url[len - i] = '\0';
            break;
        }

    puts(url);
}
注意调用函数时，remove_filename(str)而不可以直接remove_filename("http://.....")
详情见：http://bbs.csdn.net/topics/392013587?page=1#post-401546258