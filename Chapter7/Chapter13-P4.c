#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    for (i = argc - 1; i > 0; i--)
        printf("%s ", argv[i]);

    return 0;
}


//官方答案：
//#include <stdio.h>
//
//int main(int argc, char *argv[])
//{
//  int i;
//
//  for (i = argc - 1; i > 0; i--)
//    printf("%s ", argv[i]);
//  printf("\n");
//
//  return 0;
//}
