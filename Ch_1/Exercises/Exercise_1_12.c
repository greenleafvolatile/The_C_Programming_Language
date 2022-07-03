/********************************************************
 * Exercise 1-12: Write a program that prints its       *
 * input one word per line.                             *
 *                                                      *
 * @author greenleafvolatile                            *
 * @version 1.0                                         *
 * @since 02-02-2022                                    *
 * ******************************************************/

#include <stdio.h>

int
main(void)
{
    int c, is_following_non_whitespace_char = 0; // One word per line, so do not put a newline if input line starts with whitespace character.

        while((c = getchar()) != EOF) {

        if ((c == ' ' || c == '\t') && is_following_non_whitespace_char) { // One word per line, so do not put multiple newline if parsing sequence of whitespace characters.
            putchar('\n');
            is_following_non_whitespace_char = 0;
        }
        else if (c != ' ' && c != '\t'){
            putchar(c);
            is_following_non_whitespace_char = 1;
        }
    }
    
    return 0;
}
