
/***************************************************************************************************************************
 * Exercise 1_6: Verify that the expression getchar() != EOF is 0 or 1.                                                    *
 *                                                                                                                         *
 * @author greenleafvolatile	                                                                                           *
 * @version 1.0                                                                                                            *
 * @since 25-01-2022                                                                                                       *
 *                                                                                                                         *
 * Note: I wanted to capture stdin directly (without buffering).                                                           *
 * The solution I used I found here:                                                                                       *
 * https://stackoverflow.com/questions/1798511/how-to-avoid-pressing-enter-with-getchar-for-reading-a-single-character-only*
 * *************************************************************************************************************************/
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int
main(void) {
	
	int d;
	static struct termios old_t, new_t;

	// Get the parameters of the current terminal and write them to old_t.
	tcgetattr(STDIN_FILENO, &old_t); 

	new_t = old_t; 

	// Turn off the ICANON bit.
	new_t.c_lflag &= ~(ICANON);
	
	// Change the parameters of the current terminal immediately.
	tcsetattr(STDIN_FILENO, TCSANOW, &new_t);
	
	printf("Press any key or CTRl-D to see thee the value of \"getchar() != EOF\":\n");
	while((d = (getchar() != EOF)))
		printf("(getchar() != EOF) == %d\n", d);

	printf("(getchar() != EOF) != %d\n", d);

	// Reset the parameters of the terminal.
	tcsetattr(STDIN_FILENO, TCSANOW, &old_t);

	return 0;
}


