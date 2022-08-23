#include <stdio.h>

/* prototype */
void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void)
{
	int h, min, time, departure_time, arrival_time;

	printf ("Enter a 24-hour time:");
	scanf ("%d:%d", &h, &min);

	time = h * 60 + min;

	find_closest_flight(time, &departure_time, &arrival_time);

	printf("Closest departure time is %d:%.2d, ", departure_time / 60,
            departure_time - departure_time / 60 * 60);
    printf("arrival at %d:%.2d", arrival_time / 60,
           arrival_time - arrival_time / 60 * 60);

	return 0;
}

/**********************************************************************
  Function: find_closest_flight
  Description:  find the closest flight and put the time of departure
                and arrival in the PointVariable
  Calls:
  Called by:
  Input:
  Output:
  Return:
  Others:
 **********************************************************************/
void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
    if (desired_time < 531.5f && desired_time >= 172.5f) {
        *departure_time = 480;
        *arrival_time = 616;
    }
	else if (desired_time < 634.5f && desired_time >= 531.5f) {
        *departure_time = 583;
        *arrival_time = 712;
	}
	else if (desired_time < 723.0f && desired_time >= 634.5f) {
        *departure_time = 679;
        *arrival_time = 811;
	}
	else if (desired_time < 803.5f && desired_time >= 723.0f) {
        *departure_time = 767;
        *arrival_time = 900;
	}
	else if (desired_time < 892.5f && desired_time >= 803.5f) {
        *departure_time = 840;
        *arrival_time = 968;
	}
	else if (desired_time < 1042.5f && desired_time >= 892.5) {
        *departure_time = 945;
        *arrival_time = 1075;
	}
	else if (desired_time < 1222.5 && desired_time >= 1042.5f) {
        *departure_time = 1140;
        *arrival_time = 1280;
	}
	else {
        *departure_time = 1305;
        *arrival_time = 1438;
	}
}
