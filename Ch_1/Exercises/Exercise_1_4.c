/*********************************************************************************
 * Exercise 1-4: Write a program to print th ecorresponding Celsius to Fahrenheit*
 * table.                                                                        *
 * @author greenleafvolatile                                                     *
 * @version 1.0                                                                  *
 * @since 22-01-2022                                                             *
 * *******************************************************************************/
#include <stdio.h>

int
main(void) {

    float fahr, celsius;
    int  lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    celsius = lower;
    
    printf("%-7s  %s\n", "Celsius", "Fahrenheit");

    while (celsius <= upper) {
        fahr = (celsius * 9.0 / 5.0) + 32;
        printf("%-7.0f  %.2f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
