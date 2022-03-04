/*******************************************************************************
 * Exercise 1-21: Write a program that replaces strings of blanks by the       *
 * minimum number of tabs and blanks to achieve the same spacing. Use the same *
 * tab stops as for exercise 1-20.                                             *
 *                                                                             *
 * @author greenleafvolatile                                                   *
 * @version 1.0                                                                *
 * @since 04-03-2022                                                           *
 *******************************************************************************/
#include <stdio.h>

#define TAB_LENGTH 4

int
main(void) 
{
   int ch, blank_counter = 0;

   while((ch = getchar()) != EOF) {

     // Keep count of blanks parsed.
     if (ch == ' ') {
       ++blank_counter;
     } else {
       
       if (blank_counter >= TAB_LENGTH) {
         // Divide number of blanks by tab length to get number of tabs
         // to print to stdout.
         for (int i = 0; i < blank_counter / TAB_LENGTH; ++i) 
           putchar('\t');
       }

       // Print (remaining) blanks to stdout.
       for (int i = 0; i < blank_counter % TAB_LENGTH; ++i) 
         putchar(' ');

       blank_counter = 0;
       putchar(ch);
     }
   }
   return 0;
}
     
     








