/****************************************************************************
 * Exercise 1-15: Rewrite the temperature conversion program of Section 1.2 *
 * to use a function for conversion.                                        *
 *                                                                          *
 * @author greenleafvolatile                                                *
 * @version 1.0                                                             *
 * @since 09-02-2022                                                        *
 * **************************************************************************/
#include <stdio.h>

int
convert(int);

int
main()
{
    float fahr, celsius;
    int  lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = convert(fahr);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

int
convert(int fahr)
{
 return (5.0 / 9.0) * (fahr - 32);
}
