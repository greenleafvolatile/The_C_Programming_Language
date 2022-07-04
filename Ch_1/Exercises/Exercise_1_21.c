/******************************************************************************
 * @file Exercise_1_21.c                                                      *
 *                                                                            *
 * @brief                                                                     *
 *                                                                            *
 * "Exercise 1-21: Write a program that replaces strings of blanks by the     *
 * minimum number of tabs and blanks to achieve the same spacing. Use the     *
 * same tab stops as for exercise 1-20. When either a tab or a single blank   *
 * would suffice to reach a tab stop, which should be give preference?"       *
 *                                                                            *
 * Note: I don't know the answer to the above question. I chose to give       *
 * preference to a tab in cases where a single blank or a tab were            *
 * sufficient to reach a tab stop.                                            *
 *                                                                            *
 * @author greenleafvolatile                                                  *
 * @version 1.0                                                               *
 * @since 04-03-2022                                                          *
 ******************************************************************************/
// Directives
#include <stdio.h>

#define TAB_STOP 8

// Prototypes
/**
 * @brief Print n blanks to stdout.
 *
 * @param int number of blanks to print.
 *
 * @return void.
 */
void
put_blank(int);

/**
 * @brief Print n number of tabs to stdout.
 *
 * @param int number of tabs to print.
 *
 * @return void.
 */
void
entab(int);

int
main(void) 
{
  int ch, column_counted = 0, blanks_counted = 0;
  
  while((ch = getchar()) != EOF && ch != '\n') {

    // Count number of characters inputted.
    // in order to know when a tab should be
    // printed.
    ++column_counted; 
    
    if (ch == ' ') {
      // Count number of blanks inputted
      // in order to know if a tab should
      // be printed.
      ++blanks_counted;
    } else if (ch != ' ') {

      if (blanks_counted > 0) {

        if (column_counted > TAB_STOP) {
          entab(column_counted - 1);
          put_blank((column_counted - 1) % TAB_STOP);
          column_counted = column_counted % TAB_STOP;
        } else if (column_counted <= TAB_STOP) {
          put_blank(blanks_counted);
        }

        blanks_counted = 0;

        // Reset the character count when TAB_STOP
        // number of characters have been printed to
        // stdout consecutively.
      } else if (column_counted % TAB_STOP == 0) { 
        column_counted = 0;
      }
      putchar(ch);
    }
   }

   // Handle trailing blanks and lines that 
   // consist solely of blanks.
   if (blanks_counted > 0) {
     entab(column_counted);
     put_blank(column_counted % TAB_STOP);
   }

   return 0;
}

void 
put_blank(int number_of_blanks)
{
  for (int i = 0; i < number_of_blanks; ++i) 
    putchar(' ');
}

void
entab(int column_counted)
{
  for (int i = 0; i < column_counted / TAB_STOP; ++i) {
    putchar('\t');
  }
}
     








