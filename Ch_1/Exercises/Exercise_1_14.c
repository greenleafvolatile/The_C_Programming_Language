/****************************************************************************
 * Exercise 1-14: Write a program to print a histogram of the frequencies of*
 * different characters in its input.                                       *
 *                                                                          *
 * @author greenleafvolatile                                                *
 * @version 1.0                                                             *
 * @since 08-02-2022                                                        *
 * **************************************************************************/
#include <stdio.h>

int
main(void) 
{
    int c;
    int chars[94] = {0}; // Using ASCII code, exclude control and extended codes.

    while ((c = getchar()) != EOF) 
        ++chars[c - '!'];

    for (int i = '!'; i <= '~'; ++i) {
        printf("[%c]:", i);
        for (int j = 0; j < chars[i - '!']; ++j) 
            putchar('*');
        putchar('\n');
    }
    return 0;
}


