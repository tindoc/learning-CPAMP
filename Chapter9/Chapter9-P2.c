#include <stdio.h>

float taxes(float income)
{
    float n;

    if (income < 750)
		n = 750 * .01f;
	else if (income < 2250)
		n = 7.50f + (income - 750) * .02f;
	else if (income < 3750)
		n = 37.50f + (income - 2250) * .03f;
	else if (income < 5250)
		n = 82.50f + (income - 3750) * .04f;
	else if (income < 7000)
		n = 142.50f + (income - 5250) * .05f;
	else
		n = 230.000f + (income - 7000) * .06f;

    return n;
}

int main (void)
{
	float income;

	printf ("Enter the income:");
	scanf ("%f", &income);

	printf ("The taxes you should pay is %.2f\n", taxes(income));

	return 0;
}
