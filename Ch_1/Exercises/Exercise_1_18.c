/***************************************************************************
 * Exercise 1-18: Write a program to remove trailing blanks and tabs from  *
 * each line of input, and to delete entirely blank lines.                 *
 *                                                                         *
 * Note:                                                                   *
 * I took 'delete entirely blank lines' to mean not printing them          *
 * to stdout since we are not storing all the lines.                       *
 *                                                                         *
 * @author greenleafvolatile                                               *
 * @version 1.0                                                            *
 * @since 19-02-2022                                                       *
 * *************************************************************************/
#include <stdio.h>

#define MAXLINE 100 /* maximum input line size */

int
get_line(char [], int);

int
get_length(char []);

int
is_entirely_blank_line(char [], int);

int
get_index_of_last_non_blank_non_tab_non_newline_character(char [], int len);

int
main(void) 
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {

      printf("Line length with trailing blanks and tabs: %d\n", get_length(line));
      if (is_entirely_blank_line(line, len) ) {
        // Do nothing.
      } else {
        int last = get_index_of_last_non_blank_non_tab_non_newline_character(line, len);
        // If original input had a newline as final character, add newline
        // character.
        if (line[len - 1] == '\n') {
          line[last + 1] = '\n';
          line[last + 2] = '\0';
        } else {
          line[last + 1] = '\0';
        }
      }
      printf("Line length without trailing blanks and tabs: %d\n", get_length(line));
    }
    return 0;
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

/* Get length of string. */
int
get_length(char line[]) 
{

  int i = 0;
  while(line[i] != '\0') 
    ++i;
  return i;
}



/* Check if line consistst entirely of blanks and tabs. */
int
is_entirely_blank_line(char line[], int len) 
{

  for (int i = 0; i < len; ++i) {

    if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t') {
      return 0;
    }
  }
  return 1;
}

/* Get index of last non-blank, non-tab, non-newline character. */
int
get_index_of_last_non_blank_non_tab_non_newline_character(char line[], int len) 
{

  int i = len - 1;
  while(line[i] == ' ' || line[i] == '\t' || line[i] == '\n') 
    --i;
  return i;
}                            
