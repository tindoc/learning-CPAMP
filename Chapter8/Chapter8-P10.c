#include <stdio.h>

int main(void)
{
	int h, min, time, i, difference, difference_mim, mim = 0;
	int takeoff[8] = {480, 583, 679, 767, 840, 945, 1140, 1305};
	int landing[8] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

	printf ("Enter a 24-hour time:");
	scanf ("%d:%d", &h, &min);

	time = h * 60 + min;

	printf ("Closest departure time is ");

    //假设输入的时间与第一个时间之差为最小值
    difference_mim = takeoff[0] - time;
    //在这里使用绝对值说明输入时间可以在最接近起飞时间的前面和后面
    if (difference_mim < 0)
        difference_mim = -difference_mim;

	for (i = 1; i < 8; i++) {
        difference = takeoff[i] - time;
        if (difference < 0)
            difference = -difference;
        if (difference < difference_mim) {
            difference_mim = difference;
            mim = i;    //使用mim来储存当时间差为最小时是第几个数组
        }
	}

	printf("%d:%d", takeoff[mim] / 60, takeoff[mim] - takeoff[mim] / 60 * 60);

	return 0;
}

//如果是要求的是距离输入时间最近的且在输入时间之前的时间的话
//从a[0]开始执行循环
//确保time - takeoff[i] < 0 即可输出i了
//之前第五章的时候想过这个问题
//最好的解决办法是，显示最接近输入时间的前面和后面的两个数，让用户自由选择
