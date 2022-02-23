/***************************************************************************
 * Exercise 1-19: Write a function reverse(s) that reverses the character  *
 * string s. Use it to write a program that reverses its input a line      *
 * at a time.                                                              *
 * @author greenleafvolatile                                               *
 * @version 1.0                                                            *
 * @since 19-02-2022                                                       *
 * *************************************************************************/
#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int
get_line(char [], int);

int
get_length(char []);

void
reverse(char []);

int
main(void) 
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
      reverse(line);
      printf("Reversed line: %s", line);
    }
    return 0;
}

void 
reverse(char line[])
{

  int beginning = 0;
  int end = line[get_length(line) - 1] == '\n' ? get_length(line) - 2 : get_length(line) - 1;

  while (beginning < end) {
    char tmp = line[beginning];
    line[beginning++] = line[end];
    line[end--] = tmp;
  }
  return;
}

/* Read a line, return length. */
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

/* Get length of string excluding '\0'. */
int
get_length(char line[]) 
{

  int i = 0;
  while(line[i] != '\0') 
    i++;
  return i;
}
