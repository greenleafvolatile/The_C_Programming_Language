/*****************************************************************************
 * Exercise 1-20: Write a program that replaces the tabs in the input with   *
 * the proper number of blanks to space to the next tab stop. Assume a fixed *
 * set of tab stops, say every n columns.                                    *
 *                                                                           *
 * @author greenleafvolatile                                                 *
 * @version 1.0                                                              *
 * @since 04-03-2022                                                         *
 * ***************************************************************************/
// Directives
#include <stdio.h>

#define TAB_STOP 8

int
main(void)
{

  int ch, ch_counted = 0;

  ch = getchar();
  while(ch != EOF && ch != '\n') {

    ++ch_counted;
    if (ch == '\t') {
      for (int i = 0; i < TAB_STOP - (ch_counted - 1); ++i) 
        putchar(' ');
      ch_counted = 0;
    } else {
      putchar(ch);
    }
    ch = getchar();
  }
  return 0;
}





