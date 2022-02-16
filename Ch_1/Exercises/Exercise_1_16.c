/***************************************************************************
 * Exercise 1-16: Revise the main routine of the longest line program so it*
 * will correctly print the total_length of arbitrarily long input lines,  *
 * and as much as possible of the text.                                    *
 *                                                                         *
 * Note:                                                                   *
 * A line is either:                                                       *
 * 1. MAXLINE characters with line[len - 1] being equal to '\n'            *
 * 2. Less than MAXLINE characters with line[len - 1] being '\n' or any    *
 *  other char in case of EOF.                                             *
 *                                                                         *
 * @author greenleafvolatile                                               *
 * @version 1.0                                                            *
 * @since 14-02-2022                                                       *
 * *************************************************************************/
#include <stdio.h>
#define MAXLINE 10 /* maximum input line size */

int
get_line(char [], int);

void
print_line(char [], int);

void
copy(char [], char[]);

int
main(void) 
{
    int len, total_len = 0;
    char line[MAXLINE];
    char first_part_of_line[MAXLINE];

    // Capture up to MAXLINE characters from stdin.
    while ((len = get_line(line, MAXLINE)) > 0) {
      
      if (len == MAXLINE - 1 && line[len - 1] != '\n') {

        // Store the first MAXLINE characters so "as much as possible
        // of the text" can be printed.
        if (total_len == 0) 
          copy(line, first_part_of_line);
          
        total_len += len;

      } else {
        
        printf("Length: %d\n", len + total_len);
        printf("Text: %s\n", total_len > MAXLINE - 1 ? first_part_of_line : line);
        
        total_len = 0;
      }
    }

    return 0;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i = 0;

  while ((to[i] = from[i]) != '\0')
    ++i;
}


/* get_line: read a line into s, return length */
int
get_line(char line[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}


                            
