/******************************************************************
 * Exercise 1-9: Write a program to copy its input to its output, *
 * replacing each string of one or more blanks by a single blank. *
 *                                                                *
 * @author greenleafvolatile                                      *
 * @version 1.0                                                   *
 * @since 31-01-2022                                              *
 * ****************************************************************/
#include <stdio.h>

int
main(void) {

	int curr_char, prev_char = ' ';

	while ((curr_char = getchar()) != EOF) {

		if (curr_char != ' ' || prev_char != ' ') {
			putchar(curr_char);
		}
		prev_char = curr_char;
	}

	return 0;
}

		



