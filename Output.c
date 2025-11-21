#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "Definitions.h"

/* 

  File: Output.c
  Author: Emilina Salazar
  Debugged: Christopher Farlow, Max Klein
  Assignment: Wordle Project 11/22/2025
  Date: 11/22/2025
  References: notes, google

*/

void print_sep(int word_length);
void print_guess_row(char *guess, int colors[], int word_length);
void print_color(int colors[], char guess[], int word_length);

/*
  Prints a separator line based on the word length
  Arguments:
  @word_length: length of the word being guessed
  Returns: none
*/
void print_sep(int word_length)
{
  int i;
  int n = word_length;

  putchar('\n');
  for (i = 0; i < n; i++)
  {
    printf("+---");
  }
  printf("+\n");
}
/* 
  Prints a row of the guessed word with color coding based on correctness
  Arguments:
  @guess: the user's guessed word
  @colors: array containing color codes for each letter in guess
  @word_length: length of the word being guessed
  Returns: none
*/
void print_guess_row(char *guess, int colors[], int word_length)
{
  int i;
  int n = word_length;

  printf("|");
  for (i = 0; i < n; i++)
  {
    char ch;

    if (guess[i] != '\0')
    {
      ch = guess[i];
    }
    else
    {
      ch = ' ';
    }

    ch = (char)toupper((unsigned char)ch);
    /*print_color2(colors, guess);*/
    switch (colors[i])
    {
    case 0:
      printf(GREY_BG WHITE_TXT BOLD_TXT " %c " RESET, ch);
      break;
    case 1:
      printf(YELLOW_BG WHITE_TXT BOLD_TXT " %c " RESET, ch);
      break;
    case 2:
      printf(GREEN_BG WHITE_TXT BOLD_TXT " %c " RESET, ch);
      break;
    default:
      /*fall back to no color if colors[i] is something else*/
      printf(" %c ", ch);
      break;
    }

    printf("|");
  }
}
/*
  Prints the guessed word with color coding based on correctness
  Arguments:
  @colors: array containing color codes for each letter in guess
  @guess: the user's guessed word
  @word_length: length of the word being guessed
  Returns: none
*/
void print_color(int colors[], char guess[], int word_length)
{
  print_sep(word_length);
  print_guess_row(guess, colors, word_length);
}
