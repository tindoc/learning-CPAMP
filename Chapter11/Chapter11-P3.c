#include <stdio.h>

/* prototype */
void reduce(int numerator, int denominator,
            int *reduced_numerator, int *reduced_denominator);

int main(void)
{
    int m, n, reduced_m, reduced_n;

    printf("Enter a fraction: ");
    scanf("%d/%d", &m, &n);

    reduce(m, n, &reduced_m, &reduced_n);

    printf("In lowest terms: %d/%d\n", reduced_m, reduced_n);

    return 0;
}

/**************************************************
  Function: reduce
  Description:  count the GCD, reduce the numerator
                and denominator
  Calls:
  Called by:    main
  Input:
  Output:
  Return:
  Others:
 **************************************************/
void reduce(int numerator, int denominator,
            int *reduced_numerator, int *reduced_denominator)
{
    int mod, m, n;

    m = numerator;
    n = denominator;

    while (n != 0) {
        mod = m % n;
        m = n;
        n = mod;
    }

    *reduced_numerator = numerator / m;
    *reduced_denominator = denominator / m;
}
