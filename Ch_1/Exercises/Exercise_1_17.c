/***************************************************************************
 * Exercise 1-17: Write a program to print all input lines that are longer *
 * than 80 characters.                                                     *
 *                                                                         *
 * @author greenleafvolatile                                               *
 * @version 1.0                                                            *
 * @since 14-02-2022                                                       *
 * *************************************************************************/
#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define MAX 80

int
get_line(char [], int);

int
main(void) 
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
      
      if (len > MAX) {
        
        printf("Length: %d\nText: %s\n", len, line);
        
      }
    }

    return 0;
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


                            
