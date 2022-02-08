/**********************************************************************
 * Exercise 1-13: Write a program to print a histogram of the lengths *
 * of words in its input. It is easy to draw the histogram with the   *
 * bars horizontal; a vertical orientation is more challenging.       *
 *                                                                    *
 * @author greenleafvolatile                                          *
 * @version 1.0                                                       *
 * @since 06-02-2022                                                  *
 * ********************************************************************/
#include <stdio.h>

int
main(void) 
{
    int c, i = 0;
    int word_lengths[25] = {0}; 
                                
    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (word_lengths[i] > 0) 
                ++i;
        }
        else {
            ++word_lengths[i];
        }
    }

    for(int i = 0; i < 25; ++i) {
        if (word_lengths[i] > 0) {
            printf("[%d] ", i + 1);
            for (int j = 0; j < word_lengths[i]; ++j) {
                putchar('*');
            }

            putchar('\n');
        }
    }
    return 0;
}






        

