
/***********************************************************************
 * Exercise 1_6: Verify that the expression getchar() != EOF is 0 or 1 *
 *                                                                     *
 * @author greenleafvolatile	                                       *
 * @version 1.0                                                        *
 * @since 25-01-2022                                                   *
 * *********************************************************************/
#include <stdio.h>

int
main(void) {
	
	printf("Input any character of EOF to see the value of getchar() != EOF: ");
	printf("The value of getchar() != EOF == %d\n", getchar() != EOF);

	return 0;
}


