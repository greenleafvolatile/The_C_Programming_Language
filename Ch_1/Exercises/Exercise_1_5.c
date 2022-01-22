/****************************************************************************
 * Exercise 1-5: Modfythe temperture conversin program to print the table in*
 * reverse order, that is, from 300 degrees to 0.                           *
 * @author Daan Pol                                                         *
 * @version 1.0                                                             *
 * @since 22-01-2022                                                        *
 * **************************************************************************/
#include <stdio.h>

int
main(void) {
    
    int fahr;

    printf("%-10s  %s\n", "Fahrenheit", "Celsius");

    for (fahr = 300; fahr >= 0; fahr -= 20) {

        printf("%-10d  %.2f\n", fahr, 5.0/9.0 * (fahr - 32.0));
    }

    return 0;
}
