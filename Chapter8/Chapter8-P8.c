#include <stdio.h>

#define M 5
#define N 5

int main(void)
{
    int a[M][N],m, n;
    int sum_gra = 0, sum_lesson = 0, lesson_highest, lesson_lowest;
    float average_gra, average_lesson;

    //读取5个学生的5门成绩
    for (m = 0; m < M; m++) {
        printf("Enter the grades of student%d: ", m + 1);
        for (n = 0; n < N; n++)
            scanf("%d", &a[m][n]);
    }

    //计算并输出每一个学生的总分和平均分
    for (m = 0; m < M; m++) {
        printf("Student%d grade totals: ", m + 1);
        for (n = 0; n < N; n++) {
            sum_gra += a[m][n];
        }
        average_gra = sum_gra / (float)N;    //需要强制转换为float类型
        printf("%d average is: %.2f\n", sum_gra, average_gra);
        sum_gra = 0;
    }

    //计算并输出每门成绩的平均分，最高，最低分
    for (n = 0; n < N; n++) {
        printf("The average of lesson%d is: ", n + 1);
        lesson_highest = lesson_lowest = a[0][n];    //初始化最大最小值为每列的第一个值
        for (m = 0; m < M; m++) {
            sum_lesson += a[m][n];
            if (a[m][n] >= lesson_highest)
                lesson_highest = a[m][n];
            if (a[m][n] <= lesson_lowest)
                lesson_lowest = a[m][n];
        }
        average_lesson = sum_lesson / (float)M;
        printf("%.2f The highest is %d The lowest is %d\n", average_lesson, lesson_highest, lesson_lowest);
        sum_lesson = 0;
    }


    return 0;
}


//官方答案
//#include <stdio.h>
//
//#define NUM_QUIZZES  5
//#define NUM_STUDENTS 5
//
//int main(void)
//{
//  int grades[NUM_STUDENTS][NUM_QUIZZES];
//  int high, low, quiz, student, total;
//
//  for (student = 0; student < NUM_STUDENTS; student++) {
//    printf("Enter grades for student %d: ", student + 1);
//    for (quiz = 0; quiz < NUM_QUIZZES; quiz++)
//      scanf("%d", &grades[student][quiz]);
//  }
//
//  printf("\nStudent  Total  Average\n");
//  for (student = 0; student < NUM_STUDENTS; student++) {
//    printf("%4d      ", student + 1);
//    total = 0;
//    for (quiz = 0; quiz < NUM_QUIZZES; quiz++)
//      total += grades[student][quiz];
//    printf("%3d     %3d\n", total, total / NUM_QUIZZES);
//  }
//
//  printf("\nQuiz  Average  High  Low\n");
//  for (quiz = 0; quiz < NUM_QUIZZES; quiz++) {
//    printf("%3d     ", quiz + 1);
//    total = 0;
//    high = 0;
//    low = 100;
//    //答案充分利用了题目的特殊性
//    //因为就成绩而言，0是最小的，100是最大的
//    //因此不需要给high和low初始化数组的值
//    for (student = 0; student < NUM_STUDENTS; student++) {
//      total += grades[student][quiz];
//      if (grades[student][quiz] > high)
//        high = grades[student][quiz];
//      if (grades[student][quiz] < low)
//        low = grades[student][quiz];
//    }
//    printf("%3d    %3d   %3d\n", total / NUM_STUDENTS, high, low);
//  }
//
//  return 0;
//}
