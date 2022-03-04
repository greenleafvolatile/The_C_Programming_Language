/*****************************************************************************
 * Exercise 1-20: Write a program that replaces the tabs in the input with   *
 * the proper number of blanks to space to the next tab stop. Assume a fixed *
 * set of tab stops, say every n columns.                                    *
 *                                                                           *
 * @author greenleafvolatile                                                 *
 * @version 1.0                                                              *
 * @since 04-03-2022                                                         *
 * ***************************************************************************/
#include <stdio.h>

#define TAB_LENGTH 4

int
main(void)
{

  int c;

  while((c = getchar()) != EOF) {

    if (c == '\t') {
      for (int i = 0; i < TAB_LENGTH; ++i) 
        putchar(' ');
    } else {
      putchar(c);
    }
  }
  return 0;
}





