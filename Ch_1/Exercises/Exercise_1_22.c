/*********************************************
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
 *    character before that blank character. For example,  if you were to fold the line
 *    "Lorem ipsum sit dolor" after the 14th column, the output should be:
 *
 *    "Lorem ipsum
 *    sit dolor"
 *
 *
 *
 * 
 * @author greenleafvolatile
 * @version 1.0
 * @since 04-07-2022
 *********************************************/
// Directives
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAB_STOP 8          /* A comment here. */
#define MAX_LINE 100         /* A comment here. */
#define CLMN_TO_FLD_AFTR 14  /* A comment here. */

typedef enum {
  EXPAND_TABS_FAILED,
  EXPAND_TABS_SUCCESS
} error;

// Prototypes

/**
 * @brief Takes input from user and stores in array.
 *
 */
int
get_line(char *, int);

/**
 * @brief print from start index up to and including end index.
 */
void
print_line(int start_index, int end_index, const char *line );

/**
 * @brieaf
 */
int
is_in_first_word(int, int,  const char *);

/**
 * @brief
 */
int
get_indx_of_lst_non_blank_char(int, const char *);

/**
 * @brief
 */
void
fold_line(const char *, int);

/**
 * @brief
 */
int
is_leading_blank(int, int, const char *);

/**
 * @brief
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
  
  int curr_indx = 0;
  int indx_of_lst_non_blank_char = 0;
  
  while (curr_indx < line_length - 1) {
 
    if ((line[curr_indx + CLMN_TO_FLD_AFTR - 1] == ' ' && !is_leading_blank(curr_indx, curr_indx + CLMN_TO_FLD_AFTR - 1, line)) || 
       (line[curr_indx + CLMN_TO_FLD_AFTR - 1] != ' ' && line[curr_indx + CLMN_TO_FLD_AFTR] != ' ' && !is_in_first_word(curr_indx, curr_indx + CLMN_TO_FLD_AFTR, line)))

    {
      indx_of_lst_non_blank_char = get_indx_of_lst_non_blank_char(curr_indx + CLMN_TO_FLD_AFTR - 1, line);
      print_line(curr_indx, indx_of_lst_non_blank_char, line);
      curr_indx = indx_of_lst_non_blank_char + 1;
    } else {
      print_line(curr_indx, curr_indx + CLMN_TO_FLD_AFTR - 1 > line_length ? line_length - 1 : curr_indx + CLMN_TO_FLD_AFTR - 1, line);
      curr_indx = curr_indx + CLMN_TO_FLD_AFTR < line_length ? curr_indx + CLMN_TO_FLD_AFTR : line_length - 1; 
    }

    if (line[curr_indx] != '\n')
      fputc('\n', stdout);
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

  if (ch == '\n')
    line[i++] = ch;

  line[i] = '\0';
  return i;

}

void
print_line(int start_index, int end_index, const char *line) 
{
  for(; start_index <= end_index; ++start_index) {

    if (line[start_index] == ' ') {
      fputc('x', stdout);
    } else {
      fputc(line[start_index], stdout);
    }
  }
  return;
}

int
is_in_first_word(int start_index, int end_index, const char *line)
{

  int is_in_first_word = 1;

  while(line[start_index] == ' ') // Account for line with leading blanks.
      ++start_index;
      
  for (; start_index < end_index; ++start_index) {
    if (line[start_index] == ' ') {
      is_in_first_word = 0;
      break;
    }
  }
  return is_in_first_word;
}

int
get_indx_of_lst_non_blank_char(int index, const char *line)
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


