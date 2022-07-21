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

#define MAX_LINE 100             /* A comment here. */
#define CLMN_TO_FLD_AFTR 10  /* A comment here. */

// Prototypes

/**
 * @brief Gets input from use and stores in array.
 *
 */
int
get_line(char *, int);

/**
 * @brief print from start index up to and including end index.
 */
void
print_line(int start_index, int end_index, char * line );

/**
 * @brieaf
 */
int
is_in_first_word(int, int,  char *);

/**
 * @brief
 */
int
get_indx_of_lst_alphnmrc_char(int, char *);

/**
 * @brief
 */
void
fold_line(char *, int);

/**
 * @brief
 */
int
is_leading_blank(int, int, char *);

int
main(void)
{

  char line[MAX_LINE];
  int line_length;

  while((line_length = get_line(line, MAX_LINE)) > 0) {
    
    if (CLMN_TO_FLD_AFTR > line_length) {
      fputs(line, stdout);
    } else {
      fold_line(line, line_length);
    }
  }

  return EXIT_SUCCESS;
}

void
fold_line(char *line, int line_length)
{
  
  int curr_indx = 0;
  int indx_of_lst_alphnmrc_char = 0;
  
  while (curr_indx < line_length) {
    
    // 1: if CLMN_TO_FLD_AFTR is part of the first word of the line,
    // then split the word. 
    if (is_in_first_word(curr_indx, curr_indx + CLMN_TO_FLD_AFTR, line)) {
      print_line(curr_indx, curr_indx + CLMN_TO_FLD_AFTR - 1, line);
      curr_indx += CLMN_TO_FLD_AFTR; 
    }
    
    // 2: if CLMN_TO_FLD_AFTR is a leading blank or if it's the last
    // or only character in a word, then print from curr_indx to
    // CLMN_TO_FLD_AFTR.
    else if (is_leading_blank(curr_indx, CLMN_TO_FLD_AFTR - 1, line) || (isalpha(line[curr_indx + CLMN_TO_FLD_AFTR - 1]) && isspace(line[curr_indx + CLMN_TO_FLD_AFTR]))) {
      print_line(curr_indx, CLMN_TO_FLD_AFTR - 1, line);
      curr_indx = CLMN_TO_FLD_AFTR;
    }
      
    // 3: if CLM_TO_FLD_AFTR is non-leading blank or any character but the
    // last character in a word, then find the index of the last character of the preceding word and
    // print from curr_indx up to and including that character.
    else if (isspace(line[curr_indx + CLMN_TO_FLD_AFTR - 1]) || isalpha(line[curr_indx + CLMN_TO_FLD_AFTR ])) {  
        indx_of_lst_alphnmrc_char = get_indx_of_lst_alphnmrc_char(curr_indx + CLMN_TO_FLD_AFTR, line);
        print_line(curr_indx, indx_of_lst_alphnmrc_char, line);
        curr_indx = indx_of_lst_alphnmrc_char + 1;
    }
  }
  
  return;
}

int
get_line(char line[], int line_length)
{

  int ch, i = 0;

  while (i < line_length - 1 && (ch = getchar()) != '\n' && ch != EOF) 
    line[i++] = ch;

  if (ch == '\n')
    line[i++] = ch;

  line[i] = '\0';
  return i;

}

void
print_line(int start_index, int end_index, char *line) 
{
  for(; start_index <= end_index; ++start_index) {

    if (line[start_index] == ' ') {
      fputc('x', stdout);
    } else {
      fputc(line[start_index], stdout);
    }
  }

  fputc('\n', stdout);
  return;
}

int
is_in_first_word(int start_index, int end_index, char *line)
{

  int is_in_first_word = 0;

  while(isspace(line[start_index])) // Account for line with leading blanks.
      ++start_index;
      
  for (; start_index < end_index; ++start_index) {
    if (isspace(line[start_index])) {
      is_in_first_word = 1;
      break;
    }
  }

  return is_in_first_word;
}

int
get_indx_of_lst_alphnmrc_char(int index, char *line)
{
  while(isalpha(line[index]))
    --index;

  while(isspace(line[index]))
    --index;

  return index;
}

int
is_leading_blank(int start_index, int end_index, char *line)
{
  int is_leading_blank = 1;

  for(; end_index >= start_index; --end_index) {
    if (isalpha(line[end_index]))
      is_leading_blank = 0;
  }

  return is_leading_blank;
}


