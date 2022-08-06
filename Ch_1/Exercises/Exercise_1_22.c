/*
 * @file Exercise 1-22
 *
 * @brief
 *
 * Exercise 1-22: "Write a program to "fold" long input line into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very 
 * long lines."
 * 
 * Notes:
 *
 * 1. "[...] after the last non-blank character [...]" I took this to mean,
 *    find the last blank character, then split the line at the last non-blank
 *    character before that blank character (i.e. the last letter of the
 *    previous word), e.g. (folding after the 14th column):
 *    
 *    IN: 
 *    Lorem ipsum sit dolor
 *    
 *    OUT:
 *    Lorem ipsum
 *    sit dolor"
 *
 * 2. If the column to fold after is part of the first word of the 
 *    line, the word is split, e.g. (folding after 3rd column):
 *    
 *    IN:
 *    lorem
 *
 *    OUT:
 *    lor
 *    em
 *
 * 3. If the column to fold after is part of a word, but not the first word of
 *    the line and not the last character of said word, the line is split at
 *    the last non-blank character (see 1).
 *    
 * 4. If the column to fold after is a blank, but not a leading blank, the line
 *    is split after the last non-blank character (see 1).
 *
 * 5. If the column to fold after is a leading blank, the line is split at said
 *    column, e.g. (folding after fifth column, x's representing
 *    blanks):
 *
 *    IN:
 *    xxxxxxlorem
 *
 *    OUT:
 *    xxxxx
 *    xlore
 *    m
 *
 * @author greenleafvolatile
 * @version 1.0
 * @since 04-07-2022
 */
// Directives
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAB_STOP 8          /* Number of blanks in a tab.*/
#define MAX_LINE 100        /* Maximum number of characters a user can input is equal to MAX_LINE - 1.*/
#define CLMN_TO_FLD_AFTR 1 /* Column to fold line after.*/

typedef enum {
  EXPAND_TABS_FAILED,
  EXPAND_TABS_SUCCESS
} error;

// Prototypes

/**
 * @brief Takes input from user and stores in array.
 *
 * @param char* pointer to char array in which user input is stored.
 *
 * @param int maximum size of the char array.
 *
 * @return int length of line inputted by user.
 */
int
get_line(char *, int);

/**
 * @brief Print from start index up to and including end index.
 *
 * @param int the start index.
 *
 * @param the end index.
 *
 * @param char * pointer to char array.
 *
 * @return void.
 */
void
print_line(int, int, const char *);

/**
 * @brief Verify if char is part of the first word of a line.
 *
 * @param int index from which to start parsing.
 * 
 * @param int index at which to stop parsing.
 *
 * @param char * pointer to char array.
 *
 * @return int 1 if char is part of the first word else 0.
 */
int
is_in_first_word(int, int,  const char *);

/**
 * @brief Find last character of previous word.
 *
 * @param int index to start parsing from.
 *
 * @param char * pointer to char array.
 *
 * @return int index of last non-blank character.
 */
int
get_indx_of_lst_non_blnk_char(int, const char *);

/**
 * @brief Fold a line.
 *
 * @param char * pointer to char array.
 *
 * @param int length of input line.
 *
 * @return void.
 */
void
fold_line(const char *, int);

/**
 * @brief Verify if blank is leading blank.
 * 
 * @param int index at which to start parsing.
 *
 * @param index at whic to stop parsing.
 *
 * @param char * pointer to char array.
 *
 * @return int 1 is blank is leading blank else 0.
 */
int
is_leading_blank(int, int, const char *);

/**
 * @brief Expand tabs to blanks.
 *
 * @param char * pointer to char array.
 *
 * @param int * pointer to int length of input line.
 *
 * @return error EXPAND_TABS_SUCCESFULL or EXPAND_TABS_FAILED.
 */
error
expand_tabs(char *, int *);

int
main(void)
{

  char line[MAX_LINE];
  int line_length;
  
  while((line_length = get_line(line, MAX_LINE)) > 0) {
  
    if (expand_tabs(line, &line_length)) {
      
      if (CLMN_TO_FLD_AFTR > line_length) {
        fputs(line, stdout);
        fputc('\n', stdout);
      } else {
        fold_line(line, line_length);
      }

    } else {
      return EXIT_FAILURE;
    }
  }

  return EXIT_SUCCESS;
}

void
fold_line(const char *line, int line_length)
{
  
  int curr_indx, indx_of_lst_non_blnk_char, fldng_indx;
  curr_indx = indx_of_lst_non_blnk_char = fldng_indx = 0;
  
  while (curr_indx < line_length) {
    
    fldng_indx = curr_indx + CLMN_TO_FLD_AFTR - 1 > line_length - 1 ? line_length - 1 : curr_indx + CLMN_TO_FLD_AFTR - 1;
    
    if ((isspace(line[fldng_indx]) && !is_leading_blank(curr_indx, fldng_indx, line)) ||
       (isalpha(line[fldng_indx]) && isalpha(line[fldng_indx + 1]) && !is_in_first_word(curr_indx, fldng_indx, line))) {
      
      indx_of_lst_non_blnk_char = get_indx_of_lst_non_blnk_char(fldng_indx, line);
      print_line(curr_indx, indx_of_lst_non_blnk_char, line);
      curr_indx = indx_of_lst_non_blnk_char + 1;
    
    } else {
      
      print_line(curr_indx, fldng_indx, line);
      curr_indx += CLMN_TO_FLD_AFTR;
    }
  }
  return;
}

error
expand_tabs(char *line, int *line_length)
{

  for (int i = 0; i < *line_length; ++i) {

    if (line[i] == '\t') {
      int number_of_blanks = TAB_STOP - (i % TAB_STOP);

      if (*line_length + number_of_blanks - 1 > MAX_LINE) {
        return EXPAND_TABS_FAILED;
      } else {

        if (number_of_blanks > 1) {

          for (int j = *line_length; j > i; --j) {
            line[j + number_of_blanks - 1] = line[j];
          }
        }

        for (int k = i; k < i + number_of_blanks; ++k) {
          line[k] = 'x';
        }

        *line_length += number_of_blanks - 1;
      }
    }
  }
  return EXPAND_TABS_SUCCESS;
}

int
get_line(char line[], int max_length)
{

  int ch, i = 0;

  while (i < max_length - 1 && (ch = getchar()) != '\n' && ch != EOF) 
    line[i++] = ch;

  line[i] = '\0';
  return i;

}

void
print_line(int start_index, int end_index, const char *line) 
{

  for(; start_index <= end_index; ++start_index) 
    fputc(line[start_index], stdout);

  fputc('\n', stdout);
  return;
}

int
is_in_first_word(int start_index, int end_index, const char *line)
{

  int is_in_first_word = 1;

  while(line[start_index] == ' ') // Account for line with leading blanks.
      ++start_index;
      
  for (; start_index <= end_index; ++start_index) {
    if (line[start_index] == ' ') {
      is_in_first_word = 0;
      break;
    }
  }
  return is_in_first_word;
}

int
get_indx_of_lst_non_blnk_char(int index, const char *line)
{

  while(line[index] != ' ')
    --index;

  while(line[index] == ' ')
    --index;

  return index;
}

int
is_leading_blank(int start_index, int end_index, const char *line)
{

  int is_leading_blank = 1;

  for(; end_index >= start_index; --end_index) {
    if (line[end_index] != ' ') {
      is_leading_blank = 0;
      break;
    }
  }
  return is_leading_blank;
}


