/*********************************************
 * @file Exercise 1-22
 *
 * @brief
 *
 * Exercise 1-22: "Write a program to "fold" long input line into two or more
 * shorter lines after the last non-whitespace character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very 
 * long lines."
 * 
 * Notes:
 *
 * 1. "[...] after the last non-whitespace character [...]" I took this to mean,
 *    find the last whitespace character, then split the line at the last non-whitespace
 *    character before that whitespace character. For example,  if you were to fold the line
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
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE 100             /* A comment here. */
#define COLUMN_TO_FOLD_AFTER 10  /* A comment here. */

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
get_index_of_last_non_whitespace_character(int, char *);

/**
 * @brief
 */
void
fold_line(char *, int);

/**
 * @brief
 */
int
is_leading_whitespace(int, int, char *);

int
main(void)
{

  char line[MAX_LINE];
  int line_length;

  while((line_length = get_line(line, MAX_LINE)) > 0) {
    
    if (COLUMN_TO_FOLD_AFTER > line_length) {
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
  
  int current_index = 0;
  int index_of_last_non_whitespace_character = 0;
  
  while (current_index < line_length) {
    
    // Case 1: if COLUM_TO_FOLD_AFTER is part of the first word of the line,
    // then split the word. 
    if (is_in_first_word(current_index, current_index + COLUMN_TO_FOLD_AFTER, line)) {
      print_line(current_index, current_index + COLUMN_TO_FOLD_AFTER - 1, line);
      current_index += COLUMN_TO_FOLD_AFTER; 
    }
    
    // Case 2: if COLUMN_TO_FOLD_AFTER is a leading blank or if it's the last
    // or only character in a word, then print from current_index to
    // COLUMN_TO_FOLD_AFTER.
    else if (is_leading_whitespace(current_index, COLUMN_TO_FOLD_AFTER - 1, line) || isalpha(line[current_index + COLUMN_TO_FOLD_AFTER - 1]) && isspace(line[current_index + COLUMN_TO_FOLD_AFTER]))
      print_line(current_index, COLUMN_TO_FOLD_AFTER - 1, line);
      current_index = COLUMN_TO_FOLD_AFTER;
    }
      
    // Case 3: if COLUMN_TO_FOLD after is non-leading whitespace or any character but the
    // last character in a word, then find the index of the last character of the preceding word and
    // print from current_index up to and including that character.
    else if (isspace(line[current_index + COLUMN_TO_FOLD_AFTER - 1]) || isalpha(line[current_index + COLUMN_TO_FOLD_AFTER ])) {  
        index_of_last_non_whitespace_character = get_index_of_last_non_whitespace_character(current_index + COLUMN_TO_FOLD_AFTER, line);
        print_line(current_index, index_of_last_non_whitespace_character, line);
        current_index = index_of_last_non_whitespace_character + 1;
    }
    
    return;
}

int
get_line(char line[], int line_length)
{

  int ch, i = 0;

  while (i < line_length - 1 && (ch = getchar()) != '\n' && ch != EOF) {
    line[i++] = ch;
  }
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
get_index_of_last_non_whitespace_character(int index, char *line)
{
  while(isalpha(line[index]))
    --index;

  while(isspace(line[index]))
    --index;

  return index;
}

int
is_leading_whitespace(int start_index, int end_index, char *line)
{
  int is_leading_whitespace = 1;

  for(; end_index >= start_index; --end_index) {
    if (isalpha(line[end_index]))
      is_leading_whitespace = 0;
  }

  return is_leading_whitespace;
}


