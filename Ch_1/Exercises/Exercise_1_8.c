/*********************************************************************
 * Exercise 1-8: Write a program to count blanks, tabs, and newlines.*
 *                                                                   *
 * @author greenleafvolatile                                         *
 * @version 1.0                                                      *
 * @since 31-01-2022                                                 *
 * *******************************************************************/
#include <stdio.h>

int
main(void) {

	int c, blanks, tabs, newlines;
	blanks = tabs = newlines = 0;

	while((c = getchar()) != EOF) {

		if (c == ' ') {
			++blanks;
		} else if (c == '\t') {
			++tabs;
		} else if (c == '\n') {
			++newlines;
		}
	}

	printf("%-10s%d\n%-10s%d\n%-10s%d\n", "Blanks:", blanks, "Tabs:", tabs, "Newlines:", newlines);
	return 0;
}
