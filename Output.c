#include "play.h"
#include <string.h>
#include "colors.h"

void print_sep(Game *g);
void print_guess_row(char *guess, int colors[], Game *g);
void print_color(int colors[], char guess[], Game *g);

void print_sep(Game *g)
{
  int i;
  int n = g->word_length;

  putchar('\n');
  for (i = 0; i < n; i++)
  {
    printf("+---");
  }
  printf("+\n");
}

void print_guess_row(char *guess, int colors[], Game *g)
{
  int i;
  int n = g->word_length;

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

void print_color(int colors[], char guess[], Game *g)
{
  print_sep(g);
  print_guess_row(guess, colors, g);
}
