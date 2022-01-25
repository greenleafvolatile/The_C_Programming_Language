/*******************************************************************
 * Exercise: 1-3 Modify the temperature conversion program to print*
 * a heading above the table.                                      *
 * @author greenleafvolatile                                       *
 * @version 1.0                                                    *
 * @since 21-01-2022                                               *
 *******************************************************************/
#include <stdio.h>

int
main(void) {

    float fahr, celsius;
    int  lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;

    printf("%-10s %s\n", "Fahrenheit", "Celsius");

    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%-10.0f %.2f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

	
