#include <string.h>
#include <stdio.h>
<<<<<<< HEAD
#include <ctype.h>
#include "Definitions.h"

=======
#include "Definitions.h"
>>>>>>> b825c9030803690e06542e457bfeefcae86e2e60

void print_sep(int word_length);
void print_guess_row(char *guess, int colors[], int word_length);
void print_color(int colors[], char guess[], int word_length);
void clear_line();

void clear_line()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }
}

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
  printf("\n");
}

void print_color(int colors[], char guess[], int word_length)
{
  print_sep(word_length);
  print_guess_row(guess, colors, word_length);
}
