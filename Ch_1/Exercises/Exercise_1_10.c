/******************************************************************
 * Exercise 1-10: Write a program to copy its input to its output,*
 * replacing each tab by \t, each backspace by \b, and each       *
 * backslash by \\ This makes tabs and backspaces visible in      *
 * an unambiguous way.                                            *
 *                                                                *
 * The problem with this exercise is that in canonical mode the   *
 * \b is 'eaten', i.e. you can not capture it, because of the line*
 * buffering done by the operating system / terminal.             *
 *                                                                *
 * So, in order to capture \b you have to set the terminal        *
 * to non-canonical (raw) mode. Note that because there is no     *
 * line buffering you can not stop processing input when EOF      *
 * (CTRL-D) is read (there is no EOF).                            *
 *                                                                *
 * I found the solution for setting the terminal to non-canonical *
 * mode here:                                                     *
 * https://stackoverflow.com/questions/1798511/                   *
 * how-to-avoid-pressing-enter-with-getchar-for-reading           *
 * -a-single-character-only                                       *
 *                                                                *
 * @author greenleavolatile                                       *
 * @version 1.0                                                   *
 * @since 02-02-2022                                              *
 * ****************************************************************/

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

//The terminal emulator I use (st) produces DEL when backspace is typed.
#define BACKSPACE 127

int
main(void)
{
    int c;
    static struct termios old_t, new_t;

    // Get the terminal attributes.
    tcgetattr(STDIN_FILENO, &old_t);
    new_t = old_t;
    /* Change the terminal attributes
     * by turning off the ICANON bit with 
     * the bitwise NOT operator.*/
    new_t.c_lflag &= ~(ICANON | ECHO); 
    // Set the new terminal attributes.
    tcsetattr(STDIN_FILENO, TCSANOW, &new_t);

    while ((c = getchar()) != '.'){

        switch(c) {

            case '\t':
                putchar('\\');
                putchar('t');
                break;

            case BACKSPACE:
                putchar('\\');
                putchar('b');
                break;

            case '\\':
                putchar('\\');
                putchar('\\');
                break;

            default: 
                putchar(c);
        }
    }

    // Reset the terminal attributes.
    tcsetattr(STDIN_FILENO, TCSANOW, &old_t);
    return 0;
}



                        
